
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

class Caculator:
    def __init__(self):
        # 生成一個計算用的堆疊
        self._stack = Stack(20)

        # 設定 *運算子* 的運算方法
        self._operations = {
            "+": self._plus,
            "-": self._minus,
            "*": self._multiply,
            "/": self._devide
        }

    def _plus(self, op1: int, op2: int) -> int:
        return op1 + op2

    def _minus(self, op1: int, op2: int) -> int:
        return op1 - op2

    def _multiply(self, op1: int, op2: int) -> int:
        return op1 * op2

    def _devide(self, op1: int, op2: int) -> float:
        return op1 / op2

    def postfix(self, expression: str) -> int:
        # 將運算式分解成 List
        for op in expression.split():
            # 如果是 *運算子* (+-*/)
            if op in self._operations:
                # 由堆疊中取出 *運算元*
                op1 = self._stack.pop()
                op2 = self._stack.pop()

                # 計算後，將計算結果推回推疊
                self._stack.push(self._operations[op](op2, op1))
            else:
                # 如果是 *運算元*，先轉為 *int* 後，推入堆疊
                self._stack.push(int(op))

        # 計算結束，計算結果在堆疊頂端
        return self._stack.pop()

if __name__ == "__main__":
    caculator = Caculator()

    print(f"讓我們 *計算* 一些 *後置表示式* (postfix expression)")

    print(f" 3 5 + = {caculator.postfix('3 5 +')}")
    print(f" 3 5 - = {caculator.postfix('3 5 -')}")
    print(f" 3 5 * = {caculator.postfix('3 5 *')}")
    print(f" 3 5 / = {caculator.postfix('3 5 /')}")
    print(f" (1 + 3) * 5 - 4 * (8 / 2) =")
    print(f" 1 3 + 5 * 4 8 2 / * - = {caculator.postfix('1 3 + 5 * 4 8 2 / * -')}")

# caculator.py
