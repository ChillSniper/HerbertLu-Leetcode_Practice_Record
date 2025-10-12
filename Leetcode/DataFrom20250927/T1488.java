import java.util.*;

public class T1488 {
    public int[] avoidFlood(int[] rains) {
        // 有思路，但是思路非常混乱
        // 不可行，rains[i] 达到了1e9
        // 那怎么解决呢？
        // 新学到一个知识点：有序集合
        int n = rains.length;   
        int[] ans = new int[n];
        // 这题还真挺难的，问题在于各个Function之间的映射关系
        Map<Integer, Integer> record = new HashMap<>();
        TreeSet<Integer> coll = new TreeSet<>();
        for (int i = 0;i < n;i ++) {
            int lake = rains[i];
            if(lake == 0) {
                coll.add(i);
                ans[i] = 1; // ...
                continue;
            }
            if(!record.containsKey(lake)) {
                // record.put(lake, i);
            } else {
                int j = record.get(lake);
                Integer target = coll.higher(j);
                if(target == null) {
                    return new int[]{};
                }
                ans[target] = lake;
                coll.remove(target);
            }
            record.put(lake, i);
            ans[i] = -1;
        }
        return ans;
    }
}
