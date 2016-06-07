#pragma once
#ifndef TESTING_H
#define TESTING_H
#include "stdafx.h"

class Testing{
public:
	Testing();

	void ConstructorDef();
	void ConstructorPar();
	void ConstructorClo();

	void Print();

	void ppAdd();
	void ppSub();
	void ppMul();
	void ppDiv();
	void fpAdd();
	void fpSub();
	void fpMul();
	void fpDiv();
	void pfAdd();
	void pfSub();
	void pfMul();
	void pfDiv();

	void Addp();
	void Subp();
	void Mulp();
	void Divp();
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

	void Less();
	void Greater();
	void Equals();
	void notEquals();

	void sIndexer();
	void rIndexer();
};

#endif