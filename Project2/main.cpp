#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "Racegame.h"
#include "Horse.h"
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {
	srand(time(nullptr)); //������ ���������� ���� ����ð��� ���� ���ϰ� ����
	Racegame rg;	//RacegameŬ���� rg����
	rg.run();	//RacegameŬ������ run�޼ҵ� ����

	return 0;
}