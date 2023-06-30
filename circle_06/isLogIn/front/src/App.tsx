import React, { useEffect, useState } from 'react'
import io from 'socket.io-client'

const socket = io('http://localhost:3001') // 웹소켓 서버 주소에 맞게 수정

function App() {
  const [isLoggedIn, setIsLoggedIn] = useState(false)

  useEffect(() => {
    // 웹소켓에 연결되었을 때
    socket.on('connect', () => {
      console.log('웹소켓에 연결되었습니다.')

      // 로그인 상태 확인 요청
      socket.emit('checkLoginStatus')
    })

    // 로그인 상태 수신
    socket.on('loginStatus', status => {
      console.log('로그인 상태를 수신했습니다.')
      setIsLoggedIn(status)
    })

    // 웹소켓 연결이 종료되었을 때
    socket.on('disconnect', () => {
      console.log('웹소켓 연결이 종료되었습니다.')
    })

    // 컴포넌트 언마운트 시 웹소켓 연결 종료
    return () => {
      socket.disconnect()
    }
  }, [])

  return (
    <div>
      <h1>친구 로그인 상태 확인</h1>
      <div id='status'>
        {isLoggedIn
          ? '친구가 로그인한 상태입니다.'
          : '친구가 로그아웃한 상태입니다.'}
      </div>
    </div>
  )
}

export default App
