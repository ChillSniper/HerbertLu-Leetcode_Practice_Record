import java.util.*;

public class T1733{
    public int minimumTeachings(int n, int[][] languages, int[][] friendships) {
        int m = languages.length;
        boolean[][] flag = new boolean[m + 1][n + 1];
        for (int i = 0;i < m;i ++) {
            int user = i + 1;
            for (int j : languages[i]) {
                flag[user][j] = true;
            }
        }
        List<int[]> record = new ArrayList<>();

        for (int[] item : friendships) {
            int u = item[0], v = item[1];
            boolean know = false;
            for (int lan : languages[u - 1]) {
                if(flag[v][lan] == true) {
                    know = true;
                    break;
                }
            }
            if(know == false) {
                int[] fk = new int[2];
                fk[0] = u;
                fk[1] = v;
                record.add(fk);
            }
        }

        int ans = m;
        for (int i = 1;i <= n;i ++) {
            HashSet<Integer> st = new HashSet<>();
            for (int[] item : record) {
                int u = item[0], v = item[1];
                if(flag[u][i] == false) {
                    st.add(u);
                }
                if(flag[v][i] == false) {
                    st.add(v);
                }
            }
            ans = Math.min(ans, st.size());
        }

        return ans;
    }
}