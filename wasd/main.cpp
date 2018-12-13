#include "Student.hpp"
#include <algorithm>

using namespace std;

int cmp(const void * a, const void *b){
	return ((Student*)a)->Surname() > ((Student*)b)->Surname();
}

int main(){
	const int size = 3;//размер массива	 10
	setlocale(LC_ALL, "");
	Student students[size];//сам массив студентов
	int a;
	while(true){
		 cout << "\n1. Считать данные\n2. Вывод двоечников\n3. Вывод всех\n4. Выход\n-> ";
		 cin >> a;
		 if(a == 1){
			 cout << "Фамилия Инициалы Группа оценки[5]\n";
			 try{
				 //считываем данные
				for(int i = 0; i < size; ++i){
				     cin >> students[i];
				}
				/*Сортируем*/
				qsort(students, size, sizeof(Student), cmp);
			 }
			 catch(const Exception& e){
				cout << "\n" << e.what();
			 }
		 }
		 if(a == 2){
			 bool flg = true;
			 for(int i = 0; i < size; ++i){
				if(students[i].ContainTwo()){
					cout << "\n" << students[i];
					flg = false;
				}
			 }
			 if(flg){
				cout << "Не найдено!";
			 }
		 }
		 else if(a == 3){
		   for(int i = 0; i < size; ++i){
					cout << "\n" << students[i];
			 }
		 }
		 if(a == 4){
			 return 0;
		 }
	}
}