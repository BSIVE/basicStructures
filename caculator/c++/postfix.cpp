
#include <iostream>
#include <sstream>

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

class Caculator {
    private:
        // 運算用的堆疊
        Stack stack_;

    public:
        Caculator();

    public:
        int postfix(string);

    private:
        // 真正的運算方法
        int plus_(int, int);
        int minus_(int, int);
        int multiply_(int, int);
        int devide_(int, int);
};

Caculator::Caculator(): stack_(Stack(20)) {
    ; // This is intended to be empty.
}

int Caculator::postfix(string expression) {
    string token;
    // 將運算式分解成 string 串流
    stringstream tokens(expression);

    while (tokens >> token) {
        if (token == "+") { // 如果是 *運算子*
            // 由堆疊中取出 *運算元*
            int op1 = stack_.pop();
            int op2 = stack_.pop();

            // 計算後，將計算結果推回堆疊
            stack_.push(plus_(op2, op1));
        }
        else if (token == "-") { // 如果是 *運算子*
            // 由堆疊中取出 *運算元*
            int op1 = stack_.pop();
            int op2 = stack_.pop();

            // 計算後，將計算結果推回堆疊
            stack_.push(minus_(op2, op1));
        }
        else if (token == "*") { // 如果是 *運算子*
            // 由堆疊中取出 *運算元*
            int op1 = stack_.pop();
            int op2 = stack_.pop();

            // 計算後，將計算結果推回堆疊
            stack_.push(multiply_(op2, op1));
        }
        else if (token == "/") { // 如果是 *運算子*
            // 由堆疊中取出 *運算元*
            int op1 = stack_.pop();
            int op2 = stack_.pop();

            // 計算後，將計算結果推回堆疊
            stack_.push(devide_(op2, op1));
        }
        else {
            // 如果是 *運算元*，先轉為 *int* 後，推入堆疊
            stack_.push(stoi(token));
        }
    }

    // 計算結束，計算結果在堆疊頂端
    return stack_.pop();
}

int Caculator::plus_(int op1, int op2) {
    return op1 + op2;
}

int Caculator::minus_(int op1, int op2) {
    return op1 - op2;
}

int Caculator::multiply_(int op1, int op2) {
    return op1 * op2;
}

int Caculator::devide_(int op1, int op2) {
    return op1 / op2;
}

int main(int argc, char** argv) {
    Caculator caculator = Caculator();

    cout << "讓我們 *計算* 一些 *後置表示式* (postfix expression)" << endl;

    cout << " 3 5 + = " << caculator.postfix("3 5 +") << endl;
    cout << " 3 5 - = " << caculator.postfix("3 5 -") << endl;
    cout << " 3 5 * = " << caculator.postfix("3 5 *") << endl;
    cout << " 3 5 / = " << caculator.postfix("3 5 /") << endl;
    cout << " (1 + 3) * 5 - 4 * (8 / 2) =" << endl;
    cout << " 1 3 + 5 * 4 8 2 / * - = "
         << caculator.postfix("1 3 + 5 * 4 8 2 / * -  ") << endl;
}

// stack.cpp
