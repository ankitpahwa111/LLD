import java.util.Random;

public class Dice {
    int max;

    Dice(){
        this.max = 6;
    }
    public int rollDice() {
        Random random = new Random();
        return random.nextInt(max);
    }
}
