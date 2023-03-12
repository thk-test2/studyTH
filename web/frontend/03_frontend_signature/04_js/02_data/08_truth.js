
// 참과 거짓

// 거짓
// 1) false
// 2) 0
// 3) null
// 4) undefined
// 5) NaN
// 6) ''
// 7) 0n

if (true) {
    console.log('참!');
}

if (123) {
    console.log('참!');
}

if (0) {
    console.log('참! 0');
}

if ('0') {
    console.log('참! 00');
}

// const fruits = ['Apple', 'Banana'];
const fruits = [];

if (fruits.length) {
    console.log('아이템이 들어있음!');
}