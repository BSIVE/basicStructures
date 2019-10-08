
public class NArray {
    public final int COLS;
    public final int ROWS;

    private int[] _contents;

    public NArray(int cols, int rows) {
        this.COLS = cols;
        this.ROWS = rows;

        this._contents = new int[cols * rows];
    }

    public int get(int col, int row) {
        return this._contents[row * this.COLS + col];
    }

    public void set(int col, int row, int value) {
        this._contents[row * this.COLS + col] = value;
    }

    public static void dump(NArray board) {
        System.out.println("盤面 (board) 內容：");

        for (int j = 0; j < board.ROWS; j ++) {
            for (int i = 0; i < board.COLS; i ++) {
                System.out.println(String.format(
                    "  (%d, %d) = %d", i, j, board.get(i, j)
                ));
            }
        }
    }

    public static void main(String[] args) {
        NArray board = new NArray(3, 3);

        System.out.println("盤面 (board) 設定：");

        for (int j = 0; j < board.ROWS; j ++) {
            for (int i = 0; i < board.COLS; i ++) {
                System.out.println(String.format(
                    "  (%d, %d) = %d", i, j, (i + j * board.COLS)
                ));

                board.set(i, j, (i + j * board.COLS));
            }
        }

        NArray.dump(board);
    }
}

// NArray.java
