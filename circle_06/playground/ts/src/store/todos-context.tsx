import React, { useState, ReactNode } from 'react'
import Todo from '../models/Todo'

type TodosContextObj = {
  items: Todo[]
  addTodo: (text: string) => void
  removeTodo: (id: string) => void
}

type TodosContextProviderProps = {
  children: ReactNode
}

export const TodosContext = React.createContext<TodosContextObj>({
  items: [],
  addTodo: () => {},
  removeTodo: (id: string) => {},
})

const TodosContextProvider: React.FC<TodosContextProviderProps> = (
  props: TodosContextProviderProps
) => {
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

  const contextValue: TodosContextObj = {
    items: todos,
    addTodo: addTodoHandler,
    removeTodo: removeHandler,
  }

  return (
    <TodosContext.Provider value={contextValue}>
      {props.children}
    </TodosContext.Provider>
  )
}

export default TodosContextProvider
