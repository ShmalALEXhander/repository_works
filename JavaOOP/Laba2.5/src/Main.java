public class Main {
    public static void main(String[] args) {
        int value = Integer.parseInt(args[0]);
        String str2="";
        String str8="";
        String str16="";
        int osn=2;
        int x=value;
        System.out.println(value);
        while(x>0){
            str2 += (char)(x % osn +'0');
            x /= osn;
        }
        for (int i = str2.length() - 1; i >= 0; i--) {
            System.out.printf("%c",str2.charAt(i)); //!!!!!
        }
        x=value;
        osn=8;
        while(x>0){
            str8 += (char)(x % osn +'0');
            x /= osn;
        }
        System.out.print(" ");
        for (int i = str8.length() - 1; i >= 0; i--) {
            System.out.printf("%c",str8.charAt(i)); //!!!!!
        }
        x=value;
        osn=16;
        while(x>0){
            int ch= x % osn;
            if (ch<10) {
                str16 += (char) (ch + '0');
            }
            else {
                str16+=(char)(ch-10+'A');
            }
            x /= osn;
        }
        System.out.print(" ");
        for (int i = str16.length() - 1; i >= 0; i--) {
            System.out.printf("%c",str16.charAt(i)); //!!!!!
        }
    };
}