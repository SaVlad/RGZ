#include "stdafx.h"
#include <Windows.h>
#pragma once
#ifndef DYNARR_H
#define DYNARR_H

template<typename T>
class Array{
private:
	int length;
	int size;
	T*values;
	void realc(){
		int ns = po2(length + 1);
		if(ns <= size)return;
		//T*old = new T[size]{0};
		T*old = (T*)calloc(size,sizeof(T));
		memcpy_s(old, length*sizeof(T), values, length*sizeof(T));
		free(values);
		//values=new T[ns]{0};
		values = (T*)calloc(ns,sizeof(T));
		memcpy_s(values, length*sizeof(T), old, length*sizeof(T));
		free(old);
		size = ns;
	}
	int po2(int n){
		return powf(2, ceilf(log2f(n)));
	}
public:
	Array(){
		size = 0;
		length = 0;
		//values = new T[0]{0};
		values = (T*)calloc(0,sizeof(T));
	}
	Array(Array&a){
		size = a.size;
		length = a.length;
		//values = new T[size]{0};
		values = (T*)calloc(size,sizeof(T));
		if(length)
			memcpy_s(values, length, a.values, length);
	}
	Array(int l){
		length = l;
		size = po2(length);
		//values = new T[size]{0};
		values = (T*)calloc(size,sizeof(T));
		if(length)
			memset(values, 0, length);
	}
	Array(int l, T o){
		length = l;
		size = po2(length);
		//values = new T[size]{0};
		values = (T*)calloc(size,sizeof(T));
		if(length)
			memset(values, o, length);
	}

	~Array(){
		//delete[] values;
		free(values);
		size = 0;
		length = 0;
	}

	int getSize(){
		return length;
	}
	int getAllocated(){
		return size;
	}

	T get(int i){
		return values[i];
	}
	void set(int i, T o){
		values[i] = o;
	}

	void add(T o){
		realc();
		values[length] = o;
		length++;
	}
	void del(int n){
		for(int i = n; i < length-1; i++)
			values[i] = values[i + 1];
		length--;
	}

	int find(T o){
		for(int i = 0; i < length; i++)
			if(o == values[i])return i;
		return -1;
	}

	Array<T>&operator=(Array&a){
		if(this == &a)return *this;
		delete[]values;
		size = a.size;
		length = a.length;
		values = new T[size];
		if(length)
			memcpy_s(values, length, a.values, length);
		return *this;
	}
	T&operator[](int i){
		return values[i];
	}
	const T&operator[](int i) const{
		return values[i];
	}
};

#endif