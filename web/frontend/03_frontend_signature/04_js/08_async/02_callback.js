
// 콜백 패턴

const a = (callback) => {
    setTimeout(() => {
        console.log(1);
        callback();
    }, 1000);
}
const b = (callback) => {
    setTimeout(() => {
        console.log(2);
        callback();
    }, 1000);
}
const c = () => console.log(3);

a(() => {
    b(() => {
        c();
    });
});


const getMovies = (movieName, callback) => {
    fetch(`https://www.omdbapi.com/?apikey=7035c60c&s=${movieName}`)
        .then(res => res.json())
        .then(res => {
            console.log(res);
            callback();
        })
}

getMovies('frozen', () => {
    console.log('겨울왕국!');
    getMovies('avengers', () => {
        console.log('어벤져스!');
        getMovies('avatar', () => {
            console.log('아바타!');
        })
    })
})
