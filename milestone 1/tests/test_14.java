//import java.io.*;
class Geek {
	// data members of the class.
	int name;
	int id;
	Geek(int name, int id)
	{
		this.name = name;
		this.id = id;
	}
}
class GFG {
	public static void main(String[] args)
	{
		// This would invoke the parameterized constructor.
		Geek geek1 = new Geek(14,2);
		//System.out.println("GeekName :" + geek1.name + " and GeekId :" + geek1.id);
	}
}
