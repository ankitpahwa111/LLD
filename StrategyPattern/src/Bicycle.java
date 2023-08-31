import DriveStrategy.DefaultStrategy;

public class Bicycle extends Vehicle{
    Bicycle() {
        super(new DefaultStrategy());
    }
}
