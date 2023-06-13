import React, { useRef } from 'react'

const NewToDo: React.FC<{ addTodoHandler: (text: string) => void }> = ({
  addTodoHandler,
}) => {
  const todoTextInputRef = useRef<HTMLInputElement>(null)
  const submitHandler = (evt: React.FormEvent) => {
    evt.preventDefault()

    const enteredText = todoTextInputRef.current!.value

    if (enteredText.trim().length === 0) {
      return
    }

    addTodoHandler(enteredText)
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
