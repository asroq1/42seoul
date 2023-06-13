import React from 'react'
const TodoItem: React.FC<{
  text: string
  onRemoveTodo: (event: React.MouseEvent) => void
}> = ({ text, onRemoveTodo }) => {
  return <li onClick={onRemoveTodo}>{text}</li>
}

export default TodoItem
