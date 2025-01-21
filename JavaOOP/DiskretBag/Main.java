import java.util.*;

public class Main {
    public static void main(String[] args) {

        var scanner = new Scanner(System.in);
        System.out.println("enter max weight");
        String s;
        try {
             s = scanner.nextLine();

        finally{
            System.out.println("enter amount of items");
        }
        var maxWeight = Integer.parseInt(s);
        System.out.println("enter amount of items");
        s = scanner.nextLine();
        var allItemsCount =  Integer.parseInt(s);
        var items = new int[allItemsCount];
        for (int i = 0; i < allItemsCount; i++) {
            System.out.println("enter weight " + i);
            s = scanner.nextLine();
            var w =  Integer.parseInt(s);
            items[i] = w;
        }
        var r = selectMaxWeight(maxWeight, items);
//        System.out.println(r + " " + r.stream().mapToInt(Integer::intValue).sum());
        System.out.println("items: " + r);
    }

    private static List<Integer> selectMaxWeight(int maxWeight, int[] weights) {
        var f = new boolean[maxWeight + 1];
        var items = new ArrayList<List<Integer>>(maxWeight + 1);
        for (int i = 0; i < maxWeight + 1; i++) {
            items.add( new ArrayList<>());
        }
        f[0] = true;
        for (int i = 0; i < weights.length; i++) {
            var tmp = Arrays.copyOf(f, f.length);
            for (int w = weights[i]; w <= maxWeight; w++) {
                if (!tmp[w] && f[w - weights[i]]){
                    tmp[w] = true;
                    items.get(w).addAll(items.get(w - weights[i]));
                    items.get(w).add(weights[i]);
                }
            }
            f = tmp;
        }

        for (int i = maxWeight; i > 0; i--) {
            if (f[i]){
                return items.get(i);
            }
        }

        return new ArrayList<>();
    }
}
