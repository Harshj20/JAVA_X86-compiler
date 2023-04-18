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

	static int foo(int a, int b){
		int c =  b - a;
		return c;
	}

	public static void main(String[] args)
	{
		// test_5(2, 3);
		// int d= 2^(2|4) ;
		// int e= d*2 + d*3;
		//int z = foo(2,e);
		boolean z = 4 < 3;
		int x = 1;
		int e = 5;
		if(e==70 && z){
			System.println(x);
		}
		else{
			System.println(x+e);
		}
		// if(e > 20){
		// 	e = 5;
		// }
		// else
		// 	e = 10;
		//System.println(e);
	}
}
