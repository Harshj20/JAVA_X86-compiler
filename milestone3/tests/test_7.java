public class test_7 {
    
    static int f = 0;
    public static void main(String[] args) {
        
        int a = (2 > 3) ? 0 : ( (5 > 6) ? 9 : 10 );
        System.println(a);
        
        a = 5;
        int b = a++;
        System.println(a);
        System.println(b);
    }
}
