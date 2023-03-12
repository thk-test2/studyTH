
// 메모리 누수(Memory Leak)

// 더 이상 필요하지 않은 데이터가 해제되지 못하고 메모리를 계속 차지되는 현상입니다.

// - 불필요한 전역 변수 사용
// - 분리된 노드 참조
// - 해제하지 않은 타이머
// - 잘못된 클로저 사용

window.hello = 'Hello world!';
window.heropy = { name: 'Heropy', age: 85 };



const btn = document.querySelector('button');
// const parent = document.querySelector('.parent');

btn.addEventListener('click', () => {
  const parent = document.querySelector('.parent');
  console.log(parent);
  parent && parent.remove();
});



const getFn = () => {
  let a = 0;
  return name => {
    // a += 1;
    // console.log(a);
    return `Hello ${name}~`;
  }
}

const fn = getFn();
console.log(fn('Heropy'));
console.log(fn('Neo'));
console.log(fn('Lewis'));