#pragma once

// 1. ���� ����ϴ� ���
#include<stack>

using namespace std;

void Data001()
{
	// ���� ����
	stack<int> myStack;

	// ��ɾ�
	// �Է�
	myStack.push(1);

	//������ ����� ����Ű�� ��
	int value = myStack.top();

	// ������ �����͸� ����
	myStack.pop();

	// �����Ͱ� ������� �ƴ��� Ȯ���ϴ� �Լ�
	if (!myStack.empty())
	{
		int value = myStack.top();
	}
}

// 2. ť ����ϴ� ���
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

// 3. �� ����ϴ� ���
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

