
// 매개변수 패턴 (Parameter pattern)
//// 기본값 (Default value)

function sum(a, b = 1) {
    return a + b;
}

console.log(sum(1, 2));
console.log(sum(7));

//// 구조 분해 할당 (Destructuring assignment)

const user = {
    name: 'THK',
    age: 85,
    email: 'asdf@gmail.com'
}

// function getName(user) {
//     const { name } = user;
//     return name;
// }

function getName({ name }) {
    return name;
}
function getEmail({ email = '이메일이 없습니다.' }) {
    return email;
}

console.log(getName(user));
console.log(getEmail(user));




const fruits = ['Apple', 'Banana', 'Cherry'];
const numbers = [1, 2, 3, 4, 5, 6, 7];
// function getSecondItem(array) {
//     return array[1];
// }

function getSecondItem([, b]) {
    return b;
}
console.log(getSecondItem(fruits));
console.log(getSecondItem(numbers));



//// 나머지 매개변수 (Rest parameter)
function sum2(...rest) {
    console.log(rest);
    console.log(arguments);
    return rest.reduce(function (acc, cur) {
        return acc + cur;
    }, 0);
}

console.log(sum2(1, 2));
console.log(sum2(1, 2, 3, 4));
console.log(sum2(1, 2, 3, 4, 5, 6, 7, 8, 9, 10));
