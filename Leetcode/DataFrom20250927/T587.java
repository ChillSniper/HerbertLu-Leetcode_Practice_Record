import java.util.*;

public class T587 {
    public int[][] outerTrees(int[][] trees) {
        // 这傻软题的意思就是把整片森林包围起来
        // 然后别整出折线来
        // 为什么我看不懂这个题解
        // 这个题的做法实际上是一个构造二维凸包的过程
        Arrays.sort(trees, (a, b) -> {
            return a[0] != b[0] ? a[0] - b[0] : a[1] - b[1];    
        });
        int n = trees.length, tp = 0;
        int[] MyStack = new int[n + 10];
        boolean[] vis = new boolean[n + 10];
        MyStack[++ tp] = 0;
        for (int i = 1;i < n;i ++) {
            int[] c = trees[i];
            while(tp >= 2) {
                int[] b = trees[MyStack[tp]], a = trees[MyStack[tp - 1]];
                int area = ComputeArea(a, b, c);
                if(area >= 0) {
                    break;
                }
                vis[MyStack[tp]] = false;
                -- tp;

            }
            MyStack[++ tp] = i;
            vis[i] = true;
        }
        int m = tp;
        for (int i = n - 1;i >= 0;i --) {
            if(vis[i])  
                continue;
            int[] c = trees[i];
            while(tp > m) {
                int[] b = trees[MyStack[tp]], a = trees[MyStack[tp - 1]];
                int area = ComputeArea(a, b, c);
                if(area >= 0) {
                    break;
                }
                vis[MyStack[tp]] = false;
                -- tp;

            }
            MyStack[++ tp] = i;
            vis[i] = true;
        }
        int[][] ans = new int[tp - 1][2];
        for (int i = 0;i < tp - 1;i ++) {
            ans[i] = trees[MyStack[i + 1]];
        }
        return ans;
    }
    private int[] computeVector(int[] a, int[] b) {
        int[] ans = new int[2];
        ans[0] = a[0] - b[0];
        ans[1] = a[1] - b[1];
        return ans;
    }
    private int ComputeArea(int[] a, int[] b, int[] c) {
        int[] x = computeVector(a, b);
        int[] y = computeVector(a, c);
        return x[0] * y[1] - x[1] * y[0];
    }

}
