import { Component } from "../core/heropy";

export default class FruitItem extends Component {
  constructor(payload) {
    super({
      tagName: 'li',
      props: payload.props
    })
  }
  render() {
    // this.el.textContent = this.props.name;
    this.el.innerHTML = /* html */ `
      <span>${this.props.name}</span>
      <span>${this.props.price}</span>
    `

    this.el.addEventListener('click', () => {
      console.log(this.props.name, this.props.price);
    })
  }
}