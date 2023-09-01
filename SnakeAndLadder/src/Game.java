import java.util.Deque;
import java.util.LinkedList;
import java.util.Random;
import java.util.concurrent.ThreadLocalRandom;

public class Game {
    Board board;
    int boardSize;
    int numDices;
    Dice dice;
    Deque<Player> players = new LinkedList<>();

    Game(int boardSize, int numDices) {
        this.boardSize = boardSize;
        board = new Board(boardSize);
        this.numDices = numDices;
        this.dice = new Dice();
    }


    void startGame() {
        while(true) {
            Player playerToPlay = players.getFirst();
            players.pop();
            players.addLast(playerToPlay);
            System.out.println("Player turn : " + playerToPlay.name + " Current position: " + playerToPlay.currentPosition);
            int diceRoll = 0;
            for(int i=0; i<numDices; i++) {
                diceRoll += dice.rollDice();
            }
            int newPosition = playerToPlay.currentPosition + diceRoll;
            newPosition = getNewPositionAfterJumps(newPosition);
            playerToPlay.currentPosition = newPosition;
            System.out.println(playerToPlay.name + " new Position: " + playerToPlay.currentPosition);
            if(checkIfPlayerWon(playerToPlay)) {
                System.out.println("Player " + playerToPlay.name + " Won");
                break;
            }
        }
    }

    int getNewPositionAfterJumps(int currentPosition) {
        if(currentPosition > (board.maxSize * (board.maxSize-1)))
            return currentPosition;
        int cellRow = currentPosition/10;
        int cellCol = currentPosition%10;
        Cell cell = board.cells[cellRow][cellCol];
        if(cell.jump!=null) {
            String snakeOrLadder  = cell.jump.start < cell.jump.end ? "Ladder" : "Snake";
            System.out.println("Effected by " + snakeOrLadder);
            return cell.jump.end;
        }
        return currentPosition;
    }

    boolean checkIfPlayerWon(Player player) {
        return player.currentPosition > (board.maxSize * (board.maxSize-1));
    }

    void addPlayer(Player player) {
        players.addLast(player);
    }

    void addJumps(int snakes, int ladders) {
        Random random = new Random();
        for(int i=0; i<snakes; i++) {
            int start = ThreadLocalRandom.current().nextInt(1, boardSize*(boardSize-1));
            int end = random.nextInt(start);
            board.addJump(start, end);
        }
        for(int i=0; i<ladders; i++) {
            int end = ThreadLocalRandom.current().nextInt(1, boardSize*(boardSize-1));
            int start = random.nextInt(end);
            board.addJump(start, end);
        }
    }
}
