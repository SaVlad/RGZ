#include "stdafx.h"
#include "testing.h"
//Какую часть программы тестировать
//В конечной программе будет тестироваться все
#define T_PRINT

float* __read(int*l){
	printf("Length: ");
	scanf_s("%d", l);
	float*v = new float[*l];
	printf("Values:\n");
	for(int i = *l - 1; i >= 0; i--){
		printf(" x^%d: ", i);
		scanf("%f", &v[i]);
	}
	return v;
}

Testing::Testing(){
	printf(">Testing start\n");
	printf("Polynom 1:\n");
	v1=__read(&l1);

	#ifdef T_CON or T_PP or T_P or T_LOGIC
	printf("Polynom 2:\n");
	v2=__read(&l2);
	#endif

	#ifdef T_FP or T_PF or T_F
	printf("Base number:\n");
	scanf("%f", &f);
	#endif


	#ifdef T_CON
	ConstructorDef();
	ConstructorPar();
	ConstructorClo();
	#endif

	#ifdef T_PRINT
	Print();
	#endif

	#ifdef T_PP
	ppAdd();
	ppSub();
	ppMul();
	ppDiv();
	#endif

	#ifdef T_FP
	fpAdd();
	fpSub();
	fpMul();
	fpDiv();
	#endif

	#ifdef T_PF
	pfAdd();
	pfSub();
	pfMul();
	pfDiv();
	#endif

	#ifdef T_P
	Addp();
	Subp();
	Mulp();
	Divp();
	#endif

	#ifdef T_F
	Addf();
	Subf();
	Mulf();
	Divf();
	#endif

	#ifdef T_ID
	incPost();
	decPost();
	incPref();
	decPref();
	#endif

	#ifdef T_UN
	unPos();
	unNeg();
	#endif

	#ifdef T_LOGIC
	Less();
	Greater();
	Equals();
	notEquals();
	#endif

	#ifdef T_INDEX
	sIndexer();
	rIndexer();
	#endif
}

void Testing::ConstructorDef(){
	printf(">Default constructor\n");
	Polynom p;
	printf("Expected: 0\nGot:      ");
	p.Print();
	printf("\n");
}
void Testing::ConstructorPar(){
	printf(">Parametric constructor\n");
	Polynom p(l1, v1);
	printf("Got:      ");
	p.Print();
	printf("\n");
}
void Testing::ConstructorClo(){
	printf(">Clone constructor\n");
	Polynom p1(l1,v1);
	Polynom p2(p1);
	printf("Expected: ");
	p1.Print();
	printf("\nGot:      ");
	p2.Print();
	printf("\n");
}
void Testing::Print(){
	printf(">Print testing\n");
	Polynom p(l1, v1);
	printf("Values[%d]:",l1);
	for(int i = l1 - 1; i >= 0; printf(" %.2f", v1[i--]));
	printf("\nPrint:      ");
	p.Print();
	printf("\n");
}