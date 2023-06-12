import React, { useState } from 'react'
import {
  getAuth,
  createUserWithEmailAndPassword,
  signInWithEmailAndPassword,
  GoogleAuthProvider,
  signInWithPopup,
} from 'firebase/auth'

import { authService } from '../firebase'
export default function Auth() {
  const [value, setValue] = useState({
    email: '',
    password: '',
  })
  const [newAccount, setNewAccount] = useState(true)
  const [error, setError] = useState('')
  const handleValue = e => {
    const { name, value } = e.target
    if (name === 'email') {
      setValue(prev => ({
        ...prev,
        email: value,
      }))
    } else if (name === 'password') {
      setValue(prev => ({
        ...prev,
        password: value,
      }))
    }
  }
  const handlerSocial = async e => {
    let provider = new GoogleAuthProvider()

    await signInWithPopup(authService, provider)
  }

  const handleSubmit = async e => {
    e.preventDefault()
    try {
      let data
      const auth = getAuth()
      if (newAccount) {
        data = await createUserWithEmailAndPassword(
          auth,
          value.email,
          value.password
        )
      } else {
        data = await signInWithEmailAndPassword(
          auth,
          value.email,
          value.password
        )
      }
    } catch (err) {
      setError(err.message)
    }
  }
  const toggleAccount = () => {
    setNewAccount(prev => !prev)
  }
  return (
    <div>
      <form onSubmit={handleSubmit}>
        <input
          onChange={handleValue}
          value={value.email}
          required
          placeholder='email'
          name='email'
          type='email'
        />
        <input
          onChange={handleValue}
          value={value.password}
          required
          placeholder='password'
          name='password'
          type='password'
        />
        <input type='submit' value={newAccount ? 'Creat Account' : 'Log In'} />
        {error}
      </form>
      <span onClick={toggleAccount}>
        {newAccount ? 'Create Account' : 'Log in'}
      </span>
      <button onClick={handlerSocial}>Continue with google </button>
    </div>
  )
}
