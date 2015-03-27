// test_z.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <algorithm>
using namespace std;

struct pt {
	int x, y; //координаты начала и конца
};

inline bool getIntersect(int a, int b, int c, int d) { //функция проверки пересечения двух прямых
	if (a > b)  swap(a, b);
	if (c > d)  swap(c, d);
	return (max(a, c) <= min(b, d));
}

int _tmain(int argc, _TCHAR* argv[]) {
	setlocale(LC_ALL, "Russian");
	int n;
	cout << "Введите количество прямых" <<endl;
	cin >> n;
	if (n > 1) { //незачем проходить цикл, если ввели неправильное количество прямых 
	pt *a = new pt[n]; //динамический массив для экономии места
	bool flag = true; //булевой переменной определяем, будут ли несовпадения прямых
	int i = 0, j = 0;
	while (i < n){
		cout << "Введите координаты " << i + 1 << "-й прямой" << endl;
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

	if (flag) cout << "Есть общие точки" << endl;
	else cout << "Нет точек" << endl;
	delete[] a;
	}
	else cout << "Введено некорректное количество прямых (надо 2 или больше)" << endl;
	return 0;
}