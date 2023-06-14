import React, { useContext, useRef } from 'react'
import { TodosContext } from '../store/todos-context'

const NewToDo: React.FC = () => {
  const todosContext = useContext(TodosContext)
  const todoTextInputRef = useRef<HTMLInputElement>(null)
  const submitHandler = (evt: React.FormEvent) => {
    evt.preventDefault()

    const enteredText = todoTextInputRef.current!.value

    if (enteredText.trim().length === 0) {
      return
    }

    todosContext.addTodo(enteredText)
  }

  return (
    <form onSubmit={submitHandler}>
      <label htmlFor='text'>Todo text </label>
      <input type='text' id='text' ref={todoTextInputRef} />
      <button>Add Todo</button>
    </form>
  )
}

export default NewToDo
