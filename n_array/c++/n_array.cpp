
#include <iostream>

using namespace std;

class NArray {
    public:
        const int COLS;
        const int ROWS;

    private:
        int *content_;

    public:
        NArray(int, int);
        ~NArray();

    public:
        int get(int, int);
        void set(int, int, int);
};

NArray::NArray(int cols, int rows) : COLS(cols), ROWS(rows) {
    content_ = new int [cols * rows];
}

NArray::~NArray() {
    delete[] content_;
}

int NArray::get(int i, int j) {
    return content_[i + j * COLS];
}

void NArray::set(int i, int j, int value) {
    content_[i + j * COLS] = value;
}

void dump(NArray *board) {
    cout << "盤面 (board) 內容：" << endl;

    for (int j = 0; j < board->ROWS; j ++) {
        for (int i = 0; i < board->COLS; i ++) {
            cout << "  (" << i << ", " << j << ") = "
                 << board->get(i, j) << endl;
        }
    }
}

int main(int argc, char** argv) {
    NArray *board = new NArray(3, 3);

    cout << "盤面 (board) 設定：" << endl;

    for (int j = 0; j < board->ROWS; j ++) {
        for (int i = 0; i < board->COLS; i ++) {
            cout << "  (" << i << ", " << j << ") = "
                 << i + j * board->COLS <<endl;

            board->set(i, j, i + j * board->COLS);
        }
    }

    dump(board);
}

// n_array.cpp
