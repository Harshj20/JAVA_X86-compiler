//Java code for using 'this' keyword to
//refer current class instance variables
class Test
{
	static int a;
	static int b;
	
	// Parameterized constructor
	static Test(int a, int b)
	{
		this.a = a;
		this.b = b;
		int c = (((a++)+3)+(int)(3.0));
		int d= 2+3*4;
		int e= 5-4+3;
	}

	static void display()
	{
		//Displaying value of variables a and b
		System.out.println("a = " + a + " b = " + b);
	}

	public static void main(String[] args)
	{
		Test object = new Test(10, 20);
		object.display();
	}
}
