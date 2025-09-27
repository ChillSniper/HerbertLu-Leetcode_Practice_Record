package problems_set;

import java.util.ArrayList;
import java.util.List;

public class T165 {
    public int compareVersion(String version1, String version2) {
        List<Integer> v1 = new ArrayList<>(), v2 = new ArrayList<>();
        GetArr(v1, version1);
        GetArr(v2, version2);
        int len_1 = v1.size(), len_2 = v2.size();
        while(len_1 < len_2) {
            v1.add(0);
            ++ len_1;
        }
        while(len_2 < len_1) {
            v2.add(0);
            ++ len_2;
        }
        for (int i = 0;i < len_1;i ++) {
            if(v1.get(i) < v2.get(i))
                return -1;
            if(v1.get(i) > v2.get(i))
                return 1;
        }
        return 0;
    }
    private void GetArr(List<Integer> v1, String version1) {
        int cur_val = 0, len = version1.length();
        for (int i = 0;i < len;i ++) {
            char ch = version1.charAt(i);
            if(ch == '.') {
                continue;
            }
            int j = i;
            while(j < len && version1.charAt(j) != '.') {
                int val = version1.charAt(j) - '0';
                cur_val = cur_val * 10 + val;
            }
            i = j - 1;
            v1.add(cur_val);
            cur_val = 0;
        }
        
    }
}
