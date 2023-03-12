
// .replace()
// 대상 문자에서 패턴(문자, 정규식)과 일치하는 부분을 교체한 새로운 문자를 반환합니다.

const str = 'Hello, Hello?!';

console.log(str.replace('Hello', 'Hi'));
console.log(str.replace(/Hello/g, 'Hi'));
console.log(str);


// .slice()
// 대상 문자의 일부를 추출해 새로운 문자를 반환합니다.
// 두번째 인수 직전까지 추출하고, 두 번째 인수를 생략하면 대상 문자의 끝까지 추출합니다.

console.log(str.slice(0, 5));
console.log(str.slice(6, -1));
console.log(str.slice(6));
console.log(str);


// .split()
// 대상 문자를 주어진 구분자로 나눠 배열로 반환합니다.
console.log(str.split(', '));
console.log(str.split('').reverse().join(''));


// .toLowerCase()
// 대상 문자를 영어 소문자로 변환해 새로운 문자로 반환합니다.
console.log(str.toLowerCase());

console.log(str.toUpperCase());

// .trim()
// 대상 문자의 앞뒤 공백 문자(space, tab 등)를 제거한 새로운 문자를 반환합니다.
const str2 = '    T  H  K   ';
console.log(str2.trim());
console.log(str2);