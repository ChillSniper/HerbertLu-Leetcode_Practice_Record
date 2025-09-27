package miscellaneous_problems;

// public class T812 {
//     public double largestTriangleArea(int[][] points) {
//         int n = points.length;
//         double ans = 0;
//         for (int i = 0;i < n;i ++) {
//             for (int j = i + 1;j < n;j ++) {
//                 for (int k = j + 1;k < n;k ++) {
//                     double a = Math.sqrt(Math.pow(points[i][0] - points[j][0], 2) + Math.pow(points[i][1] - points[j][1], 2));
//                     double b = Math.sqrt(Math.pow(points[i][0] - points[k][0], 2) + Math.pow(points[i][1] - points[k][1], 2));
//                     double c = Math.sqrt(Math.pow(points[j][0] - points[k][0], 2) + Math.pow(points[j][1] - points[k][1], 2));
//                     double area = GetArea(a, b, c);
//                     ans = Math.max(area, ans);
//                 }
//             }
//         }
//         return ans;
//     }
//     private double GetArea(double a, double b, double c) {
//         if(a + b <= c || a + c <= b || b + c <= a)
//             return 0;
//         double p = (a + b + c) / 2;
//         return Math.sqrt(p * (p - a) * (p - b) * (p - c));
//     }
// }

// 原来有可以不用海伦公式的办法，那样计算的话会快一点
// 怎么把向量计算给忘了。。。

public class T812 {
    public double largestTriangleArea(int[][] points) {
        double ans = 0;
        int n = points.length;
        for (int i = 0;i < n;i ++) {
            for (int j = i + 1;j < n;j ++) {
                for (int k = j + 1;k < n;k ++) {
                    double x1 = points[j][0] - points[i][0], y1 = points[j][1] - points[i][1];
                    double x2 = points[k][0] - points[i][0], y2 = points[k][1] - points[i][1];
                    ans = Math.max(ans, Math.abs(x1 * y2 - x2 * y1) * 0.5);
                }
            }
        }
        return ans;
    }
}