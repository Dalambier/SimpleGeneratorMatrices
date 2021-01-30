#include <iostream>
#include <Windows.h>
#include <stdio.h>
#include <ctime>

HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
using namespace std;

const short FD_color = 12;
const short FP_color = 14;
const short SD_color = 11;
const short SP_color = 9;
const short DD_color = 10;
const short PP_color = 13;

void color(int value, int colorID, bool endline = false)
{
	SetConsoleTextAttribute(handle, colorID);
	cout << '\t' << value;
	if (endline)
	{
		cout << endl;
	}
	SetConsoleTextAttribute(handle, 15);
}

void arrwork(int x, int y)
{
	srand((unsigned)time(NULL));
	int sizeline(y*5), matrix, DD(0), PP(0), FD(0), FP(0), SD(0), SP(0), sum(0); //F-first, S-second, P-parallel, D-diagonal.
	system("cls");
	cout << "\n\tМатрица:\n";


	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			matrix = 11 + rand() % 88;
			sum += matrix;

			if ((i == j) && (y - j == i + 1) ) //Пересекающие диагонали
			{
				color(matrix, DD_color);
				DD += matrix; FD += matrix; SD += matrix;
			}
			else if ( ((i - 1 == j) || (i + 1 == j)) && ((y - j == i + 2) || (y - j == i)) ) //Пересекающие параллели
			{
				color(matrix, PP_color); 
				PP += matrix; FP += matrix; SP += matrix;
			}
			else if (i == j) //Главная диагональ
			{
				color(matrix, FD_color);
				FD += matrix;
			}
			else if (y - j == i + 1) // Побочная диагональ
			{
				color(matrix, SD_color);
				SD += matrix;
			}
			else if ((i - 1 == j) || (i + 1 == j)) //Главные параллели
			{
				color(matrix, FP_color);
				FP += matrix;
			}
			else if ((y - j == i + 2) || (y - j == i)) //Побочные параллели
			{
				color(matrix, SP_color);
				SP += matrix;
			}
			else //Остальное
			{
				cout << '\t' << matrix;
			}
		}
		cout << endl << endl;
	}
	cout << "\n\tСумма главной диагонали: "; color(FD, FD_color, true);
	cout << "\tСумма параллельных линий ГД: "; color(FP, FP_color, true);
	cout << "\tСумма побочной диагонали: "; color(SD, SD_color, true);
	cout << "\tСумма параллельных линий ПД: "; color(SP, SP_color, true);
	cout << endl;
	cout << "\tОбщая сумма всех элементов: "; color(sum, 15, true);
	
	if (DD!=0)
	{
		cout << "\tСумма пересекающих диагоналей: "; color(DD, DD_color, true);
		cout << "\tСумма пересекающих параллелей: "; color(PP, PP_color, true);
	}
	cout << endl;

	if (x == y)
		cout << "\tДанная матрица является квадратной\n\n";
	else
		cout << "\n\tДанная матрица не является квадратной\n";
	cout << "\tВсего строк в матрице:    "; color(x, FP_color, true);
	cout << "\tВсего столбцов в матрице: "; color(y, FP_color, true);
	cout << "\tВсего элементов в матрице: "; color(x*y, FD_color, false);
	cout << endl << endl;
}

int main()
{
	SetConsoleTextAttribute(handle, 15);
	setlocale(LC_ALL, "ru");
	system("title Работа с матрицами");
	cout << "Разработчик - Гришин Данил Витальевич\n\n";
	int x, y;
	while (true)
	{
		cout << "Введите x и y матрицы:\n(Введите нулевую матрицу, чтобы завершить работу)\n"; cin >> x >> y;
		if ((x == 0) && (y == 0)) break;
		arrwork (x,y);
	}
	return 0;
}