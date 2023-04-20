// Fibonacci Series using Recursion
class test_13 {
	static int fib(int n)
	{
		if (n <= 1)
			return n;
		return fib(n-1) + fib(n-2);
	}

	public static void main(String args[])
	{
		int n = 9;
		n = fib(n);
		System.println(n);
	}
}
