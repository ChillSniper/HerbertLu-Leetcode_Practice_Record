package miscellaneous_problems;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class T49 {
    public List<List<String>> groupAnagrams(String[] strs) {
        List<List<String>> ans = new ArrayList<>();
        Map<String, List<String>> record = new HashMap<>();
        for (String s : strs) {
            char[] fk = s.toCharArray();
            Arrays.sort(fk);
            String sorted = new String(fk);
            record.computeIfAbsent(sorted, _ -> new ArrayList<>()).add(s);
        }

        for (Map.Entry<String, List<String>> mp : record.entrySet()) {
            ans.add(mp.getValue());
        }
        return ans;
    }
}
