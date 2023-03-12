
const date = new Date();
console.log(date);
// 타임스탬프 - 'Sun Feb 05 2023 21:00:06 GMT+0900 (한국 표준시)'

const d1 = new Date(2022, 11, 16, 12, 57, 30);
console.log(d1);

const d2 = new Date('Fri Dec 16 2022 12:57:30 GMT+0900 (한국 표준시)');
console.log(d2);
console.log(d2.getFullYear());

console.log(d2.getDay()); // 요일을 숫자로 반환

Date.prototype.isAfter = function (date) {
    const a = this.getTime();
    const b = this.getTime();
    return a > b;
}

console.log(d1.isAfter(d2));
console.log(d2.isAfter(d1));
