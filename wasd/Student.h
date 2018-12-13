#pragma once
#include "Exception.hpp"
#include <iostream>

class Student{
private:
	std::string init;//инициалы
	std::string surname;//фамили€
	std::string group;//группа
	int marks[5];//успеваемость
public:
	Student(const std::string& init = "", const std::string& surname = "", const std::string& group = "", int* marks = nullptr);
	Student(const Student& s);
	~Student();
	Student& operator=(const Student& s);//оператор присваивани€
public:
	friend std::istream& operator>>(std::istream& in, Student& s);//оператор ввода
	friend std::ostream& operator<<(std::ostream& out, const Student& s);//оператор вывода
public:
	std::string& initials();
	std::string& Surname();
	std::string& Group();
	int* Marks();
	//выводит, €вл€ютс€ ли оценки хорошими
	bool ContainTwo() const;
};