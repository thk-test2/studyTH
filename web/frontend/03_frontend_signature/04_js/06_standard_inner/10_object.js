
// Object.assign()
// 하나 이상의 소스 객체로부터 대상 객체로 속성을 복사하고 대상 객체를 반환합니다.
const target = { a: 1, b: 2 };
const source1 = { b: 3, c: 4 };
const source2 = { c: 5, d: 6};
// const result = Object.assign(target, source1, source2);
// const result = Object.assign({}, target, source1, source2);
const result = {
    ...target,
    ...source1,
    ...source2,
}

console.log(target);
console.log(result);


// Object.entries()
// 주어진 객체의 각 속성과 값으로 하나의 배열을 만들어 요소로 추가한 2차원 배열을 반환합니다.

const user = {
    name: 'THK',
    age: 83,
    isValid: true,
    email: 'asdf@asdf.com'
}

console.log(Object.entries(user));
for (const [key, value] of Object.entries(user)) {
    console.log(key, value);
}


// Object.keys()
// 주어진 객체의 속성 이름을 나열한 배열을 반환합니다.
console.log(Object.keys(user));

console.log(Object.values(user));