

// 이렇게 ...를 활용해 중복을 줄일 수 있다.
const cookie = {
	base : "cookie",
	madeIn : "korea",
}


const chocoCookie = {
	...cookie,
	toping : "choco",
}


const strawBerryCookie = {
	...cookie,
	toping : "strawBerry",
}
