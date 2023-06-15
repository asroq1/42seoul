import Home from '../routes/Home'
import Auth from '../routes/Auth'
import { HashRouter as Router, Routes, Route } from 'react-router-dom'
import Navigation from './Navigation'
import Profile from '../routes/Profile'
export default function AppRouter({
  isLoggedIn,
  userObj,
  newName,
  refreshUser,
}) {
  return (
    <Router>
      {isLoggedIn && <Navigation userObj={userObj} />}
      <Routes>
        {isLoggedIn ? (
          <>
            <Route exact path='/' element={<Home userObj={userObj} />} />
            <Route
              exact
              path='/profile'
              element={
                <Profile
                  userObj={userObj}
                  newName={newName}
                  refreshUser={refreshUser}
                />
              }
            />
          </>
        ) : (
          <Route exact path='/' element={<Auth />} />
        )}
      </Routes>
    </Router>
  )
}
