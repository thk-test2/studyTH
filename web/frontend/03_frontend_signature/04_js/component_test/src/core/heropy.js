
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