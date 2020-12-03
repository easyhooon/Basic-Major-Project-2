#pragma once
#include "FileManager.h"
#include "SubjectPlan.h"

using namespace std;

class SubjectPlanFile : public FileManager {
private:
	//�����ڸ� save �� �� �ְ� �ϱ�. ���� ��� �߰�
	void fileSave(string subjectName) {
		string evaluation;
		string filePath = subjectName + " ���ǰ�ȹ��.txt";

		// write File
		ofstream ofs;
		ofs.open(filePath.data(), ios::app);
		// ios::app �̾�� �����ϰ� �ϴ� ����
		if (!ofs) {
			cout << "������ �� �� �����ϴ�" << endl;
			exit(0);
		}

		cout << "������ �Է����ּ���()" << endl;
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
		string filePath = subjectName + " ���ǰ�ȹ��.txt";

		// read File
		ifs.open(filePath.c_str());

		if (!ifs) {
			cout << "���ǰ�ȹ���� �������� �ʽ��ϴ�." << endl;
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