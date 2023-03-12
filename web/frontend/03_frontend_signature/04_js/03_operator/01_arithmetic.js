
// 산술 (Arithmetic)
console.log(1 + 2);
console.log(5 - 7);
console.log(3 * 4);
console.log(10 / 2);
console.log(7 % 5);

function isEven(num) {
    return num % 2 === 0;
}

console.log(isEven(3));
console.log(isEven(12));


// 할당 (Assignment)

let a = 3;

// a = a + 2;
// a += 2;
a -= 2;

console.log(a);


// 증감 연산자
let b = 3;
console.log(b++);
console.log(b);

console.log(--b);
console.log(b);
