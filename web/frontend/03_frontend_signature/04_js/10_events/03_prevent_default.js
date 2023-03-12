
// 기본 동작 방지

// 마우스 휠의 스크롤 동작 방지!
const parentEl = document.querySelector('.parent');
parentEl.addEventListener('wheel', event => {
  event.preventDefault();
  console.log(event.type);
});

// <a> 태그에서 페이지 이동 방지!
const anchorEl = document.querySelector('a');
anchorEl.addEventListener('click', event => {
  event.preventDefault();
  console.log(event.type);
});