
#pragma once
#include <iostream>
using namespace std;

typedef struct StudentInfo {
	string name;
	unsigned studentNumber = 0;
	unsigned classNumber = 0;
	double scoreMath = 0;
	double scoreEnglish = 0;
	double scoreComputer = 0;
} StudentInfo;

class Student {
private:
	StudentInfo info;	// ѧ����Ϣ
public:
	Student();
	Student(const Student& S);
	Student(StudentInfo _info);
	Student operator=(const Student& S);

public:
	void DisplayInfo();		// ��ʾ��Ϣ
	StudentInfo GetInfo() const;
};
