# 이 프로젝트를 하며 배운 것 정리

## Singleton

Player와 Controller를 Singleton으로 구현 -> 한 객체만 생성되도록!

singleton 코드; 
 
```cpp
//Controller.cpp
Controller::Controller()
{
	init();
}

Controller* Controller::getInstance()
{
	if (instance == nullptr) instance = new Controller();
	return instance;
}
```

```cpp
//Controller.h
class Controller
{
private:
	Controller();
	~Controller();
	static Controller* instance;	//static 변수 -> 클래스 외부에서 선언 필요!
public:
	static Controller* getInstance();
	void init();
};
```

Error: 
심각도	코드	설명	프로젝트	파일	줄	비표시 오류(Suppression) 상태
오류	LNK2001	"private: static class Controller * Controller::instance" (?instance@Controller@@0PEAV1@EA) 외부 기호를 확인할 수 없습니다.	PlusPlusValley	C:\Users\black\Desktop\PlusPlusValley\PlusPlusValley\Controller.obj	1	

해결: **static변수를 class바깥에서 정의해주어서 해결!**

Controller.cpp 맨 위에 `Controller* Controller::instance = nullptr;`를 추가해주어서 




## 서로서로 `#include`하는 문제

Player와 NPC가 직접적으로 / 돌아돌아 서로 include했다

컴파일이 안 된다. 왜? 서로 필요하니까... player부르려면 npc 불러야하고 npc부르려면 또 player불러야하고..

구조를 고쳐야 했는데 그럴 시간이 없었따

그래서 그냥 NPC에 있는 메소드를 분해해서 Player에 넣었다...


## GUI-Model 간 연결 문제

GUI랑 Model이랑 따로 프로젝트를 만들어서 링크할라했더니

뭐 링커문제가 난다ㅣ lnk 2028 lnk2019?였나

그래서 해결방법 찾다 찾다

1. GUI프로젝트에 참조-model 프로젝트 추가

2. GUI 프로젝트에 컴파일 옵션? 몰라 어디에 $(ProjectDir);$(SolutionDir)\model프로젝트명 추가

3. model 프로젝트의 프로젝트 옵션 - 실행파일(exe)에서 정적라이브러리(.lib)로 변경

했더니 링커 문제는 안 났다.

이제 새로운 문제가 생김...



그래서 그냥 코드를 다 복사-붙여넣기해서 새로운 GUI 프로젝트에다 갖다넣었더니

돌아가긴 하는데

model쪽에서 테스트를 할 수가 없다...

GUI로 돌아가니까....


## GUI 이미지 백그라운드

매번 Src = "./images/img1.png"이런 식으로 불러왔더니 속도가 느렸다. 그럴만도했지.. 왜냐? 디스크에 접근하는 거니까!

그래서 이미지 배열에 저장해놓고, 캐시된 그 배열을 이용하기로 했다.

방법은 이거! https://docs.microsoft.com/en-us/dotnet/api/system.windows.forms.control.backgroundimage?view=netframework-4.8
