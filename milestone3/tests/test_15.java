class Car {
    private int year;
    private int mileage;

    public Car(int year, int mileage) {
        this.year = year;
        this.mileage = mileage;
    }

    public int getYear() {
        return year;
    }

    public int getMileage() {
        return mileage;
    }
}

public class test_15 {
    // Function that creates and returns a Car object
    // public static Car createCar(int year, int mileage) {
    //     return new Car(year, mileage);
    // }
    public static void main(String[] args) {
        // Call the function to create a Car object
        Car car = new Car(2020, 5000);

        // Access the properties of the Car object
        System.println(car.getYear());
        System.println(car.getMileage());
    }

}
