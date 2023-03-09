#include <windows.h>

#include <iostream>
#include <string>

#include "Vehicle.h"
#include "TypeRace.h"
#include "TypeReg.h"
#include "TypeFinish.h"

//структура для хранения, сортировки и вывода результатов гонки
struct GameResult
{
	Vehicle *vehicle;
	double time;
};

// функция запроса расстояния с проверкой корректности ввода целочисленного значения
int readString(std::string requestStr)
{
	std::string tmp;	//переменная приема строки
	bool tmpErr = 0; 	//наличие недопустимых символов в строке = 1
	int requestDigit;	//переменная возврата числового значения из функции
	const int leftAnsiDig = 48, rightAnsiDig = 57;
	do
	{
		if (tmpErr)
		{
			system("cls");
			std::cout	<< "Введено нечисловое или отрицательное значение! Попробуйте снова.\n"
						<< requestStr;
		}
		else
		{
			std::cout << requestStr;
		}
		tmpErr = 0;
		tmp = "";
		std::getline(std::cin, tmp);
		if (tmp != "")
		{
			//посимвольная проверка строки на остутствие нечисловых символов
			for (int j = 0; j < tmp.length(); ++j)
			{
				if ((static_cast<int>(tmp[j]) < leftAnsiDig) || (static_cast<int>(tmp[j]) > rightAnsiDig))
				{
					tmpErr = 1;
					break;
				}
			}
			if (!tmpErr)
			{
				requestDigit = std::stoi(tmp);
			}
		}
		else
		{
			tmpErr = 1;
		}
	} while (tmpErr);
	return requestDigit;
}

void sortArr(GameResult *arr, int size)
{
	if (size == 1) { return; }
	GameResult tmp;
	bool change = 0;
	do
	{
		change = 0;
		for (int i = 0; i < size - 1; ++i)
		{
			if (arr[i].time > arr[i + 1].time)
			{
				tmp.time = arr[i].time;
				tmp.vehicle = arr[i].vehicle;

				arr[i].time = arr[i + 1].time;
				arr[i].vehicle = arr[i + 1].vehicle;

				arr[i + 1].time = tmp.time;
				arr[i + 1].vehicle = tmp.vehicle;

				change = 1;
			}			
		}
		size--;
	} while (change);	
}

void printArr(GameResult *arr, int size)
{
	for (int i = 0; i < size; ++i)
	{
		if ((arr[i].vehicle)->getName().length() < 8)
		{
			std::cout << i + 1 << ". " << (arr[i].vehicle)->getName() << ".\t\t\tВремя: " << arr[i].time << '\n';
		}
		else
		{
			std::cout << i + 1 << ". " << (arr[i].vehicle)->getName() << ".\t\tВремя: " << arr[i].time << '\n';
		}
		
	}
}

int main(int argc, char** argv)
{
	setlocale(LC_ALL,"RU");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	
	int err = 0;						//промежуточная переменная хранящая код ошибки
										//err = 1 - значение вне допустимого диапазона
	int tmpIn;							//временная переменная для ввода разных пунктов меню
	TypeRace typeRace;					//хранение типа гонки
	TypeFinish endGame;					//переменная для запроса рестарта/окночания игры после гонки
	int distanceRace;					//хранение дистанции гонки
	int reg;							//для ввода в программу типа ТС или окончания регистрации
	const int qV = 7;					//кол-во существующих типов ТС
	Vehicle *arrV[qV];					//массив-хранитель указателей на все ТС
	int qRegV = 0;						//переменная хранящая кол-во зарегестрированных на гонку ТС
	std::string menu = "";				//текст меню для запроса данных у пользователя
	
	GameResult gameResult[qV];			//хранение результатов гонки
	
	//общий цикл игры
	do
	{
		system("cls");
		qRegV = 0;

		//инициализация всех видов ТС
		for (int i = 0; i < qV; ++i)
		{
			arrV[i] = Vehicle::creation(static_cast<TypeReg>(i + 1));
		}

		std::cout << "Добро пожаловать в гоночный симулятор!\n";
		//цикл запроса типа гонки
		do
		{			
			err = 0;
			menu =	"1. Гонка для наземного транспорта\n" \
					"2. Гонка для воздушного транспорта\n" \
					"3. Смешанная гонка\n" \
					"Выберите тип гонки : ";
			tmpIn = readString(menu);
			if (tmpIn < 1 || tmpIn > 3) 
			{ 
				err = 1; 
				system("cls");
				std::cout << "Введенное значение вне допустимого диапазона! Попробуйте снова.\n";
			}
			else
			{
				typeRace = static_cast<TypeRace>(tmpIn);
			}
		} while (err > 0);
		
		//запрос дистанции гонки
		system("cls");
		do
		{
			err = 0;
			distanceRace = readString("Укажите длину дистанции (положительное целое число): ");
			system("cls");
			if (distanceRace == 0)
			{
				err = 1;
				std::cout << "Гонка не может быть проведена на нулевой дистанции!\n";
			}
		} while (err > 0);
		
		//цикл регистрации транспортных средств на гонку
		do
		{
			err = 0;
			menu = "";
			if (qRegV < 2)
			{
				menu += "Должно быть зарегестрировано хотя бы 2 транспортных средства.\n";
			}
			switch (typeRace)
			{
			case(TypeRace::AIR):
				menu = menu + "Гонка для воздушного транспорта. Расстояние: " + std::to_string(distanceRace) + "\n";
				break;
			case(TypeRace::GROUND):
				menu = menu + "Гонка для наземного транспорта. Расстояние: " + std::to_string(distanceRace) + "\n";
				break;
			case (TypeRace::MIX):
				menu = menu + "Гонка для любого вида транспорта. Расстояние: " + std::to_string(distanceRace) + "\n";
				break;
			}
			//вывод зарегестрированных ТС
			if (qRegV > 0)
			{
				menu += "Зарегестрированные транспортные средства: ";
				for (int i = 0, j = 0; i < qV; ++i)
				{
					if (arrV[i]->getReg() == 1)
					{
						j++;
						if (j < qRegV)
						{
							menu = menu + arrV[i]->getName() + ", ";
						}
						else
						{
							menu = menu + arrV[i]->getName();
						}
					}
				}
				menu += "\n";
			}
			//вывод доступных к регистрации ТС
			//пользователю не дается возможность регистрировать ранее зарегестрированные ТС и завершить регистрацию пока не будет два ТС
			//недопустимые действия пользователю не выводятся на экран в принципе
			int available = 0;					//для хранения актуального кол-ва еще не зарегестрированных, но доступных к регистрации ТС с учетом типа гонки и ранее зарегестрированных ТС
			TypeReg arrAvailable[qV];			//для храния доступных к регистрации типов ТС
			for (int i = 0; i < qV; ++i)
			{
				//пропуск зарегестрированных ТС и ТС не соответствующих типу гонки
				if ((arrV[i]->getEnviroment() == TypeEnvironment::GROUND && typeRace == TypeRace::AIR) || \
					(arrV[i]->getEnviroment() == TypeEnvironment::AIR && typeRace == TypeRace::GROUND) || \
					(arrV[i]->getReg() == 1))
				{
					continue;
				}
				
				available++;
				menu = menu + std::to_string(available) + ". " + arrV[i]->getName() + "\n";	//зпись в меню доступных ТС
				
				arrAvailable[available - 1] = arrV[i]->getType();							//запись в массив типов доступных ТС по классу enum TypeReg		
			}
			if (qRegV >= 2)	//если уже зарегестрировано два и более ТС, то дается возможность завершить регистрацию
			{
				menu = menu +	"0. Закончить регистрацию\n" \
								"Выберите транспорт или 0 для окончания регистрации: ";
			}
			else
			{
				menu = menu + "Выберите транспорт: ";
			}
			
			reg = readString(menu);	//ввод типа ТС для регистрации

			//проверка допустимости введенного значения
			if (qRegV >= 2 && reg > available)		//введено значение более допустимого значения, вариант когда 0 - допустимое значение, т.к. 2 ТС уже зарегестрированы
			{
				err = 1;
				system("cls");
				std::cout << "Введенное значение вне допустимого диапазона! Попробуйте снова.\n";
			}
			else if (qRegV < 2 && (reg > available || reg == 0)) //введено значение более допустимого значения или 0, 0 - недопустимое значение, т.к. еще нет 2х зарегестрированных ТС
			{
				err = 1;
				system("cls");
				std::cout << "Введенное значение вне допустимого диапазона! Попробуйте снова.\n";
			}
			else
			{
				system("cls");
				if (static_cast<TypeReg>(reg) != TypeReg::END)
				{
					arrV[static_cast<int>(arrAvailable[reg - 1]) - 1]->setReg(1);	//регистрация ТС на основе введенное reg
					//вывод успешности регистрации
					if (arrAvailable[reg - 1] == TypeReg::BOOTS)			//окончание -ы
					{
						std::cout << arrV[static_cast<int>(arrAvailable[reg - 1]) - 1]->getName() << " успешно зарегестрированы!\n";
					}
					else if (arrAvailable[reg - 1] == TypeReg::BROOM)		//окончание -а
					{
						std::cout << arrV[static_cast<int>(arrAvailable[reg - 1]) - 1]->getName() << " успешно зарегестрирована!\n";
					}
					else													//без окончания
					{
						std::cout << arrV[static_cast<int>(arrAvailable[reg - 1]) - 1]->getName() << " успешно зарегестрирован!\n";
					}					
					qRegV++;	//кол-во зарегестрированных ТС
				}
			}
		} while (err > 0 || static_cast<TypeReg>(reg) != TypeReg::END);
		
		//гонка
		for (int i = 0, j = 0; i < qV; ++i)
		{
			if (arrV[i]->getReg() == 1)
			{
				gameResult[j].time = arrV[i]->raceTime(distanceRace);
				gameResult[j].vehicle = arrV[i];
				++j;
			}
		}
		
		std::cout << "Результаты гонки: \n";
		sortArr(gameResult, qRegV);
		printArr(gameResult, qRegV);

		//освобождение памяти 
		for (int i = 0; i < qV; ++i)
		{
			delete arrV[i];
			arrV[i] = nullptr;
			gameResult[i].vehicle = nullptr;
		}

		//цикл запроса окончания или рестарта игры
		do
		{
			err = 0;
			menu =	"\n1. Провести еще одну гонку\n" \
					"2. Выйти\n" \
					"Выберите действие: ";
			tmpIn = readString(menu);
			if (tmpIn != 1 && tmpIn != 2)
			{
				err = 1;
				system("cls");
				std::cout << "Введенное значение вне допустимого диапазона! Попробуйте снова.\n";
			}
			else
			{
				endGame = static_cast<TypeFinish>(tmpIn);
			}
		} while (err > 0);		

	} while (endGame == TypeFinish::RES);
	
	std::cout << "Игра окончена!\n";
	system("pause");
	return 0;
}

