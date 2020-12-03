#pragma once
#include<iostream>
#include<string>
#include<conio.h>
#include<fstream>
#include<windows.h>
#include<time.h>

#include"Subject.h"
#include"TimeTable.h"
#include"Menu.h"

using namespace std;

class Draw {
private:
	TimeTable* timetable;
	clock_t start, tempTime;
	Subject list[4];
	double time = 0;
	string result= "                               ";
	int inputLimit = 0;
	int inputNum;

public:
   Draw() {
      start = clock();
	  this->init();
   }

   void cursorView(char show)//Ŀ�������
   {
	   HANDLE hConsole;
	   CONSOLE_CURSOR_INFO ConsoleCursor;

	   hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	   ConsoleCursor.bVisible = show;
	   ConsoleCursor.dwSize = 1;

	   SetConsoleCursorInfo(hConsole, &ConsoleCursor);
   }

   void gotoXY(int x, int y) {
	   COORD Cur;
	   Cur.X = x;
	   Cur.Y = y;
	   SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);
   }

   void init() {
	   ifstream ifs;
	   ifs.open("subjectlist.txt");
	   int index = 0;

	   while (!ifs.eof()) {
		   string name;
		   int num;

		   string day;
		   int start;
		   int finish;
		   string room;
		   int credit;
		   int limit;

		   ifs >> name >> num >> day >> start >> finish >> room >> credit >> limit;

		   Subject temp(name, num, credit, limit, day, start, finish, room);
		   list[index] = temp;

		   index++;
	   }
	   ifs.close();

   }
   void drawStroke(int y) {
      for (int i = 5; i < 45; i++) {

		 gotoXY(20, i);
   
         if (i == 5 || i == 44) { cout << "-------------------------------------------------------------------------------------------"; }
         else {
            cout << "|";
         
			if (i == 7) { cout << "       ================================������û===================================="; }
			else if (i == 8) { cout << "	��ȣ�� �Է��ϼ��� :" << "				�����ϱ�" << "              "; }

			else if (i == 10) { cout << "list limit :" << inputLimit; }
			else if (i == 11) { cout << "time :" << time; }
			
			
			//else if (i == 10) { cout << "           �����ϱ�"; }
			
			else if (i == 12) { cout << "result :" << result; }

			//����� ������ ������ ������.

			else if (i == 13) { cout << "	����"; }
			
			gotoXY(110, i);
			cout << "|";
         }
      }
	  gotoXY(21, y);
	  cout << "��";

	  this->cursorView(0);
   }

   Subject search(int inputnum) {

	   for (int i = 0; i < (sizeof(list) / sizeof(Subject)); i++) {
		   if (list[i].getSubNum() == inputnum) { return list[i]; }
		   //else{����ó��}
	   }

   }

   void save(int inputNum) {
	   Subject temp;

	   tempTime = clock();
	   time = tempTime;


	   temp = search(inputNum);
	   inputLimit = temp.getSubLimit();

	   if (inputLimit > time) {
		   if (timetable->add(temp)) {
			   result = "���忡 �����ϼ̽��ϴ�.";
		   }
		   else {
			   result = "���忡 �����߽��ϴ�.";
		   }
	   }
	   else if (inputLimit <= time) {
		   result = "���忡 �����߽��ϴ�.";
	   }
   }
   
   void remove() {
	   Subject temp;
	   temp = search(inputNum);
	   if (timetable->remove(temp) == true) {
		   result = "������ �����ϼ̽��ϴ�.";
	   }
	   else {
		   result = "�������� �ʴ� �����Դϴ� �ٽ� Ȯ���ϼ���";
	   }
   }
   
   void showMenu(Account* account) {
	   int y = 8;
	   int ch;

	   //�޸� ��ŷ�� �������� ���ѷ��� ���
	   //1.����ġ���� �� �� ��ɿ� ���� �޼ҵ尡 ����ȴ�
	   //2.�޼ҵ尡 ����ȴ�.
	   //3.����γ� ���� �޴��� ���ư��������� ��� �ݺ��Ѵ�.
	   // �����޴��� ���ư��� ����� ����ġ������ �� �� �ƹ� �͵� �������� �ʰ�
	   //���� while(1)�� �Ǿ��ִ� ���ѷ����� break�� �����ִ� ����� ����ߴ�.
	   while (1) {
		   do {
			   //ȭ��׸���
			   this->drawStroke(y);
			   gotoXY(47, 8);
			   if (y == 8) {
				   cursorView(1);
				   cin >> inputNum;
			   }
			   cursorView(0);
			   ch = getch();
			   if (ch == 224) {
				   ch = getch();
				   switch (ch) {
				   case 72:
					   if (y != 8) { y--; }break;
				   case 80:
					   if (y != 11) { y++; }break;
				   default:
					   break;
				   }
			   }
			   system("cls");

		   } while (ch != '\r');

		   switch (y)
		   {
		   case 8: break;
		   case 9:this->save(inputNum); break;
		   case 10:this->remove(); break;
		   case 11:break;
		   default:break;
		   }

		   //���ῡ�� ���͸� �Է��ϸ� y�� 11�� �������´�. 
		   //while���� Ż���ϰ� �������� ���� �� �� �ִ�. 
		   if (y == 11) {
			   break;
		   }
	   }
   }

   void run(Account* account) {
	   this->showMenu(account);
   }
};