#include <iostream>
#include <string>
#include "Horse.h"
using namespace std;

void Horse::horseRun() {
	d = d + rand() % 6;				// 거리 d는 0부터 5사이 난수 
	if (d > 20) {					//d가 20이 넘어도 20 고정
		d = 20;
	}
}

void Horse::show()const {
	for (int i = 0; i < d; i++)		//"--"출력 문
		cout << "--";
	cout << "(  )=> " << d << endl;
}

int Horse::finish() {
	if (d == 20)
		return 1;					//들어왔는지를 판별하기위해 int형. 들어오면1 아니면0
	else return 0;
}