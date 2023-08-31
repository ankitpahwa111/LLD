package DriveStrategy;

import DriveStrategy.DriveStrategy;

public class DefaultStrategy implements DriveStrategy {
    @Override
    public void drive() {
        System.out.println("This is normal drive");
    }
}
