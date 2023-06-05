
// 1. 첫 번째 실행
function taskA(a, b, callback){
	console.log("in a");
// 1-1. web api로 넘겨줌
	setTimeout(() => {
	console.log("set time a");
		const res = a + b;
		callback(res);
	}, 3000);
// 1-2.callback queue에 들어간 콜백 함수를 3초 이후에 event loop에 감지된 콜백함수를 callstack에 올리고 수행
}

// 2. 두 번째 실행
function taskB(a, callback){
	console.log("in b");
// 2-1. web api로 넘겨줌
	setTimeout(() => {
		const res = a * 2;
		callback(res);
	}, 1000);
// 2-2. callback queue에 들어간 콜백 함수를1초 이후에 event loop에 감지된 콜백함수를 callstack에 올리고 수행

}

// 3. 세 번째 실행
function taskC(a, callback){
	console.log("in c");
// 3-1. webApi로 넘겨줌
	setTimeout(() => {
	console.log("set time c");
		const res = a * -1;
		callback(res);
	}, 2000);
// 3-2.callback queue에 들어간 콜백 함수를 2초 이후에 event loop에 감지된 콜백함수를 callstack에 올리고 수행

}

taskA(3, 4, res =>{
	console.log("a res : ", res);
})


taskB(7, res =>{
	console.log("b res : ", res);
})


taskC(14, res =>{
	console.log("c res : ", res);
})

// 4. 네 번째 실행
console.log("end...");