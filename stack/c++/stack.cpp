
#include <iostream>

using namespace std;

class Stack {
    private:
        // 堆疊 top 指標；指向下一個存放資料的位置
        int top;
        // 一維陣列，用來存放堆疊內容
        int *content_;

    public:
        Stack(int);
        ~Stack();

    public:
        int pop();
        void push(int);

    public:
        static void dump(Stack&);
};

Stack::Stack(int capacity) {
    top = 0;

    content_ = new int [capacity];
}

Stack::~Stack() {
    delete[] content_;
}

int Stack::pop() {
    return content_[-- top];
}

void Stack::push(int i) {
    content_[top ++] = i;
}

void Stack::dump(Stack& deck) {
    cout << "堆疊 (stack)： [";

    for (int i= 0; i < deck.top; i ++) {
        cout << " " << deck.content_[i];
    }

    cout << " ] top = " << deck.top << endl;
}

int main(int argc, char** argv) {
    Stack deck = Stack(10);

    cout << "讓我們 *推* (push) 一些資料進堆疊 (stack)。" << endl;

    for (int i = 0; i < 5; i ++) {
        cout << "  推入 (data pushed): " << i << "; ";

        deck.push(i);
        Stack::dump(deck);
    }

    cout << endl;
    Stack::dump(deck);
    cout << endl;

    cout << "資料推完了，現在把資料 *彈* (pop) 出來：" << endl;

    for (int i = 0; i < 5; i ++) {
        cout << "  彈出 (data popped): " << deck.pop() << "; ";
        Stack::dump(deck);
    }
}

// stack.cpp
