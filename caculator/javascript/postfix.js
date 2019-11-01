
class Stack {
  constructor(capacity) {
    // 堆疊 top 指標；指向下一個存放資料的位置
    this.top_ = 0;
    // 一堆陣列：用來存放堆疊內容
    this.content_ = new Array(capacity);
  }

  pop() {
    return this.content_[-- this.top_];
  }

  push(value) {
    this.content_[this.top_ ++] = value;
  }

  get top() {
    return this.top_;
  }
}

let dump = (deck) => {
  process.stdout.write('堆疊 (stack)： [');

  for (let i = 0; i < deck.top; i ++) {
    process.stdout.write(` ${deck.content_[i]}`);
  }

  process.stdout.write(` ] top = ${deck.top}\n`);
}

class Caculator {
  constructor() {
    // 生成一個計算用的堆疊
    this.stack_ = new Stack(20);

    // 設定 *運算子* 的運算方法
    this.operations_ = {
      "+": this.plus_,
      "-": this.minus_,
      "*": this.multiply_,
      "/": this.devide_,
    }
  }

  plus_(op1, op2) {
    return op1 + op2;
  }

  minus_(op1, op2) {
    return op1 - op2;
  }

  multiply_(op1, op2) {
    return op1 * op2;
  }

  devide_(op1, op2) {
    return op1 / op2;
  }

  postfix(expression) {
    // 將運算式分解成 List
    for (const op of expression.split(' ')) {
      // 如果是 *運算子* (+-*/)
      if (op in this.operations_) {
        // 由堆疊取出 *運算元*
        let op1 = this.stack_.pop();
        let op2 = this.stack_.pop();

        // 計算後，將計算結果推入堆疊
        this.stack_.push(this.operations_[op](op2, op1));
      }
      else {
        // 如果是 *運算元*，先轉為 *int* 後，推入堆疊
        this.stack_.push(parseInt(op, 10));
      }
    }

    // 計算結束，計算結果在堆疊頂端
    return this.stack_.pop();
  }
}

(() => {
  caculator = new Caculator();

  process.stdout.write(
    `讓我們 *計算* 一些 *後置表示式* (postfix expression)\n`
  );

  process.stdout.write(` 3 5 + = ${caculator.postfix('3 5 +')}\n`);
  process.stdout.write(` 3 5 - = ${caculator.postfix('3 5 -')}\n`);
  process.stdout.write(` 3 5 * = ${caculator.postfix('3 5 *')}\n`);
  process.stdout.write(` 3 5 / = ${caculator.postfix('3 5 /')}\n`);
  process.stdout.write(` (1 + 3) * 5 - 4 * (8 / 2) =\n`);
  process.stdout.write(
    ` 1 3 + 5 * 4 8 2 / * - = ${caculator.postfix('1 3 + 5 * 4 8 2 / * -')}\n`
  );
})();

// postfix.js
