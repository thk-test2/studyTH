
// 논리 (Logical)

// AND 연산자
const a = true;
const b = false;

if (a && b) {
    console.log('모두가 참!');
}

if (a && !b) {
    console.log('모두가 참!');
}

if (a || b) {
    console.log('하나 이상이 참!');
}


// AND 연산자 (왼쪽부터 거짓을 반환)
console.log(true && false);
console.log(1 && 0);
console.log(1 && 2 && 0);
console.log(1 && 0 && 2);
console.log(0 && 1 && 2);

console.log('A' && 'B' && '');

// 모두가 참이면 마지막 데이터를 반환
console.log('A' && 'B' && 'C');


// OR 연산자 (왼쪽부터 참을 반환)
console.log(false || true);
console.log(0 || 1);
console.log(false || 0 || {});
console.log(false || [] || null);
console.log(function() {} || undefined || '');
