//generics

// template처럼 자료형 때문에 여러 함수를 만들 필요성이 없어진다.

const insertBegining = <T>(array: T[], value: T): T[] => {
  const newArr = [value, ...array]
  return newArr
}

const intArr = [4, 6, 8]

const newIntArr = insertBegining(intArr, 1)

const strArr = ['a', 'b', 'c ']

const newStrArr = insertBegining(strArr, 'f')

console.log(newIntArr)
console.log(newStrArr)
