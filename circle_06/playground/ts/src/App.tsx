import React, { useState } from 'react'
import './App.css'
import Todo from './models/Todo'
import Todos from './components/Todos'
import NewToDo from './components/NewToDo'

function App() {
  // const todos = [new Todo('Hello Wolrd 42'), new Todo('Good Bye 42')]

  const [todos, setTodos] = useState<Todo[]>([])

  const addTodoHandler = (text: string) => {
    const newTodo = new Todo(text)
    setTodos(curr => {
      return curr.concat(newTodo)
    })
  }

  const removeHandler = (id: string) => {
    const updatedTodos = todos.filter(obj => obj.id !== id)
    return setTodos(updatedTodos)
  }

  return (
    <div className='App'>
      <NewToDo addTodoHandler={addTodoHandler} />
      <Todos items={todos} onRemoveTodo={removeHandler} />
    </div>
  )
}

export default App
