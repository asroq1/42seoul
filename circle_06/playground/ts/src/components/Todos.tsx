import React from 'react'
import Todo from '../models/Todo'
import TodoItem from './TodoItem'

const Todos: React.FC<{
  items: Todo[]
  onRemoveTodo: (id: string) => void
}> = ({ items, onRemoveTodo }) => {
  return (
    <ul>
      {items.map(item => (
        <TodoItem
          key={item.id}
          text={item.text}
          onRemoveTodo={onRemoveTodo.bind(null, item.id)}
        />
      ))}
    </ul>
  )
}

export default Todos
