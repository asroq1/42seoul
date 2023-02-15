## Makefile?
make는 파일 관리 유틸리티이다!
linux상에서 반복적인 컴파일을 자동화하려고 사용하는 make 매크로의 설정 파일이다.
프로그램이 커질수록 컴파일이 매우 귀찮아진다. 각 파일에 대한 반복적 명령의 자동화로 인한 시간을 절약할 수 있다.


### 1. Makefile의 동작원리

Makefile의 실행구조는 아래와 같다.
> 소스파일(.*) -> 목적파일(.o) -> 실행파일(.out)

![](https://images.velog.io/images/asroq1/post/246839db-4d0d-45ed-a657-c18070ec3e77/makefile2.png)


Makefile은 이러한 구조로 이루어져 있다.

> 대상(Target), 의존 관계(Dependency), 명령(command)의 세 가지로 이뤄진다.

```sh
<target> : <dependency>
		   <command>
```
### 2. Makefile 만들어보기

#### 2-1. 소스파일 준비하기
>   ```main.c``` ```usa.c``` ```korea.c``` ```hi.h``` 파일을 동일한 디렉토리 내에 만들어준다.

**main.c**

```c
#include "hi.h"

int main()
{
	korea();
	usa();
	return 0;
}
```
**usa.c**

```c
#include "hi.h"

void usa()
{
	printf("hi usa\n");

}

```
**korea.c**

```c
#include "hi.h"


void korea()
{
	printf("hi korea\n");
}
```
**hi.h**

```sh

#include <stdio.h>

void korea();
void usa();
int	 main();
```
>  상단의 파일을 이전에는 ```gcc main.c usa.c korea.c hi.h```로 컴파일했을 것이다. 그리고 나면 a.out이라는 실행 파일이 만들어진다.
그러나 소스코드가 더 많아질수록 이런 행동은 너무 귀찮고 불가능해지는 순간이 오기 때문에 Makefile이 필요해진다.

#### 2-2. Makefile 만들기

 
 아래와 같이  make가 수행됐다면, main.c, usa.c, korea.c가 모두  .o 파일로 변환된다. 이후에 test.out에서 세 개의 목적 파일을 한 개의 test.out 이라는 실행 파일로 묶어준다.
```sh

<target>     <dependency>
test.out :  main.o usa.o korea.o 
			gcc -o test.out main.o usa.o korea.o
            <command>

main.o :
	gcc -c main.c
korea.o :
	gcc -c korea.c

usa.o	:
	gcc -c usa.c

```

아래와 같이 정상적으로 make가 실행된다.
![](https://images.velog.io/images/asroq1/post/926784b8-c630-4180-80a3-9d900a5eda6e/Screen%20Shot%202022-03-02%20at%2012.24.16%20PM.png)


#### 2-3. 조금 더 스마트한 Makefile 만들기
Makefile에서도 변수를 사용할 수 있다.
변수의 종류는 Make 내부에서도 사용하는 내장 변수나(CFLAGS), 확장성을 용이하게 해 주는 자동 변수($@, $<)가 있다.

 ```sh
 

CC = gcc
TARGET = test.out
OBJS = main.o korea.o usa.o

CFLAGS = -Wall -Werror -Wextra

all : $(TARGET)

$(TARGET) : $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

.c.o:
	$(CC) $(CFLAGS) -c -o $@ $<

clean : $(OBJS)
	rm -rf $(OBJS) $(TARGET)
 ```
 
 위에서 활용된 변수의 의미는 아래와 같다.
- CC: 컴파일러
- CFLAGS: 컴파일 옵션
- OBJS: Object 파일
- TARGET: 실행 파일 이름

#### 2-4. 자동 변수
상단의 코드에서 조금 특이한 $@란 것을 볼 수 있다. $@는 현재 빌드 규칙 블록의 Target 이름을 나타내는 자동 변수다.

자동 변수는 위치한 곳의 맥락에 맞도록 치환된다. $@는 명령을 수행할 때 $(TARGET)값으로 치환된다. 이렇게 하면 Target 이름을 수정할 때 Command 를 일일이 찾아서 수정하는 노가다를 하지 않을 수 있다.

아래는 자주 사용하는 자동 변수의 대표적인 예이다.

- $@: 최종 타겟을 의미하며, all과 의미가 같다.

- $^: 타겟을 생성하기 위해 필요한 모든 의존 오브젝트 객체를 말한다. (대부분 모든 .o 파일을 말함.)

- $?: 타겟을 생성하기 위해서 기술된 것들에 가장 최근에 변경된 오브젝트파일

- $% : 대상의 이름 (해당 규칙 대상이 아카이브 인 경우)

- $< : 타겟을 생성하기 위해 가장 왼쪽에 기술된 첫번째 오브젝트


### 3. Makefile 기본 패턴

```sh
CC=<컴파일러>
CFLAGS=<컴파일 옵션>
LDFLAGS=<링크 옵션>
LDLIBS=<링크 라이브러리 목록>
OBJS=<Object 파일 목록>
TARGET=<빌드 대상 이름>
 
all: $(TARGET)
 
clean:
    rm -f *.o
    rm -f $(TARGET)
 
$(TARGET): $(OBJS)
$(CC) -o $@ $(OBJS)

```
