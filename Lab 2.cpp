#include <conio.h>

#include <Windows.h>

#include <iostream>

//

//15 (25 12 55 23) Англ. Русск. 0.5 1 Вниз

enum COLORS {

	/* Цвета нормальной яркости: */

	BLACK, /* черный, 0 */

	BLUE, /* синий, 1 */

	GREEN, /* зеленый. 2 */

	CYAN, /* сине-зеленый, 3 */

	RED, /* красный, 4 */

	MAGENTA, /* красно-синий, 5 */

	BROWN, /* коричневый, 6 */

	LIGHTGRAY, /* светло-серый. 7 */

	/* Цвета повышенной яркости: */

	DARKGRAY, /* темно-серый, 8 */

	LIGHTBLUE, /* ярко-синий, 9 */

	LIGHTGREEN, /* ярко-зеленый, 10 */

	LIGHTCYAN, /* яркий сине-зеленый, 11 */

	LIGHTRED, /* ярко-красный, 12 */

	LIGHTMAGENTA, /* яркий красно-синий, 13 */

	YELLOW, /* желтый, 14 */

	WHITE /* белый. 15 */

};

const char* RussianColorNames[] 

{

"Черный",

"Синий",

"Зеленый",

"Сине-зеленый",

"Красный",

"Красно-синий",

"Коричневый",

"Светло-серый",

"Темно-серый",

"Ярко-синий",

"Ярко-зеленый",

"Яркий сине-зеленый",

"Ярко-красный",

"Яркий красно-синий",

"Желтый",

"Белый"

};

const char* EnglishColorNames[] 

{

"BLACK",

"BLUE",

"GREEN",

"CYAN",

"RED",

"MAGENTA",

"BROWN",

"LIGHTGRAY",

"DARKGRAY",

"LIGHTBLUE",

"LIGHTGREEN",

"LIGHTCYAN",

"LIGHTRED",

"LIGHTMAGENTA",

"YELLOW",

"WHITE"

};

using namespace std;

int main()

{

	setlocale(LC_ALL, "Russian"); //Локализация

	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);

	SMALL_RECT rectangle = { 25,12,55,23 }; //Координаты окна

	COORD cursor; //Координаты курсора

	cursor.X = 25;

	cursor.Y = 12;

	SetConsoleWindowInfo(handle, true, &rectangle); //Задаем размеры полей

	unsigned short sequence = 0;

	for (unsigned short backGround = 0; backGround < 16; ++backGround) //По всем цветам для фона

	{

		for (unsigned short text = 0; text < 16; ++text) //По всем цветам для цвета

		{

			SetConsoleTextAttribute(handle, (backGround << 4) | text); //Устанавливаем цвет фона и текста

			SetConsoleCursorPosition(handle, cursor); //Переводим курсор

			++cursor.Y; //Изменяем координаты курсора

			cout << " Background: " << RussianColorNames[backGround] << ", Текст: " <<   EnglishColorNames[text] << " " << endl; //Выводим инфо

			++sequence; 

			if (sequence == 2) //Если вывели 2 строчки

			{

				sequence = 0; //Сбрасываем счетчик

				Sleep(600); //Пауза в 400 мс = 0.4 с

			}

		}

	}

	SetConsoleCursorPosition(handle, cursor);

	SetConsoleTextAttribute(handle, 0x0F); //Сбрасываем цвета в исходные

	ShowWindow(GetConsoleWindow(), SW_MAXIMIZE); //Разворачиваем консоль

	cout << " " << endl;

	system("pause");

	return 0;

}