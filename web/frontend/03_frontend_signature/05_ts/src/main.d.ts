declare module 'lodash' {
  interface Lodash {
    camelCase: (str: string) => string
    snakeCase: (str: string) => string
    kebabCase: (str: string) => string
  }
  const _: Lodash
  export default _
}