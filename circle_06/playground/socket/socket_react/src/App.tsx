import { io } from 'socket.io-client'
import './App.css'
import {
  ChangeEvent,
  FormEvent,
  useCallback,
  useEffect,
  useRef,
  useState,
} from 'react'
import IChat from './models/IChat'
import {
  ChatContainer,
  Message,
  MessageBox,
  MessageForm,
} from './styles/app.styles'

// 웹소켓 연결 및 인스턴스 생성, /chat은 namespace
const socket = io('http://localhost:4000/chat')

function App() {
  // 첫 번째 파라미터는 연결할 서버 주소, 두 번째는 쿠키 설정 같은 credentioal,
  // const
  const [chats, setChats] = useState<IChat[]>([])
  const [message, setMessage] = useState<string>('')
  const chatContainerE1 = useRef<HTMLDivElement>(null)

  // 채팅 스크롤 최근 위치로 랠리하기 위함
  useEffect(() => {
    if (!chatContainerE1.current) {
      return
    }

    const chatContainer = chatContainerE1.current
    const { scrollH, clientH } = chatContainer

    if (scrollH > clientH) {
      chatContainer.scrollTop = scrollH - clientH
    }
  }, [chats.length])

  // message 이벤트 핸들러
  useEffect(() => {
    const messageHandler = (chat: IChat) => {
      setChats(prev => [...prev, chat])

      socket.on('message', messageHandler)

      return () => {
        socket.off('message', messageHandler)
      }
    }
  }, [])

  const onChange = useCallback((e: ChangeEvent<HTMLInputElement>) => {
    setMessage(e.target.value)
  }, [])

  const onSendMsg = useCallback(
    (e: FormEvent<HTMLFormElement>) => {
      e.preventDefault()
      if (!message) {
        return alert('메시지를 입력하세요.')
      }
      //emit 1para 이벤트 이름, 2para 전송할 데이터, 3para 콜백 함수로 서버 응답 오면 실행되는 함수
      socket.emit('message', message, (chat: IChat) => {
        setChats(prev => [...prev, chat])
        setMessage('')
      })
    },
    [message]
  )
  return (
    <>
      <h1>WebSocket Chat</h1>
      <ChatContainer ref={chatContainerEl}>
        {chats.map((chat, index) => (
          <MessageBox
            key={index}
            className={classNames({
              my_message: socket.id === chat.username,
              alarm: !chat.username,
            })}
          >
            <span>
              {chat.username
                ? socket.id === chat.username
                  ? ''
                  : chat.username
                : ''}
            </span>
            <Message className='message'>{chat.message}</Message>
          </MessageBox>
        ))}
      </ChatContainer>
      <MessageForm onSubmit={onSendMessage}>
        <input type='text' onChange={onChange} value={message} />
        <button>보내기</button>
      </MessageForm>
    </>
  )
}

export default App
