// 제네릭(Generic)
/// 함수

interface Obj {
  x: number
}
type Arr = [number, number]

// function toArray(a: string, b: string): string[]
// function toArray(a: number, b: number): number[]
// function toArray(a: boolean, b: boolean): boolean[]
// function toArray(a: Obj, b: Obj): Obj[]
// function toArray(a: Arr, b: Arr): Arr[]
// function toArray(a: any, b: any) {
function toArray<T>(a: T, b: T) {
  return [a, b]
}

console.log(
  toArray('Neo', 123),
  toArray<string>('Neo', 123),
  toArray('Neo', 'Anderson'),
  toArray(1, 2),
  toArray(true, false),
  toArray({x: 1}, {x: 2}),
  toArray([1, 2], [3, 4]), // number[]
  toArray<Arr>([1, 2], [3, 4, 5]) // Tuple이 아님
);


// 제네릭(Generic)
/// 클래스
class User8<P> {
  constructor(public payload: P) {
  }
  getPayload() {
    return this.payload
  }
}

interface UserAType {
  name: string
  age: number
  isValid: boolean
}
interface UserBType {
  name: string
  age: number
  emails: string[]
}
const heropy8 = new User8<UserAType>({
  name: 'Heropy',
  age: 85,
  isValid: true,
  emails: [] // ?!
})
const neo8 = new User8<UserBType>({
  name: 'Neo',
  // ?!
  emails: ['neo@gmail.com']
})


// 제네릭(Generic)
/// 인터페이스, 제약 조건
// interface MyData<T> {
interface MyData<T extends string | number[]> {
  name: string
  value: T
}
const dataA: MyData<string> = {
  name: 'Data A',
  value: 'Hello world'
}
const dataB: MyData<number> = {
  name: 'Data B',
  value: 1234
}
const dataC: MyData<boolean> = {
  name: 'Data C',
  value: true
}
const dataD: MyData<number []> = {
  name: 'Data D',
  value: [1, 2, 3, 4]
}