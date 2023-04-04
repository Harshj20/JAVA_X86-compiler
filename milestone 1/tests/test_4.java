public class SyntaxCheck {
<<<<<<< HEAD

    static void printFunc(float val) {
=======
    static void printFunc(long val) {
>>>>>>> 74c58c09f9ec938d97af0c0e1f85005b5947ceeb
        System.out.println(val);
    }
    public static void main(String[] args) {
        int a;
        a = 5;
        a++;
        printFunc(a);

        // float b = 3.14f; // Default to a float type
        // printFunc(b);

        long val = 100L;
        printFunc(val);
    }
<<<<<<< HEAD
=======

>>>>>>> 74c58c09f9ec938d97af0c0e1f85005b5947ceeb
}
