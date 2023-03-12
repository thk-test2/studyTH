
// 반복문에서 비동기 처리

const getMovies = movieName => {
  return new Promise(resolve => {
    fetch(`https://www.omdbapi.com/?apikey=7035c60c&s=${movieName}`)
      .then(res => res.json())
      .then(res => resolve(res))
  });
}

const titles = ['frozen', 'avengers', 'avatar'];

// titles.forEach(async title => {
//   const movies = await getMovies(title);
//   console.log(title, movies);
// })


const wrap = async () => {
    for (const title of titles) {
    const movies = await getMovies(title);
    console.log(title, movies);
  }
}
wrap();