import React, { useEffect, useState } from 'react'
import { authService, dbService } from '../firebase'
import { useNavigate } from 'react-router-dom'
import { collection, getDocs, orderBy, query, where } from 'firebase/firestore'
import { updateProfile } from 'firebase/auth'

export default function Profile({ userObj, newName, refreshUser }) {
  const [newDisplayName, setnewDisplayName] = useState(userObj.displayName)
  const navigate = useNavigate()
  const handleLogOutClick = () => {
    authService.signOut()
    navigate('/')
  }

  const getMyNweets = async () => {
    const q = query(
      collection(dbService, 'nweets'),
      where('creatorId', '==', userObj.uid),
      orderBy('createAt', 'desc')
    )
    const querySnapshot = await getDocs(q)
    querySnapshot.forEach(doc => {})
  }

  useEffect(() => {
    getMyNweets()
  }, [])

  const submitHandler = async evt => {
    evt.preventDefault()
    if (userObj.displayName !== newDisplayName) {
      await updateProfile(userObj, { displayName: newDisplayName })
    }
    // if (newName !== userObj.displayName) {
    //   await updateProfile(userObj, { displayName: newName })
    // }
    refreshUser()
  }
  const changeHandler = evt => {
    setnewDisplayName(evt.target.value)
  }
  return (
    <>
      <form onSubmit={submitHandler}>
        <input
          onChange={changeHandler}
          type='text'
          placeholder='Display name '
          value={newDisplayName}
        />
        <input type='submit' value='Update Profile' />
      </form>
      <button onClick={handleLogOutClick}>Log Out</button>
    </>
  )
}
