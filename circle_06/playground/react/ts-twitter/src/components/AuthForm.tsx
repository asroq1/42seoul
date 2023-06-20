import {
  createUserWithEmailAndPassword,
  getAuth,
  signInWithEmailAndPassword,
} from 'firebase/auth'
import React, { useState, ChangeEvent, FormEvent } from 'react'

const AuthForm = () => {
  const [newAccount, setNewAccount] = useState(true)

  const [value, setValue] = useState({
    email: '',
    password: '',
  })

  const toggleAccount = () => {
    setNewAccount(prev => !prev)
  }

  const [error, setError] = useState('')

  const handleValue = (e: ChangeEvent<HTMLInputElement>) => {
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
  const handleSubmit = async (e: FormEvent<HTMLFormElement>) => {
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
    } catch (err: any) {
      setError(err.message)
    }
  }
  return (
    <form onSubmit={handleSubmit}>
      <input
        onChange={handleValue}
        value={value.email}
        required
        placeholder='email'
        name='email'
        type='email'
      />
      <div className='authBtns'></div>
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
      <span onClick={toggleAccount}>
        {newAccount ? 'Create Account' : 'Log in'}
      </span>
    </form>
  )
}

export default AuthForm
