
// .length
// 문자의 길이(숫자)를 반환합니다.

const str = 'Hello world!';

console.log(str.length);

// .includes()
// 대상 문자에 주어진 문자가 포함되어 있는지(boolean) 확인합니다.
console.log(str.includes('Hello', 1));

// .indexOf()
// 대상 문자에서 주어진 문자와 일치하는 첫번째 인덱스를 반환합니다.
// 일치하는 문자가 없으면 '-1'을 반환
console.log(str.indexOf('world'));
console.log(str.indexOf('asdf'));

// .padEnd()
// 대상 문자의 길이(length)가 지정된 길이보다 작으면,
// 주어진 문자를 저장된 길이까지 끝에 붙여 새로운 문자를 반환

console.log(str.padEnd(20, '0'));
console.log(str);

console.log(str.padStart(30, 'a'));
console.log(str);