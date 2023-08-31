import DriveStrategy.SpecialStrategy;

public class OffRoadVehicle extends Vehicle{
    OffRoadVehicle() {
        super(new SpecialStrategy());
    }
}
