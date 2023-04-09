import { createRouter } from "../core/heropy";
import Home from './Home'
import Movie from './Movie'
import About from './About'

export default createRouter([
  { path: '#/', component: Home },
  { path: '#/movie', component: Movie },
  { path: '#/about', component: About }
])