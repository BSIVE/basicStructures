
from __future__ import annotations

class Stack:
    def __init__(self, capacity: int):
        # 堆疊 top 指標；指向下一個存放資料的位置
        self._top = 0
        # 一維陣列；用來存放堆疊內容
        self._content = [ None for _ in range(capacity) ]

    def pop(self) -> int:
        self._top -= 1

        return self._content[self._top]

    def push(self, i: int) -> None:
        self._content[self._top] = i
        self._top += 1

    @property
    def top(self) -> int:
        return self._top

def dump(deck):
    print(f"堆疊 (stack)： [", end="")

    for i in range(deck.top):
        print(f" {deck._content[i]}", end="")

    print(f" ] top = {deck.top}");

if __name__ == "__main__":
    deck = Stack(10)

    print(f"讓我們 *推* (push) 一些資料進堆疊 (stack)。");

    for i in range(5):
        print(f"  推入 (data pushed): {i}; ", end="");

        deck.push(i)

        dump(deck)

    print()
    dump(deck)
    print()

    print(f"資料推完了，現在把資料 *彈* (pop) 出來：")

    for i in range(5):
        print(
            f"  彈出 (data popped): {deck.pop()}; ",
            end=""
        )

        dump(deck)

# stack.py
