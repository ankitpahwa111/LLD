package DriveStrategy;

import DriveStrategy.DriveStrategy;

public class SpecialStrategy implements DriveStrategy {
    @Override
    public void drive() {
        System.out.println("This is special drive");
    }
}
