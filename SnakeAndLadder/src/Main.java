public class Main {
    public static void main(String[] args) {
        int boardSize = 10;
        int numDices = 2;
        Game game = new Game(boardSize, numDices);
        Player player1 = new Player("Ankit", 0);
        Player player2 = new Player("Surabhi", 0);
        game.players.addLast(player1);
        game.players.addLast(player2);
        game.addJumps(5,6);
        game.startGame();
    }
}