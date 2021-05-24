#pragma once
#include <iostream>
#include <string>
using namespace std;
#ifndef  HORSE_H
#define HORSE_H
class Horse {
	int d;			 //말의 이동거리
public:
	Horse() { d = 0; };//기본생성자
	void horseRun(); //말 움직임
	void show()const;	 //움직임 출력
	int finish();	 //도착한 말
	~Horse() {};	 //소멸자
};
#endif