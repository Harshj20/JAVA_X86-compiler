//Java code for using 'this' keyword to
//refer current class instance variables
class test_5
{
	static int a;
	static int b;
	
	// Parameterized constructor
	// static test_5(int a, int b)
	// {
	// 	//this.a = a;
	// 	//this.b = b;
	// 	//int c = (((a++)+3)+(int)(3.0));
	// 	int d= 2+3*4 + a;
	// 	int e= d*2 + d*3 + b;
	// 	System.println(e);
	// }

	// static void display()
	// {
	// 	//Displaying value of variables a and b
	// 	System.out.println("a = " + a + " b = " + b);
	// }

	public static void main(String[] args)
	{
		// test_5(2, 3);
		int d= 2+3*4 ;
		int e= d*2 + d*3;
		System.println(e);
	}
}
