import java.util.*;
public class T966 {
    public String[] spellchecker(String[] wordlist, String[] queries) {
        int len = queries.length, n = wordlist.length;
        String[] ans = new String[len];
        // 等晚上再写吧，现在不是很想写这个
        Set<String> fka = new HashSet<>(Arrays.asList(wordlist));
        Map<String, String> fkb = new HashMap<>(n);
        Map<String, String> fkc = new HashMap<>(n);
        for (int i = n - 1;i >= 0;i --) {
            String cur = wordlist[i];
            String toLower = cur.toLowerCase();
            fkb.put(toLower, cur);
            fkc.put(getFuckString(toLower), cur);
        }
        for (Map.Entry<String, String> fk: fkc.entrySet()) {
            System.out.println(fk.getKey() + ":" + fk.getValue());
        }
        
        for (int i = 0;i < len;i ++) {
            String q = queries[i];
            if(fka.contains(q)) {
                ans[i] = q;
                continue;
            }
            if(fkb.containsKey(q.toLowerCase())) {
                ans[i] = fkb.get(q.toLowerCase());
                continue;
            }
            ans[i] = fkc.getOrDefault(getFuckString(q.toLowerCase()), "");
        }
        return ans;   
    }
    private String getFuckString(String str) {
        char[] fk = str.toCharArray();
        int len = fk.length;
        for (int i = 0;i < len;i ++) {
            if(fk[i] == 'a' || fk[i] == 'e' || fk[i] == 'i' || fk[i] == 'o' || fk[i] == 'u') {
                fk[i] = '?';
            }
        }
        return new String(fk);
    }
}