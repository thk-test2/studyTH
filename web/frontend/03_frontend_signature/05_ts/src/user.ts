export interface User10 {
  firstName: string
  lastName: string
  age: number
  isValid: boolean
}

export function getFullName(user: User10) {
  return `${user.firstName} ${user.lastName}`
}