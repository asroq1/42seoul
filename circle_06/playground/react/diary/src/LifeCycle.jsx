import React, { useEffect, useState } from 'react'

export default function LifeCycle() {
  const [count, setCount] = useState(0)
  const [text, setText] = useState('')

  // []같은 의존성은 해당 데이터가 변경되면 마운트
  // 이와 같은 첫 렌더 상태에서만 렌더링 된다.
  useEffect(() => {
    console.log('Mount')
  }, [])

  useEffect(() => {
    console.log('Update')
  })

  // 얘는 count가 변경되는 시점에 렌더
  useEffect(() => {
    console.log(`${count}입니다`)
    if (count > 5) {
      console.log(`${count} 가 5를 넘었습니다. 1로 초기화 합니다`)
      setCount(1)
    }
  }, [count])

  // 얘는 text가 변경되는 시점에 렌더
  useEffect(() => {
    console.log(`text is updated : ${text}`)
  }, [text])

  return (
    <div style={{ padding: 20 }}>
      <div>
        {count}
        <button onClick={() => setCount(count + 1)}>+</button>
      </div>
      <div>
        <textarea onChange={e => setText(e.target.value)}></textarea>
      </div>
    </div>
  )
}
