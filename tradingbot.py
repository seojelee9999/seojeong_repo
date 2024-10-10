import pandas as pd
import talib as ta
import time
import logging
from binance.client import Client
from binance.enums import *

# Binance Futures API 키
api_key = 'wJc0gyGW7gpr6NbM63vZyup8BnOMbihPW7xC5FBY07IFiIXQRwOL7xfUWu8xL2aD'
api_secret = 'ttF38A2JeEADWEeOh3iK0HbT7HUZ0huTy820GQrxXcghOQuifp3XxzKFsiQrrVWT'

# Binance 선물 클라이언트 초기화
client = Client(api_key, api_secret)

# 손익분기점 및 매수 가격을 저장할 변수
break_even_price = None
buy_price = None
symbol = 'REEFUSDT'  # 종목 기본값 설정

# 로깅 설정
logging.basicConfig(filename='trading_bot.log', level=logging.INFO)

def set_leverage(leverage):
    """레버리지를 설정하는 함수"""
    global symbol  # global symbol 선언
    try:
        client.futures_change_leverage(symbol=symbol, leverage=leverage)
        logging.info(f"{symbol}의 레버리지가 {leverage}배로 설정되었습니다.")
    except Exception as e:
        logging.error(f"레버리지 설정 오류: {e}")

def log_wallet_balance():
    """선물 지갑의 총 주문 금액을 로그로 기록"""
    try:
        balance_info = client.futures_account_balance()
        for asset in balance_info:
            if asset['asset'] == 'USDT':
                logging.info(f"선물 지갑의 총 자산 (USDT): {asset['balance']}")
                break
    except Exception as e:
        logging.error(f"지갑 잔액 가져오기 오류: {e}")

def get_futures_candles(interval):
    """바이낸스 선물에서 15분봉 데이터를 가져오는 함수"""
    global symbol  # global symbol 선언
    try:
        candles = client.futures_klines(symbol=symbol, interval=interval)
        df = pd.DataFrame(candles, columns=[
            'open_time', 'open', 'high', 'low', 'close', 'volume', 
            'close_time', 'quote_asset_volume', 'number_of_trades', 
            'taker_buy_base_asset_volume', 'taker_buy_quote_asset_volume', 'ignore'
        ])
        df['close'] = df['close'].astype(float)
        return df
    except Exception as e:
        logging.error(f"캔들 데이터 가져오기 오류: {e}")
        return None

def generate_signals(df):
    """이동평균선(MA7)을 기준으로 매매 신호 생성"""
    try:
        ma7 = ta.SMA(df['close'], timeperiod=7)  # MA7 계산
        df['ma7'] = ma7

        # 현재 가격과 이전 가격이 이동평균선을 교차하는지 확인
        if df['close'].iloc[-1] > df['ma7'].iloc[-1] and df['close'].iloc[-2] <= df['ma7'].iloc[-2]:
            return "buy"
        elif df['close'].iloc[-1] < df['ma7'].iloc[-1] and df['close'].iloc[-2] >= df['ma7'].iloc[-2]:
            return "sell"
        else:
            return "hold"
    except Exception as e:
        logging.error(f"신호 생성 오류: {e}")
        return "hold"

def adjust_quantity_precision(quantity, precision):
    """주문 수량의 소수점 자리를 자산의 허용치에 맞춰 조정"""
    return round(quantity, precision)

def place_futures_order(signal, current_price):
    global break_even_price, buy_price, symbol  # global symbol 선언
    
    stop_loss_threshold = 0.94  # 5% 손실 허용
    take_profit_threshold = 1.06  # 5% 이익 실현
    usd_amount = 100  # 100달러 주문
    quantity = usd_amount / current_price  # 100달러에 해당하는 REEF 양
    min_quantity = 1  # 최소 거래 수량
    precision = 0  # REEF의 허용 소수점 자리수는 0

    # 소수점 자릿수 맞추기
    quantity = adjust_quantity_precision(quantity, precision)

    if quantity < min_quantity:
        logging.warning(f"주문 수량이 최소 거래 수량 미만입니다: {quantity} {symbol}")
        return
    
    try:
        if signal == "buy":
            if break_even_price is None:  # 처음 매수(롱 포지션)하는 경우
                logging.info(f"매수 신호 발생 - {usd_amount} USD 만큼 매수, 현재 가격: {current_price}")
                order = client.futures_create_order(
                    symbol=symbol,
                    side=SIDE_BUY,
                    type=ORDER_TYPE_MARKET,
                    quantity=quantity
                )
                logging.info(f"주문 응답: {order}")
                if order['status'] != 'FILLED':
                    logging.error(f"주문이 체결되지 않았습니다. 주문 상태: {order['status']}")
                else:
                    logging.info(f"주문이 성공적으로 체결되었습니다.")
                buy_price = current_price
                break_even_price = current_price
            else:
                logging.info("롱 포지션이 이미 존재하여 매수를 실행하지 않음")
        
        elif signal == "sell":
            if break_even_price is None:
                logging.info(f"매도 신호 발생 - {usd_amount} USD 만큼 매도, 현재 가격: {current_price}")
                order = client.futures_create_order(
                    symbol=symbol,
                    side=SIDE_SELL,
                    type=ORDER_TYPE_MARKET,
                    quantity=quantity
                )
                logging.info(f"주문 응답: {order}")
                if order['status'] != 'FILLED':
                    logging.error(f"주문이 체결되지 않았습니다. 주문 상태: {order['status']}")
                else:
                    logging.info(f"주문이 성공적으로 체결되었습니다.")
                buy_price = current_price
                break_even_price = current_price
            elif current_price < break_even_price:
                logging.info(f"매도 신호 발생 - {usd_amount} USD 만큼 매도, 현재 가격: {current_price}")
                order = client.futures_create_order(
                    symbol=symbol,
                    side=SIDE_SELL,
                    type=ORDER_TYPE_MARKET,
                    quantity=quantity
                )
                logging.info(f"주문 응답: {order}")
                if order['status'] != 'FILLED':
                    logging.error(f"주문이 체결되지 않았습니다. 주문 상태: {order['status']}")
                else:
                    logging.info(f"주문이 성공적으로 체결되었습니다.")
                break_even_price = None
                buy_price = None
            else:
                logging.info(f"손익분기점 미달로 매도 실행되지 않음 - 현재 가격: {current_price}")
        
        # 스톱로스 조건
        if buy_price is not None and current_price <= buy_price * stop_loss_threshold:
            logging.info(f"5% 손실로 스톱로스 실행, 현재 가격: {current_price}")
            order = client.futures_create_order(
                symbol=symbol,
                side=SIDE_SELL,
                type=ORDER_TYPE_MARKET,
                quantity=quantity
            )
            logging.info(f"스톱로스 주문 응답: {order}")
            if order['status'] != 'FILLED':
                logging.error(f"스톱로스 주문이 체결되지 않았습니다. 주문 상태: {order['status']}")
            else:
                logging.info(f"스톱로스가 성공적으로 체결되었습니다.")
            break_even_price = None
            buy_price = None

        # 이익 실현 조건
        if buy_price is not None and current_price >= buy_price * take_profit_threshold:
            logging.info(f"5% 이익 실현, 포지션 청산, 현재 가격: {current_price}")
            order = client.futures_create_order(
                symbol=symbol,
                side=SIDE_SELL,
                type=ORDER_TYPE_MARKET,
                quantity=quantity
            )
            logging.info(f"이익 실현 주문 응답: {order}")
            if order['status'] != 'FILLED':
                logging.error(f"이익 실현 주문이 체결되지 않았습니다. 주문 상태: {order['status']}")
            else:
                logging.info(f"이익 실현이 성공적으로 체결되었습니다.")
            break_even_price = None
            buy_price = None
    
    except Exception as e:
        logging.error(f"주문 중 오류 발생: {e}")

# 시작 시 선물 지갑의 총 주문 가능 금액을 로그로 기록
log_wallet_balance()

# 3배 레버리지 설정
set_leverage(6)

interval = '15m'

while True:
    try:
        df = get_futures_candles(interval)
        if df is not None:
            current_price = df['close'].iloc[-1]  # 현재 가격
            signal = generate_signals(df)
            place_futures_order(signal, current_price)
        time.sleep(1)  # API 요청 간 1초 대기
    except Exception as e:
        logging.error(f"루프 중 오류 발생: {e}")
        time.sleep(5)  # 오류 발생 시 5초 대기 후 재시작
