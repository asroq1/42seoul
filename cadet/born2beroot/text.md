

## 선행지식

### 1. 가상머신 (Virtural Machine)

> 컴퓨터 내의 컴퓨터를 만들어 작동하는 가상 환경이다.
가상머신의 중요한 특징은 머신 안에서 돌아가는 소프트웨어가 가상머신이 제공하는 환경 및 자원에 의해 제약을 받으며, 가상세계를 벗어날 수 없다.

**가상화가 유용한 상황**

-다른 OS를 활용하고 싶은 상황

-위험부담 없이 여러 실험을 하고 싶을 때

- 하나의 하드웨어에서 여러 개의 가상 서버를 설치해 하드웨어 사용률을 올리고 싶은 상황

#### 1-1 Host, Guest
Host : **실제 컴퓨터를 의미한다.**
Guest : **가상 컴퓨터를 의미한다.**

![](https://images.velog.io/images/asroq1/post/aed48bd9-92d4-4c01-8e11-5e3c23a9c388/vm.jpeg)


### 2. ISA (Instruction Set Architecture)

> 명령어의 집합 구조이며, CPU가 인식해서 무슨 명령인지 이해하고 실행할 수 있는 기계어의 명령어를 의미한다.
컴퓨터에서 다양한 과정을 걸쳐서 S/W -> H/W 단계로 넘어가게 되는데, 이때 중간다리 역할을 해주는 녀석이 **ISA**라고 할 수 있겠다.

![](https://images.velog.io/images/asroq1/post/605aa1a5-311f-4703-b2dd-cbe60879279b/isa.jpeg)


### 2-2 ISA예시

-**x64** and **x86**
x86계열의 CPU가 32비트까지 나와있고, 64비트까지 지원하도록 확장된 것이 x86-64이다.

-32bit와 64bit의 차이는 무엇인가?
> 저장 장치의 bit폭이다. 우리는 이 저장 장치를 레지스터라 부른다. 레지스터 우리가 익히 아는 캐시보다도 빠르고, 저장 용량은 더 작다. 컴퓨터 기억 장치 중 가장 빠르게 작업을 수행할 수 있는 녀석이다. 이 크기가 16bit라면 **16bitCPU**라고 정의하고  64bit라면 **64bitCP**가 된다.

-레지스터의 bit가 클수록 좋은점은?
레지스터는 우리가 생각하는 HDD or SSD와 같은 저장 매체가 아니라 **연산 대상 및 연산 결과**를 기억하는데 사용된다. 16bit가 한 번에 처리할 수 있는 양은 2의 16제곱 65536이고, 64비트는 2^64 18448744073709551616이 된다. 즉 bit가 클수록 많은 양의 데이터를 처리할 수 있기에 더 빠른 연산을 할 수 있다. 또 특징으로는 x86명령어가 x86_64에서 실행가능하지만 그 반대로는 불가능하다.

-메모리 제한
32bit환경에선 RAM의 한계가 4GB밖에 되지 않는다. 그러나 64bit는 최대 16EB(엑사바이트)까지 지원하지만 그까지 인식하는 OS가 없다.

### 2-3 RISC && CISC
- RISC(Reduced Instruction Set Computing)
- 단순하고, 빠르고, 효율적인 소수의 명령
- 복잡한 처리는 모두 소프트웨어를 이용


- CISC(Complex Instuction Set Computing)
- 편리하고 강력한 다수의 명령
- 여러 개의 명령을 하나의 명령으로 처리

++ 요즘 잘 나가는 M1 칩셋이 RISC구조이고, 인텔은 CISC구조를 사용한다.


### 3. 시스템 가상머신
> 여러 운영체제를 실행하는 가상 머신의 베이스가 되는 물리 컴퓨터를 다중화 하는 것을 시스템 가상머신이라고 한다.
동시에 여러 개의 운영체제를 설치하고 실행하기 위해 메모리를 분할하여 한 개의 컴퓨터에 여러 개의 분리된 실행환경을 생설할 수 있다.

### 3-1 대표적인 소프트웨어 및 특징
-대표적으로 VMware, VirturalBox, Parellels 등이 존재한다.

-장점
1. 각 운영체제 환경이 분리된 상황에서 같은 컴퓨터에서 병렬적으로 실행할 수 있다.
2. 실제 시스템과 약간 다른 ISA를 제공해준다.

-단점
1. VM이 동일한 하드웨어에 간접적으로 접근해서 효율성이 떨어진다.
2. 동일한 물리적 환경에서 병렬적으로 실행되는 여러 개의 VM은 시스템 환경에 따라서 성능이 달라질 수 있다.

## 과제 개념

### 1. CentOS vs Debian

#### CentOS
- 2004년도에 최초 출시했으며 배포판 중 가장 인기가 많다. 
- 인기가 많은 이유는 패치가 빠르고, 유틸의 양이 풍족하며 호환성 및 관리하는 툴의 성능이 좋다.
-쉬운 GUI가 없다.
-레드햇이라는 회사에서 배포한 리눅스이다.


#### Debian
- 1993년에 최초로 출시했으며, 온라인 커뮤니티에 시작한 것이 특징이다.
- 무료라서 개인 사용자들에게 서버용으로 인기가 많고 성능또한 우수하다. 또한 진입장벽이 낮아 초보 유저가 접근하기 용이하다.
- 많은 패키지를 가지고 있으며, 데스크탑에 특화된 GUI가 있다.
- 데비안 프로젝트에 속한 개인 그룹이 구축하고 지원하는 것이 특징이다.

### 2. Partitioning
> 저장 공간을 여러 개로 분리하는 작업. 실제로 사용하는 데이터와 백업용 데이터를 나눠서 저장하는 등 여러 방면으로 사용할 수 있다. (ex. 윈도우 포맷 후 파티션 할당으로 SSD에 os를 설치하고 HDD는 백업으로 사용)

- 각 파티션에 대한 정보는 **디스크의 파티션 테이블**에 저장된다.

- 이후 운영체제에서는 디스크를 읽을 때 이 테이블을 먼저 읽는다. 운영체제는 이 파티션들을 독립적인 장치로 인식한다.

- 디스크는 발견 순으로 sda, sdb ...(생략) 
- 파티션은 sd1, sda2... (논리 파티션은 sda5부터)

**마운트**
하드웨어 장치를 사용하기 위해서 운영체제에 인식시키는 작업이다. 특정 디렉토리에 연결해야 한다.

**볼륨**
컴퓨터가 인식할 수 있는 파일시스템을 사용해 접근할 수 있는 저장 영역

**논리 볼륨**
저장공간을 가상화해 물리 디스크 크기에 제한을 두지 않게 할 수 있다. 용량을 유연하게 조절할 수 있고, 실제 데이터에 영향을 끼치지 않고 효과를 테스트할 수 있다.
### 3. aptitude VS apt

#### aptitude
- 사용자 인터페이스를 추가해 대화형으로 패키지를 검색하고 설치 및 제거를 할 수 있는 고급 패키징 도구에 대한 인터페이스이다.
- apt보다 상대적으로 HighLevel이며 출시도 apt보다 늦게 했다.
- 사용하지 않는 패키지를 자동적으로 제거해주거나 설치,제거,업데이트 과정에서 충돌이 있을 경우엔 다른 대안도 함께 제시해준다.
#### apt
- 소프트웨어 설치 및 제거를 정상적으로 처리하는 무료 오픈소스이며,  GUI가 없고 파생된 것으로는 apt-get, apt_mark, apt-cache등이 있다.
- aptitud보다 LowLevel이지만 자유성이 높다.
- aptitude와는 다르게 충돌이 발생할 경우 그냥 안된다는 메시지만 출력해주고, 패키지 자동 제거는 추가 옵션이 필요하다.


### 4. AppArmor
- 시스템 관리자가 계정별로 프로그램의 역량을 제한할 수 있게 해주는 리눅스 커널의 보안 모듈이다.
- CentOS는 SELinux를 사용하고 나머지는 대부분은 AppArmor를 사용하고, SELinux는 IBM & RedHat 계열에서 선호하며 그 외에는 다 AppArmor를 활용한다.
- 개별 응용프로그램을 보호하는 일에 집중하고, 응용프로그램 단위의 보안 모델을 구현한다.


#### 커널이란? 
> **자원을 최대한 효율적으로 사용할 수 있도록 도와주는 운영체제의 핵심 소프트웨어**이다.
예를 들어, 아래와 같은 그림에서 한 개의 프로그램이 작업을 수행해야할 때 하드웨어의 자원을 효율적으로 관리하고 사용할 수 있게 해준다. 커널은 운영체제의 핵심 역할 중 하나이다.


### 5. UFW
> iptables의 설정 도구로서 **복잡하지 않은 방화벽**(Uncomplicated Fireewall)을 의미한다.

-서버는 어디서든지 외부에서 접근이 가능해 보안이 취약할 수 있다. 이에 따라 이미 네트워크 구성에서 하드웨어/소프트웨어에서 방화벽이 이미 사용되고 있을 수 있지만, 각 서버의 방화벽 설정은 매우 유용할 수 있다.
iptables가 매우 적합하지만 설정과 관리가 복잡해 UFW가 나오게 됐다.

### 6. SSH
> SSH는 Secure Shell의 약자로, 두 컴퓨터 간의 통신을 하게 해주는 하나의 프로토콜이다.
프로토콜의 예시로는 우리가 흔히들 아는 HTTP, HTTPS, FTP등이 있다.

- 브라우저가 웹을 띄우기 위하여 서버랑 통신할 때 HTTP, HTTPS를 쓴다면, 서로 다른 컴퓨터가 shell을 통신할 때 사용하는 것중 제일 보편적인게 SSH이다. 기존의 telnet은 암호화가 없어 보안이 취약했다.


####  SSH의 장점
HTTPS에서 통신 중 데이터가 암호화된 것처럼 SSH를 이용한 통신에서는 Client와 Host간의 통신이 암호화됐다. 고로 굉장히 안전하여 많은 사람들이 사용한다.



 

### 7. monitoring.sh

#### -wall

1. write to all 파일이나 표준 입력은 **로그인 된** 모든 사용자에게 보여준다.
2. echo "hello world" | wall || wall <파일이름>

#### -crontab

1. 유닉스 계열의 시간 기반 스케줄러
2. 분-시-일-월-요일 순으로 설정할 수 있다.
3. 아래의 명령으로 세팅할 수 있다.
```bash 
crontab -<옵션>
e : 수정
l : 확인
r : 삭제

```