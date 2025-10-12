import java.util.Arrays;
import java.util.HashSet;
import java.util.List;
import java.util.Set;

public class T139 {
    public boolean wordBreak(String s, List<String> wordDict) {
        // 这题有点那个递归嵌套的意思在，但是想不明白
        // 原来是直接处理字符串s，然后从后往前遍历，并加上记忆化搜索
        // 但是如果用dp该怎么做呢
        int n = s.length();
        Set<String> record = new HashSet<>();
        int MaxLen = 1;
        for (String item : wordDict) {
            record.add(item);
            MaxLen = Math.max(MaxLen, item.length());
        }
        int[] memo = new int[n + 1];
        Arrays.fill(memo, -1);
        return Dfs(n, MaxLen, record, memo, s);
    }
    public boolean Dfs(int i, int MaxLen, Set<String> record, int[] memo, String s) {
        if(memo[i] != -1)
            return memo[i] == 1;
        if(i == 0) {
            return true;
        }
        for (int j = 1;j <= MaxLen;j ++) {
            int index = i - j;
            if(index < 0)
                break;
            boolean flag = Dfs(index, MaxLen, record, memo, s) && record.contains(s.substring(index, i));
            if(flag) {
                memo[i] = flag ? 1 : 0;
                return flag;
            }
        }
        memo[i] = 0;
        return false;
    }
}
