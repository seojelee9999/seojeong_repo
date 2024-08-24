import java.util.*;
import java.io.*;

public class Main{
    public static void main(String[] args) throws IOException {
        Solution solution = new Solution();
        testSolution(solution, new int[]{2, 6, 11, 15}, 9, new int[]{0, 1});
        testSolution(solution, new int[]{3, 2, 4}, 6, new int[]{1, 2});
        testSolution(solution, new int[]{3, 3}, 6, new int[]{0, 1});
    }
    private static void  testSolution(Solution solution, int[] nums, int target, int expected[]){
        if (Arrays.equals(solution.twoSum(nums, target), expected)) System.out.println("success");
        else System.out.println("fail");
    }
}

class Solution{

    public int []twoSum(int []nums, int target){
        int n = nums.length;
        Map<Integer, Integer> numMap = new HashMap<>();

        for (int i = 0; i < n ; i ++) numMap.put(nums[i],i);
        for (int i = 0 ; i <n ; i++){
            int complement = target - nums[i];
            if (numMap.containsKey(complement) && numMap.get(complement) != i){
                return new int[]{i, numMap.get(complement)};
            }
        }
        return new int[]{};
    }
}