
from __future__ import annotations

from typing import List

class NArray:
    def __init__(self, cols: int, rows: int):
        self._content = [ None for _ in range(cols * rows) ]
        self._cols = cols
        self._rows = rows

    def get(self, i: int, j: int) -> int:
        return self._content[i * self._cols + j]

    def set(self, i: int, j: int, v: int) -> None:
        self._content[i * self._cols + j] = v

    @property
    def cols(self) -> int:
        return self._cols

    @property # 裝飾子 decorator
    def rows(self) -> int:
        return self._rows

def dump(board) -> None:
    print(f"盤面 (board) 內容：")

    for j in range(board.rows):
        for i in range(board.cols):
            print(f"  ({i}, {j}) = {board.get(i, j)}")

if __name__ == "__main__":
    board = NArray(3, 3)

    print(f"盤面 (board) 設定：")

    for j in range(board.rows):
        for i in range(board.cols):
            print(f"  ({i}, {j}) = {i + j * board.cols}")
            board.set(i, j, i + j * board.cols)

    dump(board)

# n_array.py
