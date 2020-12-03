#pragma once
#include <iostream>
#include <string>
#include <conio.h>
#include <Windows.h>

#include "Student.h"
#include "AccountFile.h"
#include "Draw.h"
#include "SubjectPlan.h"
#include "SubjectEvaluation.h"
#include "TimeTable.h"


using namespace std;

class Menu {
private:
	Student* s = new Student();
	void gotoXY(int x, int y) {
		COORD pos = {x, y};
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
	}

public:
	void signUp() {
		//여러개의 아이디를 만들기 위해 이 메소드를 불러올때마다 새로운 객체가 필요하다.
		AccountFile accountFile;
		Student account;
		string name;
		string id;
		string pw;
		string email;
		int ch;
		int y = 0;

		cout << "=========================" << endl;
		cout << "         회원가입        " << endl;
		cout << "=========================" << endl;
		cout << "이름을 입력해주세요" << endl;
		cin >> name;
		account.setName(name);
		cout << "사용하실 ID를 입력해주세요" << endl;
		cin >> id;
		account.setId(id);
		cout << "사용하실 PW를 입력해주세요" << endl;
		cin >> pw;
		account.setPW(pw);
		cout << "이메일을 입력해주세요" << endl;
		cin >> email;
		account.setEmail(email);
		
		cin.ignore();
		
		accountFile.fileSave(account);

		system("cls");
		do {
			cout << "축하합니다! 회원가입에 성공하였습니다." << endl;
			cout << "	LogIn" << endl;
			cout << "	메인으로 가기" << endl;
			gotoXY(0, y + 1);
			cout << "▶";

			ch = getch();
			if (ch == 224) {
				ch = getch();
				switch (ch) {
				case 72:
					if (y != 0) {
						y--;
					}
					break;
				case 80:
					if (y != 1) {
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
		case 0:
			this->logIn();
			break;
		case 1:
			this->showMenu();
			break;
		}
	}

	void logIn() {
		AccountFile accountFile;
		Account * account;
		string id;
		string pw;
		int ch;
		int y = 0;
		
		cout << "=========================" << endl;
		cout << "         로그인          " << endl;
		cout << "=========================" << endl;
		cout << "회원님의 ID를 입력해주세요" << endl;
		cin >> id;
		cout << "회원님의 PW를 입력해주세요" << endl;
		cin >> pw;

		account = accountFile.fileLoad(id);
		
		cin.ignore();
		
		if (account == NULL) {
			//아이디가 없는 경우
			system("cls");
			do
			{
				cout << "ID가 없습니다." << endl;
				cout << "	다시입력" << endl;
				cout << "	ID 찾기" << endl;
				cout << "	PW 찾기" << endl;
				cout << "	메인으로 가기" << endl;
				gotoXY(0, y + 1);
				cout << "▶";

				ch = getch();
				if (ch == 224) {
					ch = getch();
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
			case 0:
				this->logIn();
				break;
			case 1:
				this->findId();
				break;
			case 2:
				this->findPw();
				break;
			case 3:
				break;
			}
		
		}
		else if (account->getPW() == pw) {
			//로그인 성공한 경우
			system("cls");
			this->showMenuAfterLogIn(account);
		}
		else {
			system("cls");
			do
			{
				cout << "ID 또는 PW가 일치하지 않습니다" << endl;
				cout << "	다시입력" << endl;
				cout << "	ID 찾기" << endl;
				cout << "	PW 찾기" << endl;
				cout << "	메인으로 가기" << endl;
				gotoXY(0, y + 1);
				cout << "▶";

				ch = getch();
				if (ch == 224) {
					ch = getch();
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
			case 0:
				this->logIn();
				break;
			case 1:
				this->findId();
				break;
			case 2:
				this->findPw();
				break;
			case 3:
				break;
			}
		}
	}

	void findId() {
		//계정 정보 파일의 이름은 ID 기준으로 만들어지므로 로그인 메소드에서 사용 했던 비교방법을 사용하기 힘들다. 방법모색이 필요함
		//1.Linear search
		//2.이름 기준으로 된 파일 하나 더 만들기
		//3. ???

		//Account* account;
		//AccountFile accountFile;
		string name;
		string id;
		string email;
		int ch;
		int y = 0;

		cout << "=========================" << endl;
		cout << "         ID 찾기         " << endl;
		cout << "=========================" << endl;
		cout << "회원님의 이름을 입력해주세요." << endl;
		cin >> name;
		cout << "회원님의 Email을 입력해주세요." << endl;
		cin >> email;

		if (name == s->getName() && email == s->getEmail()) {
			system("cls");
			do {
				cout << "회원님의 ID는 " << s->getId() << "로 확인 되었습니다." << endl;
				cout << "	LogIn" << endl;
				cout << "	PW 찾기" << endl;
				cout << "	메인으로 가기" << endl;
				gotoXY(0, y + 1);
				cout << "▶";

				ch = getch();
				if (ch == 224) {
					ch = getch();
					switch (ch) {
					case 72:
						if (y != 0) {
							y--;
						}
						break;
					case 80:
						if (y != 2) {
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
			case 0 :
				this->logIn();
				break;
			case 1:
				this->findPw();
				break;
			case 2:
				break;
			}
		}
		else {
			system("cls");
			do
			{
				cout << "ID를 찾을 수 없습니다." << endl;
				cout << "	다시입력" << endl;
				cout << "	메인으로 가기" << endl;
				gotoXY(0, y + 1);
				cout << "▶";

				ch = getch();
				if (ch == 224) {
					ch = getch();
					switch (ch) {
					case 72:
						if (y != 0) {
							y--;
						}
						break;
					case 80:
						if (y != 1) {
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
			case 0:
				this->findId();
				break;
			case 1:
				break;
			}
		}
	}

	void findPw() {
		Account * account;
		AccountFile accountFile;
		string id;
		string email;
		int ch;
		int y = 0;

		cout << "=========================" << endl;
		cout << "         PW 찾기         " << endl;
		cout << "=========================" << endl;
		cout << "회원님의 ID을 입력해주세요" << endl;
		cin >> id;
		cout << "회원님의 Email을 입력해주세요" << endl;
		cin >> email;

		account = accountFile.fileLoad(id);
		cin.ignore();

		if (account != NULL && account->getEmail() == email) {
			//성공, ID가 있고 email도 맞는 경우
			system("cls");
			do {
				cout << "회원님의 PW는 " << "\'"<< account->getPW() << "\'" << "(으)로 확인 되었습니다" << endl;
				cout << "	LogIn" << endl;
				cout << "	메인으로 가기" << endl;
				gotoXY(0, y + 1);
				cout << "▶";

				ch = getch();
				if (ch == 224) {
					ch = getch();
					switch (ch) {
					case 72:
						if (y != 0) {
							y--;
						}
						break;
					case 80:
						if (y != 1) {
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
			case 0:
				this->logIn();
				break;
			case 1:
				break;
			}
		}
		else {
			//ID 가 없거나 email이 틀린경우
			system("cls");
			do
			{
				cout << "PW를 찾을 수 없습니다." << endl;
				cout << "	다시입력" << endl;
				cout << "	ID찾기" << endl;
				cout << "	메인으로 가기" << endl;
				gotoXY(0, y + 1);
				cout << "▶";

				ch = getch();
				if (ch == 224) {
					ch = getch();
					switch (ch) {
					case 72:
						if (y != 0) {
							y--;
						}
						break;
					case 80:
						if (y != 1) {
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
			case 0:
				this->findPw();
				break;
			case 1:
				this->findId();
				break;
			case 2:
				break;
			}
		}
	}

	void showMenu() {
		while (1) {
			int y = 0;
			int ch;

			do {
				cout << "=========================" << endl;
				cout << "   모의수강신청프로그램  " << endl;
				cout << "=========================" << endl;
				cout << "		1. 회원가입        " << endl;
				cout << "		2. 로그인          " << endl;
				cout << "		3. 아이디찾기      " << endl;
				cout << "		4. 비밀번호찾기    " << endl;
				cout << "		5. 종료" << endl;
				cout << "=========================" << endl;
				gotoXY(0, y + 3);
				cout << "▶";

				ch = getch();
				if (ch == 224) {
					ch = getch();
					switch (ch) {
					case 72:
						if (y != 0) {
							y--;
						}
						break;
					case 80:
						if (y != 4) {
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
			case 0: this->signUp(); break;
			case 1: this->logIn(); break;
			case 2: this->findId(); break;
			case 3: this->findPw(); break;
			case 4: exit(0); break;
			default: break;
			}
		}
	}

	void showMenuAfterLogIn(Account* account) {
		while (1) {
			Draw registerClass;
			//LecturePlan 클래스 수정 필요
			//LecturePlan lecturePlan; 
			SubjectEvaluation subjectEvaluation;
			TimeTable timeTable;
			int y = 0;
			int ch;

			do {
				//시간표 짜보는 기능 추가 필요.
				cout << "=========================" << endl;
				cout << "   모의수강신청프로그램  " << endl;
				cout << "=========================" << endl;
				cout << "		1. 수강신청        " << endl;
				cout << "		2. 강의계획서          " << endl;
				cout << "		3. 강의평가      " << endl;
				cout << "		4. 수강신청결과    " << endl;
				cout << "		5. 로그아웃		" << endl;
				cout << "		6. 종료" << endl;
				cout << "=========================" << endl;
				gotoXY(0, y + 3);
				cout << "▶";

				ch = getch();
				if (ch == 224) {
					ch = getch();
					switch (ch) {
					case 72:
						if (y != 0) {
							y--;
						}
						break;
					case 80:
						if (y != 5) {
							y++;
						}
						break;
					default:
						break;
					}
				}
				system("cls");

			} while (ch != '\r');

			//로그인 후의 기능들을 불러오는 것이기 때문에 account를 파라미터로 받고 각 계정에 정보를 저장해야 한다.
			//Student 수정필요
			switch (y) {
				//수강신청(구현중, 정상작동 안될것임)
			case 0: registerClass.run(account); break;
				//강의 계획서구현필요(account 필요없음)
			case 1: break;
				//강의평가
			case 2: subjectEvaluation.showSubjectEvaluation(); break;
				//시간표 결과보기
			case 3: timeTable.run(0, 0, account); break;
				//로그아웃
			case 4: break;
				//종료
			case 5: exit(0); break;
			default: break;
			}

			if (y == 4) {
				break;
			}
		}
	}
	
	void run() {
		this->showMenu();
	}
};
