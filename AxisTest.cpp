#include <iostream>
#include <algorithm>
using namespace std;

//здесь вводим данные
int n, j = 2;
bool flag = true;
struct pt {
	int x, y; //координаты начала и конца
};
pt *coord = NULL;

void massiveInput(int n, char **argv) { //функция для заполнения массива
	coord = new pt[n];
	for (int i = 0; i < n; i++){
		coord[i].x = atoi(argv[j++]);
		coord[i].y = atoi(argv[j++]);
		cout << coord[i].x << " " << coord[i].y <<endl;
		if (coord[i].x > coord[i].y)  swap(coord[i].x, coord[i].y); // если ввели начало правее конца на оси, то меняем их местами
	}
}

//здесь обрабатываем
bool getAllConnections(int n) {
	int i = 0;
	int a = coord[0].x, b = coord[0].y;
	while (i < n){
		if ((i > 0) && (flag)){
			a = max(coord[i - 1].x, coord[i].x);
			b = min(coord[i - 1].y, coord[i].y); //устанавливаем границы, где оба отрезка имеют общие точки
		}
		if (max(coord[i].x, a) <= min(coord[i].y, b)) flag = true; //если начало самого левого отрезка лежит на оси левее их концов (или соприкасается), то у отрезков есть точки соприкосновения
		else {
			flag = false;
			break; //если имеется хоть одно несовпадение — меняем флаг и выходим из цикла
		}
		i++;
	}
	delete[] coord;
	return flag;
}

int main(int argc, char **argv) {
	setlocale(LC_ALL, "Russian");
	if (argc < 6) {
		cout << "Введено недостаточно аргументов (" << argc-1 << ")."<< endl;
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
