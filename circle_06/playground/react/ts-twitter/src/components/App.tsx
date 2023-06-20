import { useEffect, useState } from 'react'
import './App.css'
import AppRouter from './Router'
import { getAuth, onAuthStateChanged } from 'firebase/auth'
import User from '../models/User'
function App() {
  const [init, setInit] = useState<boolean>(false)
  const [isLoggedIn, setIsLoggedIn] = useState<boolean>(false)
  const [userObj, setUserObj] = useState<User | null>(null)
  const [newName, setNewName] = useState<string | null>('')

  const refreshUser = () => {
    setNewName(userObj?.displayName || null)
  }

  useEffect(() => {
    const auth = getAuth()
    onAuthStateChanged(auth, (user: User | null) => {
      if (user) {
        setIsLoggedIn(true)
        setUserObj(user)
      } else {
        setIsLoggedIn(false)
        setUserObj(null)
      }
      setInit(true)
    })
  }, [])

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
