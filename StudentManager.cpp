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
	cout << "\t\tѧ���ɼ�����ϵͳ                     " << endl;
	cout << "------------------------------------------------" << endl;
	cout << "\t\t1.¼��ѧ����Ϣ" << endl;
	cout << "\t\t2.��ʾѧ����Ϣ" << endl;
	cout << "\t\t3.��ѯѧ����Ϣ" << endl;
	cout << "\t\t4.�޸�ѧ����Ϣ" << endl;
	cout << "\t\t5.���ѧ����Ϣ" << endl;
	cout << "\t\t6.����ѧ����Ϣ" << endl;
	cout << "\t\t7.ɾ��ѧ����Ϣ" << endl;
	cout << "\t\t0.�˳�" << endl;
	cout << "------------------------------------------------" << endl;
	cout << "��ѡ��[ ]\b\b";
	return true;
}

bool StudentManager::ImportMenu() {
	cout << "------------------------------------------------" << endl;
	cout << "\t\t  ¼��ѧ����Ϣ                     " << endl;
	cout << "------------------------------------------------" << endl;
	cout << "\t\t1.�ļ���������" << endl;
	cout << "\t\t2.�ֶ���������" << endl;
	cout << "\t\t0.�����ϲ�˵�" << endl;
	cout << "------------------------------------------------" << endl;
	cout << "��ѡ��[ ]\b\b";
	return true;
}

bool StudentManager::DisplayMenu() {
	cout << "------------------------------------------------" << endl;
	cout << "\t\t  ��ʾѧ����Ϣ                     " << endl;
	cout << "------------------------------------------------" << endl;

	return true;
}

bool StudentManager::FindMenu() {
	cout << "------------------------------------------------" << endl;
	cout << "\t\t  ����ѧ����Ϣ                     " << endl;
	cout << "------------------------------------------------" << endl;
	return true;
}

bool StudentManager::ReviseMenu() {
	cout << "------------------------------------------------" << endl;
	cout << "\t\t  �޸�ѧ����Ϣ                     " << endl;
	cout << "------------------------------------------------" << endl;
	return true;
}

bool StudentManager::ReviseMenu2() {
	cout << "------------------------------------------------" << endl;
	cout << "��ѡ���޸���Ŀ:" << endl;
	cout << "1.�޸�ѧ��" << endl;
	cout << "2.�޸�����" << endl;
	cout << "3.�޸İ��" << endl;
	cout << "4.�޸���ѧ�ɼ�" << endl;
	cout << "5.�޸�Ӣ��ɼ�" << endl;
	cout << "6.�޸ļ�����ɼ�" << endl;
	cout << "0.�����ϲ�˵�" << endl;
	cout << "------------------------------------------------" << endl;
	cout << "��ѡ��[ ]\b\b";
	return true;
}

bool StudentManager::AddMenu() {
	cout << "------------------------------------------------" << endl;
	cout << "\t\t  ���ѧ����Ϣ                     " << endl;
	cout << "------------------------------------------------" << endl;
	return true;
}

bool StudentManager::SortMenu() {
	cout << "------------------------------------------------" << endl;
	cout << "\t\t  ����ѧ����Ϣ                     " << endl;
	cout << "------------------------------------------------" << endl;
	cout << "\t\t1.��ѧ������" << endl;
	cout << "\t\t2.����ѧ�ɼ�����" << endl;
	cout << "\t\t3.��Ӣ��ɼ�����" << endl;
	cout << "\t\t4.��������ɼ�����" << endl;
	cout << "\t\t5.��ƽ���ɼ�����" << endl;
	cout << "\t\t6.���ֳܷɼ�����" << endl;
	cout << "\t\t0.�����ϲ�˵�" << endl;
	cout << "------------------------------------------------" << endl;
	cout << "��ѡ������ؼ��֣�[ ]\b\b";
	return true;
}

bool StudentManager::EraseMenu() {
	cout << "------------------------------------------------" << endl;
	cout << "\t\t  ɾ��ѧ����Ϣ                     " << endl;
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
		cout << "�ļ���ʧ�ܣ�" << endl;
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
	auto it_rm = StudentList.end();	// ��ɾ��
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
			// ¼��
		case '1': {
			char op1;
			while (!system("cls") && ImportMenu() && cin >> op1) {
				switch (op1) {
				case '1':
					cout << "�������ļ�����" << endl;
					cin >> fileName;	// �����ļ�����
					if (import(fileName))
						cout << "����ɹ�" << endl;
					else
						cout << "����ʧ��" << endl;
					system("pause");
					break;
				case '2':
					char op11;
					do {
						system("cls");
						ImportMenu();
						cout << "\b\b\b\b\b\b\b\b\b\b\b\b";
						cout << "�밴˳����������ѧ����Ϣ, (ѧ�ţ��������༶����ѧ�����������ɼ�):" << endl;
						cin >> _info.studentNumber >> _info.name >> _info.classNumber >> _info.scoreMath >> _info.scoreEnglish >> _info.scoreComputer;
						StudentList.push_back(Student(_info));
						cout << "����ɹ�" << endl;
						cout << "�Ƿ������" << endl;
						cout << "1.����" << endl;
						cout << "0.����" << endl;
					} while (cin >> op11 && op11 == '1' && op11 != '0');

					break;
				case '0':
					break;
				default:
					cout << "��Ч�����룬������" << endl;
					system("pause");
					break;
				}
				if (op1 == '0')
					break;
			}
		}
				break;
				// ��ʾ
		case '2': {
			system("cls");
			DisplayMenu();
			if (StudentList.empty()) {
				cout << "ѧ������Ϊ��" << endl;
				system("pause");
				system("cls");
				break;
			}
			cout << "ѧ��\t����\t�༶\t��\t��\t��\t�ܷ�\t����" << endl;
			for (auto it = StudentList.begin(); it != StudentList.end(); it++) {
				it->DisplayInfo();
			}
			cout << "��ʾ���" << endl;
			system("pause");
			system("cls");
		}
				break;
				// ��ѯ
		case '3': {
			char op3;
			do {
				system("cls");
				FindMenu();
				cout << "������ѧ��:";
				cin >> _info.studentNumber;
				if ((index = find(_info.studentNumber)) != -1) {
					cout << "��ѯ�ɹ�" << endl << endl;
					cout << "ѧ��\t����\t�༶\t��\t��\t��\t�ܷ�\t����" << endl << endl;
					StudentList.at(index).DisplayInfo();
				}
				else {
					cout << "��ѯʧ��" << endl << endl;
				}
				cout << "------------------------------------------------" << endl;
				cout << "�Ƿ������" << endl;
				cout << "1.����" << endl;
				cout << "0.����" << endl;
			} while (cin >> op3 && op3 != '0');
			if (op3 == '0')
				system("cls");
		}
				break;
				// �޸�
		case '4': {
			//char op4;
			while (!system("cls") && ReviseMenu() && cout << "������ѧ��(���� 0 �����ϲ�˵�):") {
				cin >> _info.studentNumber;
				if (_info.studentNumber == 0) {
					system("cls");
					break;
				}
				else if ((index = find(_info.studentNumber)) != -1) {
					cout << "��ѯ�ɹ�" << endl << endl;
					cout << "ѧ��\t����\t�༶\t��\t��\t��\t�ܷ�\t����" << endl << endl;
					StudentList.at(index).DisplayInfo();
					tempStudent = Student(StudentList.at(index));
					_info = tempStudent.GetInfo();

					system("pause");
				}
				else {
					cout << "��ѯʧ��" << endl << endl;
					continue;
				}
				char op44;
				while ( ReviseMenu2() && cin >> op44 && op44 != '0') {
					switch (op44) {
					case '1': {
						cout << "���޸�ѧ��: ";
						cin >> _info.studentNumber;
						revise(index, Student(_info));
						cout << "�޸ĳɹ�, �������: " << endl;
						cout << "ѧ��\t����\t�༶\t��\t��\t��\t�ܷ�\t����" << endl << endl;
						StudentList.at(index).DisplayInfo();
					}break;
					case '2': {
						cout << "���޸�����: ";
						cin >> _info.name;
						revise(index, Student(_info));
						cout << "�޸ĳɹ�, �������: " << endl;
						cout << "ѧ��\t����\t�༶\t��\t��\t��\t�ܷ�\t����" << endl << endl;
						StudentList.at(index).DisplayInfo();
					}break;
					case '3': {
						cout << "���޸İ��: ";
						cin >> _info.classNumber;
						revise(index, Student(_info));
						cout << "�޸ĳɹ�, �������: " << endl;
						cout << "ѧ��\t����\t�༶\t��\t��\t��\t�ܷ�\t����" << endl << endl;
						StudentList.at(index).DisplayInfo();

					}break;
					case '4': {
						cout << "���޸���ѧ�ɼ�: ";
						cin >> _info.scoreMath;
						revise(index, Student(_info));
						cout << "�޸ĳɹ�, �������: " << endl;
						cout << "ѧ��\t����\t�༶\t��\t��\t��\t�ܷ�\t����" << endl << endl;
						StudentList.at(index).DisplayInfo();
					}break;
					case '5': {
						cout << "���޸�Ӣ��ɼ�: ";
						cin >> _info.scoreEnglish;
						revise(index, Student(_info));
						cout << "�޸ĳɹ�, �������: " << endl;
						cout << "ѧ��\t����\t�༶\t��\t��\t��\t�ܷ�\t����" << endl << endl;
						StudentList.at(index).DisplayInfo();
					}break;
					case '6': {
						cout << "���޸ļ�����ɼ�: ";
						cin >> _info.scoreComputer;
						revise(index, Student(_info));
						cout << "�޸ĳɹ�, �������: " << endl;
						cout << "ѧ��\t����\t�༶\t��\t��\t��\t�ܷ�\t����" << endl << endl;
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
				// ���
		case '5': {
			AddMenu();
			cout << "�밴˳����������ѧ����Ϣ, (ѧ�ţ��������༶����ѧ�����������ɼ�):" << endl;
			cin >> _info.studentNumber >> _info.name >> _info.classNumber >> _info.scoreMath >> _info.scoreEnglish >> _info.scoreComputer;
			StudentList.push_back(Student(_info));
			cout << "��ӳɹ�" << endl;
			system("pause");
			system("cls");
		}
				break;
				// ����
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
				cout << "�������" << endl;
				system("pause");
				if (op6 == '0') {
					break;
				}
			}

		}
				break;
				// ɾ��
		case '7': {
			system("cls");
			EraseMenu();
			cout << "�������ɾ��ѧ����ѧ��: ";
			cin >> _info.studentNumber;
			if ((index = find(_info.studentNumber)) != -1) {
				StudentList.erase(StudentList.begin() + index);
				cout << "ɾ���ɹ�" << endl;
			}
			else {
				cout << "�Ҳ�����ѧ��" << endl;
			}
			system("pause");

		}
				break;
				// ����
		case '0':
			break;
		default: {
			cout << "��Ч�����룬������" << endl;
			system("pause");
		}break;
		}
	}
}

