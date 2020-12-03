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

   void cursorView(char show)//커서숨기기
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
         
			if (i == 7) { cout << "       ================================수강신청===================================="; }
			else if (i == 8) { cout << "	번호를 입력하세요 :" << "				저장하기" << "              "; }

			else if (i == 10) { cout << "list limit :" << inputLimit; }
			else if (i == 11) { cout << "time :" << time; }
			
			
			//else if (i == 10) { cout << "           삭제하기"; }
			
			else if (i == 12) { cout << "result :" << result; }

			//저장된 과목이 떳으면 좋겠음.

			else if (i == 13) { cout << "	종료"; }
			
			gotoXY(110, i);
			cout << "|";
         }
      }
	  gotoXY(21, y);
	  cout << "▶";

	  this->cursorView(0);
   }

   Subject search(int inputnum) {

	   for (int i = 0; i < (sizeof(list) / sizeof(Subject)); i++) {
		   if (list[i].getSubNum() == inputnum) { return list[i]; }
		   //else{예외처리}
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
			   result = "저장에 성공하셨습니다.";
		   }
		   else {
			   result = "저장에 실패했습니다.";
		   }
	   }
	   else if (inputLimit <= time) {
		   result = "저장에 실패했습니다.";
	   }
   }
   
   void remove() {
	   Subject temp;
	   temp = search(inputNum);
	   if (timetable->remove(temp) == true) {
		   result = "삭제에 성공하셨습니다.";
	   }
	   else {
		   result = "존재하지 않는 과목입니다 다시 확인하세요";
	   }
   }
   
   void showMenu(Account* account) {
	   int y = 8;
	   int ch;

	   //메모리 리킹을 막기위해 무한루프 사용
	   //1.스위치문에 들어간 후 기능에 따른 메소드가 실행된다
	   //2.메소드가 종료된다.
	   //3.종료로나 이전 메뉴로 돌아가기전까지 계속 반복한다.
	   // 이전메뉴로 돌아가는 방법은 스위치문으로 들어간 후 아무 것도 실행하지 않고
	   //현재 while(1)로 되어있는 무한루프를 break로 끊어주는 방식을 사용했다.
	   while (1) {
		   do {
			   //화면그리기
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

		   //종료에서 엔터를 입력하면 y는 11로 빠져나온다. 
		   //while문을 탈출하고 현재기능을 종료 할 수 있다. 
		   if (y == 11) {
			   break;
		   }
	   }
   }

   void run(Account* account) {
	   this->showMenu(account);
   }
};