#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <conio.h>
#include <Windows.h>
#include "SubjectEvaluatingFile.h"
using namespace std;

class SubjectEvaluation {
private:
	string subName;
	string evaluation;
	void gotoXY(int x, int y) {
		COORD pos = { x, y };
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
	}
public:
	SubjectEvaluation() {

	}
	void showSubjectEvaluation() {
		while (1) {
			int y = 0;
			int ch;

			do
			{
				cout << "======================" << endl;
				cout << "       강의평가      " << endl;
				cout << "======================" << endl;
				cout << "   1. 평가하기       " << endl;
				cout << "   2. 강의평보기     " << endl;
				cout << "   3. 메인으로 이동  " << endl;
				cout << "======================" << endl;

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
				system("cls");
			} while (ch != '\r');

			switch (y) {
			case 0: this->doSubjectEvaluation(); break;
			case 1: this->seeSubjectEvaluation(); break;
			case 2: break;
			default: break;
			}
			if (y == 2) {
				break;
			}
		}
	}

	void doSubjectEvaluation() {
		SubjectEvaluating subjectEvaluating;
		int ch;
		cout << "평가하실 강의명을 입력해주세요" << endl;
		cin >> subName;
		cin.ignore();

		//강의명을 제대로 입력했을 때와 아닐때를 구분 필요 

		subjectEvaluating.fileSave(subName);
		cout << "강의평가에 등록되었습니다" << endl;
		cout << "▶   강의평가 메뉴로 가기" << endl;
		do
		{
			ch = _getch();

			system("cls");
		} while (ch != '\r');

	}

	void seeSubjectEvaluation() {
		SubjectEvaluating subjectEvaluating;
		int ch;
		cout << "강의명을 입력해주세요" << endl;
		cin >> subName;
		cin.ignore();

		//강의명을 제대로 입력했을 때와 아닐때를 구분 필요 

		subjectEvaluating.fileLoad(subName);
		cout << "▶   강의평가 메뉴로 가기" << endl;
		do
		{
			ch = _getch();

			system("cls");
		} while (ch != '\r');
	}
};