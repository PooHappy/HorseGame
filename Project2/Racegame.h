#pragma once
#include <iostream>
#include <string>
#include "Horse.h"
#ifndef  RACEGAME_H
#define RACEGAME_H
using namespace std;
class Racegame {
private:
	int time;
	int horses;
	int pick;
	int winner;
	int winner_cnt[];
	int horseInsert()const;
	int pickInsert()const;
public:
	void run();
	Racegame() {};	//�⺻������
	~Racegame() {};	//�Ҹ���
};
#endif
