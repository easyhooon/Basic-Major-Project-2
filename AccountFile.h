#pragma once
#include "FileManager.h"
#include "Student.h"
#include "Administrator.h"
#include <string>
using namespace std;

//FileMager 자식클래스, 계정 파일 입출력
class AccountFile : public FileManager {
public:
	AccountFile() {

	}

	void fileSave(Student student) {
		ofstream ofs;
		string fileName = student.getId() + ".txt";
		ofs.open(fileName);
		if (!ofs) {
			cout << "학생정보를 저장할 수 없습니다." << endl;
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
			cout << "관리자정보를 저장할 수 없습니다." << endl;
			exit(0);
		}
		ofs << admin.getId() << " " << admin.getPW() << " " << admin.getName() << " " << admin.getEmail() << " " << admin.getAccountGrade() << endl;

		ofs.close();
	}

	void subjectSave(Student student, int subjectNum) {
		string filePath = student.getName() + ".txt";
		// write File
		string chekSubject;
		//이미 과목이 있으면 true 없으면 false;
		bool check = false;
		ofstream ofs;
		ifstream ifs;
		ofs.open(filePath.data(), ios::app);
		ifs.open(filePath.c_str());
		// ios::app 이어쓰기 가능하게 하는 역할
		if (!ofs) {
			cout << "파일을 열 수 없습니다" << endl;
			exit(0);
		}
		else {
			while (ifs >> chekSubject) {
				if (chekSubject == to_string(subjectNum)) {
					check = true;
				}
			}
			if (check) {
				cout << "동일한 과목이 존재합니다." << endl;
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
		//배열을 살리기위해 static사용
		//사용하지 않으면 이상한 주소값을 반환함.
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
			cout << "파일을 열 수 없습니다.";
			
		}
		else {
			if (ifs >> id >> pw >> name >> email >> accountGrade) {
				// 회원 정보 뒤에 저장된 과목 이름을 받아오기위해 ifs로 회원정보를 받아 흘려버린다.
			}
			while (ifs >> subjectNum) {
				count++;
				subjects[count] = atoi(subjectNum.c_str());
				subjectNum.clear();

			}

			//길이 알아내기 필요
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
				//관리자일때
				account = new Administrator(name, id, pw, email);
			}
			else if (accountGrade == 1) {
				//학생일때
				account = new Student(name, id, pw, email);
			}
		}
		ifs.close();

		return account;
	}
};