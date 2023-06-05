// 이렇게  executor를 활용해 프로미스 객체를 리턴할 수도 있고, 아래 예제처럼 return할 때 생성하는 방법도 있다.
function isPromiseP(number){
	const executor = (resovle, reject) =>{
		setTimeout(() => {
			if(typeof number === "number"){
				console.log(number);
				resovle(number >= 0 ? "양수": "음수");
			}else{
				reject("숫자형 값이 아닙니다.");
			}
		}, (2000));
	};
	const asyncTask = new Promise(executor);
	return asyncTask;
}

const res1 = isPromiseP(101);

res1.then((res) =>{
	console.log(`작업 성공 : $${res}`);

}).catch((err) =>{
	console.log(`작업 실패 : $${err}`);
})


// 이전 콜백 지옥 프로미스로 바꾸기

// 1. 첫 번째 실행
function taskA(a, b){
	return new Promise((resovle, reject) =>{
		setTimeout(() => {
			const res = a + b;
			resovle(res);
		}, 3000);
	});
}

// 2. 두 번째 실행
function taskB(a){
	return new Promise((resovle, reject) =>{
		setTimeout(() => {
			const res = a * 2;
			resovle(res);
		}, 1000);
	})
}

// 3. 세 번째 실행
function taskC(a){
	return new Promise((resolve, reject) =>{
		setTimeout(() => {
			const res = a * -1;
			resolve(res);
		}, 2000);
	})
}

const res = taskA(5, 1).then(res =>{
	console.log(`a 리턴 값은 ${res}`);
	return taskB(res);
}).then(res => {
	console.log(`b 리턴 값은 ${res}`);
	return taskC(res);
}).then(res => {
	console.log(`c 리턴 값은 ${res}`);

})

