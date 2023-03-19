import { Component } from "../core/heropy";

export default class About extends Component {
  render() {
    const { a, b, c } = history.state;
    this.el.innerHTML = /* html */ `
      <h1>About Page!</h1>
      <h2>${a}</h2>
      <h2>${b}</h2>
      <h2>${c}</h2>
    `
  }
}