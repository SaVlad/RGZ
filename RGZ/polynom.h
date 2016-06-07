#pragma once
#ifndef POLYNOM_H
#define POLYNOM_H
#include "stdafx.h"

class Polynom{
private:
	int length;
	float*values;
public:
	Polynom();
	Polynom(int, float*);
	Polynom(Polynom&);

	~Polynom();

	void Print();

	Polynom operator+(Polynom);
	Polynom operator-(Polynom);
	Polynom operator*(Polynom);
	Polynom operator/(Polynom);
	friend Polynom operator+(float, Polynom);
	friend Polynom operator-(float, Polynom);
	friend Polynom operator*(float, Polynom);
	friend Polynom operator/(float, Polynom);
	Polynom operator+(float);
	Polynom operator-(float);
	Polynom operator*(float);
	Polynom operator/(float);

	void operator+=(Polynom);
	void operator-=(Polynom);
	void operator*=(Polynom);
	void operator/=(Polynom);
	void operator+=(float);
	void operator-=(float);
	void operator*=(float);
	void operator/=(float);

	Polynom operator++();
	Polynom operator++(int);
	Polynom operator--();
	Polynom operator--(int);
	Polynom operator-();
	Polynom operator+();

	bool operator<(Polynom);
	bool operator>(Polynom);
	bool operator==(Polynom);
	bool operator!=(Polynom);

	float operator[](int);
	float operator()(int);
};

#endif