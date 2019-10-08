
#include <stdio.h>
#include <stdlib.h>

typedef struct n_array {
    int cols;
    int rows;
    int *content_;

    int (* get)(struct n_array const *, int, int);
    void (* set)(struct n_array const *, int, int, int);
} n_array;

int get(n_array const *board, int i, int j) {
    return board->content_[i + j * board->cols];
}

void set(n_array const *board, int i, int j, int value) {
    board->content_[i + j * board->cols] = value;
}

n_array *new_array(int cols, int rows) {
    n_array *board = (n_array *)malloc(sizeof(n_array));

    board->cols = cols;
    board->rows = rows;

    board->content_ = (int *)malloc(cols * rows * sizeof(int));

    board->get = get;
    board->set = set;

    return board;
}

void dump(n_array *board) {
    printf("盤面 (board) 內容：\n");

    for (int j = 0; j < board->rows; j ++) {
        for (int i = 0; i < board->cols; i ++) {
            printf(
                "  (%d, %d) = %d\n",
                i, j, board->get(board, i, j)
            );
        }
    }
}

void main(int argc, char** argv) {
    n_array *board = new_array(3, 3);

    printf("盤面 (board) 設定：\n");

    for (int j = 0; j < board->rows; j ++) {
        for (int i = 0; i < board->cols; i ++) {
            printf("  (%d, %d) = %d\n", i, j, i + j * board->cols);
            board->set(board, i, j, i + j * board->cols);
        }
    }

    dump(board);
}

// n_array.c
