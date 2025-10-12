public class T167_1 {
    public boolean scoreBalance(String s) {
        int n = s.length();
        for (int i = 0;i + 1 < n;i ++) {
            int x = 0, y = 0;
            for (int j = 0;j <= i;j ++) 
                x += (s.charAt(j) - 'a' + 1);
            for (int j = i + 1;j < n;j ++)
                y += (s.charAt(j) - 'a' + 1);
            if(x == y)
                return true;
        }   
        return false;
    }
}
