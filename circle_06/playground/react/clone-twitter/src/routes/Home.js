import React, { useEffect, useState } from 'react'
import { collection, orderBy, query, onSnapshot } from 'firebase/firestore'
import { dbService } from '../firebase'
import Nweet from '../components/Nweet'
import NweetFactory from '../components/NweetFactory'

export default function Home({ userObj }) {
  const [nweets, setNweets] = useState([])

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

  return (
    <>
      <NweetFactory userObj={userObj} />
      <div className='container'>
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
