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
				cout << "       ������      " << endl;
				cout << "======================" << endl;
				cout << "   1. ���ϱ�       " << endl;
				cout << "   2. �����򺸱�     " << endl;
				cout << "   3. �������� �̵�  " << endl;
				cout << "======================" << endl;

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
		cout << "���Ͻ� ���Ǹ��� �Է����ּ���" << endl;
		cin >> subName;
		cin.ignore();

		//���Ǹ��� ����� �Է����� ���� �ƴҶ��� ���� �ʿ� 

		subjectEvaluating.fileSave(subName);
		cout << "�����򰡿� ��ϵǾ����ϴ�" << endl;
		cout << "��   ������ �޴��� ����" << endl;
		do
		{
			ch = _getch();

			system("cls");
		} while (ch != '\r');

	}

	void seeSubjectEvaluation() {
		SubjectEvaluating subjectEvaluating;
		int ch;
		cout << "���Ǹ��� �Է����ּ���" << endl;
		cin >> subName;
		cin.ignore();

		//���Ǹ��� ����� �Է����� ���� �ƴҶ��� ���� �ʿ� 

		subjectEvaluating.fileLoad(subName);
		cout << "��   ������ �޴��� ����" << endl;
		do
		{
			ch = _getch();

			system("cls");
		} while (ch != '\r');
	}
};