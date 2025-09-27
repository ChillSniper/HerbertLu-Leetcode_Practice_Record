package problems_set;
import java.util.HashMap;
import java.util.Map;

public class T166 {
    public String fractionToDecimal(int numerator, int denominator) {
        // 问题来了，我怎么判断有没有循环节？
        // 具体的运算是用那个除法，就是纯粹的列竖式计算
        // 所以循环节怎么找呢
        // 对啊，循环节怎么找呢。。。
        // 而且其实还有一个问题，如果我除了一个负数怎么办？
        // 任意举出几个例子
        
        // + / + : 3 / 5 = 0.6
        // - / - : -3 / -8 这个转化为正数去做
        // - / + or + / -: -3 / 8 这种也是转化为正数, 最后结果前面加个-
        // nmd原来是这个意思，如果余数又出现了一次的话，说明循环节出现！
        StringBuilder fk = new StringBuilder();
        long x, y;
        x = numerator > 0 ? numerator : -(long)numerator;
        y = denominator > 0 ? denominator : -(long)denominator;
        String signal = (long)numerator * (long)denominator < 0 ? "-" : "";
        long p = x / y, lf = x % y;
        if(lf == 0) {
            return fk.append(signal).append(p).toString();
        }
        fk.append(signal).append(p).append(".");
        Map<Long, Integer> record = new HashMap<>();
        StringBuilder store = new StringBuilder();
        lf *= 10;
        int i = 0;
        while(true) {
            if(record.containsKey(lf)) {
                int index = record.get(lf);
                fk.append(store.substring(0, index)).append("(").append(store.substring(index)).append(")");
                break;
            }
            record.put(lf, i++);
            store.append(lf / y);
            lf %= y;
            lf *= 10;
            if(lf == 0) {
                fk.append(store);
                break;
            }
        }
        return fk.toString();
    }
}
