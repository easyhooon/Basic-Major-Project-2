#pragma once
#include "FileManager.h"
#include "SubjectEvaluation.h"
using namespace std;
class SubjectEvaluating : public FileManager {
public:
	SubjectEvaluating() {

	}
	//save �ʿ�
	void fileSave(string lectureName) {
		string evaluation;
		string filePath = lectureName + " ������.txt";

		// write File
		ofstream ofs;
		ofs.open(filePath.data(), ios::app);
		// ios::app �̾�� �����ϰ� �ϴ� ����
		if (!ofs) {
			cout << "������ �� �� �����ϴ�" << endl;
			exit(0);
		}

		cout << "������ �Է����ּ���: " << endl;
		getline(cin, evaluation);
		ofs << evaluation << endl;
		ofs.close();
	}

	void fileLoad(string lectureName) {
		ifstream ifs;
		string line;

		lectureName += " ������.txt";
		ifs.open(lectureName.c_str());	

		if (!ifs) {
			cout << "�ش簭�ǰ� �������� �ʽ��ϴ�." << endl;
		}

		while (!ifs.eof()) {
			line.clear();
			getline(ifs, line);
			cout << line << endl;
		}
		ifs.close();
	}
};