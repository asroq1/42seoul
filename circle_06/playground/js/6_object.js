
// obj는 아래와 같이 객체 리터럴로 선언할 수 있고, new키워드를 사용해서도 생성할 수 있다.
const person = {
    // key-value쌍으로 이루어짐.
    name : "hyunjung", 
    age : 25
}

console.log(person.name);
console.log(person.age);

// new키워드 ! 그러나 객체 리터럴 사용하는게 더 낫다고 한다.
const person2 = new Object();

// 위에서 만든 const 객체는 신기하게도 read-only이지만 객체의 멤버에 접근이 가능하다.

person.name = "who am i";
person.age = 100;

// 어떻게 이것이 가능하냐면 person이라는 상수를 수정하는 행동이 아닌 객체를 수정하기 때문.
console.log(person.name);
console.log(person.age);

// 그때문에 아래 예제는 실행이 불가능하다.
person = {
    name : "test", 
    age : 2100
}

console.log(person.name);
console.log(person.age);
