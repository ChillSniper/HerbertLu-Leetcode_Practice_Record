import java.util.*;
class MovieRentingSystem {

    private Map<Integer, TreeSet<int[]>> unrented;
    final private Set<int[]> rented;
    final private Map<Long, Integer> table;

    public MovieRentingSystem(int n, int[][] entries) {
        // 这个题不太好搞，主要是题目太复杂了
        // 这种破题实际上是围绕map和set展开，这样方便对容器的操作
        // 但是麻烦的是题目实在是太长了，所以要搞清楚键和值之间的对应关系，不然会非常晕
        // movie -> (price, shop); // it's unrented
        // (price, shop, movie); // it's rented
        // (shop, movie) -> price
        this.unrented = new HashMap<>();
        this.rented = new TreeSet<>(
            (a, b) -> {
                if(a[0] != b[0])
                    return a[0] - b[0];
                if(a[1] != b[1])
                    return a[1] - b[1];
                return a[2] - b[2];
            }
        );
        this.table = new HashMap<>();
            
        for (int[] e : entries) {
            int shop = e[0], movie = e[1], price = e[2];
            table.put((long)shop << 32 | movie, price);
            unrented.computeIfAbsent(movie, k -> new TreeSet<>(
                (a, b) -> {
                    if(a[0] != b[0])
                        return a[0] - b[0];
                    return a[1] - b[1];
                }
            )).add(new int[] {price, shop});
        }
    }
    
    public List<Integer> search(int movie) {
        if(!unrented.containsKey(movie)) {
            return List.of();
        }
        List<Integer> ans = new ArrayList<>(5);
        for (int[] k : unrented.get(movie)) {
            ans.add(k[1]);
            if(ans.size() == 5)
                break;
        }
        return ans;
    }
    
    public void rent(int shop, int movie) {
        int price = table.get((long)shop << 32 | movie);
        unrented.get(movie).remove(new int[]{price, shop});
        rented.add(new int[]{price, shop, movie});
    }
    
    public void drop(int shop, int movie) {
        int price = table.get((long)shop << 32 | movie);
        rented.remove(new int[]{price, shop, movie});
        unrented.get(movie).add(new int[]{price, shop});
    }
    
    public List<List<Integer>> report() {
        List<List<Integer>> ans = new ArrayList<>(5);
        for (int[] e : rented) {
            ans.add(List.of(e[1], e[2]));
            if(ans.size() == 5)
                break;
        }
        return ans;
    }
}

/**
 * Your MovieRentingSystem object will be instantiated and called as such:
 * MovieRentingSystem obj = new MovieRentingSystem(n, entries);
 * List<Integer> param_1 = obj.search(movie);
 * obj.rent(shop,movie);
 * obj.drop(shop,movie);
 * List<List<Integer>> param_4 = obj.report();
 */