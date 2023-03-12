
// .toFixed()
// 숫자를 지정된 고정 소수점 표기(자릿수)까지 표현하는 문자로 반환합니다.

const num = 3.141592;

console.log(num.toFixed(2));
console.log(typeof num.toFixed(2));

console.log(parseFloat(num.toFixed(2)));
console.log(typeof parseFloat(num.toFixed(2)));


// .toLocaleString()
// 숫자를 현지 언어 형식의 문자로 반환합니다.

const num2 = 1000000;
console.log(num2.toLocaleString());
console.log(`${num2.toLocaleString()} 원`);


// Number.isInteger()
// 숫자가 정수(integer)인지 확인합니다.
const num3 = 123;
const pi = 3.14;
console.log(Number.isInteger(num3));
console.log(Number.isInteger(pi));


// Number.isNaN()
// 주어진 값이 'NaN'인지 확인합니다.
const num4 = NaN;
const num5 = 123;
const str = 'Hello World';
const nul = null;

console.log(Number.isNaN(num4));
console.log(Number.isNaN(num5));
console.log(Number.isNaN(str));
console.log(Number.isNaN(nul));


// Number.parseInt() 또는 parseInt()
// 주어진 값(숫자, 문자)을 파싱해 특정 진수(radix)의 전수로 반환합니다.
const str2 = '3.14159123123';
const num6 = 3.141591123123;
console.log(Number.parseInt(str2, 10));
console.log(Number.parseInt(num6, 10));

// Number.parseFloat() 또는 parseFloat()
// 주어진 값(숫자, 문자)을 파싱해 부동소수점 실수로 반환(숫자)합니다.
const str3 = '3.14123123';
const num7 = 3.14123123;
console.log(Number.parseFloat(str3));
console.log(Number.parseFloat(num7));