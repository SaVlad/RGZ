#include "stdafx.h"
#include "polynom.h"

Polynom::Polynom():Polynom(0, 0){}
Polynom::Polynom(int l, float*v){
	length = l;
	values = new float[l];
	if(v)
		memcpy_s(values, l*sizeof(float), v, l*sizeof(float));
}
Polynom::Polynom(Polynom&p){
	length = p.length;
	values = new float[length];
	memcpy_s(values, length*sizeof(float), p.values, p.length*sizeof(float));
}
Polynom::Polynom(float f){
	length=1;
	values=new float[1];
	values[0]=f;
}

Polynom::~Polynom(){
	length = 0;
	delete values;
}

void Polynom::Print(){
	if(length == 0){
		printf("0");
	}else if(length == 1){
		printf("%.2f", values[0]);
	} else{
		float v= values[length - 1];
		if(v!=0){
			if(fabsf(v) != 1)
				printf("%.2f*", v);
			printf("x^%d", length - 1);
		}
		for(int i = length - 2; i > 0; i--){
			v = values[i];
			if(v == 0)continue;
			if(v > 0)
				printf(" +");
			if(fabsf(v) != 1)
				printf("%.2f*", v);
			printf("x^%d", i);
		}
		v = values[0];
		if(v != 0){
			if(v > 0)
				printf(" +");
			printf("%.2f", v);
		}
	}

}

Polynom Polynom::operator+(Polynom p){
	bool tm=length>p.length;
	int xl=tm?length:p.length;
	int nl=tm?p.length:length;
	Polynom r;
	r.length=xl;
	r.values=new float[r.length];
	for(int i=0;i<nl;i++)
		r.values[i]=values[i]+p.values[i];
	for(int i=nl;i<xl;i++)
		r.values[i]=tm?values[i]:p.values[i];
	return r;
}
Polynom Polynom::operator-(Polynom p){
	return *(this)+(-p);
}
Polynom Polynom::operator*(Polynom p){
	//Умножение полином на полином - нетривиальная задача. Займусь позже
	return *this;
}
Polynom Polynom::operator/(Polynom p){
	//Деление полином на полином - нетривиальная задача. Займусь позже
	return *this;
}

Polynom operator+(float f, Polynom p){
	return Polynom(f)+p;
}
Polynom operator-(float f, Polynom p){
	return f+(-p);
}
Polynom operator*(float f, Polynom p){
	return Polynom(f)*p;
}
Polynom operator/(float f, Polynom p){
	return Polynom(f)/p;
}

Polynom Polynom::operator+(float f){
	return *(this)+Polynom(f);
}
Polynom Polynom::operator-(float f){
	return *(this)-Polynom(f);
}
Polynom Polynom::operator*(float f){
	return *(this)*Polynom(f);
}
Polynom Polynom::operator/(float f){
	return *(this)/Polynom(f);
}

Polynom Polynom::operator++(){ //++p
	if(length==0){
		length=1;
		values=new float[1];
		values[0]=1;
	}else
		values[0]++;
	return *this;
}
Polynom Polynom::operator++(int){ //p++
	Polynom r(*this);
	if(length==0){
		length=1;
		values=new float[1];
		values[0]=1;
	}else
		values[0]++;
	return r;
}
Polynom Polynom::operator--(){ //--p
	if(length==0){
		length=1;
		values=new float[1];
		values[0]=-1;
	}else
		values[0]--;
	return *this;
}
Polynom Polynom::operator--(int){ //p--
	Polynom r(*this);
	if(length==0){
		length=1;
		values=new float[1];
		values[0]=-1;
	}else
		values[0]--;
	return r;
}
Polynom Polynom::operator-(){
	Polynom r(*this);
	for(int i=0;i<r.length;i++)
		r.values[i]*=-1;
	return r;
}
Polynom Polynom::operator+(){
	return *this;
}