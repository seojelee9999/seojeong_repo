import java.util.HashSet;


public class Main

class Solution1 {
    public int lengthOfLongestSubstring(String s) {
        String part=""; int max=0;
        int l=0,r=0;
        int count=0;
        HashSet<Character> charSet= new HashSet<>();
        while(l<s.length()){
            count=0;
            //charSet.add(s.charAt(l));
            while(count==charSet.size() && r<s.length()){
                charSet.add(s.charAt(r));
                r++;
                count++;
            }
            max=Math.max(max,charSet.size());
            charSet.clear();
            r=l;
            l++;

        }
        return max;
    }
}