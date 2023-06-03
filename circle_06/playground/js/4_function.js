
// js에는 함수 선언식, 함수 표현식, 화살표 함수라는 세 가지의 함수 선언법이 있다.
// c, c++을 사용한 사람들에게 익숙한 함수 선언식은 호이스팅을 한다는 특징이 있다.

// 함수 선언식
function helloA()
{
    return "hello A42";
}

console.log(helloA());

// 함수 표현식

let helloB = function(){
    return "hello B42"
}

console.log(helloB());

// 함수 선언식의 호이스팅
// hoist함수가 선언 이전에 호출 되었음에도 결과가 출력되는 것은 함수 선언식은 js엔진이 호이스팅으로 함수를 최상단으로 끌어 올린다.
console.log(Hoist());

function Hoist()
{
    return "what a hoist!";
}

// 그러나 표현식은 불가능 !
console.log(HoistB());

let HoistB = function()
{
    return "what a B hoist!";
}


// 화살표 함수는 표현식을 더 간결하게 표현할 수 있고, 호이스팅이 적용되지 않음

let arrow = () => {
    return "what a arrow !";
}

console.log(arrow());
