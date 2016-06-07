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