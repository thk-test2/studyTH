
// 클로저(Closure)

// 함수가 선언될 때의 유효범위(렉시컬 범위)를 기억하고 있다가,
// 함수가 외부에서 호출될 때 그 유효범위의 특정 변수를 참조할 수 있는 개념을 말합니다.

function createCount() {
  let a = 0;
  return function() {
    return a += 1;
  }
}

const count = createCount();

console.log(count()); // 1
console.log(count()); // 2
console.log(count()); // 3

const count2 = createCount();

console.log(count2());
console.log(count2());


const h1El = document.querySelector('h1');
const h2El = document.querySelector('h2');

// 별도의 상태 관리가 필요!
// let h1IsRed = false;
// let h2IsRed = false;

// h1El.addEventListener('click', event => {
//   h1IsRed = !h1IsRed;
//   h1El.style.color = h1IsRed ? 'red' : 'black';
// });

// h2El.addEventListener('click', event => {
//   h2IsRed = !h2IsRed;
//   h2El.style.color = h2IsRed ? 'red' : 'black';
// });

// 하나의 함수로 정리!
const createToggleHandler = () => {
  let isRed = false;
  return event => {
    isRed = !isRed;
    event.target.style.color = isRed ? 'red' : 'black';
  }
}
h1El.addEventListener('click', createToggleHandler());
h2El.addEventListener('click', createToggleHandler());