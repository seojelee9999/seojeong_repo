import java.util.*;
import java.io.*;

public class Main{
    public static void main(String[] args) throws IOException {

    }
}


//Definition for singly-linked list.
class ListNode {
    int val;
    ListNode next;

    ListNode() {
    }

    ListNode(int val) {
        this.val = val;
    }

    ListNode(int val, ListNode next) {
        this.val = val;
        this.next = next;
    }
}
class Solution {
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        ListNode ans = null;
        ListNode tmp = null;
        int carry = 0;
        int sum = 0;
        while (l1 != null || l2 != null){
            sum = 0;
            if (carry == 1) {
                sum += 1;
                carry = 0;
            }
            if (l1 != null){
                sum += l1.val;
                l1 = l1.next;
            }
            if (l2 != null){
                sum += l2.val;
                l2 = l2.next;
            }
            if (sum >= 10){
                carry = 1;
                sum -= 10;
            }
            if (ans == null){
                ans = new ListNode(sum);
                tmp = ans;
            }
            else{
                tmp.next = new ListNode(sum);
                tmp = tmp.next;
            }

        }
        if (carry == 1){tmp.next = new ListNode(1);}
        return ans;
    }
}