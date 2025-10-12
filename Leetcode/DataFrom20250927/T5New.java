import java.util.*;

public class T5New {
    public String longestPalindrome(String s) {
        int n = s.length();
        char[] ch = new char[2 * n + 3];
        Arrays.fill(ch, '#');
        ch[0] = '?'; ch[2 * n + 2] = '!';
        for (int i = 0;i < n;i ++) {
            ch[2 * i + 2] = s.charAt(i);
        }
        // 然后我tmd就忘了，好像是一个什么半长度来着
        // 忘了。。。复习一下
        // 还有，那个对称位置怎么计算的来着
        int[] halfLen = new int[ch.length - 2];
        halfLen[1] = 1;
        int MaxI = 0;
        int BoxMid = 0;
        int BoxR = 0;
        for (int i = 2;i < halfLen.length;i ++) {
            int hl = 1;
            if(i < BoxR) {
                hl = Math.min(halfLen[2 * BoxMid - i], BoxR - i);
            }
            while(ch[i + hl] == ch[i - hl]) {
                ++ hl;
            }
            if(i + hl > BoxR) {
                BoxMid = i;
                BoxR = i + hl;
            }
            halfLen[i] = hl;
            if(hl > halfLen[MaxI]) {
                MaxI = i;
            }
        }
        StringBuilder fk = new StringBuilder();
        for (int i = MaxI - halfLen[MaxI] + 1;i < MaxI + halfLen[MaxI];i ++) {
            if(ch[i] != '#' && ch[i] != '?' && ch[i] != '!') {
                fk.append(ch[i]);
            }
        }
        return fk.toString();
    }
}
