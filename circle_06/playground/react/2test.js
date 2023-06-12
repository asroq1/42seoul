function fetchDataWithoutAwait() {
  fetch('https://jsonplaceholder.typicode.com/comments')
    .then(response => response.json())
    .then(data => {
      //   console.log(data)
    })
    .catch(error => {
      console.error(error)
    })
}

fetchDataWithoutAwait()
