import React from 'react'
import MeetupForm from '../../components/meetups/NewMeetupForm'

export default function NewMeetupPage() {
  const addMeetupHandler = meetupData => {
    console.log(meetupData)
  }
  return <MeetupForm onAddMeetup={addMeetupHandler} />
}
