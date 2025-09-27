package miscellaneous_problems;
import java.util.*;

public class Router {

    final private Set<List<Integer>> record;
    final private Map<Integer, List<Integer>> fk;
    final private int LIMIT;
    final private Deque<int[]> dq;

    public Router(int memoryLimit) {
        // 这题还一个难点是数据元素的表示方法
        this.record = new HashSet<>();    
        this.fk = new HashMap<>();
        this.LIMIT = memoryLimit;
        this.dq = new ArrayDeque<>();
    }
    
    public boolean addPacket(int source, int destination, int timestamp) {
        List<Integer> tmp = List.of(source, destination, timestamp);
        if(record.contains(tmp)) 
            return false;
        if(dq.size() == LIMIT) {
            int[] g_out = dq.pollFirst();
            int t_d = g_out[1];
            fk.get(t_d).remove(0);
            record.remove(List.of(g_out[0], g_out[1], g_out[2]));
        }

        record.add(tmp);
        dq.offerLast(new int[]{source, destination, timestamp});
        // fk.put(destination, tmp);
        fk.computeIfAbsent(destination, ArrayList::new).add(timestamp);
        return true;
    }
    
    public int[] forwardPacket() {
        if(dq.isEmpty()) {
            return new int[]{};
        }
        int[] tmp = dq.pollFirst();
        int des = tmp[1];
        List<Integer> ltmp = List.of(tmp[0], tmp[1], tmp[2]);
        record.remove(ltmp);
        fk.get(des).remove(0);
        return tmp;
    }
    
    public int getCount(int destination, int startTime, int endTime) {
        List<Integer> us = fk.get(destination);
        int x = UsingBinarySearch(us, startTime);
        int y = UsingBinarySearch(us, endTime + 1);
        return y - x;
    }

    private int UsingBinarySearch(List<Integer> fuck, int target) {
        int len = fuck.size(), l = 0, r = len - 1;
        if(len == 0) 
            return -1;
        while(l <= r) {
            int mid = (r - l) / 2 + l;
            if(fuck.get(mid) < target) {
                l = mid + 1;
            }
            else {
                r = mid - 1;
            }
        }
        return l;
    }
}

/**
 * Your Router object will be instantiated and called as such:
 * Router obj = new Router(memoryLimit);
 * boolean param_1 = obj.addPacket(source,destination,timestamp);
 * int[] param_2 = obj.forwardPacket();
 * int param_3 = obj.getCount(destination,startTime,endTime);
 */
