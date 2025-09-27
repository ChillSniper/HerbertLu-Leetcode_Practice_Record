package miscellaneous_problems;
class Solution {
    public int[] twoSum(int[] numbers, int target) {
        int n = numbers.length, l = 0, r = n - 1;
        for (;l < r;) {
            while(numbers[r] + numbers[l] > target) {
                -- r;
            }
            while(numbers[r] + numbers[l] < target) {
                ++ l;
            }
            if (numbers[r] + numbers[l] == target) {
                break;
            }
        }
        int[] ans = new int[] {l + 1, r + 1};
        return ans;
    }
}