#pragma once
#include "FileManager.h"
#include "SubjectPlan.h"

using namespace std;

class SubjectPlanFile : public FileManager {
private:
	//관리자만 save 할 수 있게 하기. 차후 기능 추가
	void fileSave(string subjectName) {
		string evaluation;
		string filePath = subjectName + " 강의계획서.txt";

		// write File
		ofstream ofs;
		ofs.open(filePath.data(), ios::app);
		// ios::app 이어쓰기 가능하게 하는 역할
		if (!ofs) {
			cout << "파일을 열 수 없습니다" << endl;
			exit(0);
		}

		cout << "내용을 입력해주세요()" << endl;
		getline(cin, evaluation);
		ofs << evaluation << endl;
		ofs.close();
	}

public:
	SubjectPlanFile() {

	}
	void fileLoad(string subjectName) {
		ifstream ifs;
		string line;
		string filePath = subjectName + " 강의계획서.txt";

		// read File
		ifs.open(filePath.c_str());

		if (!ifs) {
			cout << "강의계획서가 존재하지 않습니다." << endl;
			exit(0);
		}
		while (!ifs.eof()) {
			line.clear();
			getline(ifs, line);
			cout << line << endl;
		}
		ifs.close();
	}
};