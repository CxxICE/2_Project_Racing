#include "Camel.h"

Camel::Camel()
{
	name = "�������";
	speed = 10;
	timeToRest = 30;
	type = TypeReg::CAMEL;
}

double Camel::raceTime(int distance)
{
	double time, goTime;
	int restCount;
	goTime = distance / speed;
	restCount = static_cast<int>(goTime / timeToRest);
	
	//�������� ������� == 0, ���� true, ������ ��������� ����� ����� �� ��������� ������� ����� � ��� ��������� �� �����
	if (goTime - restCount * timeToRest == 0) { restCount--; } 

	if (restCount == 0)										//��������� ������ ������� �� ������� ������ ��� ������ ����� �� ������� ����� �����
	{
		time = goTime;
	}
	else if (restCount == 1)								//��������� ������� ����� ������ ������ � �� �� �� ������� ����� �����
	{
		time = goTime + restTime_1;
	}
	else													//��������� ������� ����� ��� ����� ��� ������ � ��������� �� �� ������� ����� �����
	{
		time = goTime + restTime_1 + restTime_2more * (restCount - 1);
	}
	return time;
}