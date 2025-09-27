package problems_set;
import java.util.*;
class Spreadsheet {

    Map<String, Integer> record = new HashMap<>();

    public Spreadsheet(int rows) {
    }
    
    public void setCell(String cell, int value) {
        record.put(cell, value);
    }
    
    public void resetCell(String cell) {
        record.remove(cell);
    }
    
    public int getValue(String formula) {
        int ans = 0;
        for (String fk : formula.substring(1).split("\\+")) {
            if(Character.isUpperCase(fk.charAt(0))) {
                ans += record.getOrDefault(fk, 0);
            } else {
                ans += Integer.parseInt(fk);
            }
        }
        return ans;
    }
}

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet obj = new Spreadsheet(rows);
 * obj.setCell(cell,value);
 * obj.resetCell(cell);
 * int param_3 = obj.getValue(formula);
 */