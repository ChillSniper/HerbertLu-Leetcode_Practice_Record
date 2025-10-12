import java.util.ArrayDeque;
import java.util.Deque;

public class T150 {
    public int evalRPN(String[] tokens) {
        int n = tokens.length;
        Deque<Integer> dq = new ArrayDeque<>();
        
        for (int i = 0;i < n;i ++) {
            String tmp = tokens[i];
            if(tmp.equals("+") || tmp.equals("-") || tmp.equals("*") || tmp.equals("/")) {
                int b = dq.pollLast();
                int a = dq.pollLast();
                switch (tmp) {
                    case "+"->
                        dq.add(a + b);
                    case "-"->
                        dq.add(a - b);
                    case "*"->
                        dq.add(a * b);
                    case "/"->
                        dq.add(a / b);
                    default->
                        throw new AssertionError();
                }
            }
            else {
                dq.addLast(Integer.parseInt(tmp));
            }
        }
        return dq.getLast();
    }
}
