#pragma once
#include "Exception.hpp"
#include <iostream>

class Student{
private:
	std::string init;//��������
	std::string surname;//�������
	std::string group;//������
	int marks[5];//������������
public:
	Student(const std::string& init = "", const std::string& surname = "", const std::string& group = "", int* marks = nullptr);
	Student(const Student& s);
	~Student();
	Student& operator=(const Student& s);//�������� ������������
public:
	friend std::istream& operator>>(std::istream& in, Student& s);//�������� �����
	friend std::ostream& operator<<(std::ostream& out, const Student& s);//�������� ������
public:
	std::string& initials();
	std::string& Surname();
	std::string& Group();
	int* Marks();
	//�������, �������� �� ������ ��������
	bool ContainTwo() const;
};