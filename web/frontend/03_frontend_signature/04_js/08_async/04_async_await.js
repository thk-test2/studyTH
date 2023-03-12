
// Async / Await

const a = () => {
  return new Promise(resolve => {
    setTimeout(() => {
      console.log(1);
      resolve();
    }, 1000);
  });
}
const b = () => console.log(2);

// a().then(() => b())

const wrap = async () => {
  await a();
  b();
}

wrap();


const getMovies = async movieName => {
  const res = await fetch(`https://www.omdbapi.com/?apikey=7035c60c&s=${movieName}`);
  const j = await res.json();
  console.log(j);  
}

const wrap2 = async () => {
  await getMovies('frozen');
  console.log('겨울왕국!');
  
  await getMovies('avengers');
  console.log('어벤져스!');
  
  await getMovies('avatar');
  console.log('아바타!');
}

wrap2();

// getMovies('frozen')
//   .then(() => {
//     console.log('겨울왕국!');
//     return getMovies('avengers');
//   })
//   .then(() => {
//     console.log('어벤져스!');
//     return getMovies('avatar');
//   })
//   .then(() => {
//     console.log('아바타');
//   })