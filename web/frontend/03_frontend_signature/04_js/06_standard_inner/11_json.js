
// JSON(Javascript Object Notation)

// 데이터 전달을 위한 표준 포맷!
// 문자, 숫자, boolean, Null, 객체, 배열만 사용
// 문자는 큰 따옴표만 사용
// 후행 쉼표 사용 불가
// .json 확장자 사용

// JSON.stringify() - 데이터를 JSON 문자로 변환합니다.
// JSON.parse() - JSON 문자를 분석해 데이터로 변환합니다.

// console.log(JSON.stringify('Hello world'));
// console.log(JSON.stringify(123));
// console.log(JSON.stringify(false));
// console.log(JSON.stringify(null));
// console.log(JSON.stringify({ name: 'THK', age: 81}));
// console.log(JSON.stringify([1, 2, 3]));

// console.log('// ---------------------------------- //');
// console.log(JSON.parse('"Hello world!"'));
// console.log(JSON.parse('123'));
// console.log(JSON.parse('false'));
// console.log(JSON.parse('null'));
// console.log(JSON.parse('{"name":"THK","age":85}'));
// console.log(JSON.parse('[1,2,3]'));

import abc from './test.json' assert { type: "json" };

console.log(abc);
