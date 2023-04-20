// Java Program to Illustrate Methods

// Class 1
// Helper class
class Addition {

	// Initially taking sum as 0
	// as we have not started computation
	int sum = 0;

	// Method
	// To add two numbers
	public int addTwoInt(int a, int b)
	{
		int z = 1, y;
		// Adding two integer value
		y = a + b;

		// Returning summation of two values
		return y;
	}
}

// Class 2
// Helper class
class test_4 {

	// Main driver method
	public static void main(String[] args)
	{

		// Creating object of class 1 inside main() method
		Addition add = new Addition();

		// Calling method of above class
		// to add two integer
		// using instance created

		int s = add.addTwoInt(41, 42);

		// Printing the sum of two numbers
		System.println(s);
	}
}
