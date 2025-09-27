package miscellaneous_problems;
public class T1094 {
    public boolean carPooling(int[][] trips, int capacity) {
        int n = trips.length;
        final int N = 1010;
        int record[] = new int[N];
        for (int i = 0;i < n;i ++) {
            int np = trips[i][0], f = trips[i][1], t = trips[i][2];
            record[f] += np;
            record[t] -= np;
            if(record[f] > capacity) 
                return false;
        }
        for (int i = 1;i < N;i ++) {
            record[i] += record[i - 1];
            if (record[i] > capacity) 
                return false;
        }
        return true;
    }
}