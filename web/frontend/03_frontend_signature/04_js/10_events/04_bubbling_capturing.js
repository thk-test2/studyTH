
// 이벤트 전파(버블) 정지

const parentEl = document.querySelector('.parent');
const childEl = document.querySelector('.child');
const anchorEl = document.querySelector('a');


window.addEventListener('click', event => {
  console.log('Window!');
}, { capture: true });
document.body.addEventListener('click', event => {
  console.log('Body!');
  event.stopPropagation();
}, { capture: true });
parentEl.addEventListener('click', event => {
  console.log('Parent!');
  // event.stopPropagation();
}, { capture: true });
childEl.addEventListener('click', event => {
  console.log('Child!');
});
anchorEl.addEventListener('click', event => {
  console.log('Anchor!');
});
