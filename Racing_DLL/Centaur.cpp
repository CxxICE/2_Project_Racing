#include "Centaur.h"

Centaur::Centaur()
{
	name = "�������";
	speed = 15;
	timeToRest = 8;
	type = TypeReg::CENTAUR;
}

double Centaur::raceTime(int distance)
{
	double time, goTime;
	int restCount;
	goTime = distance / speed;
	restCount = static_cast<int>(goTime / timeToRest);

	//�������� ������� == 0, ���� true, ������ ��������� ����� ����� �� ��������� ������� ����� � ��� ��������� �� �����
	if (goTime - restCount * timeToRest == 0) { restCount--; }

	time = goTime + restTime_all * restCount;
	return time;
}