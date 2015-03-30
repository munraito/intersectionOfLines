#include "stdafx.h"
#include <iostream>
#include <algorithm>
using namespace std;

int n, i = 0, j = 0;
bool flag = true; //булевой переменной определяем, будут ли несовпадения прямых

struct pt {
	int x, y; //координаты начала и конца
};

inline bool getIntersect(int a, int b, int c, int d) { //функция проверки пересечения двух прямых
	if (a > b)  swap(a, b);
	if (c > d)  swap(c, d);
	return (max(a, c) <= min(b, d));
}
inline bool getAllConnections(int n) {
	pt *a = new pt[n]; //динамический массив для экономии места
	while (i < n){
		cout << "Введите координаты " << i + 1 << "-го отрезка" << endl;
		cin >> a[i].x >> a[i].y;
		while (j < i){ //этим циклом сравниваем i-тую прямую со всеми предшествующими
			if (getIntersect(a[i].x, a[i].y, a[j].x, a[j].y)) flag = true;
			else {
				flag = false;
				break; //если хоть одно несовпадение — меняем флаг и выходим из цикла
			}
			j++;
		}
		if (!flag) break; //не делаем лишних итераций
		i++;
	}
	delete[] a;
	return flag;
}

int main() {
	setlocale(LC_ALL, "Russian");
	cout << "Введите количество отрезков" << endl;
	cin >> n;
	if (n > 1) { //незачем что-то делать, если ввели неправильное количество прямых 
		if (getAllConnections(n)) cout << "Есть общие точки" << endl;
		else cout << "Нет точек" << endl;
	}
	else cout << "Введено некорректное количество прямых (надо 2 или больше)" << endl;
	return 0;
}
