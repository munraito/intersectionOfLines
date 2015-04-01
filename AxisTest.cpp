#include <iostream>
#include <algorithm>
using namespace std;

//здесь вводим данные
int n, i = 0, j = 2, a, b;
struct pt {
	int x, y; //координаты начала и конца
};
pt *coord = NULL;

void massiveInput(int n, char **argv) { //функция для заполнения массива
	coord = new pt[n];
	while (i < n){
		coord[i].x = atoi(argv[j++]);
		coord[i].y = atoi(argv[j++]);
		if (coord[i].x > coord[i].y)  swap(coord[i].x, coord[i].y); // если ввели начало правее конца на оси, то меняем их местами
		i++;
	}
}

//здесь обрабатываем
bool getAllConnections(int n) {
	bool flag = false;
	while (i < n){
		if ((i > 1) && (flag)){
			a = max(coord[i - 2].x, coord[i - 1].x);
			b = min(coord[i - 2].y, coord[i - 1].y); //устанавливаем границы, где оба отрезка имеют общие точки
			cout << "Границы пересекаемости отрезков: [" << a << "; " << b << "]" << endl;
		}
		if (i > 0) { //начинаем проверять на пересечение со второго отрезка
			if (max(coord[i].x, a) <= min(coord[i].y, b)) flag = true; //если начало самого левого отрезка лежит на оси левее их концов (или соприкасается), то у отрезков есть точки соприкосновения
			else {
				flag = false;
				break; //если имеется хоть одно несовпадение — меняем флаг и выходим из цикла
			}
		}
		i++;
	}
	delete[] coord;
	return flag;
}

int main(int argc, char **argv) {
	setlocale(LC_ALL, "Russian");
	if (argc < 6) {
		cout << "Введено меньше двух отрезков" << endl;
		return 0;
	}
	n = atoi(argv[1]);
	massiveInput(n, argv);
	if (getAllConnections(n))
		cout << "Есть общие точки" << endl;
	else
		cout << "Нет точек" << endl;
	return 0;
}
