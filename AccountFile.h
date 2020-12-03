#pragma once
#include "FileManager.h"
#include "Student.h"
#include "Administrator.h"
#include <string>
using namespace std;

//FileMager �ڽ�Ŭ����, ���� ���� �����
class AccountFile : public FileManager {
public:
	AccountFile() {

	}

	void fileSave(Student student) {
		ofstream ofs;
		string fileName = student.getId() + ".txt";
		ofs.open(fileName);
		if (!ofs) {
			cout << "�л������� ������ �� �����ϴ�." << endl;
			exit(0);
		}
		ofs << student.getId() << " " << student.getPW() << " " << student.getName() << " " << student.getEmail() << " "  << student.getAccountGrade() << endl;

		ofs.close();
	}

	void fileSave(Administrator admin) {
		ofstream ofs;
		string fileName = admin.getName() + ".txt";
		ofs.open(fileName);
		if (!ofs) {
			cout << "������������ ������ �� �����ϴ�." << endl;
			exit(0);
		}
		ofs << admin.getId() << " " << admin.getPW() << " " << admin.getName() << " " << admin.getEmail() << " " << admin.getAccountGrade() << endl;

		ofs.close();
	}

	void subjectSave(Student student, int subjectNum) {
		string filePath = student.getName() + ".txt";
		// write File
		string chekSubject;
		//�̹� ������ ������ true ������ false;
		bool check = false;
		ofstream ofs;
		ifstream ifs;
		ofs.open(filePath.data(), ios::app);
		ifs.open(filePath.c_str());
		// ios::app �̾�� �����ϰ� �ϴ� ����
		if (!ofs) {
			cout << "������ �� �� �����ϴ�" << endl;
			exit(0);
		}
		else {
			while (ifs >> chekSubject) {
				if (chekSubject == to_string(subjectNum)) {
					check = true;
				}
			}
			if (check) {
				cout << "������ ������ �����մϴ�." << endl;
			}
			else {
				ofs << subjectNum << " ";
			}
		}
		ofs.close();
	}

	int* subjectLoad(string studentId) {
		ifstream ifs;
		string subjectNum;
		//�迭�� �츮������ static���
		//������� ������ �̻��� �ּҰ��� ��ȯ��.
		static int subjects[10] = { 0 };
		int count = -1;
		string name;
		string id;
		string pw;
		string email;
		int accountGrade;
		studentId += ".txt";
		ifs.open(studentId.c_str());
		if (!ifs) {
			cout << "������ �� �� �����ϴ�.";
			
		}
		else {
			if (ifs >> id >> pw >> name >> email >> accountGrade) {
				// ȸ�� ���� �ڿ� ����� ���� �̸��� �޾ƿ������� ifs�� ȸ�������� �޾� ���������.
			}
			while (ifs >> subjectNum) {
				count++;
				subjects[count] = atoi(subjectNum.c_str());
				subjectNum.clear();

			}

			//���� �˾Ƴ��� �ʿ�
			/*for (int i = 0; i <= count; i++) {
				cout << subjects[i] << endl;
			}*/
		}
		ifs.close();

		return subjects;
	}
	

	Account* fileLoad(string fileId) {
		ifstream ifs;
		Account* account;
		string name;
		string id;
		string pw;
		string email;
		int accountGrade;
		fileId += ".txt";
		ifs.open(fileId.c_str());
		if (!ifs) {
			return NULL;
		}

		while (ifs >> id >> pw >> name >> email >> accountGrade) {
			if (accountGrade == 0) {
				//�������϶�
				account = new Administrator(name, id, pw, email);
			}
			else if (accountGrade == 1) {
				//�л��϶�
				account = new Student(name, id, pw, email);
			}
		}
		ifs.close();

		return account;
	}
};