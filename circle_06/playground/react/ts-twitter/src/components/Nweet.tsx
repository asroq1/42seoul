import React, { ChangeEvent, FormEvent, useState } from 'react'
import { dbService, storageService } from '../firebase'
import { deleteDoc, doc, updateDoc } from 'firebase/firestore'
import { deleteObject } from 'firebase/storage'
import { ref } from 'firebase/storage'
// import { NweetObj } from '../models/NweetObj'
import NweetObj from '../models/NweetObj'

type NweetProps = {
  nweetObj: NweetObj
  isOwner: boolean
}
const Nweet: React.FC<NweetProps> = ({ nweetObj, isOwner }) => {
  const NweetTextRef = doc(dbService, 'nweets', `${nweetObj.creatorId}`)
  const [editing, setEditing] = useState(false)
  const [newNweet, setNewnweet] = useState(nweetObj.nweet)

  const toggleEditing = () => {
    setEditing(prev => !prev)
  }
  const editHandler = (evt: ChangeEvent<HTMLInputElement>) => {
    setNewnweet(evt.target.value)
  }

  const editSubmitHandler = async (evt: FormEvent<HTMLFormElement>) => {
    evt.preventDefault()
    await updateDoc(NweetTextRef, { nweet: newNweet })
    toggleEditing()
  }
  const deleteHandler = async () => {
    const ok = window.confirm('You sure want to delete it?')
    const urlRef = ref(storageService, nweetObj.attatchmentUrl)
    if (ok) {
      await deleteDoc(NweetTextRef)
      await deleteObject(urlRef)
    }
  }
  console.log(nweetObj)
  return (
    <div key={nweetObj.creatorId}>
      {editing ? (
        <>
          <form onSubmit={editSubmitHandler}>
            <input
              type='text'
              onChange={editHandler}
              placeholder='Edit your nweet'
              value={newNweet}
              required
            />
            <input type='submit' value='Update' />
          </form>
          <button onClick={toggleEditing}>Cancel</button>
        </>
      ) : (
        <>
          <h4>{nweetObj.nweet}</h4>
          {nweetObj.attatchmentUrl && (
            <img
              src={nweetObj.attatchmentUrl}
              alt='img'
              width='50px'
              height='50px'
            />
          )}
          {isOwner && (
            <>
              <button onClick={deleteHandler}>Delete</button>
              <button onClick={toggleEditing}>Edit</button>
            </>
          )}
        </>
      )}
    </div>
  )
}

export default Nweet
