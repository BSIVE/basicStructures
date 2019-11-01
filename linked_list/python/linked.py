
from __future__ import annotations

class Node:
    def __init__(self, data: int):
        # 初始化 Node 的 *data* 欄位
        self.data = data

        # 初始化 Node 的 *next* 指標
        self.next = None

    def append(self, node: Node) -> None:
        cursor = self

        while cursor.next:
            cursor = cursor.next

        cursor.next = node

def dump(linked: Node) -> None:
    print(f"鍵結串列 (linked-list)：")

    cursor = linked

    while cursor:
        print(f" -> {cursor.data}", end="")
        cursor = cursor.next

    print()

if __name__ == "__main__":
    text = "abcdefghijk"

    print(f"讓我們 *建立* (create) 一個資料串列：\n")

    print(f"原始字串是： '{text}'")

    head = Node(text[0])

    for i in text[1:]:
        head.append(Node(i))

    print()
    dump(head)
    print()

# linked.py
