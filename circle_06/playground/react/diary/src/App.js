import { useRef, useState } from 'react'
import './App.css'
import DiaryEdit from './DiaryEdit'
import DiaryList from './DiaryList'
import LifeCycle from './LifeCycle'

// const dummyList = [
//   {
//     id: 1,
//     author: 'js',
//     content: 'hello world',
//     emotion: 5,
//     created_date: new Date().getTime(),
//   },
//   {
//     id: 2,
//     author: 'hello',
//     content: 'hello world',
//     emotion: 2,
//     created_date: new Date().getTime(),
//   },
//   {
//     id: 3,
//     author: 'babo',
//     content: 'hello world',
//     emotion: 5,
//     created_date: new Date().getTime(),
//   },
//   {
//     id: 4,
//     author: 'jjj',
//     content: 'hello world',
//     emotion: 1,
//     created_date: new Date().getTime(),
//   },
// ]

function App() {
  const [data, setData] = useState([])

  const itemId = useRef(0)
  const onCreate = (author, content, emotion) => {
    const created_date = new Date().getTime()
    console.log(created_date)
    const newItem = {
      author,
      content,
      emotion,
      created_date,
      id: itemId.current, //그냥 let으로 한다면 리렌더링 되면서 변수가 초기화 되기 때문에 이와 같이 사용
    }
    itemId.current += 1
    setData([newItem, ...data])
  }

  const onRemove = targetID => {
    const newArr = data.filter(itr => itr.id !== targetID) //  targetID와 일치하지 않는 새로운 배열 리턴
    setData(newArr)
  }

  const onEdit = (id, newContent) => {
    setData(
      data.map(itr => (itr.id === id ? { ...itr, content: newContent } : itr))
    )
  }
  return (
    <div className='App'>
      <LifeCycle />
      <DiaryEdit onCreate={onCreate} />
      <DiaryList diaryList={data} onRemove={onRemove} onEdit={onEdit} />
    </div>
  )
}

export default App
