import React from 'react'
import { authService } from '../firebase'
import { useNavigate } from 'react-router-dom'

export default function Profile() {
  const navigate = useNavigate()
  const handleLogOutClick = () => {
    authService.signOut()
    navigate('/')
  }
  return (
    <div>
      profile
      <button onClick={handleLogOutClick}>Log Out</button>
    </div>
  )
}
