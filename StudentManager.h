#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include "Student.h"
#include <vector>

typedef enum class SortKey {
	SCORE_MATH,
	SCORE_ENGLISH,
	SCORE_COMPUTER,
	SCORE_AVERAGE,
	SCORE_SUM,
	STUDENTNUMBER
}SortKey;

class StudentManager {
private:
	vector<Student> StudentList;
public:
	StudentManager();
	~StudentManager();

	Student& operator[](unsigned index);

protected:
	// ���˵�
	bool MainMenu();
	// ������Ϣ �˵�
	bool ImportMenu();
	// ��ʾ��Ϣ �˵�
	bool DisplayMenu();
	// ������Ϣ �˵�
	bool FindMenu();
	// �޸���Ϣ �˵�
	bool ReviseMenu();
	bool ReviseMenu2();
	// ׷����Ϣ �˵�
	bool AddMenu();
	// ������Ϣ �˵�
	bool SortMenu();
	// ɾ����Ϣ �˵�
	bool EraseMenu();

protected:
	// ɾ��ָ���±��ѧ��
	void erase(const unsigned index);
	// �޸�ָ���±��ѧ����Ϣ
	void revise(const unsigned studentNumber, const Student& StuInfo);
	// ����ָ���ؼ�������
	void sort(SortKey key);
	// ����ѧ����Ϣ�ɼ�, ���ļ�������ֶ�����
	bool import(string filePath);
	// ����ѧ�Ų���ѧ�����ҵ������±꣬�Ҳ������� -1
	int find(const unsigned _studentNumber);
	// ѡ������(Ĭ���ǽ���)
	void _sort(SortKey key);
	Student max(SortKey key, vector<Student>& sortList);

public:
	void Manager();		// ����ϵͳ��ں���
};

