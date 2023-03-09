#include "SpeedCamel.h"

SpeedCamel::SpeedCamel()
{
	name = "�������-���������";
	speed = 40;
	timeToRest = 10;
	type = TypeReg::SPEEDCAMEL;
}

double SpeedCamel::raceTime(int distance)
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
	else if (restCount == 2)								//��������� ������� ����� ���� ������� � ��������� �� �� ������� ����� �����
	{
		time = goTime + restTime_1 + restTime_2;
	}
	else													//��������� ������� ����� ��� ����� ��� ������ � ��������� �� �� ������� ����� �����
	{
		time = goTime + restTime_1 + restTime_2 + restTime_3more * (restCount - 2);
	}
	return time;
}