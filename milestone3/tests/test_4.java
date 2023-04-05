public class SyntaxCheck {
    static void demo(long val) {
        int x =1;
    }
    public static void main(String[] args) {
        int a;
        a = 5;
        a++;
        demo(a);

        // float b = 3.14f; // Default to a float type
        // demo(b);

        long val = 100L;
        demo(val);
    }

}
