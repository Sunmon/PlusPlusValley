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

