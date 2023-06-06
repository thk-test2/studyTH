// /// <reference path="./main.d.ts" />
import _ from 'lodash'

const str = 'the brown fox jumps over the lazy dog'

console.log(_.camelCase(str));
console.log(_.snakeCase(str));
console.log(_.kebabCase(str));