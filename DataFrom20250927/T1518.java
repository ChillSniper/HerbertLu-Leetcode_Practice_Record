public class T1518 {
    public int numWaterBottles(int numBottles, int numExchange) {
        int ans = 0, empty_ = 0, full_= numBottles;
        while(empty_ >= numExchange || full_ > 0) {
            ans += full_;
            empty_ += full_;
            full_ = empty_ / numExchange;
            empty_ %= numExchange;
        }
        return ans;
    }
}
