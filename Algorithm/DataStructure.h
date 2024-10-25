#pragma once

// 1. 스택 사용하는 방법
#include<stack>

using namespace std;

void Data001()
{
	// 스택 선언
	stack<int> myStack;

	// 명령어
	// 입력
	myStack.push(1);

	//스택의 상단을 가리키는 값
	int value = myStack.top();

	// 스택의 데이터를 삭제
	myStack.pop();

	// 데이터가 비었는지 아닌지 확인하는 함수
	if (!myStack.empty())
	{
		int value = myStack.top();
	}
}

// 2. 큐 사용하는 방법
#include<queue>

void Data002()
{
	queue<int> myQueue;

	myQueue.push(1);
	myQueue.back();
	myQueue.size();
	myQueue.front();
	myQueue.back();
}

// 3. 덱 사용하는 방법
#include<deque>

void Case003()
{
	deque<int> myDeque;

	myDeque.push_front(1);
	myDeque.push_back(2);
	myDeque.pop_front();
	myDeque.pop_back();
	myDeque.size();
	myDeque.front();
	myDeque.back();
	myDeque.empty();
}

