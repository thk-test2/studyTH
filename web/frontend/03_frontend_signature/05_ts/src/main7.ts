// 인터페이스(Interface)
// 확장(상속)

interface UserA {
  name: string
  age: number
}
interface UserB extends UserA {
  isValid: boolean
}

const heropy6: UserA = {
  name: 'Heropy',
  age: 85,
  isValid: true
}
const neo6: UserB = {
  name: 'Neo',
  age: 102,
  isValid: true
}


interface FullName {
  firstName: string
  lastName: string
}
interface FullName {
  middleName: string
  lastName: boolean
}

const fullName: FullName = {
  firstName: 'Tomas',
  middleName: 'Sean',
  lastName: 'Connery'
}