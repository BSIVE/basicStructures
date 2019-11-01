
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


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

int plus(int op1, int op2) {
    return op1 + op2;
}

int minus(int op1, int op2) {
    return op1 - op2;
}

int multiply(int op1, int op2) {
    return op1 * op2;
}

int devide(int op1, int op2) {
    return (int)op1 / (int)op2;
}

int postfix(char const *expression) {
    // 生成一個計算用的堆疊
    stack *stack_ = new_stack(20);

    char *token = NULL;
    char *exp = (char *)malloc(strlen(expression) + 1);
    int op1 = 0;
    int op2 = 0;

    strcpy(exp, expression);

    // 將運算式分解成 token
    token = strtok(exp, " ");

    while (token != NULL) {
        switch (*token) {
            case '+':
                // 由堆疊中取出 *運算元*
                op1 = stack_->pop(stack_);
                op2 = stack_->pop(stack_);

                // 計算後，將計算結果推回堆疊
                stack_->push(stack_, plus(op2, op1));

                break;

            case '-':
                // 由堆疊中取出 *運算元*
                op1 = stack_->pop(stack_);
                op2 = stack_->pop(stack_);

                // 計算後，將計算結果推回堆疊
                stack_->push(stack_, minus(op2, op1));

                break;

            case '*':
                // 由堆疊中取出 *運算元*
                op1 = stack_->pop(stack_);
                op2 = stack_->pop(stack_);

                // 計算後，將計算結果推回堆疊
                stack_->push(stack_, multiply(op2, op1));

                break;

            case '/':
                // 由堆疊中取出 *運算元*
                op1 = stack_->pop(stack_);
                op2 = stack_->pop(stack_);

                // 計算後，將計算結果推回堆疊
                stack_->push(stack_, devide(op2, op1));

                break;

            default:
                // 如果是 *運算元*，先轉為 *int* 後，推入堆疊
                stack_->push(stack_, strtol(token, NULL, 10));
        }

        token = strtok(NULL, " ");
    }

    // 計算結束，計算結果在堆疊頂端
    return stack_->pop(stack_);
}

void main(int argc, char** argv) {
    printf("讓我們 *計算* 一些 *後置表示式* (postfix expression)\n");

    printf(" 3 5 + = %d\n", postfix("3 5 +"));
    printf(" 3 5 - = %d\n", postfix("3 5 -"));
    printf(" 3 5 * = %d\n", postfix("3 5 *"));
    printf(" 3 5 / = %d\n", postfix("3 5 /"));
    printf(" (1 + 3) * 5 - 4 * (8 / 2) =\n");
    printf(
        " 1 3 + 5 * 4 8 2 / * - = %d\n",
        postfix("1 3 + 5 * 4 8 2 / * -")
    );
}

// post_fix.c
