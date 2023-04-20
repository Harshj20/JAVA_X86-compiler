
// Base or Super Class
class Employee {
	int salary = 60000;
}

// Inherited or Sub Class
class Engineer extends Employee {
	int benefits = 10000;
}

// Driver Class
class test_6 {
	public static void main(String args[])
	{
		Engineer E1 = new Engineer();
        int x = E1.salary;
		System.println(x);
	}
}
// Java program to illustrate the
// concept of inheritance


