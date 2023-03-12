
// 이벤트 객체

// 이벤트 객체는 대상에서 발생한 이벤트 정보를 담고 있습니다.

const parentEl = document.querySelector('.parent');

parentEl.addEventListener('click', event => {
  console.log(event.target, event.currentTarget);
  console.log(event);
});

parentEl.addEventListener('wheel', event => {
  console.log(event);
});

const inputEl = document.querySelector('input');

inputEl.addEventListener('keydown', event => {
  console.log(event.key);
});