#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>
#include <conio.h>
#include "SubjectPlanFile.h"

using namespace std;

class SubjectPlan {
private:
	string subName;
	//Menu* m = new Menu();
	void gotoXY(int x, int y) {
		COORD pos = { x, y };
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
		//goto xy �Լ� -> Windows.h ��������ʿ�
	}

public:
	SubjectPlan() {

	}
	void seeSubjectPlan() {
		SubjectPlanFile SubjectPlanFile;
		int ch; //�������� ������ ���������� ����
		cout << "���Ǹ��� �Է����ּ��� " << endl;
		cin >> subName;

		// read File

		//���Ǹ��� ����� �Է����� ���� �ƴҶ��� ���� �ʿ�

		SubjectPlanFile.fileLoad(subName);

		cout << "��   ���ǰ�ȹ�� �޴��� ����" << endl;
		do {
			ch = _getch();
		} while (ch != '\r');
		system("cls");
	}

	void showSubjectPlan() {
		int y = 0;
		int ch;
		while (1) {
			do
			{
				cout << "=====================" << endl;
				cout << "      ���ǰ�ȹ��     " << endl;
				cout << "=====================" << endl;
				cout << "   1.���ǰ�ȹ�� ���� " << endl;
				cout << "   2.�������� �̵�   " << endl;
				cout << "=====================" << endl;

				gotoXY(0, y + 3);
				cout << "��";

				ch = _getch();
				if (ch == 224) {
					ch = _getch();
					switch (ch) {
					case 72:
						if (y != 0) {
							y--;
						}
						break;
					case 80:
						if (y != 3) {
							y++;
						}
						break;
					default:
						break;
					}
				}
				system("cls"); // �ݺ����� �ռ� ����� �����ִ� �Լ� 

			} while (ch != '\r');

			switch (y) {
			case 0: this->seeSubjectPlan(); break;
			case 1: break;
			default: break;
			}
			if (y == 1) {
				break;
			}
		}
	}
};