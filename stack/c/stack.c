
#include <stdio.h>
#include <stdlib.h>

typedef struct stack {
    // 堆疊 top 指標；指向下一個存放資料的位置
    int top;
    // 一維陣列，用來存放堆疊內容
    int *content_;

    int (* pop)(struct stack *);
    void (* push)(struct stack *, int);
} stack;

int pop(stack *deck) {
    return deck->content_[-- deck->top];
}

void push(stack *deck, int i) {
    deck->content_[deck->top ++] = i;
}

stack *new_stack(int capacity) {
    stack *deck = (stack *)malloc(sizeof(stack));

    deck->top = 0;
    deck->content_ = (int *)malloc(capacity * sizeof(int));

    deck->pop = pop;
    deck->push = push;

    return deck;
}

void dump(stack *deck) {
    printf("堆疊 (stack)： [");

    for (int i= 0; i < deck->top; i ++) {
        printf(" %d", deck->content_[i]);
    }

    printf(" ] top = %d\n", deck->top);
}

void main(int argc, char** argv) {
    stack *deck = new_stack(10);

    printf("讓我們 *推* (push) 一些資料進堆疊 (stack)。\n");

    for (int i = 0; i < 5; i ++) {
        printf("  推入 (data pushed): %d; ", i);

        deck->push(deck, i);
        dump(deck);
    }

    printf("\n");
    dump(deck);
    printf("\n");

    printf("資料推完了，現在把資料 *彈* (pop) 出來：\n");

    for (int i = 0; i < 5; i ++) {
        printf("  彈出 (data popped): %d; ", deck->pop(deck));
        dump(deck);
    }
}

// stack.c
