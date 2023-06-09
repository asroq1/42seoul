import React, { useRef, useState } from 'react'

export default function DiaryItem({
  author,
  content,
  emotion,
  created_date,
  id,
  onRemove,
  onEdit,
}) {
  const localInput = useRef()
  const toggleIsEdit = () => {
    setIsEdit(!isEdit)
  }
  const [localContent, setLocalContent] = useState(content)
  const [isEdit, setIsEdit] = useState(false)

  const handleRemove = () => {
    if (window.confirm(`${id} 게시물을 삭제하시겠습니까 ?`)) {
      onRemove(id)
    }
  }
  const handleQuitEdit = () => {
    setIsEdit(false)
    setLocalContent(content)
  }

  const handleEdit = () => {
    if (localContent.length < 5) {
      localInput.current.focus()
    }
    if (window.confirm(`${id}번째 게시물을 수정하시겠어요?`))
      onEdit(id, localContent)
    toggleIsEdit()
  }
  return (
    <div className='DiaryItem'>
      <div className='info'>
        <span>
          작성자 : {author} | 감정 : {emotion}
        </span>
        <br />
        <span className='date'>
          {new Date(created_date).toLocaleDateString()}
        </span>
      </div>
      <div className='content'>
        {isEdit ? (
          <>
            <textarea
              ref={localInput}
              value={localContent}
              onChange={e => setLocalContent(e.target.value)}
            ></textarea>
          </>
        ) : (
          <>{content}</>
        )}
      </div>
      {isEdit ? (
        <>
          <button onClick={handleQuitEdit}>수정 취소</button>
          <button onClick={handleEdit}>수정 완료</button>
        </>
      ) : (
        <>
          <button onClick={handleRemove}>삭제</button>
          <button onClick={toggleIsEdit}>수정</button>
        </>
      )}
    </div>
  )
}
