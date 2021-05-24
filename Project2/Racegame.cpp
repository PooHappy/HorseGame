#include <iostream>
#include <string>
#include "Racegame.h"
using namespace std;

int Racegame::horseInsert()const//말 마릿수를 입력함
{
	int temp = 0;			//while문 실행을 위해 선언
	int n;					//입력받는 변수

	while (temp == 0) {
		cin >> n;			//키보드로부터 입력받음
		if (cin.fail()) {	//입력받은게 int형이 아닐경우 1반환 
			cout << "잘못된 숫자 입력입니다." << endl;
			cout << "다시 입력해주세요" << endl;
			cin.clear();	//버퍼초기화
			cin.ignore(256, '\n');
		}
		else if (n < 2) {	//2마리 이상 설정
			cout << "최소 2마리의 말이 필요합니다." << endl;
			cout << "다시 입력해주세요" << endl;
		}
		else if (n > 5) {	//5마리 이하 설정
			cout << "최대 5마리의 말이 필요합니다." << endl;
			cout << "다시 입력해주세요" << endl;
		}
		else {
			temp = 1;		//while문 탈출
		}
	}
	return n;				//입력받은 숫자만큼 horses에 저장
}



int Racegame::pickInsert()const //내 말을 선택함
{
	int temp = 0;			//while문 실행을 위한 선언
	int n;					//입력받는 변수

	while (temp == 0) {
		cin >> n;
		if (cin.fail()) {	//입력받은게 int형이 아닐경우 1반환 
			cout << "잘못된 숫자 입력입니다." << endl;
			cout << "다시 입력해주세요" << endl;
			cin.clear();
			cin.ignore(256, '\n');
		}
		else if (n < 1 || n > horses) {
			cout << "잘못된 입력입니다. 입력은 1이상 " << horses << "이하여야 합니다." << endl;
			cout << "다시 입력해주세요" << endl;
		}					//최소 1, 최대 입력받은 horses안에서 pick할수 있게 함
		else {
			temp = 1;		//while문 탈출
		}
	}
	return n;				//pick에 입력했던 n을 저장
}

void Racegame::run() {
	time = 0;				//횟수 출력위한 변수
	winner = 0;				//승자 판별을 위한 변수

	cout << "경마게임!" << endl;
	cout << "몇 마리의 말로 플레이하시겠습니까?" << endl;
	horses = horseInsert();			//말 마릿수를 입력받는 메소드

	cout << "몇 번째 말을 선택하시겠습니까?" << endl;
	pick = pickInsert();			//내 말을 선택하는 메소드

	cout << "\n\n" << endl;

	Horse* h = new Horse[horses];	//입력한 마릿수 만큼 생성
	int f;							//다 들어왔는지 판별하기 위한 변수
	int temp = 0;					//공동우승인지 단독우승인지 판별하기 위한 변수
	bool pan = false;
	int* winner_cnt = new int[horses];	//승자를 넣을 배열
	for (int i = 0; i < horses; i++) {	//초기화 선언
		winner_cnt[i] = 0;
	}
	while (1) {				//무한루프
		f = 0;
		time++;				//루프안을 돌때마다 time을 증가시켜 회차를 보여줌
		cout << "Time : " << time << endl;
		cout << "======================================================" << endl;
		for (int i = 0; i < horses; i++) {
			h[i].horseRun();//말이 0~5사이 난수만큼 뛰고
			cout << i + 1 << "|";
			h[i].show();	//그 결과값을 보여줌
		}
		cout << "======================================================\n\n" << endl;

		for (int i = 0; i < horses; i++) {
			if (h[i].finish())	//만약 i번째 말이 들어왔으면
				if (winner == 0) {	//승자변수가 0이면
					winner_cnt[temp] = i + 1;	//승자배열에 넣어줌
					temp++;		//temp증가
				}
			f = f + h[i].finish();	//f에 결승선에 들어온 말 수만큼 더해준다
		}
		winner = winner + winner_cnt[0];		//winner를 증가시켜 다른 회차때 들어오는 말이 winner_cnt배열에 들어가지 않도록 해준다.

		if (f == horses) {		//만약 결승선에 들어온 말 수와 입력했던 말 수가 같으면
			if (temp == 1) {	//단독우승 이라면
				cout << "우승자는 " << winner_cnt[0] << "번째 말입니다!" << endl;
				if (winner_cnt[0] == pick)		//우승자와 내가 정한 말이 같다면
					cout << "축하드립니다! 당신은 승리하셨습니다." << endl;
				else
					cout << "당신은 패배하셨습니다. :(" << endl;
				break;			//while문 탈출
			}
			if (temp > 1) {		//공동우승이라면
				for (int j = 0; j < temp; j++) {
					cout << "공동 우승입니다! 우승말은 " << winner_cnt[j] << "번째 말입니다!" << endl;
				}
				for (int j = 0; j < temp; j++) {
					if (winner_cnt[j] == pick)	//승자배열에서 내가 정한 말이 있으면 우승
					{
						cout << "축하드립니다! 당신은 승리하셨습니다." << endl;
						pan = true;				//내가 정한 말이 우승하였을때, true선언해서 패배시 출력하는 if문을 피해감.
					}
				}
				if (pan == false) {				//내가 정한말이 우승하지 못했을 경우 false반환 -> 패배
					cout << "당신은 패배하셨습니다. :(" << endl;
				}
				break;
			}
		}
	}
	delete[] h;			//동적으로 할당받은 h배열 해제
}