
// js는 골때리게도 아래와 같은 예제를 console.log로 연산하면 추측하기 어려운 결과가 나온다. 
let numA= 10;
let numB = "2";

// 숫자20이 나옴. 자동적으로 형변환 해서 곱산 연셈 수행. 
console.log(numA * numB);
// 그러나 + 를 한다면 문자열 102가 나옴.
console.log(numA + numB);
// 우리가 원하던 연산을 하기 위해 parseInt()라는 함수를 이용해 숫자를 만들 수 있다. 숫자 12가 나옴.
console.log(numA + parseInt(numB));


//아래 같은 경우에는 null이 아닌 undefined가 나온다.
let variable;

console.log(variable);

// null로 초기화를 아래처럼 해줘야함.
variable = null;
console.log(variable);

// 템플릿 리터럴 문자열 예
let name = "홍길동";

let backtick = `템플릿 문자열 입니다.
줄바꿈도 가능합니다.
나의 이름은 ${name} 입니다.`;

console.log(backtick);

// 결과) 이처럼 변수의 값을 ${}를 활용해 출력할 수 있다.
// 템플릿 문자열 입니다.
// 줄바꿈도 가능합니다.
// 나의 이름은 홍길동 입니다.

