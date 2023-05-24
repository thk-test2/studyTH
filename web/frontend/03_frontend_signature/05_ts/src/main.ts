// 타입 종류

/// 문자
let str: string
let red: string = "Red"
let green: string = 'Green'
let myColor: string = `My color is ${red}.`
let yourColor: string = 'Your color is' + green

/// 숫자
let num: number
let integer: number = 6
let float: number = 3.14
let infinity: number = Infinity
let nan: number = NaN

/// 불린
let isBoolean: boolean
let isDone: boolean = false

/// Null / Undefined
let nul: null
let und: undefined
nul = null
let num: num
console.log(nul);
console.log(und);
console.log(num);

/// 배열
const fruits: string[] = ['Apple', 'Banana', 'Cherry']
const numbers: number[] = [1, 2, 3, 4, 5, 6, 7]
const union: (string|number)[] = ['Apple', 1, 2, 'Banana', 3]
const array: [] = [1, 2, 3]

/// 객체
// typeof DATA === 'object'
const obj: object = {}
const arr: object = []
const func: object = function() {}

interface User {
  name: string
  age: number
  isValid: boolean
}
const userA: User = {
  name: 'Heropy',
  age: 85,
  isValid: true,
  email: ''
}

const userB: User = {
  name: 'Neo',
  age: 22,
  isValid: false
}

/// 함수
const add: (x: number, y: number) => number = function (x, y) {
  return x + y
}
const add2 = function (x: number, y: number): number {
  return x + y
}
const a: number = add(1, 2)

const hello: () => void = function () {
  console.log('Hello world~');
}
const hello2 = function (): void {
  console.log('Hello world~2');
}
const h: void = hello()

/// Any

/// Unknown

/// Tuple

/// Void

/// Never

/// Union

/// Intersection