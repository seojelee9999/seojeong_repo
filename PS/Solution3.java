import java.util.HashSet;
import java.util.Set;

class Solution {
    public int lengthOfLongestSubstring(String s) {
        Set<Character> set = new HashSet<>();
        char []cArr = s.toCharArray();
        int maxNum = 0;
        int cnt = 0;
        int left = 0;
        for (int right = 0 ; right < cArr.length; right++){
            if (!set.contains(cArr[right])){
            }
            else {
                if (maxNum < cnt) maxNum = cnt;
                while (set.contains(cArr[right])){
                    set.remove(cArr[left]);
                    left++;
                    cnt--;
                }
            }
            set.add(cArr[right]);
            cnt++;
        }
        maxNum = maxNum > cnt ? maxNum : cnt;
        return maxNum;
    }
}