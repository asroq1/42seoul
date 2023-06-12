import React, { useState } from 'react'

const CountView = React.memo(({ count }) => {
  console.log(`count : ${count}`)

  return <div>{count}</div>
})

const ObjView = React.memo(({ obj }) => {
  console.log(`obj cnt : ${obj.count}`)
  return <div>{obj.count}</div>
})

const areEqual = (prev, next) => {
  if (prev.obj.count === next.obj.count) {
    console.log('true')
    return true
  }
  return false
}

const MemorizedB = React.memo(ObjView, areEqual)

export default function OptimizeTest() {
  const [count, setCount] = useState(1)
  const [obj, setObj] = useState({
    count: 2,
  })

  return (
    <div style={{ padding: 50 }}>
      <div>
        <h2>Counter A</h2>
        <button
          onClick={() => {
            setCount(count)
          }}
        >
          click here
        </button>
        <CountView count={count} />
      </div>
      <div>
        <h2>Counter B :</h2>
        <button
          onClick={() => {
            setObj({
              count: obj.count,
            })
          }}
        >
          click here
        </button>
        <MemorizedB obj={obj} />
      </div>
    </div>
  )
}
