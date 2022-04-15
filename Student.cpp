// Student.cpp : ���ļ����� "main" ����������ִ�н��ڴ˴���ʼ��������
//
#include "Student.h"

Student::Student()
{
}

Student::Student(const Student& S) {
    info = S.info;
    info.name = string(S.info.name);
}

Student::Student(StudentInfo _info) {
    info = _info;
    info.name = string(_info.name);
}

Student Student::operator=(const Student& S) {
    info = S.info;
    info.name = string(S.info.name);
    return *this;
}

void Student::DisplayInfo() {

//    cout << "ѧ��\t����\t�༶\t��ѧ�ɼ�\t����ɼ�\t������ɼ�\t�ܷ�\t����\n" << endl;
    cout << info.studentNumber << "\t";
    cout << info.name << "\t";
    cout << info.classNumber << "\t";
    cout << info.scoreMath << "\t";
    cout << info.scoreEnglish << "\t";
    cout << info.scoreComputer << "\t";
    cout << info.scoreMath + info.scoreEnglish + info.scoreComputer << "\t";
    printf("%.1f\n", (double)(info.scoreMath + info.scoreEnglish + info.scoreComputer) / 3.0);
}

StudentInfo Student::GetInfo() const {
    StudentInfo _info = info;
    _info.name = string(info.name);
    return _info;
}

