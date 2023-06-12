// Import the functions you need from the SDKs you need
import { initializeApp } from 'firebase/app'
// TODO: Add SDKs for Firebase products that you want to use
// https://firebase.google.com/docs/web/setup#available-libraries
import { getAuth } from 'firebase/auth'
// Your web app's Firebase configuration
const firebaseConfig = {
  apiKey: 'AIzaSyAdbB0JzQmjPVp6WXzlmPjGEyLn2BKmINI',
  authDomain: 'nwitter-38c6c.firebaseapp.com',
  projectId: 'nwitter-38c6c',
  storageBucket: 'nwitter-38c6c.appspot.com',
  messagingSenderId: '480682457720',
  appId: '1:480682457720:web:5ec5ef5ae1194b76e5cb8d',
}

// Initialize Firebase
export const firebase = initializeApp(firebaseConfig)

export const firebaseInstance = firebase

export const authService = getAuth()
