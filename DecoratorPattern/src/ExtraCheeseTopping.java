public class ExtraCheeseTopping implements ToppingDecorator{
    BasePizza basePizza;
    ExtraCheeseTopping(BasePizza basePizza) {
        this.basePizza = basePizza;
    }
    @Override
    public int getCost() {
        return this.basePizza.getCost()+40;
    }
}
