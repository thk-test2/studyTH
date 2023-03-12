
// Keyboard Events

// keydown: 키를 누를 때
// keyup: 키를 땔 때

const inputEl = document.querySelector('input');

inputEl.addEventListener('keydown', event => {
  if (event.key === 'Enter' && !event.isComposing) {
    console.log(event.isComposing); // 이전엔 한글 중복 처리를 위해 이런 방식을 사용함
    console.log(event.target.value);
  };
});

// inputEl.addEventListener('keyup', event => {
//   console.log(event.key);
// });