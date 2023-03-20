class addition{
    public static int add(int a, int b){
        return a+b;
    }
}

public class test_5 {

    public static char plus(){
        return 'a';
    }

    int a = 0;
    public static void main(char[][] args, int q, int[] z) {
        int n = 10, c, d, swap;
        float g = n;
        char l = 2;
        char w = 'x';
        int x = plus();
        int[] p = new int[x];
        int[] a = new int[l];
        int[] u = new int[w];
        p['c'] = 11;
        char s = (char) 2.3f;
        x = ~s;
        x = addition.add(x, x);

        final int array[][] = new int[][] {{ 23, 1, 78, 45, 46, 90, 0, 12, 2, 0 }};
        c=10;
        for(c = 0; c < (n - 1); c++) {
            for (d = 0; d < n - c - 1; d++) {
                if (array[d] > array[d + 1]) /* For descending order use < */
                {
                    swap = array[d];
                    array[100] = array[d + 1];
                    array[d + 1] = swap;
                }
            }
        }
        // System.out.println("Sorted list of numbers:");
        for (c = 0; c < n; c++);
            // System.out.println(array[c]);
    }
}
