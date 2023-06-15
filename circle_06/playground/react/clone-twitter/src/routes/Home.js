import React, { useEffect, useRef, useState } from 'react'
import {
  addDoc,
  serverTimestamp,
  collection,
  orderBy,
  query,
  onSnapshot,
} from 'firebase/firestore'
import { dbService, storageService } from '../firebase'
import Nweet from '../components/Nweet'
import { ref, uploadString, getDownloadURL } from 'firebase/storage'
import { v4 } from 'uuid'

export default function Home({ userObj }) {
  const [nweet, setNweet] = useState('')
  const [nweets, setNweets] = useState([])
  const [attatchment, setAttatchment] = useState('')

  const fileRef = useRef()

  useEffect(() => {
    const q = query(
      collection(dbService, 'nweets'),
      orderBy('createAt', 'desc')
    )
    onSnapshot(q, snapshot => {
      const newArr = snapshot.docs.map(doc => ({
        id: doc.id,
        ...doc.data(),
      }))
      setNweets(newArr)
    })
  }, [])

  const submitHandler = async evt => {
    evt.preventDefault()

    let attatchmentUrl = ''
    if (attatchment !== '') {
      const fileRef = ref(storageService, `${userObj.uid}/${v4()}`)
      const res = await uploadString(fileRef, attatchment, 'data_url')
      // const file = await res.ref.getDownloadURL(res.ref)
      attatchmentUrl = await getDownloadURL(res.ref)
    }

    const nweetObj = {
      nweet,
      createAt: serverTimestamp(),
      creatorId: userObj.uid,
      attatchmentUrl,
    }

    await addDoc(collection(dbService, 'nweets'), nweetObj)
    setNweet('')
    setAttatchment('')
  }

  const changeHandler = evt => {
    setNweet(evt.target.value)
  }

  const fileHandler = evt => {
    const file = evt.target.files[0]
    const reader = new FileReader()
    reader.onloadend = finishEvt => {
      setAttatchment(finishEvt.currentTarget.result)
    }
    reader.readAsDataURL(file)
  }

  const deleteFileHandler = () => {
    setAttatchment(null)
    fileRef.current.value = ''
  }

  return (
    <>
      <form onSubmit={submitHandler}>
        <input
          value={nweet}
          type='text'
          placeholder='what do you think'
          maxLength={120}
          onChange={changeHandler}
        />
        <input
          type='file'
          accept='image/*'
          onChange={fileHandler}
          ref={fileRef}
        />
        <input type='submit' value='Nweet' />
        {attatchment && (
          <div>
            <img src={attatchment} width='50px' height='50px' />
            <button onClick={deleteFileHandler}>Clear</button>
          </div>
        )}
      </form>
      <div>
        {nweets.map(nweet => (
          <Nweet
            key={nweet.id}
            nweetObj={nweet}
            isOwner={nweet.creatorId === userObj.uid}
          />
        ))}
      </div>
    </>
  )
}
