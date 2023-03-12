
// 얕은 복사 & 깊은 복사

// 참조형은 가변성으로 인해, 데이터를 복사할 때 주의가 필요합니다.

// 얕은 복사(Shallow Copy) - 참조형의 1차원 데이터만 복사
// 깊은 복사(Deep Copy) - 참조형의 모든 차원 데이터를 복사


// let a = 1;
// let b = a;

// b = 2;

// console.log(b);
// console.log(a);

// b = 3;

// console.log(b);
// console.log(a);



// const aa = { x: 1};
// // const bb = aa;
// // const bb = Object.assign({}, aa);
// const bb = { ...aa }; // 전개 연산자는 대표적으로 중괄호를 제거하는 역할을 함

// bb.x = 2;

// console.log(bb); // {x: 2}
// console.log(aa); // {x: 2}


import cloneDeep from 'lodash/cloneDeep';

const aaa = {x: {y: 1}};
// const bbb = { ...aaa }; // 얕은 복사!
const bbb = cloneDeep(aaa);

bbb.x.y = 2;

console.log(bbb);
console.log(aaa);


// 배열
const aaaa = [1, 2, 3];
// const bbbb = aaaa;
// const bbbb = aaaa.concat([]); // 깊은 복사
const bbbb = [ ...aaaa ]; // 깊은 복사

bbbb[0] = 4;

console.log(bbbb); // [4, 2, 3]
console.log(aaaa); // [4, 2, 3]