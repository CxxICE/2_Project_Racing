#include "SpecialBoots.h"

SpecialBoots::SpecialBoots()
{
	name = "�������-���������";
	speed = 6;
	timeToRest = 60;
	type = TypeReg::BOOTS;
}

double SpecialBoots::raceTime(int distance)
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