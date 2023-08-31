public class MushroomTopping implements ToppingDecorator{
    BasePizza basePizza;
    MushroomTopping(BasePizza basePizza) {
        this.basePizza = basePizza;
    }
    @Override
    public int getCost() {
        return this.basePizza.getCost()+50;
    }
}
