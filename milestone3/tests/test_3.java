//Java code for using 'this' keyword to
//refer current class instance variables
class test_3
{
	int a;
	int b;

	static int foo(int a, int b){
		int c =  b - a;
		return c;
	}

	public static void main(String[] args)
	{
		// test_5(2, 3);
		int d= 2^(2|4) ;
		int e= d*2 + d*3;
		int y = foo(2,e);
		System.println(y);
		boolean z = 4 < 3;
		int x = 1;
		if(e==70 && z){
			System.println(x);
		}
		else{
			System.println(x+e);
		}
		if(e >= 20){
			e = 5;
		}
		else{
			e = 10;
		}
		System.println(e);
	}
}
