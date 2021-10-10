/*
Студент потока характеризуется следующими данными:

- ФИО (до 50 символов);

- номер группы;

- набор из пяти оценок за последнюю сессию (без указания предметов);

- размер стипендии.

Необходимо:

1) разработать (и программно реализовать) динамические структуры данных и алгоритмы их обработки, позволяющие поддерживать выполнение следующих функций:

- консольный ввод/вывод данных о всех студентах потока;

- файловый ввод/вывод данных о потоке;

- редактирование данных о студентах и группах потока, включающее операции добавления/удаления групп и студентов;

1)Вывести в порядке роста номеров перечень всех групп потока, в которых количество студентов, не получающих стипендию,
превышает заданное число
2)Вывести (с разбивкой по группам) фамилии всех студентов, не получающих стипендии
 */





#include <iostream>
#include <fstream>

using namespace std;
ifstream in;
ofstream out;

struct student
{
	string NAME;
	int GROUP, GRANT, MARKS[5];
	student* next = nullptr;
	int grant, n;
	student* next;
	student* sort;

};

struct group
{
	int dataa;
	int GROUP;
	group* next = nullptr;
	student* students = new student;
	float k2;
	group* k2_link;
	group* back = nullptr;
};

//Функции, используемые в программе

group* EndGroup(group* main, int a) // Функция прохода до места в списке групп (вернуть указатель)
{
	while ((main->next != nullptr) && (main->next->dataa < a))
		main = main->next;
	return(main);
};

string InputStr() // ввод ФИО для консоли
{
	string NAME, a;
	for (int i = 0; i < 3; i++)
	{
		cin >> NAME;
		a += NAME;
		a += ' ';
	}
	return(a);
}

string InputStrF()  // ввод ФИО для функции
{
	string NAME, a;
	for (int i = 0; i < 3; i++)
	{
		in >> NAME;
		a += NAME;
		a += ' ';
	}
	return(a);
}

group* FindGroup(group* main, int numbergr)  //поиск группы 
{
	while ((main->next != nullptr) && (main->next->dataa != numbergr))
	{
		main = main->next;
	}
	return (main);
};

student* EndStudent(student* main, string a)
{
	while (1)
	{
		if ((main->next == nullptr) || (main->next->NAME > a))
		{
			return(main);
			break;
		}
		main = main->next;
	}
};

student* FindStudent(student* main, string namesurname) //поиск студента 
{
	while (1)
	{
		while (main->next != nullptr)
		{
			if (main->next->NAME != namesurname) break;
			main = main->next;
		}
		return (main);
	}
};

group* AddGroup(int a) // ввод группы
{
	group* main;
	main = new group;
	main->dataa = a;
	return(main);
}

student* AddStudentC()  // ввод студента(консоль)
{
	student* main;
	main = new student;
	cout << "Введите ФИО, 5 оценок и стипендию студента: " << endl;
	main->NAME = InputStr();
	for (int i = 0; i < 5; i++)
	{
		cin >> main->MARKS[i];
	}
	cin >> main->GRANT;
	cout << "Ввод успешно завершён." << endl;
	return(main);
}

student* AddStudentF() // ввод студента(фаил)
{
	student* main;
	main = new student;
	main->NAME = InputStrF();
	for (int i = 0; i < 5; i++)
	{
		in >> main->MARKS[i];
	}
	in >> main->GRANT;
	cout << "Ввод успешно завершён." << endl;
	return(main);
}

void DeleteGroup(group* main)  // удаление группы
{
	group* a;
	a = main->next->next;
	delete main->next;
	main->next = a;
}

void DeleteStudent(student* main)  // удаление студента
{
	student* a;
	a = main->next->next;
	delete main->next;
	main->next = a;
}

void OutputInfoStudentsF(student* main, group* p) // вывод информации о студенте(функция)
{
	out << p->GROUP << "\t";
	out << main->NAME << "\t";
	for (int i = 0; i < 5; i++)
		out << main->MARKS[i] << " ";
	out << "\t" << main->GRANT << endl;
}

void OutputInfoStudentsFSPEC(student* main, group* p)
{
	if (main->GRANT != 0)
	{
		out << p->GROUP << "\t";
		out << main->NAME << "\t";
		for (int i = 0; i < 5; i++)
			out << main->MARKS[i] << " ";
		out << "\t" << main->GRANT << endl;
	}
}
void OutputInfoStudentsC(student* main, group* p) // вывод информации о студенте(консоль)
{
	cout << p->GROUP << "\t";
	cout << main->NAME << "\t";
	for (int i = 0; i < 5; i++)
		cout << main->MARKS[i] << " ";
	cout << "\t" << main->GRANT << endl;
}

void OutputInfoStudentsCSPEC(student* main, group* p) // вывод информации о студенте(консоль)
{
	int grant;
	if (main->GRANT != 0)
	{

		cout << p->GROUP << "\t";
		cout << main->NAME << "\t";
		for (int i = 0; i < 5; i++)
			cout << main->MARKS[i] << " ";
		cout << "\t" << main->GRANT << endl;
	}
}
// П.З.1
//Вывести в порядке роста номеров перечень всех групп потока, в которых количество студентов, не получающих стипендию,
//превышает заданное число 


void dop(student* main) // индивидуальное задание
{
	int x;
	group* Top = 0, * z = 0, * d, * Topk2 = 0, * Backk2 = 0, *Back=0;
	student* p = 0, * t, * h, * TopSort = 0, * BackSort = 0;
	string a;
	bool flag = false;
	float k1;
	bool back;


	system("cls");

	cout << "Задайте количество студентов, не получающих стипендию: " << endl;
	cin >> x;

	flag = false;
	Back = Top;
	while (Back)
	{
		k1 = 0;
		main = Back->students;
		while (main)
		{

			if (main->GRANT = 0)
			{
				k1++;
				break;
			}


			main = main->next;
		}
		Back->k2 = k1;
		if (Back->k2 >= x)
		{
			if (Topk2 == 0)
			{
				Topk2 = Back;
				Backk2 = Topk2;
				Backk2->k2_link = 0;
			}
			else
			{
				if (Back->GROUP <= Topk2->GROUP)
					flag = false;
				while (Back->GROUP >= Backk2->GROUP)
				{
					flag = true;
					z = Backk2;
					Backk2 = Backk2->k2_link;
					if (Backk2 == 0)
						break;
				}
				if (flag == false)
				{
					d = Topk2;
					Topk2 = Back;
					Backk2 = Topk2;
					Backk2->k2_link = d;
				}
				if (flag == true)
				{
					d = Backk2;
					Backk2 = Back;
					z->k2_link = Backk2;
					Backk2->k2_link = d;
				}
			}
		}
		Back = Back->next;
	}


	Backk2 = Topk2;
	cout << "\n";
	cout << "Вывод в порядке роста номеров перечень всех групп потока, в которых количество студентов, не получающих стипендию, превышает заданное число: " << endl;
	while (Backk2)
	{
		cout << Backk2->GROUP << endl;
		cout << "\n";
		Backk2 = Backk2->k2_link;
	}
}

int main()
{
	in.open("input.txt");
	out.open("output.txt");
	setlocale(0, "");
	student* pointer_MAIN, * st, * st1;								//Вспомогательные указатели на студентов
	group GROUPS;											//Структура групп
	group* gr_head = &GROUPS, * gr_mainptr = gr_head, * gr;		//Вспомогательные указатели на группы
	int choice, choice2, numbergr;							//Переменная выбора пункта меню
	string namesur;
	bool pos1 = false, pos2 = false, pos3 = false;
	while (1)
	{
		cout << " 1 - Добавить группу;" << endl;
		if (pos1) cout << " 2 - Удалить группу;" << endl;
		if (pos1) cout << " 3 - Добавить студента;" << endl;
		if (pos2 && pos1) cout << " 4 - Удалить студента;" << endl;
		if (pos2 && pos1) cout << " 5 - Вывод информации о студентах;" << endl;
		if (pos2 && pos1) cout << " 6 - Индивидуальное задание: вывод данных студентов со стипендией;" << endl;
		if (pos2 && pos1) cout << " 7 - Индивидуальное задание: ;" << endl;
		cout << " 0 - Выход" << endl;
		cin >> choice;
		system("cls");
		switch (choice)
		{
		case 1:								// Создать группу
		{
			cout << "Введите номер группы:" << endl;
			cin >> numbergr;
			gr_mainptr = EndGroup(gr_head, numbergr);		//Функция прохода до места в списке групп (вернуть указатель)
			if (gr_mainptr->next == nullptr)
			{
				gr_mainptr->next = AddGroup(numbergr);
			}
			else
			{
				gr = gr_mainptr->next;
				gr_mainptr->next = AddGroup(numbergr);			//Функция добавления группы
				gr_mainptr->next->next = gr;
			}
			pos1 = true;
			break;
		}
		if (pos1) case 2:					// Удалить группу
		{
			cout << "Введите номер группы:" << endl;
			cin >> numbergr;
			gr_mainptr = FindGroup(gr_head, numbergr); //Функция поиска группы (вернуть указатель на группу)
			if (gr_mainptr->next == nullptr)
			{
				cout << "Группа не найдена." << endl;
				break;
			}
			else DeleteGroup(gr_mainptr);				//Функция удаления группы
			if (gr_head->next == nullptr) pos1 = false;
			break;
		}
		if (pos1) case 3:					// Добавить студента
		{
			cout << " 1 - Ввод с клавиатуры;\n 2 - Ввод из файла;" << endl;
			cin >> choice;
			if (choice == 1)
			{
				cout << "Введите номер группы:" << endl;
				cin >> numbergr;
			}
			else
				in >> numbergr;
			gr_mainptr = FindGroup(gr_head, numbergr); //Функция поиска группы (вернуть указатель на группу)
			if (gr_mainptr->next == nullptr)
			{
				cout << "Группа не найдена." << endl;
				break;
			}
			else gr_mainptr = gr_mainptr->next;
			pos2 = true;
			if (choice == 1)	//Функция добавления студентa
				st = AddStudentC();
			else
				st = AddStudentF();
			pointer_MAIN = EndStudent(gr_mainptr->students, st->NAME);//Функция дохода до места в списке студентов(вернуть указатель на конец)
			if (pointer_MAIN->next == nullptr)
			{
				pointer_MAIN->next = st;
			}
			else
			{
				st1 = pointer_MAIN->next;
				pointer_MAIN->next = st;
				pointer_MAIN->next->next = st1;
			}
			pointer_MAIN->next->GROUP = numbergr;
			break;
		}
		if (pos2) case 4:					// Удалить студента
		{
			cout << "Введите номер группы:" << endl;
			cin >> numbergr;
			gr_mainptr = FindGroup(gr_head, numbergr); //Функция поиска группы (вернуть указатель на группу)
			if (gr_mainptr->next == nullptr)
			{
				cout << "Группа не найдена." << endl;
				break;
			}
			cout << "Введите ФИО студента:" << endl;
			namesur = InputStr();
			pointer_MAIN = FindStudent(gr_mainptr->students, namesur);//Функция поиска студента (вернуть указатель на студента)
			if (pointer_MAIN->next == nullptr)
			{
				cout << "Студент не найден." << endl;
				break;
			}
			else
				DeleteStudent(pointer_MAIN);//Функция удаления студента
			break;
		}
		if (pos2) case 5:					//Функция вывода информации о студентах
		{
			cout << "Вывод информации в файл (1) или на экран (2)?" << endl;
			cin >> choice;
			cout << " 1 - Вывод информации об определённом студенте;" << endl;
			cout << " 2 - Вывод информации о группе;" << endl;
			cout << " 3 - Вывод информации обо всех студентах потока;" << endl;
			cin >> choice2;
			if (choice2 == 1)
			{
				cout << "Введите группу:" << endl;					//Поиск группы
				cin >> numbergr;
				gr_mainptr = FindGroup(gr_head, numbergr);
				if (gr_mainptr->next == nullptr)
				{
					cout << "Группа не найдена." << endl;
					break;
				}
				else gr_mainptr = gr_mainptr->next;
				cout << "Введите ФИО студента:" << endl;			//Поиск студента по фио
				namesur = InputStr();
				pointer_MAIN = FindStudent(gr_mainptr->students, namesur);//Функция поиска студента (вернуть указатель на студента)
				if (pointer_MAIN->next == nullptr)
				{
					cout << "Студент не найден." << endl;
					break;
				}
				else												//Вывод студента
				{
					if (choice == 1)
					{
						OutputInfoStudentsF(pointer_MAIN->next, gr_mainptr->next);
					}
					else
					{
						OutputInfoStudentsC(pointer_MAIN->next, gr_mainptr->next);
					}
				}
			}
			else if (choice2 == 2)									//Если о группе

			{
				cout << "Введите группу:" << endl;					//Поиск группы
				cin >> numbergr;
				gr_mainptr = FindGroup(gr_head, numbergr);
				if (gr_mainptr->next == nullptr)
				{
					cout << "Группа не найдена." << endl;
					break;
				}
				else gr_mainptr = gr_mainptr->next;
				pointer_MAIN = gr_mainptr->students;
				while (pointer_MAIN->next != nullptr)				//Вывод информации о всех студентах группы
				{
					if (choice == 1)
					{
						OutputInfoStudentsF(pointer_MAIN->next, gr_mainptr->next);
					}
					else
					{
						OutputInfoStudentsC(pointer_MAIN->next, gr_mainptr->next);
					}
					pointer_MAIN = pointer_MAIN->next;
				}

			}
			else														//Если о потоке
			{
				gr_mainptr = gr_head;
				while (gr_mainptr != nullptr)							//Цикл перехода до конца списка групп
				{
					pointer_MAIN = gr_mainptr->students;
					while (pointer_MAIN->next != nullptr)				//Вывод информации о всех студентах группы
					{
						if (choice == 1)
						{
							OutputInfoStudentsF(pointer_MAIN->next, gr_mainptr->next);
						}
						else
						{
							OutputInfoStudentsC(pointer_MAIN->next, gr_mainptr->next);
						}
						pointer_MAIN = pointer_MAIN->next;
					}
					gr_mainptr = gr_mainptr->next;
				}
			}
			break;
		}
		if (pos2) case 6:					//Индивидуальное задание
		{
			//Вывод на экран всего потока студентов, имеющих значение стипендии !=0
			gr_mainptr = gr_head;
			int noup;
			while (gr_mainptr != nullptr)							//Цикл перехода до конца списка групп
			{
				pointer_MAIN = gr_mainptr->students;
				while (pointer_MAIN->next != nullptr)				//Вывод информации о всех студентах группы
				{

					if (choice == 1)
					{
						OutputInfoStudentsFSPEC(pointer_MAIN->next, gr_mainptr->next);
					}
					else
					{
						OutputInfoStudentsCSPEC(pointer_MAIN->next, gr_mainptr->next);
					}
					pointer_MAIN = pointer_MAIN->next;
				}
				gr_mainptr = gr_mainptr->next;
			}
			break;
		}

		



		case 0:// Выход
		{
			delete gr_head->next;
			exit(1);
		}
		}
		}
	}
