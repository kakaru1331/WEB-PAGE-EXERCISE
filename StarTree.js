/*
for문을 사용하여 0부터 10미만의 정수 중에서 짝수만을 작은 수부터 출력하시오.
ex) 
0
2
4
6
8
*/


for (var i = 0; i < 10; i++){
	if (i % 2 === 0){
		console.log(i)
	}
}


/*
for문을 사용하여 0부터 10미만의 정수 중에서 짝수만을 작은 수부터 문자열로 출력하시오.
ex) 02468
*/

// 빈문자열에 연산자로 넘버를 담은 뒤에 출력.
var numToString = '';
for (var i = 0; i < 10; i++){
	if (i % 2 === 0){
	numToString += i
	} 
};
console.log(numToString);


/*
for문을 사용하여 0부터 10미만의 정수 중에서 홀수만을 큰수부터 출력하시오.
ex)
9
7
5
3
1
*/

// 첫 문제를 응용. 초기값은 10, 감소.
for (var i = 10; i > 0; i--){
	if (i % 2 === 1){
		console.log(i);
	}
};


/*
while문을 사용하여 0부터 10까지 정수 중에서 짝수만을 작은 수부터 출력하시오.
ex)
0
2
4
6
8
*/

// i를 while문 밖에 선언. 조건으로 i를 찍어준다. 이후 블럭 밖에서 i++

var i = 0;

while (i < 10){
	if (i % 2 === 0){
		console.log(i)
	}
	i++
};


/*
while문을 사용하여 0부터 10미만의 정수 중에서 홀수만을 큰수부터 출력하시오.
ex)
9
7
5
3
1
*/

// 위와 동일
var i = 10;
while (i > 0){
	if (i % 2 === 1){
	console.log(i)
	}
	i--
};


/*
삼각형출력하기

다음을 참고하여 *(별)로 높이가 5인(var line = 5) 삼각형을 문자열로 완성하라.
개행문자('\n')를 사용하여 개행한다. 완성된 문자열의 마지막은 개행문자('\n')로 끝나도 관게없다.

// 높이(line)가 5
*
**
***
****
*****

*/

// 빈 문자열 생성 -> i+1만큼 별을 찍고 개행. 반복.


var starTree = '';
for (i = 0; i < 5; i++){
	for (j = 0; j <= i; j++){
		starTree += '*'
	}
	starTree += '\n'
}
console.log(starTree);

/*
트리 출력하기

다음을 참고하여 *(별)로 트리를 문자열로 완성하라.
개행문자('\n')를 사용하여 개행한다. 완성된 문자열의 마지막은 개행문자('\n')로 끝나도 관게없다.

// 높이(line)가 3일때 + 높이(line)가 5일때
*
**
***
*
**
***
****
*****

*/

// 높이 3, 5트리를 담을 문자열을 생성 -> 여덟줄이 필요하므로 i는 8까지. -> for와 els로 각각 3, 5 트리를 만든다.
var starTreeH3 = '';
var starTreeH5 = '';
for (var i = 0; i < 8; i++){
	if (i < 3){
		for (j = 0; j <= i; j++){
				starTreeH3 += '*';
		}
		starTreeH3 += '\n';
	}	else {
			for (k = 3; k <= i; k++){
				starTreeH5 += '*';
			}
			starTreeH5 += '\n';
		}
}
console.log(starTreeH3 + starTreeH5);