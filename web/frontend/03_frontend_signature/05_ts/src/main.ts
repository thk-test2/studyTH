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
let hello3: any = 'Hello world'
hello3 = 123
hello3 = false
hello3 = null
hello3 = {}
hello3 = []
hello3 = function () {}

/// Unknown
const aa: any = 123
const u: unknown = 123

const any: any = u
const boo: boolean = u
const num2: number = u
const arr2: string[] = u
const obj2: { x: string, y: number } = u

/// Tuple
const tuple: [string, number, boolean] = ['a', 1, false]
const users: [number, string, boolean][]
  = [[1, 'Neo', true], [2, 'Evan', false], [3, 'Lewis', true]]

/// Void
function hello4(msg: string): void {
  console.log(`Hello ${msg}`);
}
const hi: void = hello4('world')

/// Never
const nev: [] = []
nev.push(3)

/// Union
let union2: string | number
union2 = 'Hello type!'
union2 = 123
union2 = false

/// Intersection
interface User {
  name: string,
  age: number
}
interface Validation {
  isValid: boolean
}
const heropy: User & Validation = {
  name: 'Neo',
  age: 85,
  isValid: true
}

// 타입 추론(Inference)
// '추론' - 어떠한 판단을 근거로 삼아 다른 판단을 이끌어 냄.

// 1) 초기화된 변수
// 2) 기본값이 설정된 매개 변수
// 3) 반환 값이 있는 함수

// 초기화된 변수 'num'
let num3 = 12
num3 = 'Hello type!'

// 기본값이 지정된 매개 변수 'b' + 반환 값이 확실한 함수 'add'
function add3(a: number, b = 2) {
  return a + b
}