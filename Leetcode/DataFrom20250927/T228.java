import java.util.ArrayList;
import java.util.List;

public class T228 {
    public List<String> summaryRanges(int[] nums) {
        List<String> ans = new ArrayList<>();
        int n = nums.length;
        int st = nums[0], fin = nums[0];
        for (int i = 1;i < n;i ++) {
            if(nums[i] == nums[i - 1] + 1) {
                fin = nums[i];
            }
            else {
                AddOp(ans, st, fin);
                st = nums[i];
                fin = nums[i];
            }
        }
        AddOp(ans, st, fin);
        return ans;
    }
    public void AddOp(List<String> ans, int st, int fin) {
        StringBuilder t = new StringBuilder();
        if(st != fin) {
            t.append(st).append("->").append(fin);
        } else {
            t.append(st);
        }
        ans.add(t.toString());
    }
}
