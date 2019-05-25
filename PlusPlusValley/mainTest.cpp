// testing git solution
// 테스트용 코드
#include <iostream>
#include "character.h"

int main()
{
	std::cout << "hi" << std::endl;

	//test for character
	character* testChar = new character();
	testChar->setx(10);
	std::cout << testChar->getx() << std::endl;

}