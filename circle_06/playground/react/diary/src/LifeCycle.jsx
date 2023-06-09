import React, { useState } from 'react'
import UnmountTest from './UnmountTest'

export default function LifeCycle() {
  const [isVisible, setIsvisible] = useState(false)

  const toggle = () => {
    setIsvisible(!isVisible)
  }
  return (
    <div style={{ padding: 20 }}>
      <button onClick={toggle}>ON/OFF</button>
      {isVisible && <UnmountTest />}
    </div>
  )
}
