
'use strict'

class Node {
  constructor(data) {
    // 初始化 Node 的 *data* 欄位
    this.data = data;

    // 初始化 Node 的 *next* 指標
    this.next = null;
  }

  append(node) {
    let cursor = this;

    while (cursor.next) {
      cursor = cursor.next;
    }

    cursor.next = node;
  }
}

let dump = (linked) => {
  process.stdout.write(`鍵結串列 (linked-list)：\n`);

  let cursor = linked;

  while (cursor) {
    process.stdout.write(` -> ${cursor.data}`);
    cursor = cursor.next
  }

  process.stdout.write(`\n`);
}

let main = () => {
  let text = "abcdefghijk";

  process.stdout.write(`讓我們 *建立* (create) 一個資料串列：\n\n`);

  process.stdout.write(`原始字串是： '${text}'\n`);

  let head = new Node(text[0]);

  for (let i of text.substring(1)) {
    head.append(new Node(i));
  }

  process.stdout.write(`\n`);
  dump(head)
  process.stdout.write(`\n`);
}

main();

// linked.js
