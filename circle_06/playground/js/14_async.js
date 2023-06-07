
function delay(ms){
	return new Promise((res) =>{
		setTimeout(res , ms);
	})
}

async function asynFunc(){
	await delay(3000);
	return "this is async";
}

async function main(){
	const res = await asynFunc();
	console.log(res);
}

main();