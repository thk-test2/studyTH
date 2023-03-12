
// Resolve, Reject 그리고 에러 핸들링
const getMovies = movieName => {
  return new Promise((resolve, reject) => {
    fetch(`https://www.omdbapi.com/?apikey=7035c60c&s=${movieName}`)
      .then(res => res.json())
      .then(json => {
        console.log(json);
        if (json.Response === 'False') {
          reject(json.Error);
        }
        resolve(json);
      })
      .catch(error => {
        reject(error);
      })
  })
}

let loading = true;

// .then()
getMovies('avengers')
  .then(movies => console.log('영화 목록:', movies))
  .catch(error => console.log('에러 발생:', error))
  .finally(() => loading = false);

// async/await
const wrap = async () => {
  try {
    const movies = await getMovies('avensdfgers');
    console.log('영화 목록:', movies);
  } catch(error) {
    console.log('에러 발생:', error);
  } finally {
    loading = false;
  }
}

wrap();