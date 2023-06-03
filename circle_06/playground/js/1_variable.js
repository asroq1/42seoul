
// 기본적으로 var, let은 똑같은데 var의 경우에는 아래처럼 재선언이 가능하다. var은 쓰지 말자.
var age = 25;
var age = 30;

// let은 재선언이 불가능하다.
let age = 25;

age = 30

//const는 read-only라서 밑에서 값을 새로 쓰는 것이 불가능하다.
const age = 25;

age = 30;