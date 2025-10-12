public class T289 {
    public void gameOfLife(int[][] board) {
        // 这道题如果另外开一个数组是可以很方便的搞掉的，但是问题在于怎么原地操作
        int m = board.length, n = board[0].length;
        final int DEAD = 1000, LIVE = 2000;
        // 1001
        for (int i = 0;i < m;i ++) {
            for (int j = 0;j < n;j ++) {
                int val = GetLiveNum(board, i, j);
                if(board[i][j] % 10 == 1 && (val < 2 || val > 3)) {
                    board[i][j] += DEAD;
                }
                else if(board[i][j] % 10 == 1 && (val >= 2 && val <= 3)) {
                    board[i][j] += LIVE;
                }
                else if(val == 3) {
                    board[i][j] += LIVE;
                }
                else {
                    board[i][j] += DEAD;
                }
            }
        }
        for (int i = 0;i < m;i ++) {
            for (int j = 0;j < n;j ++) {
                if(board[i][j] / 1000 == 1) {
                    board[i][j] = 0;
                }
                else {
                    board[i][j] = 1;
                }
            }
        }
    }
    static final int dir[][] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1}};
    static final int DIRECTION_NUM = 8;
    private int GetLiveNum(int[][] board, int x, int y) {
        int m = board.length, n = board[0].length, cnt = 0;
        for (int i = 0;i < DIRECTION_NUM;i ++) {
            int n_x = x + dir[i][0];
            int n_y = y + dir[i][1];
            if(n_x >= 0 && n_x < m && n_y >= 0 && n_y < n && board[n_x][n_y] % 10 == 1) {
                ++ cnt;
            }
        }
        return cnt;
    }
}
