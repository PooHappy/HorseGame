#pragma once
#include <iostream>
#include <string>
using namespace std;
#ifndef  HORSE_H
#define HORSE_H
class Horse {
	int d;			 //���� �̵��Ÿ�
public:
	Horse() { d = 0; };//�⺻������
	void horseRun(); //�� ������
	void show()const;	 //������ ���
	int finish();	 //������ ��
	~Horse() {};	 //�Ҹ���
};
#endif