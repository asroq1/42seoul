import Home from '../routes/Home'
import Auth from '../routes/Auth'
import { HashRouter as Router, Routes, Route } from 'react-router-dom'
import Navigation from './Navigation'
import Profile from '../routes/Profile'
export default function AppRouter({ isLoggedIn }) {
  return (
    <Router>
      {isLoggedIn && <Navigation />}
      <Routes>
        {isLoggedIn ? (
          <>
            <Route exact path='/' element={<Home />} />
            <Route exact path='/profile' element={<Profile />} />
          </>
        ) : (
          <Route exact path='/' element={<Auth />} />
        )}
      </Routes>
    </Router>
  )
}
