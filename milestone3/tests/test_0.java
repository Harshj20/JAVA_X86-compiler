// public // Class 1
// Helper class
class Addition {
 
    // Initially taking sum as 0
    // as we have not started computation
    static int sum = 0;
    static int a[][] = new int[10][9];
    char y;
    int z;
    // // Method
    // // To add two numbers
    // static public Addition(int x, int y){
    //     x = this.a[2][6];
    //     // this.a[2][3] = x;
    // }
    static public Addition(){

    }
    int addTwoInt(int a, int b)
    {
 
        // Adding two integer value
        //int[] sum = this.a[9];

        // Returning summation of two values
        return a + b;
    }
}
 
// Class 2
//Helper class
class test_0 {
    // Addition l = new Addition();
    int sum;
 
    // Main driver method
    public static void main()
    {
 
        // Creating object of class 1 inside main() method
        Addition add = new Addition();
        add.z = add.addTwoInt(1,5);
        // Calling method of above class
        // to add two integer
        // // using instance created
        //int s = add.a[0][0];
        //add.z = s;
        //s = add.a[0][0];
        //String a = "Hello world";
        //int x, z[];
        // Printing the sum of two numbers
        System.out.println(add.z);
    }
} 
