public class Board {
    int maxSize;
    Cell [][] cells;

    private void initializeCells() {

        cells = new Cell[maxSize][maxSize];

        for(int i=0;i<maxSize;i++) {
            for(int j=0; j<maxSize;j++) {
                Cell cellObj = new Cell();
                cells[i][j] = cellObj;
            }
        }
    }

    Board(int maxSize) {
        this.maxSize = maxSize;
        initializeCells();
    }


    void addJump(int start, int end) {
        int startCellRow = start/maxSize;
        int startCellCol = start%maxSize;
//        int endCellRow = end/maxSize;
//        int endCellCol = end%maxSize;
        Jump jump = new Jump();
        jump.start = start;
        jump.end = end;
        Cell startCell = cells[startCellRow][startCellCol];
        startCell.jump = jump;
    }
}
