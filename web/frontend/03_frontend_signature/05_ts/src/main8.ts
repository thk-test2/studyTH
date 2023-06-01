// 타입 별칭(Alias)

type TypeA = string
type TypeB = string | number | boolean
type User6 = {
  name: string
  age: number
  isValid: boolean
} | [string, number, boolean]

const userA6: User6 = {
  name: 'Neo',
  age: 85,
  isValid: true
}
const userB6: User6 = ['Evan', 36, false]

function someFunc(param: TypeB): TypeA {
  switch (typeof param) {
    case 'string':
      return param.toUpperCase()
    case 'number':
      return param.toFixed(2)
    default:
      // return true
      return 'Boolean!'
  }
}


type TypeUser = {
  name: string
  age: number
  isValid: boolean
}
interface InterfaceUser {
  name: string
  age: number
  isValid: boolean
}

const heropy7: ?? = {
  name: 'Heropy',
  age: 85,
  isValid: true
}