
const str = `Template literal
  are string literals
  allowing embedded expressions.`;

console.log(str);

let language = 'Javascript';
let expression = `I love ${language}`;
console.log(expression);

expression = `I love ${language.split('').reverse().join('')}`;
console.log(expression);