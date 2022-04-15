#include "StudentManager.h"

StudentManager::StudentManager() {

}

StudentManager::~StudentManager() {

}

Student& StudentManager::operator[](unsigned index) {
	if (index < StudentList.size())
		return StudentList.at(index);
	else
		return *StudentList.end();

}

bool StudentManager::MainMenu() {
	cout << "------------------------------------------------" << endl;
	cout << "\t\t学生成绩管理系统                     " << endl;
	cout << "------------------------------------------------" << endl;
	cout << "\t\t1.录入学生信息" << endl;
	cout << "\t\t2.显示学生信息" << endl;
	cout << "\t\t3.查询学生信息" << endl;
	cout << "\t\t4.修改学生信息" << endl;
	cout << "\t\t5.添加学生信息" << endl;
	cout << "\t\t6.排序学生信息" << endl;
	cout << "\t\t7.删除学生信息" << endl;
	cout << "\t\t0.退出" << endl;
	cout << "------------------------------------------------" << endl;
	cout << "请选择：[ ]\b\b";
	return true;
}

bool StudentManager::ImportMenu() {
	cout << "------------------------------------------------" << endl;
	cout << "\t\t  录入学生信息                     " << endl;
	cout << "------------------------------------------------" << endl;
	cout << "\t\t1.文件批量导入" << endl;
	cout << "\t\t2.手动批量导入" << endl;
	cout << "\t\t0.返回上层菜单" << endl;
	cout << "------------------------------------------------" << endl;
	cout << "请选择：[ ]\b\b";
	return true;
}

bool StudentManager::DisplayMenu() {
	cout << "------------------------------------------------" << endl;
	cout << "\t\t  显示学生信息                     " << endl;
	cout << "------------------------------------------------" << endl;

	return true;
}

bool StudentManager::FindMenu() {
	cout << "------------------------------------------------" << endl;
	cout << "\t\t  查找学生信息                     " << endl;
	cout << "------------------------------------------------" << endl;
	return true;
}

bool StudentManager::ReviseMenu() {
	cout << "------------------------------------------------" << endl;
	cout << "\t\t  修改学生信息                     " << endl;
	cout << "------------------------------------------------" << endl;
	return true;
}

bool StudentManager::ReviseMenu2() {
	cout << "------------------------------------------------" << endl;
	cout << "请选择修改项目:" << endl;
	cout << "1.修改学号" << endl;
	cout << "2.修改姓名" << endl;
	cout << "3.修改班号" << endl;
	cout << "4.修改数学成绩" << endl;
	cout << "5.修改英语成绩" << endl;
	cout << "6.修改计算机成绩" << endl;
	cout << "0.返回上层菜单" << endl;
	cout << "------------------------------------------------" << endl;
	cout << "请选择：[ ]\b\b";
	return true;
}

bool StudentManager::AddMenu() {
	cout << "------------------------------------------------" << endl;
	cout << "\t\t  添加学生信息                     " << endl;
	cout << "------------------------------------------------" << endl;
	return true;
}

bool StudentManager::SortMenu() {
	cout << "------------------------------------------------" << endl;
	cout << "\t\t  排序学生信息                     " << endl;
	cout << "------------------------------------------------" << endl;
	cout << "\t\t1.按学号排序" << endl;
	cout << "\t\t2.按数学成绩排序" << endl;
	cout << "\t\t3.按英语成绩排序" << endl;
	cout << "\t\t4.按计算机成绩排序" << endl;
	cout << "\t\t5.按平均成绩排序" << endl;
	cout << "\t\t6.按总分成绩排序" << endl;
	cout << "\t\t0.返回上层菜单" << endl;
	cout << "------------------------------------------------" << endl;
	cout << "请选择排序关键字：[ ]\b\b";
	return true;
}

bool StudentManager::EraseMenu() {
	cout << "------------------------------------------------" << endl;
	cout << "\t\t  删除学生信息                     " << endl;
	cout << "------------------------------------------------" << endl;
	return true;
}

void StudentManager::erase(const unsigned index) {
	if (index < StudentList.size())
		StudentList.erase(StudentList.begin() + index);
}

void StudentManager::revise(const unsigned studentNumber, const Student& StuInfo) {
	StudentList.at(studentNumber) = Student(StuInfo);

}

void StudentManager::sort(SortKey key) {
	switch (key) {
	case SortKey::SCORE_MATH:
		break;
	case SortKey::SCORE_ENGLISH:
		break;
	case SortKey::SCORE_COMPUTER:
		break;
	case SortKey::SCORE_AVERAGE:
		break;
	case SortKey::SCORE_SUM:
		break;
	case SortKey::STUDENTNUMBER:
		break;
	default:
		break;
	}
}

bool StudentManager::import(string filePath) {
	Student* S = nullptr;
	FILE* fp = fopen(filePath.c_str(), "r");
	if (!fp) {
		cout << "文件打开失败！" << endl;
		return false;
	}
	StudentInfo _info;
	char str[20];
	while (fscanf(fp, "%u\t%s\t%u\t%lf\t%lf\t%lf\n", &_info.studentNumber, str, &_info.classNumber,
		&_info.scoreMath, &_info.scoreEnglish, &_info.scoreComputer) != EOF) {
		_info.name = string(str);
		S = new Student(_info);
		StudentList.push_back(*S);
	}
	return true;
}

int StudentManager::find(const unsigned _studentNumber) {
	for (unsigned i = 0; i < StudentList.size(); i++) {
		if (StudentList.at(i).GetInfo().studentNumber == _studentNumber) {
			return i;
		}
	}
	return -1;
}

void StudentManager::_sort(SortKey key) {
	vector<Student>* sortList = new vector<Student>;
	switch (key) {
	case SortKey::SCORE_MATH: {
		while (!StudentList.empty()) {
			max(key, *sortList);
		}
	}
		break;
	case SortKey::SCORE_ENGLISH: {
		while (!StudentList.empty()) {
			max(key, *sortList);
		}
	}
		break;
	case SortKey::SCORE_COMPUTER: {
		while (!StudentList.empty()) {
			max(key, *sortList);
		}
	}
		break;
	case SortKey::SCORE_AVERAGE:
	case SortKey::SCORE_SUM: {
		while (!StudentList.empty()) {
			max(key, *sortList);
		}
	}
		break;
	case SortKey::STUDENTNUMBER: {
		while (!StudentList.empty()) {
			max(key, *sortList);
		}
	}
		break;
	default:
		break;
	}
	StudentList = *sortList;
}

Student StudentManager::max(SortKey key, vector<Student>& sortList) {
	Student maxStudent;
	auto it_rm = StudentList.end();	// 待删除
	double max = 0;
	switch (key) {
	case SortKey::SCORE_MATH: {
		for (auto it = StudentList.begin(); it != StudentList.end(); it++) {
			if (it->GetInfo().scoreMath > max) {
				max = it->GetInfo().scoreMath;
				it_rm = it;
				maxStudent = *it;
			}
		}
	}
	break;
	case SortKey::SCORE_ENGLISH: {
		for (auto it = StudentList.begin(); it != StudentList.end(); it++) {
			if (it->GetInfo().scoreEnglish > max) {
				max = it->GetInfo().scoreEnglish;
				it_rm = it;
				maxStudent = *it;
			}
		}
	}
	break;
	case SortKey::SCORE_COMPUTER: {
		for (auto it = StudentList.begin(); it != StudentList.end(); it++) {
			if (it->GetInfo().scoreComputer > max) {
				max = it->GetInfo().scoreComputer;
				it_rm = it;
				maxStudent = *it;
			}
		}
	}
	break;
	case SortKey::SCORE_AVERAGE:
	case SortKey::SCORE_SUM: {
		for (auto it = StudentList.begin(); it != StudentList.end(); it++) {
			if ((it->GetInfo().scoreComputer + it->GetInfo().scoreEnglish + it->GetInfo().scoreMath) > max) {
				max = (it->GetInfo().scoreComputer + it->GetInfo().scoreEnglish + it->GetInfo().scoreMath);
				it_rm = it;
				maxStudent = *it;
			}
		}
	}
	break;
	case SortKey::STUDENTNUMBER: {
		for (auto it = StudentList.begin(); it != StudentList.end(); it++) {
			if (it->GetInfo().studentNumber > max) {
				max = it->GetInfo().studentNumber;
				it_rm = it;
				maxStudent = *it;
			}
		}
	}
	break;
	default:
		break;
	}

	sortList.push_back(*it_rm);
	StudentList.erase(it_rm);

	return Student();
}

void StudentManager::Manager() {
	char op = '0';
	string fileName;
	StudentInfo _info;
	Student tempStudent;
	int index;

	while (!system("cls") && MainMenu() && cin >> op && op != '0') {
		switch (op) {
			// 录入
		case '1': {
			char op1;
			while (!system("cls") && ImportMenu() && cin >> op1) {
				switch (op1) {
				case '1':
					cout << "请输入文件名：" << endl;
					cin >> fileName;	// 输入文件名字
					if (import(fileName))
						cout << "导入成功" << endl;
					else
						cout << "导入失败" << endl;
					system("pause");
					break;
				case '2':
					char op11;
					do {
						system("cls");
						ImportMenu();
						cout << "\b\b\b\b\b\b\b\b\b\b\b\b";
						cout << "请按顺序依次输入学生信息, (学号，姓名，班级，数学、外语、计算机成绩):" << endl;
						cin >> _info.studentNumber >> _info.name >> _info.classNumber >> _info.scoreMath >> _info.scoreEnglish >> _info.scoreComputer;
						StudentList.push_back(Student(_info));
						cout << "导入成功" << endl;
						cout << "是否继续？" << endl;
						cout << "1.继续" << endl;
						cout << "0.结束" << endl;
					} while (cin >> op11 && op11 == '1' && op11 != '0');

					break;
				case '0':
					break;
				default:
					cout << "无效的输入，请重试" << endl;
					system("pause");
					break;
				}
				if (op1 == '0')
					break;
			}
		}
				break;
				// 显示
		case '2': {
			system("cls");
			DisplayMenu();
			if (StudentList.empty()) {
				cout << "学生数据为空" << endl;
				system("pause");
				system("cls");
				break;
			}
			cout << "学号\t姓名\t班级\t数\t外\t计\t总分\t均分" << endl;
			for (auto it = StudentList.begin(); it != StudentList.end(); it++) {
				it->DisplayInfo();
			}
			cout << "显示完毕" << endl;
			system("pause");
			system("cls");
		}
				break;
				// 查询
		case '3': {
			char op3;
			do {
				system("cls");
				FindMenu();
				cout << "请输入学号:";
				cin >> _info.studentNumber;
				if ((index = find(_info.studentNumber)) != -1) {
					cout << "查询成功" << endl << endl;
					cout << "学号\t姓名\t班级\t数\t外\t计\t总分\t均分" << endl << endl;
					StudentList.at(index).DisplayInfo();
				}
				else {
					cout << "查询失败" << endl << endl;
				}
				cout << "------------------------------------------------" << endl;
				cout << "是否继续？" << endl;
				cout << "1.继续" << endl;
				cout << "0.结束" << endl;
			} while (cin >> op3 && op3 != '0');
			if (op3 == '0')
				system("cls");
		}
				break;
				// 修改
		case '4': {
			//char op4;
			while (!system("cls") && ReviseMenu() && cout << "请输入学号(输入 0 返回上层菜单):") {
				cin >> _info.studentNumber;
				if (_info.studentNumber == 0) {
					system("cls");
					break;
				}
				else if ((index = find(_info.studentNumber)) != -1) {
					cout << "查询成功" << endl << endl;
					cout << "学号\t姓名\t班级\t数\t外\t计\t总分\t均分" << endl << endl;
					StudentList.at(index).DisplayInfo();
					tempStudent = Student(StudentList.at(index));
					_info = tempStudent.GetInfo();

					system("pause");
				}
				else {
					cout << "查询失败" << endl << endl;
					continue;
				}
				char op44;
				while ( ReviseMenu2() && cin >> op44 && op44 != '0') {
					switch (op44) {
					case '1': {
						cout << "请修改学号: ";
						cin >> _info.studentNumber;
						revise(index, Student(_info));
						cout << "修改成功, 结果如下: " << endl;
						cout << "学号\t姓名\t班级\t数\t外\t计\t总分\t均分" << endl << endl;
						StudentList.at(index).DisplayInfo();
					}break;
					case '2': {
						cout << "请修改姓名: ";
						cin >> _info.name;
						revise(index, Student(_info));
						cout << "修改成功, 结果如下: " << endl;
						cout << "学号\t姓名\t班级\t数\t外\t计\t总分\t均分" << endl << endl;
						StudentList.at(index).DisplayInfo();
					}break;
					case '3': {
						cout << "请修改班号: ";
						cin >> _info.classNumber;
						revise(index, Student(_info));
						cout << "修改成功, 结果如下: " << endl;
						cout << "学号\t姓名\t班级\t数\t外\t计\t总分\t均分" << endl << endl;
						StudentList.at(index).DisplayInfo();

					}break;
					case '4': {
						cout << "请修改数学成绩: ";
						cin >> _info.scoreMath;
						revise(index, Student(_info));
						cout << "修改成功, 结果如下: " << endl;
						cout << "学号\t姓名\t班级\t数\t外\t计\t总分\t均分" << endl << endl;
						StudentList.at(index).DisplayInfo();
					}break;
					case '5': {
						cout << "请修改英语成绩: ";
						cin >> _info.scoreEnglish;
						revise(index, Student(_info));
						cout << "修改成功, 结果如下: " << endl;
						cout << "学号\t姓名\t班级\t数\t外\t计\t总分\t均分" << endl << endl;
						StudentList.at(index).DisplayInfo();
					}break;
					case '6': {
						cout << "请修改计算机成绩: ";
						cin >> _info.scoreComputer;
						revise(index, Student(_info));
						cout << "修改成功, 结果如下: " << endl;
						cout << "学号\t姓名\t班级\t数\t外\t计\t总分\t均分" << endl << endl;
						StudentList.at(index).DisplayInfo();
					}break;
					case '0':
						break;
					default:
						break;
					}
					system("pause");
					if (op44 == 0) {
						system("cls");
						break;
					}
				}
			}
		}
				break;
				// 添加
		case '5': {
			AddMenu();
			cout << "请按顺序依次输入学生信息, (学号，姓名，班级，数学、外语、计算机成绩):" << endl;
			cin >> _info.studentNumber >> _info.name >> _info.classNumber >> _info.scoreMath >> _info.scoreEnglish >> _info.scoreComputer;
			StudentList.push_back(Student(_info));
			cout << "添加成功" << endl;
			system("pause");
			system("cls");
		}
				break;
				// 排序
		case '6': {
			char op6;
			while (!system("cls") && SortMenu() && cin >> op6) {
				switch (op6) {
				case '1': _sort(SortKey::STUDENTNUMBER);
					break;
				case '2': _sort(SortKey::SCORE_MATH);
					break;
				case '3': _sort(SortKey::SCORE_ENGLISH);
					break;
				case '4': _sort(SortKey::SCORE_COMPUTER);
					break;
				case '5':
				case '6':_sort(SortKey::SCORE_SUM);
					break;
				case '0':
					break;
				default:
					break;
				}
				cout << "排序结束" << endl;
				system("pause");
				if (op6 == '0') {
					break;
				}
			}

		}
				break;
				// 删除
		case '7': {
			system("cls");
			EraseMenu();
			cout << "请输入待删除学生的学号: ";
			cin >> _info.studentNumber;
			if ((index = find(_info.studentNumber)) != -1) {
				StudentList.erase(StudentList.begin() + index);
				cout << "删除成功" << endl;
			}
			else {
				cout << "找不到该学生" << endl;
			}
			system("pause");

		}
				break;
				// 返回
		case '0':
			break;
		default: {
			cout << "无效的输入，请重试" << endl;
			system("pause");
		}break;
		}
	}
}

