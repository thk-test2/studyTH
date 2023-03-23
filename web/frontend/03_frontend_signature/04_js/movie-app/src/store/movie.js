import { Store } from "../core/heropy";

const store = new Store({
  searchText: '',
  page: 1,
  movies: []
})

export default store;
export const searchMovies = async page => {
  if(page === 1) {
    store.state.page = 1;
    store.state.movies = [];
  }
  const res = await fetch(`https://omdbapi.com?apikey=7035c60c&s=${store.state.searchText}&page=${page}`);
  const { Search } = await res.json();
  store.state.movies = [
    ...store.state.movies,
    ...Search
  ];
}