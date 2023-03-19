import { Component } from "../core/heropy";
import TextField from "../components/TextField";

export default class Home extends Component {
  render() {
    this.el.innerHTML = /* html */ `
      <h1>Home Page!</h1>
    `
  }
}