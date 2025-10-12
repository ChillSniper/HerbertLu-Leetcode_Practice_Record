public class T3516 {
    public int findClosest(int x, int y, int z) {
        int disx = Math.abs(x - z), disy = Math.abs(y - z);
        return disx < disy ? 1 : disx == disy ? 0 : 2;   
    }
}
