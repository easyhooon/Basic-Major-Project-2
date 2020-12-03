#pragma once
#include "FileManager.h"
#include "SubjectEvaluation.h"
using namespace std;
class SubjectEvaluating : public FileManager {
public:
	SubjectEvaluating() {

	}
	//save 필요
	void fileSave(string lectureName) {
		string evaluation;
		string filePath = lectureName + " 강의평가.txt";

		// write File
		ofstream ofs;
		ofs.open(filePath.data(), ios::app);
		// ios::app 이어쓰기 가능하게 하는 역할
		if (!ofs) {
			cout << "파일을 열 수 없습니다" << endl;
			exit(0);
		}

		cout << "내용을 입력해주세요: " << endl;
		getline(cin, evaluation);
		ofs << evaluation << endl;
		ofs.close();
	}

	void fileLoad(string lectureName) {
		ifstream ifs;
		string line;

		lectureName += " 강의평가.txt";
		ifs.open(lectureName.c_str());	

		if (!ifs) {
			cout << "해당강의가 존재하지 않습니다." << endl;
		}

		while (!ifs.eof()) {
			line.clear();
			getline(ifs, line);
			cout << line << endl;
		}
		ifs.close();
	}
};