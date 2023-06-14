import React, { useContext } from 'react'
import Todo from '../models/Todo'
import TodoItem from './TodoItem'
import { TodosContext } from '../store/todos-context'

const Todos: React.FC = () => {
  const todosContext = useContext(TodosContext)

  return (
    <ul>
      {todosContext.items.map(item => (
        <TodoItem
          key={item.id}
          text={item.text}
          onRemoveTodo={todosContext.removeTodo.bind(null, item.id)}
        />
      ))}
    </ul>
  )
}

export default Todos
