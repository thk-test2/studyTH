
// fetch(주소, 옵션)
// 네트워크를 통해 리소스의 요청(Request) 및 응답을 처리할 ㅜㅅ 있습니다.
// Promise 인스턴스를 반환합니다.

fetch('https://www.omdbapi.com/?apikey=7035c60c&s=avengers', {
  method: 'GET',
  headers: {
    'Content-type': 'application/json'
  },
  body: JSON.stringify({
    name: 'THK',
    age: 82,
    email: 'asdf@mail.com'
  })
})
  .then(res => res.json())
  .then((json) => console.log(json))


const wrap = async () => {
  const res = await fetch('https://www.omdbapi.com/?apikey=7035c60c&s=avengers');
  const json = await res.json();
  console.log(json);
}
wrap();
