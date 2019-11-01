
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    // Node 的 *data* 欄位
    char data;
    // Node 的 *next* 指標；指向下一個 Node
    struct node *next;

    void (* append)(struct node *, struct node *);
} Node;

void append(Node *this, Node *node) {
    Node *cursor = this;

    while (cursor->next) {
        cursor = cursor->next;
    }

    cursor->next = node;
}

Node *new_node(char data) {
    Node *cursor = (Node *)malloc(sizeof(Node));
 
    cursor->data = data;
    cursor->next = NULL;

    cursor->append = append;
}

void dump(Node *linked) {
    printf("鏈結串列 (linked-list)：\n");

    Node *cursor = linked;

    while (cursor) {
        printf(" -> %c", cursor->data);
        cursor = cursor->next;
    }

    printf("\n");
}

void main(int argc, char** argv) {
    Node *head;

    char text[] = "abcdefghijk";

    printf("讓我們 *建立* (create) 一個資料串列：\n\n");

    printf("原始字串是： '%s'\n", text);

    head = new_node(text[0]);

    for (int i = 1; i < strlen(text); i ++) {
        head->append(head, new_node(text[i]));
    }

    printf("\n");
    dump(head);
    printf("\n");
}

// linked.c
