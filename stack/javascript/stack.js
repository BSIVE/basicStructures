
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

let deck = new Stack(10);

process.stdout.write('讓我們 *推* (push) 一些資料進堆疊 (stack)。\n');

for (let i = 0; i < 5; i ++) {
  process.stdout.write(`  推入 (data pushed): ${i}; `);

  deck.push(i);

  dump(deck);
}

process.stdout.write('\n');
dump(deck);
process.stdout.write('\n');

process.stdout.write(`資料推完了，現在把資料 *彈* (pop) 出來：\n`);

for (let i = 0; i < 5; i ++) {
  process.stdout.write(`  彈出 (data popped): ${deck.pop()}; `);

  dump(deck);
}

// stack.js
