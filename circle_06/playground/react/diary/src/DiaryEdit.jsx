import React, { useRef, useState } from 'react'

export default function DiaryEdit({ onCreate }) {
  const [state, setState] = useState({
    author: '',
    content: '',
    emotion: 1,
  })

  const authorRef = useRef()
  const contentRef = useRef()

  const handleChangeState = e => {
    setState({
      ...state,
      [e.target.name]: e.target.value,
    })
  }

  const handleSubmit = () => {
    //작성자 최소 1글자
    if (state.author.length < 1) {
      authorRef.current.focus()
      return
    }
    //본문 최소 5글자
    if (state.content.length < 5) {
      contentRef.current.focus()
      return
    }
    onCreate(state.author, state.content, state.emotion)
    alert('저장 성공')
    setState({
      author: '',
      content: '',
      emotion: 1,
    })
  }

  return (
    <div className='DiaryEditor'>
      <h2>오늘의 일기</h2>
      <div>
        <input
          ref={authorRef}
          value={state.author}
          name='author'
          onChange={e => handleChangeState(e)}
        />
      </div>
      <div>
        <textarea
          name='content'
          ref={contentRef}
          value={state.content}
          onChange={e => handleChangeState(e)}
        />
      </div>
      <div>
        <select
          name='emotion'
          value={state.emotion}
          onChange={e => handleChangeState(e)}
        >
          <option value={1}>1</option>
          <option value={2}>2</option>
          <option value={3}>3</option>
          <option value={4}>4</option>
          <option value={5}>5</option>
        </select>
      </div>
      <div>
        <button onClick={handleSubmit}>저장하기</button>
      </div>
    </div>
  )
}
