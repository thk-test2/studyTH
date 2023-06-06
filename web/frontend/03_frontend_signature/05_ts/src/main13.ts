import { getFullName, User10 } from './user'

const heropy: User10 = {
  firstName: 'Heropy',
  lastName: 'Park',
  age: 85,
  isValid: true
}
const fullName = getFullName(heropy)

console.log(fullName);
console.log(heropy.isValid);