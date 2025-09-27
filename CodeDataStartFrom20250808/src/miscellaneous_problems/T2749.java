package problems_set;
public class T2749 {
    public int makeTheIntegerZero(int num1, int num2) {
        // 涉及到位运算的题
        // 实际上是要将思路理理清楚
        // target: let num1 - k * num2 = 0
        // we set x = num1 - k * num2
        // if (k >= lowbit(...))
        //  then return k
        // when k <= ... continue
        for (int k = 1;k <= num1 - k * num2;k ++) {
            if(k >= Long.bitCount((long)(num1 - k * num2))) {
                return k;
            }
        }
        return -1;
    }
}
