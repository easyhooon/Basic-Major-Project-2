#pragma once
#include "FileManager.h"
#include "Subject.h"

class SubjectFile : public FileManager {
public:
	SubjectFile() {

	}
	//강의번호를 파일이름으로해서 저장하는 방법
	void fileSave(Subject subject) {
		ofstream ofs;
		string fileName = to_string(subject.getSubNum()) + ".txt";
		ofs.open(fileName);

		if (!ofs) {
			cout << "강의정보를 저장할 수 없습니다." << endl;
			exit(0);
		}

		ofs << subject.getSubName() << " " << subject.getSubNum() << " " <<  subject.getSubCredit() << " " << subject.getSubLimit() << endl;
		ofs << subject.getSubDay() << " " << subject.getSubStart() << " " << subject.getSubFinish() << " " << subject.getSubRoom() << endl;
		if (subject.getSubDay2() != "") {
			ofs << subject.getSubDay2() << " " << subject.getSubStart2() << " " << subject.getSubFinish2() << " " << subject.getSubRoom2();
		}
		ofs.close();
	}

	//강의이름을 파일이름으로해서 저장하는 방법
	/*
	void fileSave(Subject subject) {
		ofstream ofs;
		string fileName = subject.getSubName() + ".txt";
		ofs.open(fileName);

		if (!ofs) {
			cout << "강의정보를 저장할 수 없습니다." << endl;
			exit(0);
		}

		ofs << subject.getSubName() << " " << subject.getSubNum() << " " << subject.getSubCredit() << " " << subject.getSubLimit() << endl;
		ofs << subject.getSubDay() << " " << subject.getSubStart() << " " << subject.getSubFinish() << " " << subject.getSubRoom() << endl;
		if (subject.getSubDay2() != "") {
			ofs << subject.getSubDay2() << " " << subject.getSubStart2() << " " << subject.getSubFinish2() << " " << subject.getSubRoom2();
		}
		ofs.close();
	}
	*/

	//강의번호로 과목 정보 불러오기, Subject 객체를 리턴 받음
	Subject fileLoad(int subjectNum) {
		ifstream ifs;
		Subject subject;

		string name;
		int num;
		string day, day2;
		int start, finish, start2, finish2;
		string room, room2;
		int credit;
		int limit;

		string fileName = to_string(subjectNum) + ".txt";
		ifs.open(fileName.c_str());

		if (!ifs) {

		}
		else {
			if (ifs >> name >> num >> credit >> limit) {

			}

			if (ifs >> day >> start >> finish >> room) {
				subject = Subject(name, num, credit, limit, day, start, finish, room);
			}

			if (ifs >> day2 >> start2 >> finish2 >> room2) {
				//delete subject;
				subject = Subject(name, num, credit, limit, day, start, finish, room, day2, start2, finish2, room2);
			}
		}

		ifs.close();

		return subject;
	}
};