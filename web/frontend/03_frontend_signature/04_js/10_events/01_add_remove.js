
// .addEventListener()
// 대상에 이벤트 청취를 등록합니다.
// 대상에 지정한 이벤트가 발생했을 때 지정한 함수(Handler)가 호출됩니다.

const parentEl = document.querySelector('.parent');
const childEl = document.querySelector('.child');

const handler = () => {
  console.log('Parent!');
}

parentEl.addEventListener('click', handler);

childEl.addEventListener('click', () => {
  console.log('Child!');
  parentEl.removeEventListener('click', handler);
});