#include "InputReference.h"
#include<iostream>


void InputExample()
{
	// stdio = iostream�� ����ȭ ���ش�.
	// buffer <- iostream, stdio.h
	std::ios_base::sync_with_stdio(true);
	std::cin.tie(NULL);

	// std::cin >> ~ std::endl; , "\n";
	// ���۰������� cin������ (�ڵ����� ����). 0.0n��

	std::cout << "My";
	printf("Name");

	// std::endl; - '\n'
	// std::endl -> std::cout << 'n' << std::flush(���۰����� ���);
	// Hello World! <- 13 char ����
	// buffer �ִ� max 1��
	// 769 Hello World! ��� std::flush 1�� ����
	// 769 std::endl;		std::flush 769�� ���� (0.01sec)
	// O(n) <- (n^2)
}
