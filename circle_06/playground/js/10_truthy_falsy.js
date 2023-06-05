
// 대표적인 truthy 들이다. 얘들은 다 조건문에서true
let a = [];
let b = {};
let c = 42;
let d = "42";


// 대표적인 falsy 들이다. 얘들은 다 조건문에서 false
let e = null;
let f = "";
let g = undefined;

if(a){
	console.log("true");
}
else {
	console.log("false");
}

// falsy속성을 이용해 에러 처리하는 방법
const getName = person =>{
	if(!person)
	{
		return console.log("not person");
	}
	return person.name;
}

let person;
const name = getName(person);
console.log(name);