
// 모듈이란 특정 데이터들의 집합입니다.
// import number, { str as xyz, arr, hello } from './module.js';

// console.log(number)
// console.log(xyz);
// console.log(arr);
// console.log(hello);

// import * as abc from './module.js';
// console.log(abc);

setTimeout(async () => {
    // import('./module.js').then(abc => {
    //     console.log(abc);
    // });

    const abc = await import('./module.js');
    console.log(abc);

}, 1000);