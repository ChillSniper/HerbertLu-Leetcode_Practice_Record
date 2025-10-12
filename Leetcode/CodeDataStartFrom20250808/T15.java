import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.List;



public class T15 {
    public static void main(String[] args) {
        int[] nums = new int[] {0, 0, 0, 0};
        T15 obj = new T15();
        List<List<Integer>> ans = obj.threeSum(nums);
        for (List<Integer> item : ans) {
            System.out.println(item);
        }
    }

    public List<List<Integer>> threeSum(int[] nums) {
        // 问题在于要不重复
        List<List<Integer>> ans = new ArrayList<>();
        Arrays.sort(nums);
        int n = nums.length, first_last_val = (int)-1e6;
        HashMap<Integer, Integer> record = new HashMap<>();

        for (int item : nums) {
            record.put(item, record.getOrDefault(item, 0) + 1);
        }

        for (int i = 0;i < n;i ++) {
            int a = nums[i];
            if(a == first_last_val) {
                continue;
            }
            first_last_val = a;
            int second_last_val = (int)-1e6;
            for (int j = i + 1;j < n - 1;j ++) {
                int b = nums[j];

                if(b == second_last_val) {
                    continue;
                }

                second_last_val = b;
                
                int target = -(a + b);
                if(target < b || b < a) {
                    continue;
                }
                if((target != b && record.containsKey(target)) 
                || (target == b && target != a && record.getOrDefault(b, 0) >= 2) 
                || (target == a && record.getOrDefault(b, 0) >= 3)) {
                    ans.add(Arrays.asList(a, b, target));
                }
            }
            
        }        
        return ans;
    }
}
