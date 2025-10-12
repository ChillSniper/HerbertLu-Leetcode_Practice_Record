public class T3100 {
    public int maxBottlesDrunk(int numBottles, int numExchange) {
        int ans = 0, _full = numBottles, _empty = 0;
        while (_full > 0 || _empty >= numExchange) { 
            if(_full > 0) {
                ans += _full;
                _empty += _full;
                _full = 0;
            }
            if(_empty >= numExchange) {
                _full += 1;
                _empty -= numExchange;
                ++ numExchange;
            }
        }
        return ans;
    }
}
