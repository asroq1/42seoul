import React, { useRef, useState } from 'react'
import { dbService, storageService } from '../firebase'
import { ref, uploadString, getDownloadURL } from 'firebase/storage'
import { v4 } from 'uuid'
import { addDoc, collection, serverTimestamp } from 'firebase/firestore'

const NweetFactory = ({ userObj }) => {
  const [nweet, setNweet] = useState('')
  const [attatchment, setAttatchment] = useState('')
  const fileRef = useRef()

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
      createAt: serverTimestamp,
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
    <form onSubmit={submitHandler} className='factoryForm'>
      <div className='factoryInput__container'>
        <input
          value={nweet}
          type='text'
          placeholder='what do you think'
          maxLength={120}
          onChange={changeHandler}
        />
      </div>

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
  )
}

export default NweetFactory
