import java.util.HashSet;

public class T36 {
    public boolean isValidSudoku(char[][] board) {
        HashSet<Character> record = new HashSet<>();
        for (int i = 0;i < SZ;i ++) {
            record.clear();
            for (int j = 0;j < SZ;j ++) {
                char ch = board[i][j];
                if (record.contains(ch) == false) {
                    record.add(ch);
                }
                else {
                    return false;
                }
            }
        }
        for (int i = 0;i < SZ;i ++) {
            record.clear();
            for (int j = 0;j < SZ;j ++) {
                char ch = board[j][i];
                if (record.contains(ch) == false) {
                    record.add(ch);
                }
                else {
                    return false;
                }
            }
        }

        for (int i = 0;i < SZ;i += 3) {
            for (int j = 0;j < SZ;j += 3) {
                record.clear();
                for (int st_i = i;st_i < i + 3;++ st_i) {
                    for (int st_j = j;st_j < j + 3;++ st_j) {
                        char ch = board[st_i][st_j];
                        if (record.contains(ch) == false) {
                            record.add(ch);
                        }
                        else {
                            return false;
                        }
                    }
                }
            }
        }
        return true;
    }
    private final int SZ = 9;
}
