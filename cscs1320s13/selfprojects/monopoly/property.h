#include <stdio.h>
#include <stdlib.h>
#include <string>

class Property{
	int price, mortgage, rent0, rent1, rent2, rent3, rent4, rent5, upPrice, group, owner;
	bool owned;
	const char* name;
public:
	void set_values(const char*, int, int, int, int, int, int, int, int, int);
	Property();
	const char* getName();
	int getPrice();
	int getMortgage();
	int getRent0();
	int getRent1();
	int getRent2();
	int getRent3();
	int getRent4();
	int getRent5();
	int getUpPrice();
	int getGroup();
};
Property::Property()
{
	name = (const char*)malloc(sizeof(80));
}

void Property::set_values(const char* name, int price, int rent0, int rent1, int rent2, int rent3, int rent4, int rent5, int upPrice, int group)
{
	this->name = name;
	this->price = price;
	mortgage = price / 2;
	this->rent0 = rent0;
	this->rent1 = rent1;
	this->rent2 = rent2;
	this->rent3 = rent3;
	this->rent4 = rent4;
	this->rent5 = rent5;
	this->upPrice = upPrice;
	this->group = group;
}

const char* Property::getName()
{
	return name;
}

int Property::getPrice()
{
	return price;
}

int Property::getMortgage()
{
	return mortgage;
}

int Property::getRent0()
{
	return rent0;
}

int Property::getRent1()
{
	return rent1;
}

int Property::getRent2()
{
	return rent2;
}

int Property::getRent3()
{
	return rent3;
}

int Property::getRent4()
{
	return rent4;
}

int Property::getRent5()
{
	return rent5;
}

int Property::getUpPrice()
{
	return upPrice;
}

int Property::getGroup()
{
	return group;
}
