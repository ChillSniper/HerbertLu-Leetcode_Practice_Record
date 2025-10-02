
import java.util.HashMap;
import java.util.Map;
import java.util.TreeSet;

public class NumberContainers {
    public NumberContainers() {
        // HashSet + TreeMap
        // 就是这个写法实在是太繁琐了
    }
    Map<Integer, Integer> Index_to_Num = new HashMap<>();
    Map<Integer, TreeSet<Integer>> Lowerset_Index = new HashMap<>();
    public void change(int index, int number) {
        int ori_val = -1;
        if(Index_to_Num.containsKey(index)) {
            ori_val = Index_to_Num.get(index);
        }
        Index_to_Num.put(index, number);
        
        if(ori_val == -1) {
        }
        else {
            Lowerset_Index.get(ori_val).remove(index);            
        }
        if(Lowerset_Index.containsKey(number)) {
        }
        else {
            Lowerset_Index.put(number, new TreeSet<>());
        }
        Lowerset_Index.get(number).add(index);
    }
    
    public int find(int number) {
        if((!Lowerset_Index.containsKey(number)) || Lowerset_Index.get(number).isEmpty())
            return -1;
        return Lowerset_Index.get(number).first();
    }
}
