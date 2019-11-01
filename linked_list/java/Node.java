
public class Node {
    // Node 的 *data* 欄位
    public char data;
    // Node 的 *next* 指標；指向下一個 Node
    public Node next;

    public Node(char data) {
        // 初始化 Node 的 *data* 欄位
        this.data = data;

        // 初始化 Node 的 *next* 指標
        this.next = null;
    }

    public void append(Node node) {
        Node cursor = this;

        while (cursor.next != null) {
            cursor = cursor.next;
        }

        cursor.next = node;
    }

    public static void dump(Node linked) {
        System.out.println("鍵結串列 (linked-list)：");

        Node cursor = linked;

        while (cursor != null) {
            System.out.print(String.format(" -> %c", cursor.data));
            cursor = cursor.next;
        }

        System.out.println();
    }

    public static void main(String[] args) {
        String text = "abcdefghijk";

        System.out.println("讓我們 *建立* (create) 一個資料串列：\n");

        System.out.println(String.format(
            "原始字串是： %s",
            text
        ));

        Node head = new Node(text.charAt(0));

        for (int i = 1; i < text.length(); i ++) {
            head.append(new Node(text.charAt(i)));
        }

        System.out.println();
        Node.dump(head);
        System.out.println();
    }
}

// Node.java
