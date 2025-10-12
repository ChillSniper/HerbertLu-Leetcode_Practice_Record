import java.util.*;

public class T5 {
    public static void main(String[] args) {
        String s = "d";
        T5 t = new T5();
        t.longestPalindrome(s);
    }
    public String longestPalindrome(String s) {
        // abcbabcdaba
        // !#a#b#c#b#a#b#c#d#a#b#a#?
        // 今天一定要把这个算法看懂！
        // 现在大概看懂了，但是距离写出来还是有一定距离的
        // 还有这个对下标的处理也很麻烦
        // 使用Manacha算法
        int n = s.length();
        char[] t = new char[2 * n + 3];
        Arrays.fill(t, '#');
        t[0] = '?';
        for (int i = 0;i < n;i ++) {
            t[i * 2 + 2] = s.charAt(i);
        }
        t[2 * n + 2] = '!';
        int[] halflen = new int[t.length];
        halflen[1] = 1;
        int MaxIndex = 0;
        //
        int BoxMID = 0, BoxR = 0;
        for (int i = 2;i < t.length - 1;i ++) {
            int hl = 1;
            if(i < BoxR) {
                hl = Math.min(halflen[2 * BoxMID - i], BoxR - i);
            }
            while(t[i - hl] == t[i + hl]) {
                ++ hl;
                BoxMID = i;
                BoxR = i + hl;
            }

            halflen[i] = hl;
            if(hl > halflen[MaxIndex])
                MaxIndex = i;
        }
        // [(maxIndex - hafllen + 2) / 2, (maxindex + halflen - 2) / 2 + 1)
        return s.substring((MaxIndex - halflen[MaxIndex]) / 2 + 1, (MaxIndex + halflen[MaxIndex]) / 2);
    }
}
