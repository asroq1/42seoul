
// 콜백함수를 이용하면 이렇게 함수를 파라미터로 받아 호출할 수  있다.
function checkYourFeel(mood, callBack1, callBack2)
{
    if(mood === "happy")
    {
        callBack1();
    }
    else
    {
        callBack2();
    }
}


function happy()
{
    console.log("happy !");
}

function sad()
{
    console.log("sad !");
}

 checkYourFeel("happy", happy, sad);