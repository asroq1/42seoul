// import React from 'react'

// const todo = ({ todoText }) => {
//   const id: string = new Date().toISOString()
//   const text: string = todoText

//   return <div></div>
// }

// export default todo

class Todo {
  id: string
  text: string

  constructor(todoText: string) {
    this.id = new Date().toISOString()
    this.text = todoText
  }
}

export default Todo
