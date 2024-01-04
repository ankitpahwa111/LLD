import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.List;


// Comparator vs Comparable
// Comparator is function or class( implementing Comparator interface and having compare override function )
// provided as part of sort function to let JDK know how to compare two custom objects

// Comparable is an interface which you have to implement in your class on which you have to apply sort
// your class should have a compareTo overriden function that returns 0 1 or -1 based on comparison

// Comparable only allows one comparison to other object , whereas we can have multiple comparators and pass
// it in sort based on our requirements
class Car implements Comparable<Car>{
    String carName;
    String version;

    public Car(String carName, String version) {
        this.carName = carName;
        this.version = version;
    }

    public String getCarName() {
        return carName;
    }

    public String getVersion() {
        return version;
    }

    @Override
    public int compareTo(Car o) {
        return o.getCarName().compareTo(this.carName);
    }
}


public class ComparatorExample {
    public static void main(String[] args) {
        Car[] carArray = new Car[3];
        Car c1 = new Car("car1", "petrol");
        Car c2 = new Car("Ankit", "dsl");
        Car c3 = new Car("Ankita", "dsl");
        carArray[0] = c1;
        carArray[1] = c2;;
        carArray[2] = c3;
        // via comparator
        Arrays.sort(carArray, (Car obj1, Car obj2) -> obj1.getCarName().compareTo(obj2.getCarName()));
        for(Car c: carArray) System.out.println(c.carName);

        System.out.println("---------------------------------------");

        // via comparable
        List<Car> carArray2 = new ArrayList<>();
        carArray2.add(c1);
        carArray2.add(c2);
        carArray2.add(c3);
        Collections.sort(carArray2);
        for(Car c: carArray) System.out.println(c.carName);

    }
}
