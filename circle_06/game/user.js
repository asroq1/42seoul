// // 내 패들

// const user = {
//   x: 0,
//   y: canvas.height / 2 - 100 / 2,
//   width: 10,
//   height: 100,
//   color: 'WHITE',
//   score: 0,
// }

// // 컴퓨터 패들
// const com = {
//   x: canvas.width - 10,
//   y: canvas.height / 2 - 100 / 2,
//   width: 10,
//   height: 100,
//   color: 'WHITE',
//   score: 0,
// }

// // 가운데 넷
// const net = {
//   x: canvas.width / 2 - 2 / 2,
//   y: 0,
//   width: 2,
//   height: 10,
//   color: 'WHITE',
// }

// const ball = {
//   x: canvas.width / 2,
//   y: canvas.height / 2,
//   radious: 10,
//   speed: 5,
//   velocityX: 5,
//   velocityY: 5,
//   color: 'WHITE',
// }

// function drawNet() {
//   for (let index = 0; index < canvas.height; index++) {
//     drawRect(net.x, net.y + i, net.width, net.height, net.color)
//   }
// }

// function update() {
//   ball.x += velocityX
//   ball.y += velocityY
//   if (ball.y + ball.radious > canvas.height || ball.y - ball.radious < 0) {
//     velocityY = -velocityY
//   }
// }

// function collision(b, p) {
//   p.top = p.y
//   p.bottom = p.y + p.height
//   p.left = p.x
//   p.right = p.x + p.width

//   b.top = b.y - b.radious
//   b.bottom = b.y + b.radious
//   b.left = b.x - b.radious

//   return (
//     b.right > p.left && b.top < p.bottom && b.left > p.right && b.bottom > p.top
//   )2
// }

const cvs = document.getElementById('pong')
const ctx = cvs.getContext('2d')

const user = {
  x: 0,
  y: cvs.height / 2 - 100 / 2,
  width: 10,
  height: 100,
  color: 'WHITE',
  score: 0,
}

const com = {
  x: cvs.width - 10,
  y: cvs.height / 2 - 100 / 2,
  width: 10,
  height: 100,
  color: 'WHITE',
  score: 0,
}

const ball = {
  x: cvs.width / 2,
  y: cvs.height / 2,
  radious: 10,
  speed: 5,
  velocityX: 5,
  velocityY: 5,
  color: 'WHITE',
}

const net = {
  x: cvs.width / 2 - 1,
  y: 0,
  width: 2,
  height: 10,
  color: 'WHITE',
}

function drawNet() {
  for (let i = 0; i < cvs.height; i += 15) {
    drawRect(net.x, net.y + i, net.width, net.height, net.color)
  }
}

function drawRect(x, y, w, h, color) {
  ctx.fillStyle = color
  ctx.fillRect(x, y, w, h)
}

drawRect(0, 0, cvs.width, cvs.height, 'BLACK')

function drawCircle(x, y, r, color) {
  ctx.fillStyle = color
  ctx.beginPath()
  ctx.arc(x, y, r, 0, Math.PI * 2, false)
  ctx.closePath()
  ctx.fill()
}

drawCircle(100, 100, 50, 'WHITE')

function drawText(text, x, y, color) {
  ctx.fillStyle = color
  ctx.font = '45px fantasy'
  ctx.fillText(text, x, y)
}

drawText('something', 300, 200, 'WHITE')

function render() {
  // console.log('render')
  drawRect(0, 0, cvs.width, cvs.height, 'BLACK')

  drawNet()

  drawText(user.score, cvs.width / 4, cvs.height / 5, 'WHITE')
  drawText(com.score, (3 * cvs.width) / 4, cvs.height / 5, 'WHITE')

  drawRect(user.x, user.y, user.width, user.height, user.color)
  drawRect(com.x, com.y, com.width, com.height, com.color)

  drawCircle(ball.x, ball.y, ball.radious, ball.color)
}

cvs.addEventListener('mousemove', movePaddle)

function movePaddle(e) {
  // console.log(`evt : ${evt}`)
  let rect = cvs.getBoundingClientRect()
  user.y = e.clientY - rect.top - user.height / 2
}

function collision(b, p) {
  p.top = p.y
  p.bottom = p.y + p.height
  p.left = p.x
  p.right = p.x + p.width

  b.top = b.y - b.radious
  b.bottom = b.y + b.radious
  b.left = b.x - b.radious
  b.right = b.x + b.radious
  return (
    // p.right > b.right &&
    // b.bottom > p.top &&
    // b.left < p.right &&
    // b.top < p.bottom
    p.left < b.right && p.top < b.bottom && p.right > b.left && p.bottom > b.top
  )
}

function resetBall() {
  ball.x = cvs.width / 2
  ball.y = cvs.height / 2

  ball.speed = 5
  ball.velocityX = -ball.velocityX
}
function update() {
  ball.x += ball.velocityX
  ball.y += ball.velocityY

  let computerLevel = 0.1
  com.y += (ball.y - (com.y + com.height / 2)) * computerLevel

  if (ball.y + ball.radious > cvs.height || ball.y - ball.radious < 0) {
    ball.velocityY = -ball.velocityY
  }
  let player = ball.x < cvs.width / 2 ? user : com

  if (collision(ball, player)) {
    // ball.velocityX = -ball.velocityX
    let collidePoint = ball.y - (player.y + player.height / 2)
    collidePoint = collidePoint / (player.height / 2)

    let angleRad = (collidePoint * Math.PI) / 4
    let direction = ball.x < cvs.width / 2 ? 1 : -1

    ball.velocityX = direction * ball.speed * Math.cos(angleRad)
    ball.velocityY = ball.speed * Math.sin(angleRad)

    ball.speed += 0.5
  }
  if (ball.x - ball.radious < 0) {
    com.score++
    resetBall()
  } else if (ball.x + ball.radious > cvs.width) {
    user.score++
    resetBall()
  }
}
function game() {
  update()
  render()
}

const framePerSecond = 50
setInterval(game, 1000 / framePerSecond)
