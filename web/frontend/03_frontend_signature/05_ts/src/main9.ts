// 함수 - 명시적 this

interface Cat {
  name: string
  age: number
}
const cat: Cat = {
  name: 'Lucy',
  age: 3
}

function hello4(this: Cat, message: string) {
  console.log(`Hello ${this.name}, ${message}`);
}
hello4.call(cat, 'You are pretty awesome!')


// 함수 - 오버로딩(Overloading)

// 1)
function add1(a: string, b: string) {
  return a + b
}
function add3(a: number, b: number) {
  return a + b
}
add1('hello ', 'world~')
add3(1, 2)
add1('hello ', 2)
add3('hello ', 2)

// 2)
function add4(a: string, b: string): string // 타입 선언
function add4(a: number, b: number): number // 타입 선언
function add4(a: any, b: any) { // 함수 구현
  return a + b
}
add4('hello', 'world~')
add4(1, 2)
add4('hello', 2)
add4('hello', 2)