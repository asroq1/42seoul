const express = require('express')
const cookieParser = require('cookie-parser')
const cors = require('cors')

const app = express()
const server = require('http').createServer(app)
const io = require('socket.io')(server, {
  cors: {
    origin: 'http://localhost:3000',
    methods: ['GET'],
    credentials: true,
  },
})
// CORS 설정
// app.use(
//   cors({
//     origin: 'http://localhost:3000', // 허용할 클라이언트의 도메인 주소
//     methods: ['GET'], // 허용할 HTTP 메서드
//     credentials: true, // 인증 정보를 함께 보낼지 여부
//   })
// )
app.use(cookieParser())

io.on('connect', socket => {
  console.log('클라이언트가 연결되었습니다.')

  socket.on('checkLoginStatus', () => {
    console.log('로그인 상태 확인 요청을 수신했습니다.')

    // 로그인 상태 확인 로직
    const isLoggedIn = true

    // 로그인 상태를 클라이언트에게 전달
    socket.emit('loginStatus', isLoggedIn)
  })

  socket.on('disconnect', () => {
    console.log('클라이언트가 연결이 종료되었습니다.')
    // 클라이언트가 연결을 종료할 때 필요한 로직을 구현합니다.
  })
})

function checkLoggedInStatus(cookieString) {
  // 인증 쿠키가 있는지 여부를 확인하여 로그인 상태를 판단합니다.
  const cookies = cookieParser.parse(cookieString)
  const authenticationCookie = cookies.auth // 인증 쿠키 이름을 'auth'로 가정

  return true
  // if (authenticationCookie) {
  //   // 인증 쿠키가 존재하면 로그인 상태로 판단
  //   return true
  // } else {
  //   // 인증 쿠키가 존재하지 않으면 로그아웃 상태로 판단
  //   return false
  // }
}

app.get('/', (req, res) => {
  res.sendFile(__dirname + '/index.html')
})

server.listen(3001, () => {
  console.log('웹소켓 서버가 3001 포트에서 실행 중입니다.')
})
