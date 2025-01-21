public class Main {
    public static void main(String[] args) {
        Pair<Integer,Integer>p1=new Pair<>(5, 3); // int double float - простые типы, Integer Double Float - ссылочные типы
        // передаются ссылки на 5 и 3, адрес ячейки передаётся
        int x = p1.getX();
        int y = p1.getY();
        System.out.println(x);
        System.out.println(y);
        Pair<String,Double>p2=new Pair<>("324",2.7);
        String x1 = p2.getX();
        double y1 = p2.getY();
        System.out.println(x1);
        System.out.println(y1);
        Pair<String,String>p3=new Pair<>("324","213");
        System.out.println(p3.getX());

        Pair<Object,Object>p4=new Pair<>(123,"213");
        System.out.println(p4.getX()); // Какие ограничения нужны ?
        Object x2 = p4.getX();      //огранеичени не нужны
        p4.setX("ыав");
        System.out.println(p4.getX());
        Pair<Object, Object> p5=Pair.make_pair("3224",213);
        p5.setX("ыав");
        Pair<Object, Object> p6=Pair.make_pair("435435",1);
        Pair<Integer,Integer>p1=new Pair<>(5,3);
    }
}