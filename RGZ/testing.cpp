#include "stdafx.h"
#include "testing.h"

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

Testing::Testing(){}

void Testing::Start(){
	printf(">Testing start\n");
	printf("Polynom 1:\n");
	//v1 = __read(&l1);
	v1 = new float[l1 = 3]{0,-2,1};

	printf("Polynom 2:\n");
	//v2 = __read(&l2);
	v2 = new float[l2 = 4]{1,4,4,8};

	printf("Base number:\n");
	//scanf("%f", &f);
	f = 1;

	printf("\n");

	ConstructorDef();
	ConstructorPar();
	ConstructorClo();

	Print();

	ppAdd();
	ppSub();
	ppMul();

	fpAdd();
	fpSub();
	fpMul();

	pfAdd();
	pfSub();
	pfMul();
	pfDiv();

	Addp();
	Subp();
	Mulp();

	Addf();
	Subf();
	Mulf();
	Divf();

	incPost();
	decPost();
	incPref();
	decPref();

	unPos();
	unNeg();

	Equals();
	notEquals();

	sIndexer();
	rIndexer();

	daAdd();
	daDel();
	daGet();
	daFind();
}

void Testing::ConstructorDef(){
	printf(">Default constructor\n");
	Polynom p;
	printf("Expected: 0\nGot:      ");
	p.Print();
	printf("\n\n");
}
void Testing::ConstructorPar(){
	printf(">Parametric constructor\n");
	Polynom p(l1, v1);
	printf("Got:      ");
	p.Print();
	printf("\n\n");
}
void Testing::ConstructorClo(){
	printf(">Clone constructor\n");
	Polynom p1(l1, v1);
	Polynom p2(p1);
	printf("Expected: ");
	p1.Print();
	printf("\nGot:      ");
	p2.Print();
	printf("\n\n");
}
void Testing::Print(){
	printf(">Print testing\n");
	Polynom p(l1, v1);
	printf("Values[%d]:", l1);
	p.PrintVals();
	printf("\nPrint:      ");
	p.Print();
	printf("\n\n");
}

void Testing::ppAdd(){
	printf(">Polynom+Polynom\n");
	Polynom p1(l1, v1);
	Polynom p2(l2, v2);
	printf("Values[%d,%d]: ", l1, l2);
	p1.Print();
	printf("\n             ");
	p2.Print();
	printf("\nResult:      ");
	(p1 + p2).Print();
	printf("\n\n");
}
void Testing::ppSub(){
	printf(">Polynom-Polynom\n");
	Polynom p1(l1, v1);
	Polynom p2(l2, v2);
	printf("Values[%d,%d]: ", l1, l2);
	p1.Print();
	printf("\n             ");
	p2.Print();
	printf("\nResult:      ");
	(p1 - p2).Print();
	printf("\n\n");
}
void Testing::ppMul(){
	printf(">Polynom*Polynom\n");
	Polynom p1(l1, v1);
	Polynom p2(l2, v2);
	printf("Values[%d,%d]: ", l1, l2);
	p1.Print();
	printf("\n             ");
	p2.Print();
	printf("\nResult:      ");
	(p1 * p2).Print();
	printf("\n\n");
}
void Testing::fpAdd(){
	printf(">Number+Polynom\n");
	Polynom p(l1, v1);
	printf("Values[%d]: ", l1);
	p.PrintVals();
	printf("\nNumber: %.2f", f);
	printf("\nResult: ");
	(f + p).Print();
	printf("\n\n");
}
void Testing::fpSub(){
	printf(">Number-Polynom\n");
	Polynom p(l1, v1);
	printf("Values[%d]: ", l1);
	p.PrintVals();
	printf("\nNumber: %.2f", f);
	printf("\nResult: ");
	(f - p).Print();
	printf("\n\n");
}
void Testing::fpMul(){
	printf(">Number*Polynom\n");
	Polynom p(l1, v1);
	printf("Values[%d]: ", l1);
	p.PrintVals();
	printf("\nNumber: %.2f", f);
	printf("\nResult: ");
	(f * p).Print();
	printf("\n\n");
}
void Testing::pfAdd(){
	printf(">Polynom+Number\n");
	Polynom p(l1, v1);
	printf("Values[%d]: ", l1);
	p.PrintVals();
	printf("\nNumber: %.2f", f);
	printf("\nResult: ");
	(p+f).Print();
	printf("\n\n");
}
void Testing::pfSub(){
	printf(">Polynom-Number\n");
	Polynom p(l1, v1);
	printf("Values[%d]: ", l1);
	p.PrintVals();
	printf("\nNumber: %.2f", f);
	printf("\nResult: ");
	(p - f).Print();
	printf("\n\n");
}
void Testing::pfMul(){
	printf(">Polynom*Number\n");
	Polynom p(l1, v1);
	printf("Values[%d]: ", l1);
	p.PrintVals();
	printf("\nNumber: %.2f", f);
	printf("\nResult: ");
	(p * f).Print();
	printf("\n\n");
}
void Testing::pfDiv(){
	printf(">Polynom/Number\n");
	Polynom p(l1, v1);
	printf("Values[%d]: ", l1);
	p.PrintVals();
	printf("\nNumber: %.2f", f);
	printf("\nResult: ");
	(p / f).Print();
	printf("\n\n");
}

void Testing::Addp(){
	printf(">Polynom+=Polynom\n");
	Polynom p1(l1, v1);
	Polynom p2(l2, v2);
	printf("Values[%d,%d]: ", l1, l2);
	p1.Print();
	printf("\n             ");
	p2.Print();
	printf("\nResult:      ");
	(p1 += p2).Print();
	printf("\n\n");
}
void Testing::Subp(){
	printf(">Polynom-=Polynom\n");
	Polynom p1(l1, v1);
	Polynom p2(l2, v2);
	printf("Values[%d,%d]: ", l1, l2);
	p1.Print();
	printf("\n             ");
	p2.Print();
	printf("\nResult:      ");
	(p1 -= p2).Print();
	printf("\n\n");
}
void Testing::Mulp(){
	printf(">Polynom*=Polynom\n");
	Polynom p1(l1, v1);
	Polynom p2(l2, v2);
	printf("Values[%d,%d]: ", l1, l2);
	p1.Print();
	printf("\n             ");
	p2.Print();
	printf("\nResult:      ");
	(p1 *= p2).Print();
	printf("\n\n");
}
void Testing::Addf(){
	printf(">Polynom+=Number\n");
	Polynom p(l1, v1);
	printf("Values[%d]: ", l1);
	p.PrintVals();
	printf("\nNumber: %.2f", f);
	printf("\nResult: ");
	(p += f).Print();
	printf("\n\n");
}
void Testing::Subf(){
	printf(">Polynom-=Number\n");
	Polynom p(l1, v1);
	printf("Values[%d]: ", l1);
	p.PrintVals();
	printf("\nNumber: %.2f", f);
	printf("\nResult: ");
	(p -= f).Print();
	printf("\n\n");
}
void Testing::Mulf(){
	printf(">Polynom*=Number\n");
	Polynom p(l1, v1);
	printf("Values[%d]: ", l1);
	p.PrintVals();
	printf("\nNumber: %.2f", f);
	printf("\nResult: ");
	(p *= f).Print();
	printf("\n\n");
}
void Testing::Divf(){
	printf(">Polynom/=Number\n");
	Polynom p(l1, v1);
	printf("Values[%d]: ", l1);
	p.PrintVals();
	printf("\nNumber: %.2f", f);
	printf("\nResult: ");
	(p /= f).Print();
	printf("\n\n");
}

void Testing::incPost(){
	printf(">Postfix increment\n");
	Polynom p(l1, v1);
	printf("Values[%d]:", l1);
	p.PrintVals();
	printf("\nIncr:      ");
	(p++).Print();
	printf("\nAfter:     ");
	p.Print();
	printf("\n\n");
}
void Testing::decPost(){
	printf(">Postfix decrement\n");
	Polynom p(l1, v1);
	printf("Values[%d]:", l1);
	p.PrintVals();
	printf("\nDecr:      ");
	(p--).Print();
	printf("\nAfter:     ");
	p.Print();
	printf("\n\n");
}
void Testing::incPref(){
	printf(">Prefix increment\n");
	Polynom p(l1, v1);
	printf("Values[%d]:", l1);
	p.PrintVals();
	printf("\nIncr:      ");
	(++p).Print();
	printf("\n\n");
}
void Testing::decPref(){
	printf(">Prefix decrement\n");
	Polynom p(l1, v1);
	printf("Values[%d]:", l1);
	p.PrintVals();
	printf("\nDecr:      ");
	(--p).Print();
	printf("\n\n");
}

void Testing::unNeg(){
	printf(">Unary negative\n");
	Polynom p(l1, v1);
	printf("Values[%d]:", l1);
	p.PrintVals();
	p = -p;
	printf("\nNegative:  ");
	p.Print();
	printf("\n\n");
}
void Testing::unPos(){
	printf(">Unary positive\n");
	Polynom p(l1, v1);
	printf("Values[%d]:", l1);
	p.PrintVals();
	p = +p;
	printf("\nPositive:  ");
	p.Print();
	printf("\n\n");
}

void Testing::Equals(){
	printf(">Polynom<Polynom\n");
	Polynom p1(l1, v1);
	Polynom p2(l2, v2);
	printf("Values[%d,%d]: ", l1, l2);
	p1.Print();
	printf("\n             ");
	p2.Print();
	printf("\nResult:      %s\n\n", p1==p2 ? "True" : "False");
}
void Testing::notEquals(){
	printf(">Polynom<Polynom\n");
	Polynom p1(l1, v1);
	Polynom p2(l2, v2);
	printf("Values[%d,%d]: ", l1, l2);
	p1.Print();
	printf("\n             ");
	p2.Print();
	printf("\nResult:      %s\n\n", p1!=p2 ? "True" : "False");
}

void Testing::sIndexer(){
	printf(">Polynom[]\n");
	Polynom p(l1, v1);
	printf("Values[%d]: ", l1);
	p.PrintVals();
	printf("\nIndex:  %.0f", f);
	printf("\nResult: %.2f\n\n", p[(int)f]);
}
void Testing::rIndexer(){
	printf(">Polynom()\n");
	Polynom p(l1, v1);
	printf("Values[%d]: ", l1);
	p.PrintVals();
	printf("\nIndex:  %.0f", f);
	printf("\nResult: %.2f\n\n", p((int)f));
}

void Testing::daAdd(){
	printf(">Array.add\n");
	Array<Polynom> arr;
	arr.add(Polynom(l1, v1));
	printf("Length: %d\nSize:   %d\nValues: \n", arr.getSize(), arr.getAllocated());
	for(int i = 0; i < arr.getSize(); i++){
		printf("    %2d: ", i);
		arr[i].Print();
		printf("\n");
	}
	arr.add(Polynom(l2, v2));
	printf("After add:\n");
	printf("Length: %d\nSize:   %d\nValues: \n", arr.getSize(), arr.getAllocated());
	for(int i = 0; i < arr.getSize(); i++){
		printf("    %2d: ", i);
		arr[i].Print();
		printf("\n");
	}
	printf("\n");
}
void Testing::daDel(){
	printf(">Array.del\n");
	Array<Polynom> arr;
	arr.add(Polynom(l1, v1));
	arr.add(Polynom(l2, v2));
	printf("Length: %d\nSize:   %d\nValues: \n", arr.getSize(), arr.getAllocated());
	for(int i = 0; i < arr.getSize(); i++){
		printf("    %2d: ", i);
		arr[i].Print();
		printf("\n");
	}
	arr.del(0);
	printf("After del:\n");
	printf("Length: %d\nSize:   %d\nValues: \n", arr.getSize(), arr.getAllocated());
	for(int i = 0; i < arr.getSize(); i++){
		printf("    %2d: ", i);
		arr[i].Print();
		printf("\n");
	}
	printf("\n");
}
void Testing::daGet(){
	printf(">Array.get\n");
	Array<Polynom> arr;
	arr.add(Polynom(l1, v1));
	arr.add(Polynom(l2, v2));
	printf("Length: %d\nSize:   %d\nValues: \n", arr.getSize(), arr.getAllocated());
	for(int i = 0; i < arr.getSize(); i++){
		printf("    %2d: ", i);
		arr[i].Print();
		printf("\n");
	}
	printf("Element at index %d: ", (int)f);
	arr[(int)f].Print();
	printf("\n\n");
}
void Testing::daFind(){
	printf(">Array.find\n");
	Array<Polynom> arr;
	Polynom p(l1, v1);
	arr.add(p);
	arr.add(Polynom(l2, v2));
	printf("Length: %d\nSize:   %d\nValues: \n", arr.getSize(), arr.getAllocated());
	for(int i = 0; i < arr.getSize(); i++){
		printf("    %2d: ", i);
		arr[i].Print();
		printf("\n");
	}
	printf("Index of first polynom: %d\n\n", arr.find(p));
}