
public class Stack {
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

    public static void main(String[] args) {
        Stack deck = new Stack(10);

        System.out.println("讓我們 *推* (push) 一些資料進堆疊 (stack)。");

        for (int i = 0; i < 5; i ++) {
            System.out.print(String.format(
                "  推入 (data pushed): %d; ",
                i
            ));

            deck.push(i);

            Stack.dump(deck);
        }

        System.out.println();
        Stack.dump(deck);
        System.out.println();

        System.out.println("資料推完了，現在把資料 *彈* (pop) 出來：");

        for (int i = 0; i < 5; i ++) {
            System.out.print(String.format(
                "  彈出 (data popped): %d; ",
                deck.pop()
            ));

            Stack.dump(deck);
        }
    }
}

// Stack.java
