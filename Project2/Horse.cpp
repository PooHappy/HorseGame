#include <iostream>
#include <string>
#include "Horse.h"
using namespace std;

void Horse::horseRun() {
	d = d + rand() % 6;				// �Ÿ� d�� 0���� 5���� ���� 
	if (d > 20) {					//d�� 20�� �Ѿ 20 ����
		d = 20;
	}
}

void Horse::show()const {
	for (int i = 0; i < d; i++)		//"--"��� ��
		cout << "--";
	cout << "(  )=> " << d << endl;
}

int Horse::finish() {
	if (d == 20)
		return 1;					//���Դ����� �Ǻ��ϱ����� int��. ������1 �ƴϸ�0
	else return 0;
}