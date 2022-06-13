// Design in memory data structure to store the data like excel sheet in rows and columns.

// Data is generic (can be int, string, bool..) and has properties like font type, size, bold,italics.
// User can add more rows and columns at the end
// User can also insert rows and columns in between existing rows/columns.

// This was asked in Round 2 of microsoft interview.

// "static void main" must be defined in a public class.

// AddCol , AddRow is missing , they will be O(n) functions
public class Main {
    static class Spreadsheet{
        HashMap<Integer, Row> rows;
        //Can Simply be
        // HashMap<Integer, <HashMap<Integer, Cell>> rows;
        
        Spreadsheet(int row, int col){
            rows = new HashMap();
            for(int i=1; i<=row; i++){
                rows.put(i, new Row(col));
            }
        }
    }
    
    static class Row{
        HashMap<Integer, Cell> cols;
        Row(int col){
            cols = new HashMap();
            for(int j=1; j<=col; j++){
                cols.put(j, null);
            }
        }
    }
    
    static class Cell<T>{
        T value;
        
    }
    public static void main(String[] args) {
        System.out.println("Hello World!");
        Spreadsheet s = new Spreadsheet(3, 3);
        s.rows.get(1).cols.putIfAbsent(1, new Cell<String>());
        s.rows.get(1).cols.get(1).value= "Hello";
        s.rows.get(1).cols.putIfAbsent(2, new Cell<Boolean>());
        s.rows.get(1).cols.get(2).value= false;
        for(int i=1; i<=s.rows.size(); i++){
            for(int j=1; j<=s.rows.get(i).cols.size(); j++){
                if(s.rows.get(i).cols.get(j)==null)
                    System.out.print("N/A\t");
                else
                    System.out.print(s.rows.get(i).cols.get(j).value+"\t"); 
            }
            System.out.println();
        }
        
    }
}