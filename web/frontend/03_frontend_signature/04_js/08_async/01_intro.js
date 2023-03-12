
// 동기오 ㅏ비동기
// - 동기: 순차적으로 코드 실행
// - 비동기: 순차적으로 코드 실행하지 않음

console.log(1);
setTimeout(() => {
    console.log(2);
}, 1000);
console.log(3);


const btnEl = document.querySelector('h1');
btnEl.addEventListener('click', () => {
    console.log('Clicked');
})

console.log('Hello World!');


fetch('https://www.omdbapi.com/?apikey=7035c60c&s=frozen')
    .then(res => res.json())
    .then(res => {
        console.log(res)
        console.log(4);
        console.log(5);
        console.log(6);
    })
