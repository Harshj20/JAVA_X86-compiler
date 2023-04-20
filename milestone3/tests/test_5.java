//import java.io.*;
class Geek {
	// data members of the class.
	int id;
	Geek(int id)
	{
		this.id = id;
	}
}
class test_5 {
	public static void main(String[] args)
	{
		// This would invoke the parameterized constructor.
		Geek geek1 = new Geek(2);
		System.println(geek1.id);
	}
}
