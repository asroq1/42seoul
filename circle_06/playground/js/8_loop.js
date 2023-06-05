

const person = {
	name : "hyunjung",
	age : 25
}

const personKeys = Object.keys(person);
console.log(personKeys);

for(let i = 0; i < personKeys.length; i++)
{
	const curKey = personKeys[i];
	const curValue = person[curKey];

	console.log(`curkEY : ${curKey} , curValue ${curValue}`);

}