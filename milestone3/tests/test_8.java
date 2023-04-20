

// Base or Super Class
class Employee {
	int salary = 60000;
}

// Inherited or Sub Class
class Engineer extends Employee {
	int benefits = 10000;
}

// Driver Class
class test_8 {
	public static void main(String args[])
	{
		Engineer E1 = new Engineer();
        int x = E1.salary;
		System.println(x);
	}
}
// Java program to illustrate the
// concept of inheritance

// base class
// class Bicycle {
// 	// the Bicycle class has two fields
// 	public int gear;
// 	public int speed;

// 	// the Bicycle class has one constructor
// 	public Bicycle(int gear, int speed)
// 	{
// 		this.gear = gear;
// 		this.speed = speed;
// 	}

// 	// the Bicycle class has three methods
// 	public void applyBrake(int decrement)
// 	{
// 		this.speed -= decrement;
// 	}

// 	public void speedUp(int increment)
// 	{
// 		this.speed += increment;
// 	}

// 	// toString() method to print info of Bicycle
// }

// // derived class
// class MountainBike extends Bicycle {

// 	// the MountainBike subclass adds one more field
// 	public int seatHeight;

// 	// the MountainBike subclass has one constructor
// 	public MountainBike(int gear, int speed,
// 						int startHeight)
// 	{
// 		// invoking base-class(Bicycle) constructor
// 		// super(gear, speed);
// 		this.seatHeight = startHeight;
// 	}

// 	// the MountainBike subclass adds one more method
// 	public void setHeight(int newValue)
// 	{
// 		this.seatHeight = newValue;
// 	}
// }

// // driver class
// public class test_8 {
// 	public static void main(String args[])
// 	{

// 		MountainBike mb = new MountainBike(3, 100, 25);
// 		int x = mb.seatHeight;
// 		System.println(x);
// 	}
// }


