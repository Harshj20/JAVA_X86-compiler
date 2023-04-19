public class test_9 {
    // int x = 0;
    // char y = 'c';
    // int z = 0;

    // public test_16(int x){
    //     z = x;
    // }

    // public int hello(int a, int b){
    //     int x = 0;
    //     char y = 'c';
    //     int z = 0;
    //     return 0;
    // }
    static int fibonacci(int n){
        if(n == 0)
            return 0;
        if(n == 1)
            return 1;
        if(n == 2)
            return 2;
        return fibonacci(n-1) + fibonacci(n-2);
    }
    public static void main(String[] args) {
            // int a = 0, b, c;
            // // b = a++;
            // a = b = (a > 1)?c:(a+1);
            // if(a < b){
            //     a = 1;
            // }
            // while(a < 3){
            //     b = a + b;
            //     for(;;){
            //         // if(b==5){
            //         //     if(a==3){
            //         //         break;
            //         //     }
            //         // }
            //     }
            //     //break;
            // }
            // a = hello(2+5*5, a++);
            System.println(fibonacci(6));
            // System.println(fibonacci(1));
            // System.println(fibonacci(2));
            // System.println(fibonacci(3));
            // System.println(fibonacci(4));
            // System.println(fibonacci(5));
            // int q[][] = new int[2][2];
            // // q[0][0] = 0;
            // q[0][1] = 1;
            // int b = 2;
            // q[1][0] = 2;
            // q[1][1] = 3; 
            // q[0][0] = q[0][1] + q[0][1];
            // q[0][0] = 1 + q[0][0];
            // q[0][0] = q[0][0] + 1;
            // b = q[0][0];
            // // int b = 0;
            // // b = q[0][0] + 1;
            // // System.println(b);
            // System.println(b);
            // int q1[] = {1,2,5,6,3};
            // System.println(q1[2]);
            // int q = 5;
            // float r = 10.0;
            // float s = q * r;
            // while(true){
            //     if(true)
            //         break;
            //     if(false)
            //         break;
            // }
    }
}
