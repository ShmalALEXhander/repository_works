public class Main {
    public static void main(String[] args) {
        PairBag c =new PairBag(5);

        Pair<String,Integer> c1 = new Pair<>("dfsdf",123);
        Pair<Integer,Integer> c2 = new Pair<>(123,123);
        c.Push(c1);
        c.Push(c2);
        c.Show(); //вывод именно объект

        PairBag c = new PairBag(5);
        Pair<String,Integer> c1 = new Pair<>("sdf", 12)
    }
}