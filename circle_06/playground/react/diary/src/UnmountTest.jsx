import React, { useEffect } from 'react'

export default function UnmounTest() {
  useEffect(() => {
    console.log('mounted !')
    return () => {
      console.log('unmounted !')
    }
  }, [])
  return <div>unmount test</div>
}
