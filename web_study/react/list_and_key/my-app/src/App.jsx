import { useState } from 'react'
import './App.css'

function App() {
  const [inputValue, setInputValue] = useState()
  const [list, setList] = useState([
    {
      id: 1,
      value: '42',
    },
    {
      id: 2,
      value: 'seoul',
    },
  ])

  const changeInputValue = evt => {
    setInputValue(evt.target.value)
  }

  const addToList = () => {
    setList(prevList => {
      return [{ id: list.length + 1 + '', value: inputValue }, ...prevList]
    })
    setInputValue('')
  }

  return (
    <>
      <input type='text' onChange={changeInputValue} />
      <button onClick={addToList}>추가</button>
      <ul>
        {list.map(item => {
          return <li key={item.id}>{item.value}</li>
        })}
      </ul>
    </>
  )
}

export default App
