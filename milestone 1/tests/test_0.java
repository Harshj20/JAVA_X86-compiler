// public // Class 1
// Helper class
class Addition {
 
    // Initially taking sum as 0
    // as we have not started computation
    static int sum = 0;
 
    // Method
    // To add two numbers
    public static int addTwoInt(int a, int b)
    {
 
        // Adding two integer value
        sum = a + b;
 
        // Returning summation of two values
        return sum;
    }
}
 
// Class 2
// Helper class
class GFG {
 
    // Main driver method
    public static void main()
    {
 
        // Creating object of class 1 inside main() method
        Addition add = new Addition();
 
        // Calling method of above class
        // to add two integer
        // using instance created
        int s = Addition.addTwoInt(1, 2.0);
 
        // Printing the sum of two numbers
        System.out.println("Sum of two integer values :"
                           + s);
    }
} 
