
// 호출 스케줄링

const hello = () => {
    console.log('Hello~');
}

const timeout = setInterval(hello, 2000);

const h1El = document.querySelector('h1');

h1El.addEventListener('click', () => {
    console.log('Clear time out');
    clearInterval(timeout);
});