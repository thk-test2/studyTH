
// 이벤트 옵션

const parentEl = document.querySelector('.parent');

// 핸들러 한 번만 실행
// parentEl.addEventListener('click', event => {
//   console.log('Parent');
// }, { 
//   once: true
// });

// 기본 동작과 핸들러 실행 분리
parentEl.addEventListener('wheel', () => {
  // console.log('Parent!');
  for (let i = 0; i < 10000; i+= 1) {
    console.log(i);
  }
}, {
  passive: true
})