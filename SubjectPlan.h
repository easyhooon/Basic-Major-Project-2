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
		//goto xy 함수 -> Windows.h 헤더파일필요
	}

public:
	SubjectPlan() {

	}
	void seeSubjectPlan() {
		SubjectPlanFile SubjectPlanFile;
		int ch; //전역변수 였던거 지역변수로 변경
		cout << "강의명을 입력해주세요 " << endl;
		cin >> subName;

		// read File

		//강의명을 제대로 입력했을 때와 아닐때를 구분 필요

		SubjectPlanFile.fileLoad(subName);

		cout << "▶   강의계획서 메뉴로 가기" << endl;
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
				cout << "      강의계획서     " << endl;
				cout << "=====================" << endl;
				cout << "   1.강의계획서 보기 " << endl;
				cout << "   2.메인으로 이동   " << endl;
				cout << "=====================" << endl;

				gotoXY(0, y + 3);
				cout << "▶";

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
				system("cls"); // 반복문에 앞선 결과를 지워주는 함수 

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