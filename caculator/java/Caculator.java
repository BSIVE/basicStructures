
class Stack {
    // 堆疊 top 指標；指向下一個存放資料的位置
    private int _top;
    // 一堆陣列；用來存放堆疊內容
    private int[] _content;

    public Stack(int capacity) {
        this._top = 0;
        this._content = new int[capacity];
    }

    public int pop() {
        return this._content[-- this._top];
    }

    public void push(int value) {
        this._content[this._top ++] = value;
    }

    public static void dump(Stack deck) {
        System.out.print("堆疊 (stack)： [");

        for (int i = 0; i < deck._top; i ++) {
            System.out.print(String.format(" %d", deck._content[i]));
        }

        System.out.println(String.format(" ] top = %d", deck._top));
    }
}

public class Caculator {
    // 運算用的堆疊
    private Stack _stack;

    public Caculator() {
        // 產生堆疊物件
        _stack = new Stack(20);
    }

    public int postfix(String expression) {
        // 將運算式分解成 string list
        String[] tokens = expression.split(" ");

        for (String token:tokens) {
            switch (token) {
                case "+": // 如果是 *運算子*
                    // 由堆疊中取出 *運算元 *
                    int op1 = _stack.pop();
                    int op2 = _stack.pop();

                    // 計算後，將計算結果推回堆疊
                    _stack.push(_plus(op2, op1));

                    break;

                case "-": // 如果是 *運算子*
                    // 由堆疊中取出 *運算元 *
                    op1 = _stack.pop();
                    op2 = _stack.pop();

                    // 計算後，將計算結果推回堆疊
                    _stack.push(_minus(op2, op1));

                    break;

                case "*": // 如果是 *運算子*
                    // 由堆疊中取出 *運算元 *
                    op1 = _stack.pop();
                    op2 = _stack.pop();

                    // 計算後，將計算結果推回堆疊
                    _stack.push(_multiply(op2, op1));

                    break;

                case "/": // 如果是 *運算子*
                    // 由堆疊中取出 *運算元 *
                    op1 = _stack.pop();
                    op2 = _stack.pop();

                    // 計算後，將計算結果推回堆疊
                    _stack.push(_devide(op2, op1));

                    break;

                default:
                    // 如果是 *運算元*，先轉為 *int* 後，推入堆疊
                    _stack.push(Integer.parseInt(token));
            }
        }

        // 計算結束，計算結果在堆疊頂端
        return _stack.pop();
    }

    private int _plus(int op1, int op2) {
        return op1 + op2;
    }

    private int _minus(int op1, int op2) {
        return op1 - op2;
    }

    private int _multiply(int op1, int op2) {
        return op1 * op2;
    }

    private int _devide(int op1, int op2) {
        return op1 / op2;
    }

    public static void main(String[] args) {
        Caculator caculator = new Caculator();

        System.out.println(
            "讓我們 *計算* 一些 *後置表示式* (postfix expression)"
        );

        System.out.println(
            String.format(" 3 5 + = %d", caculator.postfix("3 5 +"))
        );

        System.out.println(
            String.format(" 3 5 - = %d", caculator.postfix("3 5 -"))
        );

        System.out.println(
            String.format(" 3 5 * = %d", caculator.postfix("3 5 *"))
        );

        System.out.println(
            String.format(" 3 5 / = %d", caculator.postfix("3 5 /"))
        );

        System.out.println(" (1 + 3) * 5 - 4 * (8 / 2) =");
        System.out.println(
            String.format(
                " 1 3 + 5 * 4 8 2 / * - = %d",
                caculator.postfix("1 3 + 5 * 4 8 2 / * -")
            )
        );
    }
}

// Caculator.java
