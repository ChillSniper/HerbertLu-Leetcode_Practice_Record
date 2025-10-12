import java.util.*;

class ExamTracker {

    List<int[]> record;
    List<Long> Pre;
    public ExamTracker() {
        record = new ArrayList<>();
        Pre = new ArrayList<>();
        Pre.add((long)0);
    }
    
    public void record(int time, int score) {
        
        int n = Pre.size();
        Long val = Pre.get(n - 1);
        Pre.add(val + score);
        record.add(new int[]{time, score});
    }
    
    public long totalScore(int startTime, int endTime) {
        int lf = lower_bound(startTime), ri = lower_bound(endTime + 1), n = record.size();
        if(lf >= n || ri - 1 < lf)
            return 0;
        long ans = Pre.get(ri - 1 + 1) - Pre.get(lf + 1 - 1);
        return ans;
    }
    private int lower_bound(int val) {
        int n = record.size(), i = 0, j = n - 1;
        while(i <= j) {
            int mid = (i + j) >> 1;
            if(record.get(mid)[0] < val) {
                i = mid + 1;
            }
            else {
                j = mid - 1;
            }
        }
        return i;
    }
}