// testing git solution
// �׽�Ʈ�� �ڵ�
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