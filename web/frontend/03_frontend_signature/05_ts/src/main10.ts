// 클래스

// 접근 제어자(Access Modifiers)
/// public - 어디서나 자유롭게 접근 가능, 클래스 바디에서 생략 가능
/// protected - 나와 파생된 후손 클래스 내에서 접근 가능
/// private - 내 클래스에서만 접근 가능

class UserA3 {
  // public first: string = ''
  // protected last: string = ''
  // private age: number = 0
  constructor(public first: string, protected last: string, private age: number) {
    this.first = first
    this.last = last
    this.age = age
  }
  protected getAge() {
    return `${this.first} ${this.last} is ${this.age}`
  }
}
class UserB3 extends UserA3 {
  getAge() {
    return `${this.first} ${this.last} is ${this.age}`
  }
}
class UserC3 extends UserB3 {
  getAge() {
    return `${this.first} ${this.last} is ${this.age}`
  }
}

const neo3 = new UserA3('Neo', 'Anderson', 102)
console.log(neo3.first);
console.log(neo3.last);
console.log(neo3.age);

console.log(neo3.getAge());

const neo4 = new UserB3('Neo', 'Anderson', 102)
console.log(neo4.getAge());