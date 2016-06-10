#include "stdafx.h"
#pragma once
#ifndef TESTING_H
#define TESTING_H

class Testing{
private:
	int l1, l2;
	float *v1, *v2, f;
public:
	Testing();
	void Start();

	void ConstructorDef();
	void ConstructorPar();
	void ConstructorClo();

	void Print();

	void ppAdd();
	void ppSub();
	void ppMul();
	void fpAdd();
	void fpSub();
	void fpMul();
	void pfAdd();
	void pfSub();
	void pfMul();
	void pfDiv();

	void Addp();
	void Subp();
	void Mulp();
	void Addf();
	void Subf();
	void Mulf();
	void Divf();

	void incPost();
	void decPost();
	void incPref();
	void decPref();

	void unPos();
	void unNeg();

	void Equals();
	void notEquals();

	void sIndexer();
	void rIndexer();
};

#endif
