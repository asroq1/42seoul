import React from 'react'
import MeetupList from '../components/meetups/MeetupList'

const dummyData = [
  {
    id: 'm1',
    title: 'first meet up',
    image:
      'https://english.seoul.go.kr/wp-content/uploads/2019/11/yangjae-citizens-forest-9.jpg',
    address: 'yang jae dong',
    description: 'first meet up',
  },
  {
    id: 'm2',
    title: 'second meet up',
    image:
      'https://english.seoul.go.kr/wp-content/uploads/2019/11/yangjae-citizens-forest-9.jpg',
    address: 'yang jae dong',
    description: 'second meet up',
  },
  {
    id: 'm3',
    title: 'third meet up',
    image:
      'https://english.seoul.go.kr/wp-content/uploads/2019/11/yangjae-citizens-forest-9.jpg',
    address: 'yang jae dong',
    description: 'third meet up',
  },
]
export default function HomePage() {
  return <MeetupList meetups={dummyData} />
}
