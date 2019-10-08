
class NArray {
  constructor(cols, rows) {
    this.content_ = new Array(cols * rows);

    this.cols_ = cols;
    this.rows_ = rows;
  }

  get(col, row) {
    return this.content_[row * this.cols_ + col];
  }

  set(col, row, value) {
    this.content_[row * this.cols_ + col] = value;
  }

  get cols() {
    return this.cols_;
  }

  get rows() {
    return this.rows_;
  }
}

dump = function (board) {
  console.log("盤面 (board) 內容：");

  for (let j = 0; j < board.rows; j ++) {
    for (let i = 0; i < board.cols; i ++) {
      console.log(`  (${i}, ${j}) = ${board.get(i, j)}`);
    }
  }
}

let board = new NArray(3, 3);

console.log("盤面 (board) 設定：");

for (let j = 0; j < board.rows; j ++) {
  for (let i = 0; i < board.cols; i ++) {
    console.log(`  (${i}, ${j}) = ${i + j * board.cols}`);
    board.set(i, j, i + j * board.cols);
  }
}

dump(board);

// n_array.js
