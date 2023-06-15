import { useEffect, useState } from 'react'
import './App.css'
import AppRouter from './Router'
import { getAuth, onAuthStateChanged } from 'firebase/auth'
import { authService } from '../firebase'

function App() {
  const [init, setInit] = useState(false)
  const [isLoggedIn, setIsLoggedIn] = useState(false)
  const [userObj, setUserObj] = useState(null)
  const [newName, setNewName] = useState('')

  const refreshUser = () => {
    // const user = authService.currentUser
    // setNewName(user.displayName)
    setNewName(userObj.displayName)
  }

  useEffect(() => {
    const auth = getAuth()
    onAuthStateChanged(auth, user => {
      if (user) {
        setIsLoggedIn(true)
        setUserObj(user)
      } else {
        setIsLoggedIn(false)
        setUserObj(null)
      }
      setInit(true)
    })
  })
  return (
    <>
      {init ? (
        <AppRouter
          isLoggedIn={isLoggedIn}
          userObj={userObj}
          newName={newName}
          refreshUser={refreshUser}
        />
      ) : (
        'initializing...'
      )}
    </>
  )
}

export default App
