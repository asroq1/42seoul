import React from 'react'
import { FontAwesomeIcon } from '@fortawesome/react-fontawesome'
import { GoogleAuthProvider, signInWithPopup } from 'firebase/auth'

import { faTwitter } from '@fortawesome/free-brands-svg-icons'

import { authService } from '../firebase'
import AuthForm from '../components/AuthForm'
export default function Auth() {
  const handlerSocial = async e => {
    let provider = new GoogleAuthProvider()

    await signInWithPopup(authService, provider)
  }

  return (
    <div className='authContainer'>
      <FontAwesomeIcon
        icon={faTwitter}
        color={'#04AAFF'}
        size='3x'
        style={{ marginBottom: 30 }}
      />
      <AuthForm />
      <div className='authBtns'>
        <button onClick={handlerSocial} className='authBtn'>
          Continue with google{' '}
        </button>
      </div>
    </div>
  )
}
