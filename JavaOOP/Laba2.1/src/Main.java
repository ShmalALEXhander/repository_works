public class Main {
    public static void main(String args[])
    {
        System.out.println(
                "№\tData Type\tSize\t  Min. Value\t   Max. Value\t");
        System.out.println("1\t  Byte\t\t " + Byte.SIZE
                + "\t\t   " + Byte.MIN_VALUE
                + "\t\t\t\t" + Byte.MAX_VALUE);
        System.out.println("2\t  Bool\t\t " + 16
                + "\t\t    " + 0
                + "\t\t\t\t" + 1);
        System.out.println("3\t  Short\t\t " + Short.SIZE
                + "\t\t   " + Short.MIN_VALUE
                + "\t\t\t" + Short.MAX_VALUE);
        System.out.println("4\t  Integer\t " + Integer.SIZE
                + "\t\t   " + Integer.MIN_VALUE
                + "\t\t" + Integer.MAX_VALUE);
        System.out.println("5\t  Float\t\t " + Float.SIZE
                + "\t\t\t" + Float.MIN_VALUE
                + "\t\t\t" + Float.MAX_VALUE);
        System.out.println("6\t  Long\t\t " + Long.SIZE
                + "\t  " + Long.MIN_VALUE + "\t"
                + Long.MAX_VALUE);
        System.out.println("7\t  Double\t " + Double.SIZE
                + "\t\t\t" + Double.MIN_VALUE
                + "\t\t" + Short.MAX_VALUE);
        System.out.println("8\t  Character\t " + Character.SIZE
                + "\t\t\t" + (int)(Character.MIN_VALUE)
                + "\t\t\t    " + (int)(Character.MAX_VALUE));
    }
}