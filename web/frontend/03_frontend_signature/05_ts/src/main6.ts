// 인터페이스
// 인덱스 가능 타입 - 인덱스 시그니처(Index Signature)

// 배열
interface Fruits {
  [item: number]: string
}
const fruits2: Fruits = ['Apple', 'Banana', 'Cherry']
console.log(fruits2);
console.log(fruits2[1]);

// 객체
interface User4 {
  [key: string]: unknown
  name: string
  age: number
}
const heropy4: User4 = {
  name: 'Heropy',
  age: 85
}
heropy4['isValid'] = true
heropy4['emails']= ['asdf@gmail.com', 'test@gmail.com']
console.log(heropy4);


interface Payload {
  [key: string]: unknown
}
function logValues(payload: Payload) {
  for (const key in payload) {
    console.log(payload[key]);
  }
}

interface User5 {
  [key: string]: unknown
  name: string
  age: number
  isValid: boolean
}
const heropy5: User5 = {
  name: 'Heropy',
  age: 85,
  isValid: true
}
// logValues(heropy5)
logValues(heropy5)