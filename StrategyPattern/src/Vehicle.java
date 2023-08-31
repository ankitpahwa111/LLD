import DriveStrategy.DriveStrategy;

public class Vehicle {
    private int vehicleId;
    public DriveStrategy driveStrategy;
    Vehicle(DriveStrategy obj) {
        this.driveStrategy = obj;
    }
    public void drive() {
        driveStrategy.drive();
    }
}
