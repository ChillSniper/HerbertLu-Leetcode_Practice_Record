// import java.util.ArrayDeque;
// import java.util.TreeMap;

// public class MinStack {
//     public TreeMap<Integer, Integer> record;
//     public ArrayDeque<Integer> q;
//     public MinStack() {
//         record = new TreeMap<>();
//         q = new ArrayDeque<>();
//     }

//     public void push(int val) {
//         q.addLast(val);
//         record.merge(val, 1, Integer::sum);
//     }
    
//     public void pop() {
//         int val = q.pollLast();
//         record.merge(val, -1, Integer::sum);
//         if(record.get(val) == 0)
//             record.remove(val);
//     }
    
//     public int top() {
//         int val = q.getLast();
//         return val;
//     }
    
//     public int getMin() {
//         return record.firstKey();
//     }
// }

import java.util.ArrayDeque;
import java.util.Deque;

class MinStack {

    final private Deque<int[]> re;
    public MinStack() {
        re = new ArrayDeque<>();
        re.add(new int[]{0, Integer.MAX_VALUE});
    }
    
    public void push(int val) {
        int[] lst = re.getLast();
        re.add(new int[]{val, Math.min(lst[1], val)});
    }
    
    public void pop() {
        re.pollLast();
    }
    
    public int top() {
        return re.getLast()[0];
    }
    
    public int getMin() {
        return re.getLast()[1];
    }
}
