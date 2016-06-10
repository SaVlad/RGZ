#include "stdafx.h"
#define PREC 0 //Кол-во знаков после запятой

Polynom::Polynom():Polynom(0, 0){}
Polynom::Polynom(int l, float*v){
	length = l;
	values = new float[l];
	if(v)
		memcpy_s(values, l*sizeof(float), v, l*sizeof(float));
}
Polynom::Polynom(Polynom&p){
	operator=(p);
}
Polynom::Polynom(float f){
	length = 1;
	values = new float[1];
	values[0] = f;
}

Polynom::~Polynom(){
	delete[] values;
	length = 0;
	values = NULL;
}

void Polynom::Print(){
	if(length == 0){
		printf("0");
	} else if(length == 1){
		printf("%.*f", PREC, values[0]);
	} else{
		float v = values[length - 1];
		if(v != 0){
			if(v == -1)
				printf("-");
			if(fabsf(v) != 1)
				printf("%.*f*", PREC, v);
			printf("x^%d ", length - 1);
		}
		for(int i = length - 2; i > 0; i--){
			v = values[i];
			if(v == 0)continue;
			if(v > 0)
				printf("+");
			if(v == -1)
				printf("-");
			if(fabsf(v) != 1)
				printf("%.*f*", PREC, v);
			printf("x^%d ", i);
		}
		v = values[0];
		if(v != 0){
			if(v > 0)
				printf("+");
			printf("%.*f", PREC, v);
		}
	}
}

void Polynom::PrintVals(){
	for(int i = length - 1; i >= 0; printf(" %.*f", PREC, values[i--]));
}

Polynom Polynom::operator+(Polynom p){
	bool tm = length > p.length;
	int xl = tm ? length : p.length;
	int nl = tm ? p.length : length;
	Polynom r;
	r.length = xl;
	r.values = new float[r.length];
	for(int i = 0; i < nl; i++)
		r.values[i] = values[i] + p.values[i];
	for(int i = nl; i < xl; i++)
		r.values[i] = tm ? values[i] : p.values[i];
	return r;
}
Polynom Polynom::operator-(Polynom p){
	return *(this) + (-p);
}
Polynom Polynom::operator*(Polynom p){
	int n = length - 1;
	int m = p.length - 1;
	int r = n + m;
	Polynom p3(r + 1, new float[r + 1]{0});
	for(int k = 0; k <= r; k++){
		for(int i = n - k, j = m; i <= n; i++, j--){
			p3.values[r - k] += (i < 0 ? 0 : values[i]) * (j < 0 ? 0 : p.values[j]);
		}
	}
	return p3;
}

Polynom operator+(float f, Polynom p){
	return Polynom(f) + p;
}
Polynom operator-(float f, Polynom p){
	return f + (-p);
}
Polynom operator*(float f, Polynom p){
	return Polynom(f)*p;
}

Polynom Polynom::operator+(float f){
	return *(this) + Polynom(f);
}
Polynom Polynom::operator-(float f){
	return *(this) - Polynom(f);
}
Polynom Polynom::operator*(float f){
	return *(this)*Polynom(f);
}
Polynom Polynom::operator/(float f){
	Polynom p(length, values);
	for(int i = 0; i < length; i++)
		p.values[i] /= f;
	return p;
}

Polynom Polynom::operator++(){ //++p
	if(length == 0){
		length = 1;
		values = new float[1];
		values[0] = 1;
	} else
		values[0]++;
	return Polynom(*this);
}
Polynom Polynom::operator++(int){ //p++
	Polynom r(*this);
	if(r.length == 0){
		length = 1;
		values = new float[1];
		values[0] = 1;
	} else
		values[0]++;
	return r;
}
Polynom Polynom::operator--(){ //--p
	if(length == 0){
		length = 1;
		values = new float[1];
		values[0] = -1;
	} else
		values[0]--;
	return Polynom(*this);
}
Polynom Polynom::operator--(int){ //p--
	Polynom r(*this);
	if(length == 0){
		length = 1;
		values = new float[1];
		values[0] = -1;
	} else
		values[0]--;
	return r;
}
Polynom Polynom::operator-(){
	Polynom r(*this);
	for(int i = 0; i < r.length; i++)
		r.values[i] *= -1;
	return r;
}
Polynom Polynom::operator+(){
	return Polynom(*this);
}

Polynom&Polynom::operator=(Polynom&p){
	length = p.length;
	values = new float[length];
	memcpy_s(values, length*sizeof(float), p.values, p.length*sizeof(float));
	return *this;
}

Polynom&Polynom::operator+=(Polynom&p){
	return *this = *this + p;
}
Polynom&Polynom::operator-=(Polynom&p){
	return *this = *this - p;
}
Polynom&Polynom::operator*=(Polynom&p){
	return *this = *this * p;
}
Polynom&Polynom::operator+=(float f){
	return *this = *this + f;
}
Polynom&Polynom::operator-=(float f){
	return *this = *this - f;
}
Polynom&Polynom::operator*=(float f){
	return *this = *this * f;
}
Polynom&Polynom::operator/=(float f){
	return *this = *this / f;
}

bool Polynom::operator==(Polynom p){
	if(length != p.length)return false;
	for(int i = 0; i < length; i++)
		if(values[i] != p.values[i])return false;
	return true;
}
bool Polynom::operator!=(Polynom p){
	return !(*this == p);
}

float Polynom::operator[](int i){
	if(i < 0 || i >= length)return 0;
	return values[i];
}
float Polynom::operator()(int i){
	return (*this)[i];
}