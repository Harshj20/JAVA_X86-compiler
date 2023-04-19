public class test_12 {
    
    static int f = 0;
    public static void main(String[] args) {
        int a = 0;
        int b = ++a++;
        b = ++a;
        System.println(a);
        System.println(b);
    }
}
