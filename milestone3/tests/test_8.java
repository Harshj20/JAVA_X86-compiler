// Java Program to Illustrate One Time Iteration
// Inside do-while Loop
// When Condition IS Not Satisfied

// Class
class test_8 {

	// Main driver method
	public static void main(String[] args)
	{
		// initial counter variable
		int i = -2;

		do {
			// Body of loop that will execute minimum
			// 1 time for sure no matter what
			System.println(i);
			i++;
		}

		while (i < 0);
	}
}
