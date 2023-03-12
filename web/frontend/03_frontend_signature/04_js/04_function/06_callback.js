
// 콜백 (Callback)

// const a = callback => {
//     console.log('A');
//     callback();
// }

// const b = () => {
//     console.log('B');
// }

// a(b);


// const sum = (c, d, e) => {
//     const result = setTimeout(() => {
//         e(c + d);
//     }, 1000);

//     return result;
// }


// sum(10, 20, value => {
//     console.log(value);
// });

// sum(30, 70, value => {
//     console.log(value);
// });


// https://www.gstatic.com/webp/gallery/4.jpg
const loadImage = (url, cb) => {
    const imgEl = document.createElement('img');
    imgEl.src = url;
    imgEl.addEventListener('load', () => {
        setTimeout( () => {
            cb(imgEl);
        }, 1000);
    });
}

const containerEl = document.querySelector('.container');
loadImage('https://www.gstatic.com/webp/gallery/4.jpg', (imgEl) => {
    containerEl.innerHTML = '';
    containerEl.append(imgEl);
});