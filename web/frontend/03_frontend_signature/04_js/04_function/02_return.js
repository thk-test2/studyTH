
// 반환 및 종료

function hello() {
    return 'Hello~';
    console.log('Wow~');
}

console.log(hello);
console.log(hello());


function plus(num) {
    if (typeof num !== 'number') {
        console.log('숫자를 입력해 주세요!');
        return 0;
    }
    return num + 1;
}
console.log(plus(2));
console.log(plus(7));
console.log(plus());
