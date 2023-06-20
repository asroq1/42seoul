import { initializeApp } from 'firebase/app'
import { getAuth } from 'firebase/auth'
import 'firebase/firestore'
import { getFirestore } from 'firebase/firestore'
import { getStorage } from 'firebase/storage'

const firebaseConfig = {
  apiKey: 'AIzaSyAdbB0JzQmjPVp6WXzlmPjGEyLn2BKmINI',
  authDomain: 'nwitter-38c6c.firebaseapp.com',
  projectId: 'nwitter-38c6c',
  storageBucket: 'nwitter-38c6c.appspot.com',
  messagingSenderId: '480682457720',
  appId: '1:480682457720:web:5ec5ef5ae1194b76e5cb8d',
}

export const firebase = initializeApp(firebaseConfig)

export const firebaseInstance = firebase

export const authService = getAuth()

export const dbService = getFirestore()

export const storageService = getStorage()
