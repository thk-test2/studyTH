// 타입 단언(Assertion)
// '단언' - 주저하지 아니하고 딱 잘라 말함.

// 단언 키워드 - as
// Non-null 단언 연산자 - !

// 1)
// const el = document.querySelector('body') as HTMLBodyElement;
// el.textContent = 'Hello world?!';

// const el = document.querySelector('body');
// el!.textContent = 'Hello world?!';

const el = document.querySelector('title');
if (el) {
  el.textContent = 'Hello world?!';
}

// 2)
function getNumber(x: number | null | undefined) {
  // return Number((x as number).toFixed(2));
  // return Number(x!.toFixed(2));
  if (x) {
    return Number(x.toFixed(2));
  }
}
getNumber(3.1415926535)
getNumber(null)

// 3)
function getValue(x: string | number, isNumber: boolean) {
  if (isNumber) {
    return Number((x as number).toFixed(2))
  }
  return (x as string).toUpperCase()
}
getValue('hello world', false) // 'HELLO WORLD'
getValue(3.1415123123, true) // 3.14



// 할당 단언(Assertion)
// '단언' - 주저하지 아니하고 딱 잘라 말함.

// let num4: number
let num4!: number
console.log(num4);