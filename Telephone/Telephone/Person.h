#pragma once
#include <iostream>
#include <string>
#include <iomanip>

template <typename T>
ref class Person
{
public:
	Person();
	~Person();

	T^ number;
	T^ passport;
	T^ name;
	T^ surname;
	T^ secondname;
	T^ adres;
private:
};

template <typename T>
Person<T>::Person()
{
}

template <typename T>
Person<T>::~Person()
{
}