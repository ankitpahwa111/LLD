public class Main {
    public static void main(String[] args) {
        BasePizza basePizza1 = new Margherita();
        System.out.println(basePizza1.getCost());
        BasePizza basePizza2 = new MushroomTopping(new ExtraCheeseTopping(new FarmHouse()));
        System.out.println(basePizza2.getCost());
    }
}