
// forEach() 배열의 값을 바꾸지는 못한다. 각 엘리먼트마다 출력하는 예제
const arr = [2, 4 , 6 ,8];
arr.forEach(
	ele => {
		console.log(ele * 2); 
	});
// map() 만약 각 엘리먼트의 값을 변경하고 싶다면 map을 사용할 수 있다.
const arr1 = [2, 4 , 6 ,8];

const newArr = arr.map(
	ele => {
		return ele * 2; 
	});

// includes() true or false로 배열 내에 원하는 값이 있다면 bool리턴.

const arr2 = [2, 4 ,6];

arr2.includes(2); //true

arr2.includes("4"); //false 얘는 ===로 자료형까지 비교하기 때문에 false


// indexOf() 해당 요소의 인덱스 번호를 리턴해준다

const tmp = [1, 2 , 3, 4 , 5];

const n = 3;

console.log(tmp.indexOf(n)); // 3의 인덱스 번호인 2가 나온다.

// findIndex() GOE


const arr3 = [
	{color : "red"},
	{color : "blue"},
	{color : "green"},
]

console.log(arr3.findIndex(ele => {
	return ele.color === "red"; // 0
}))

// find() findIndex처럼 idx가 아닌 요소 자체를 반환한다.

const arr4 = [
	{color : "red"},
	{color : "blue"},
	{color : "green"},
]

console.log(arr4.find(ele => {
	return ele.color === "red"; // 0
}))


// filter() 전달한 콜백을 필터링 하고 싶다면 사용하면 된다.

const arr5 = [
	{idx : 1,color : "red"},
	{idx : 2,color : "blue"},
	{idx : 3,color : "green"},
]

console.log(arr5.filter(ele => {
	return ele.idx === 1; // idx1을 가진 배열 {idx : 1,color : "red"}을 리턴한다. 
}))

// slice(start, end) start부터 end-1까지 잘라서 새로 리턴해준다.

const arr6 = [
	{idx : 1,color : "red"},
	{idx : 2,color : "blue"},
	{idx : 3,color : "green"},
	{idx : 4,color : "green"},
	{idx : 5,color : "green"},

]

console.log(arr6.slice(0,2)); // [ { idx: 1, color: "red" }, { idx: 2, color: "blue" } ]를 출력한다.

// arr.1concat(arr2) arr1에 잘린 arr2 배열을 붙여줌

const arr7 = [
	{idx : 1,color : "red"},
	{idx : 2,color : "blue"},
	{idx : 3,color : "green"},
	{idx : 4,color : "green"},
	{idx : 5,color : "green"},

]
const arr8 = [
	{idx : 6,color : "red"},
	{idx : 7,color : "blue"},
]

arr7.concat(arr8); // 

console.log(arr7);

// arr7 + arr8이 합쳐진 arr7이 리턴된다. 
//[
//  { idx: 1, color: 'red' },
//  { idx: 2, color: 'blue' },
//  { idx: 3, color: 'green' },
//  { idx: 4, color: 'green' },
//  { idx: 5, color: 'green' },
//  { idx: 6, color: 'red' },
//  { idx: 7, color: 'blue' }
//]


// sort() 새로운 배열을 리턴하는게 아닌 원본을 수정해줌

let numbers = [10 , 2, 5, 7, 9];

const compare = (a, b) => {
	return a - b; //sort가 유니코드를 기준으로 정렬하기 때문에 이런 식으로 오름차순 및 내림차순 정렬이 가능함
}

numbers.sort(compare);

console.log(numbers);

// join() 여러 문자열을 합쳐준다.

const str = ["hello" , " world", "42"];

str.join("?!?!");

console.log(str);

//"hello?!?!world?!?!42"
//["hello", "world", "42"] //기존의 str은 그대로 유지되고 출력은 ?!?!가 붙은 새로운 문자열이 나온다.
