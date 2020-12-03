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
		//�������� ���̵� ����� ���� �� �޼ҵ带 �ҷ��ö����� ���ο� ��ü�� �ʿ��ϴ�.
		AccountFile accountFile;
		Student account;
		string name;
		string id;
		string pw;
		string email;
		int ch;
		int y = 0;

		cout << "=========================" << endl;
		cout << "         ȸ������        " << endl;
		cout << "=========================" << endl;
		cout << "�̸��� �Է����ּ���" << endl;
		cin >> name;
		account.setName(name);
		cout << "����Ͻ� ID�� �Է����ּ���" << endl;
		cin >> id;
		account.setId(id);
		cout << "����Ͻ� PW�� �Է����ּ���" << endl;
		cin >> pw;
		account.setPW(pw);
		cout << "�̸����� �Է����ּ���" << endl;
		cin >> email;
		account.setEmail(email);
		
		cin.ignore();
		
		accountFile.fileSave(account);

		system("cls");
		do {
			cout << "�����մϴ�! ȸ�����Կ� �����Ͽ����ϴ�." << endl;
			cout << "	LogIn" << endl;
			cout << "	�������� ����" << endl;
			gotoXY(0, y + 1);
			cout << "��";

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
		cout << "         �α���          " << endl;
		cout << "=========================" << endl;
		cout << "ȸ������ ID�� �Է����ּ���" << endl;
		cin >> id;
		cout << "ȸ������ PW�� �Է����ּ���" << endl;
		cin >> pw;

		account = accountFile.fileLoad(id);
		
		cin.ignore();
		
		if (account == NULL) {
			//���̵� ���� ���
			system("cls");
			do
			{
				cout << "ID�� �����ϴ�." << endl;
				cout << "	�ٽ��Է�" << endl;
				cout << "	ID ã��" << endl;
				cout << "	PW ã��" << endl;
				cout << "	�������� ����" << endl;
				gotoXY(0, y + 1);
				cout << "��";

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
			//�α��� ������ ���
			system("cls");
			this->showMenuAfterLogIn(account);
		}
		else {
			system("cls");
			do
			{
				cout << "ID �Ǵ� PW�� ��ġ���� �ʽ��ϴ�" << endl;
				cout << "	�ٽ��Է�" << endl;
				cout << "	ID ã��" << endl;
				cout << "	PW ã��" << endl;
				cout << "	�������� ����" << endl;
				gotoXY(0, y + 1);
				cout << "��";

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
		//���� ���� ������ �̸��� ID �������� ��������Ƿ� �α��� �޼ҵ忡�� ��� �ߴ� �񱳹���� ����ϱ� �����. �������� �ʿ���
		//1.Linear search
		//2.�̸� �������� �� ���� �ϳ� �� �����
		//3. ???

		//Account* account;
		//AccountFile accountFile;
		string name;
		string id;
		string email;
		int ch;
		int y = 0;

		cout << "=========================" << endl;
		cout << "         ID ã��         " << endl;
		cout << "=========================" << endl;
		cout << "ȸ������ �̸��� �Է����ּ���." << endl;
		cin >> name;
		cout << "ȸ������ Email�� �Է����ּ���." << endl;
		cin >> email;

		if (name == s->getName() && email == s->getEmail()) {
			system("cls");
			do {
				cout << "ȸ������ ID�� " << s->getId() << "�� Ȯ�� �Ǿ����ϴ�." << endl;
				cout << "	LogIn" << endl;
				cout << "	PW ã��" << endl;
				cout << "	�������� ����" << endl;
				gotoXY(0, y + 1);
				cout << "��";

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
				cout << "ID�� ã�� �� �����ϴ�." << endl;
				cout << "	�ٽ��Է�" << endl;
				cout << "	�������� ����" << endl;
				gotoXY(0, y + 1);
				cout << "��";

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
		cout << "         PW ã��         " << endl;
		cout << "=========================" << endl;
		cout << "ȸ������ ID�� �Է����ּ���" << endl;
		cin >> id;
		cout << "ȸ������ Email�� �Է����ּ���" << endl;
		cin >> email;

		account = accountFile.fileLoad(id);
		cin.ignore();

		if (account != NULL && account->getEmail() == email) {
			//����, ID�� �ְ� email�� �´� ���
			system("cls");
			do {
				cout << "ȸ������ PW�� " << "\'"<< account->getPW() << "\'" << "(��)�� Ȯ�� �Ǿ����ϴ�" << endl;
				cout << "	LogIn" << endl;
				cout << "	�������� ����" << endl;
				gotoXY(0, y + 1);
				cout << "��";

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
			//ID �� ���ų� email�� Ʋ�����
			system("cls");
			do
			{
				cout << "PW�� ã�� �� �����ϴ�." << endl;
				cout << "	�ٽ��Է�" << endl;
				cout << "	IDã��" << endl;
				cout << "	�������� ����" << endl;
				gotoXY(0, y + 1);
				cout << "��";

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
				cout << "   ���Ǽ�����û���α׷�  " << endl;
				cout << "=========================" << endl;
				cout << "		1. ȸ������        " << endl;
				cout << "		2. �α���          " << endl;
				cout << "		3. ���̵�ã��      " << endl;
				cout << "		4. ��й�ȣã��    " << endl;
				cout << "		5. ����" << endl;
				cout << "=========================" << endl;
				gotoXY(0, y + 3);
				cout << "��";

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
			//LecturePlan Ŭ���� ���� �ʿ�
			//LecturePlan lecturePlan; 
			SubjectEvaluation subjectEvaluation;
			TimeTable timeTable;
			int y = 0;
			int ch;

			do {
				//�ð�ǥ ¥���� ��� �߰� �ʿ�.
				cout << "=========================" << endl;
				cout << "   ���Ǽ�����û���α׷�  " << endl;
				cout << "=========================" << endl;
				cout << "		1. ������û        " << endl;
				cout << "		2. ���ǰ�ȹ��          " << endl;
				cout << "		3. ������      " << endl;
				cout << "		4. ������û���    " << endl;
				cout << "		5. �α׾ƿ�		" << endl;
				cout << "		6. ����" << endl;
				cout << "=========================" << endl;
				gotoXY(0, y + 3);
				cout << "��";

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

			//�α��� ���� ��ɵ��� �ҷ����� ���̱� ������ account�� �Ķ���ͷ� �ް� �� ������ ������ �����ؾ� �Ѵ�.
			//Student �����ʿ�
			switch (y) {
				//������û(������, �����۵� �ȵɰ���)
			case 0: registerClass.run(account); break;
				//���� ��ȹ�������ʿ�(account �ʿ����)
			case 1: break;
				//������
			case 2: subjectEvaluation.showSubjectEvaluation(); break;
				//�ð�ǥ �������
			case 3: timeTable.run(0, 0, account); break;
				//�α׾ƿ�
			case 4: break;
				//����
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
