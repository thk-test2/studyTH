// 인터페이스(Interface)

// 선택적 속성 - ?
// 읽기전용 속성 - readonly

interface User2 {
  name: string
  readonly age: number
  isValid?: boolean
}
const heropy2: User2 = {
  name: 'Heropy',
  age: 85,
  isValid: true
}
heropy2.isValid = false;
heropy2.age = 22;

const neo2: User2 = {
  name: 'Neo',
  age: 102,
}




// 함수 타입 - 호출 시그니처(Call Signature)
// 인덱스 가능 타입 - 인덱스 시그니처(Index Signature)
// 확장(상속)
