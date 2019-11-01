
#include <iostream>
#include <string>

using namespace std;

class Node {
    public:
        // Node 的 *data* 欄位
        char data;
        // Node 的 *next* 指標；指向下一個 Node
        Node *next;

    public:
        Node(char);

    public:
        void append(Node *);
};

Node::Node(char data) {
    this->data = data;
    this->next = NULL;
}

void Node::append(Node *node) {
    Node *cursor = this;

    while (cursor->next != NULL) {
        cursor = cursor->next;
    }

    cursor->next = node;
}

void dump(Node *linked) {
    cout << "鏈結串列 (linked-list)：" << endl;

    Node *cursor = linked;

    while (cursor) {
        cout << " -> " << cursor->data;
        cursor = cursor->next;
    }

    cout << endl;
}

int main(int argc, char** argv) {
    Node *head;

    string text("abcdefghijk");

    cout << "讓我們 *建立* (create) 一個資料串列：" << endl << endl;

    cout << "原始字串是： '" << text << "'" << endl;

    head = new Node(text[0]);

    for (int i = 1; i < text.length(); i ++) {
        head->append(new Node(text[i]));
    }

    cout << endl;
    dump(head);
    cout << endl;
}

// linked.cpp
