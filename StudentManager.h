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
	// 主菜单
	bool MainMenu();
	// 导入信息 菜单
	bool ImportMenu();
	// 显示信息 菜单
	bool DisplayMenu();
	// 查找信息 菜单
	bool FindMenu();
	// 修改信息 菜单
	bool ReviseMenu();
	bool ReviseMenu2();
	// 追加信息 菜单
	bool AddMenu();
	// 排序信息 菜单
	bool SortMenu();
	// 删除信息 菜单
	bool EraseMenu();

protected:
	// 删除指定下标的学生
	void erase(const unsigned index);
	// 修改指定下标的学生信息
	void revise(const unsigned studentNumber, const Student& StuInfo);
	// 按照指定关键字排序
	void sort(SortKey key);
	// 导入学生信息成绩, 分文件导入和手动导入
	bool import(string filePath);
	// 按照学号查找学生，找到返回下标，找不到返回 -1
	int find(const unsigned _studentNumber);
	// 选择排序(默认是降序)
	void _sort(SortKey key);
	Student max(SortKey key, vector<Student>& sortList);

public:
	void Manager();		// 管理系统入口函数
};

