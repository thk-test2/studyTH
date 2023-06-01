// 인터페이스(Interface)
// 함수 타입 - 호출 시그니처(Call Signature)

interface GetName {
  (param: string, hello: string): string
}
interface User3 {
  name: string
  age: number
  getName: GetName
  // getName: (param: string) => string
}
const heropy3: User3 = {
  name: 'Heropy',
  age: 85,
  getName(message: string) {
    console.log(message);
    return this.name;
  }
}
heropy3.getName('Hello~')