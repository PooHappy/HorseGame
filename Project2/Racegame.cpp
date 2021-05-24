#include <iostream>
#include <string>
#include "Racegame.h"
using namespace std;

int Racegame::horseInsert()const//�� �������� �Է���
{
	int temp = 0;			//while�� ������ ���� ����
	int n;					//�Է¹޴� ����

	while (temp == 0) {
		cin >> n;			//Ű����κ��� �Է¹���
		if (cin.fail()) {	//�Է¹����� int���� �ƴҰ�� 1��ȯ 
			cout << "�߸��� ���� �Է��Դϴ�." << endl;
			cout << "�ٽ� �Է����ּ���" << endl;
			cin.clear();	//�����ʱ�ȭ
			cin.ignore(256, '\n');
		}
		else if (n < 2) {	//2���� �̻� ����
			cout << "�ּ� 2������ ���� �ʿ��մϴ�." << endl;
			cout << "�ٽ� �Է����ּ���" << endl;
		}
		else if (n > 5) {	//5���� ���� ����
			cout << "�ִ� 5������ ���� �ʿ��մϴ�." << endl;
			cout << "�ٽ� �Է����ּ���" << endl;
		}
		else {
			temp = 1;		//while�� Ż��
		}
	}
	return n;				//�Է¹��� ���ڸ�ŭ horses�� ����
}



int Racegame::pickInsert()const //�� ���� ������
{
	int temp = 0;			//while�� ������ ���� ����
	int n;					//�Է¹޴� ����

	while (temp == 0) {
		cin >> n;
		if (cin.fail()) {	//�Է¹����� int���� �ƴҰ�� 1��ȯ 
			cout << "�߸��� ���� �Է��Դϴ�." << endl;
			cout << "�ٽ� �Է����ּ���" << endl;
			cin.clear();
			cin.ignore(256, '\n');
		}
		else if (n < 1 || n > horses) {
			cout << "�߸��� �Է��Դϴ�. �Է��� 1�̻� " << horses << "���Ͽ��� �մϴ�." << endl;
			cout << "�ٽ� �Է����ּ���" << endl;
		}					//�ּ� 1, �ִ� �Է¹��� horses�ȿ��� pick�Ҽ� �ְ� ��
		else {
			temp = 1;		//while�� Ż��
		}
	}
	return n;				//pick�� �Է��ߴ� n�� ����
}

void Racegame::run() {
	time = 0;				//Ƚ�� ������� ����
	winner = 0;				//���� �Ǻ��� ���� ����

	cout << "�渶����!" << endl;
	cout << "�� ������ ���� �÷����Ͻðڽ��ϱ�?" << endl;
	horses = horseInsert();			//�� �������� �Է¹޴� �޼ҵ�

	cout << "�� ��° ���� �����Ͻðڽ��ϱ�?" << endl;
	pick = pickInsert();			//�� ���� �����ϴ� �޼ҵ�

	cout << "\n\n" << endl;

	Horse* h = new Horse[horses];	//�Է��� ������ ��ŭ ����
	int f;							//�� ���Դ��� �Ǻ��ϱ� ���� ����
	int temp = 0;					//����������� �ܵ�������� �Ǻ��ϱ� ���� ����
	bool pan = false;
	int* winner_cnt = new int[horses];	//���ڸ� ���� �迭
	for (int i = 0; i < horses; i++) {	//�ʱ�ȭ ����
		winner_cnt[i] = 0;
	}
	while (1) {				//���ѷ���
		f = 0;
		time++;				//�������� �������� time�� �������� ȸ���� ������
		cout << "Time : " << time << endl;
		cout << "======================================================" << endl;
		for (int i = 0; i < horses; i++) {
			h[i].horseRun();//���� 0~5���� ������ŭ �ٰ�
			cout << i + 1 << "|";
			h[i].show();	//�� ������� ������
		}
		cout << "======================================================\n\n" << endl;

		for (int i = 0; i < horses; i++) {
			if (h[i].finish())	//���� i��° ���� ��������
				if (winner == 0) {	//���ں����� 0�̸�
					winner_cnt[temp] = i + 1;	//���ڹ迭�� �־���
					temp++;		//temp����
				}
			f = f + h[i].finish();	//f�� ��¼��� ���� �� ����ŭ �����ش�
		}
		winner = winner + winner_cnt[0];		//winner�� �������� �ٸ� ȸ���� ������ ���� winner_cnt�迭�� ���� �ʵ��� ���ش�.

		if (f == horses) {		//���� ��¼��� ���� �� ���� �Է��ߴ� �� ���� ������
			if (temp == 1) {	//�ܵ���� �̶��
				cout << "����ڴ� " << winner_cnt[0] << "��° ���Դϴ�!" << endl;
				if (winner_cnt[0] == pick)		//����ڿ� ���� ���� ���� ���ٸ�
					cout << "���ϵ帳�ϴ�! ����� �¸��ϼ̽��ϴ�." << endl;
				else
					cout << "����� �й��ϼ̽��ϴ�. :(" << endl;
				break;			//while�� Ż��
			}
			if (temp > 1) {		//��������̶��
				for (int j = 0; j < temp; j++) {
					cout << "���� ����Դϴ�! ��¸��� " << winner_cnt[j] << "��° ���Դϴ�!" << endl;
				}
				for (int j = 0; j < temp; j++) {
					if (winner_cnt[j] == pick)	//���ڹ迭���� ���� ���� ���� ������ ���
					{
						cout << "���ϵ帳�ϴ�! ����� �¸��ϼ̽��ϴ�." << endl;
						pan = true;				//���� ���� ���� ����Ͽ�����, true�����ؼ� �й�� ����ϴ� if���� ���ذ�.
					}
				}
				if (pan == false) {				//���� ���Ѹ��� ������� ������ ��� false��ȯ -> �й�
					cout << "����� �й��ϼ̽��ϴ�. :(" << endl;
				}
				break;
			}
		}
	}
	delete[] h;			//�������� �Ҵ���� h�迭 ����
}