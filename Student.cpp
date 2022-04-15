// Student.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
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

//    cout << "学号\t姓名\t班级\t数学成绩\t外语成绩\t计算机成绩\t总分\t均分\n" << endl;
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

