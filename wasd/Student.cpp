#include "Student.hpp"

Student::Student(const std::string& init, const std::string& surname, const std::string& group, int * marks):
init(init), surname(surname), group(group){
	if(marks != nullptr){
		this->marks[0] = marks[0];
		this->marks[1] = marks[1];
		this->marks[2] = marks[2];
		this->marks[3] = marks[3];
		this->marks[4] = marks[4];
	}
	else{
		 this->marks[0] = 1;
		this->marks[1] = 1;
		this->marks[2] = 1;
		this->marks[3] = 1;
		this->marks[4] = 1;
	}
    std::cout << "\nконструктор Student"; 
}

Student::Student(const Student& s):
init(s.init), surname(s.surname), group(s.group){
	marks[0] = s.marks[0];
	marks[1] = s.marks[1];
	marks[2] = s.marks[2];
	marks[3] = s.marks[3];
	marks[4] = s.marks[4];
	 std::cout << "\nконструктор копирования Student"; 
}

Student::~Student(){ std::cout << "\nдеструктор Student"; }

Student& Student::operator=(const Student& s){//оператор присваивания
	if(this == &s){
		return *this;
	}
	init = s.init;
	surname = s.surname;
	group = s.group;
	marks[0] = s.marks[0];
	marks[1] = s.marks[1];
	marks[2] = s.marks[2];
	marks[3] = s.marks[3];
	marks[4] = s.marks[4];
	return *this;
}
//геттеры и сеттеры
std::string& Student::initials(){ return init; }
std::string& Student::Surname(){ return surname; }
std::string& Student::Group(){ return group; }
int* Student::Marks(){
	return marks;
}


std::istream& operator>>(std::istream& in, Student& s){//оператор ввода
	if(!(in >> s.group >> s.surname >> s.group >> s.marks[0] >> s.marks[1] >> s.marks[2] >> s.marks[3] >> s.marks[4])){
		throw Exception("Некорректный ввод");
	}
	return in;
}

std::ostream& operator<<(std::ostream& out, const Student& s){//оператор вывода
	out << s.surname << ' ' << s.init << ' ' << s.group 
		<< "\n" << s.marks[0] << ' ' << s.marks[1] << ' ' << s.marks[2] << ' ' << s.marks[3] << ' ' << s.marks[4];
	return out;
}


bool Student::ContainTwo() const{
	 return marks[0] == 2 || marks[1] == 2 || marks[2] == 2 || marks[3] == 2 || marks[4] == 2;
}