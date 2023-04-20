public class test_3 {
    
    static int f = 0;
    public static void main(String[] args) {
        
        int n1 = 31, n2 = 62;
        int n3 = n1 + n2;
        int n4 = n2 / n1; 
		int max = (n1 > n2) ? n1 : n2;
        
        System.println(n3);
        System.println(n4);
        System.println(max);

        n2 -= n1;
        System.println(n2);
        
    }
}
