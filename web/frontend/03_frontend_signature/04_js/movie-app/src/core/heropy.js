
//// Component ////
export class Component {
  constructor(payload = {}) {
    const {
      tagName = 'div',
      state = {},
      props = {}
    } = payload;
    this.el = document.createElement(tagName);
    this.state = state;
    this.props = props;
    this.render();
  }
  render() {
    // ...
  }
}


//// Router ////
function routeRender(routes) {
  if (!location.hash) {
    history.replaceState(null, '', '/#/');
  }

  const routerView = document.querySelector('router-view');
  // http://localhost:1234/#/about
  // #/about?name=heropy
  const [hash, queryString = ''] = location.hash.split('?');

  // a=123&b=456
  // ['a=123', 'b=456']
  // { a: '123', b: '456' }
  const query = queryString
    .split('&')
    .reduce((acc, cur) => {
      const [key, value] = cur.split('=');
      acc[key] = value;
      return acc;
  }, {});
  history.replaceState(query, '');

  const currentRoute = routes.find(route => new RegExp(`${route.path}/?$`).test(hash));
  routerView.innerHTML = '';
  routerView.append(new currentRoute.component().el);

  window.scrollTo(0, 0);
}
export function createRouter(routes) {
  return function() {
    window.addEventListener('popstate', () => {
      routeRender(routes);
    })
    routeRender(routes);
  }
}


//// Store ////
export class Store {
  constructor(state) {
    this.state = {};
    this.observers = {};
    for (const key in state) {
      Object.defineProperty(this.state, key, {
        get: () => state[key], // state['message']
        set: val => {
          state[key] = val;
          // this.observers['message']()
          // this.observers[key]();
          if (Array.isArray(this.observers[key])) { // 호출할 콜백이 있는 경우!
            this.observers[key].forEach(observer => observer(val));
          }
        }
      });
    }
  }
  subscribe(key, cb) {
    // this.observers['message'] = () => {}
    // { message: () => {} }
    // { message: [() => {}, () => {}, ...]}

    // { message: [cb1, cb2, cb3, ...] }
    Array.isArray(this.observers[key])
      ? this.observers[key].push(cb)
      : this.observers[key] = [cb];
  }
}