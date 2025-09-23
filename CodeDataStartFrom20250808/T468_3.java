import java.util.*;

class Pair{
    public int cnt;
    public int[] arr;
    public Pair(int cnt, int[] arr) {
        this.cnt = cnt;
        this.arr = arr;
    }
};

public class T468_3 {
    public int minSplitMerge(int[] nums1, int[] nums2) {
        int n = nums1.length;
        Deque<Pair> pq = new ArrayDeque<>();
        Pair init = new Pair(n, nums1);
        pq.offerLast(init);
        while(!pq.isEmpty()) {
            Pair tmp = pq.pollFirst();
            boolean flag = CompareTwoArr(tmp.arr, nums2);
            if(flag) {
                return tmp.cnt;
            }
            for (int i = 0;i < n;i ++) {
                for (int j = i;j < n;j ++) {
                    
                }
            }
        }
    }
    private boolean CompareTwoArr(int[] nums1, int[] nums2){
        int len = nums1.length;
        for (int i = 0;i < len;i ++) {
            if(nums1[i] != nums2[i])
                return false;
        }
        return true;
    }
}
