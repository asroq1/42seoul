const { log } = require('console')
const express = require('express')
const app = express()
const http = require('http')
const server = http.createServer(app)
const { Server } = require('socket.io')
const io = new Server(server)

function findSocketByUserId(userId) {
  const connectedSockets = Object.values(io.sockets.connected)
  return connectedSockets.find(socket => socket.userId === userId)
}
app.set('port', 9000)

app.use((req, res, next) => {
  res.header('Access-Control-Allow-Origin', 'http://localhost:3000')
  res.header('Access-Control-Allow-Methods', 'GET, POST')
  res.header('Access-Control-Allow-Headers', 'Content-Type')
  next()
})

app.get('/', (req, res) => {
  res.sendFile(__dirname + '/index.html')
})

server.listen(9000, () => {
  console.log('listening on *:9000')
})

let socketList = []
let i = 1
io.on('connection', function (socket) {
  i++
  socketList.push(socket)
  console.log(`id : ${i} ${socket.id} joined`)

  socket.on('SEND', function (msg) {
    socketList.forEach(function (item, i) {
      console.log(`item is ${item.id}`)
      if (item != socket) {
        item.emit('SEND', msg)
      }
    })
  })

  socket.on('disconnect', function () {
    socketList.splice(socketList.indexOf(socket), 1)
  })
})
