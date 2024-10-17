#include "InputReference.h"
#include<iostream>


void InputExample()
{
	// stdio = iostream을 동기화 해준다.
	// buffer <- iostream, stdio.h
	std::ios_base::sync_with_stdio(true);
	std::cin.tie(NULL);

	// std::cin >> ~ std::endl; , "\n";
	// 버퍼공간에서 cin데이터 (자동으로 저장). 0.0n초

	std::cout << "My";
	printf("Name");

	// std::endl; - '\n'
	// std::endl -> std::cout << 'n' << std::flush(버퍼공간을 비움);
	// Hello World! <- 13 char 공간
	// buffer 최대 max 1만
	// 769 Hello World! 출력 std::flush 1번 실행
	// 769 std::endl;		std::flush 769번 실행 (0.01sec)
	// O(n) <- (n^2)
}
