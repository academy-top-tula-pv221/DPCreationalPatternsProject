#pragma once
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Product
{

};

class Pizza : public Product
{
public:
	int size;
	string base;
	string sauce;
	string ingMain;
	vector<string> ingrs;

	Pizza()
	{
		size = 0;
		base = "";
		sauce = "";
		ingMain = "";
	}

	string ToString()
	{
		string str = "size: " + to_string(size) + " base: " + base
			+ " sauce: " + sauce + " main ingr: " + ingMain + " ingridients: ";
		if (ingrs.size() > 0)
		{
			for (int i = 0; i < ingrs.size() - 1; i++)
				str += ingrs[i] + ", ";
			str += ingrs[ingrs.size() - 1];
		}
		return str;
	}
};


class IBuilder
{
public:
	virtual IBuilder* SetNew() = 0;
	virtual IBuilder* SetBase(string base) = 0;
	virtual IBuilder* SetSize(int size) = 0;
	virtual IBuilder* SetSauce(string sauce) = 0;
	virtual IBuilder* SetMainIngr(string ingMain) = 0;
	virtual IBuilder* SetIngr(string ingr) = 0;
	virtual Product* GetResult() = 0;
};

class PizzaBuilder : public IBuilder
{
	Pizza* pizza;
public:
	PizzaBuilder()
	{
		pizza = new Pizza();
	}
	
	IBuilder* SetNew() override
	{
		if (pizza)
			delete pizza;
		pizza = new Pizza();
		return this;
	}

	IBuilder* SetBase(string base) override
	{
		pizza->base = base;
		return this;
	}
	IBuilder* SetSize(int size) override
	{
		pizza->size = size;
		return this;
	}
	IBuilder* SetSauce(string sauce) override
	{
		pizza->sauce = sauce;
		return this;
	}
	IBuilder* SetMainIngr(string ingMain) override
	{
		pizza->ingMain = ingMain;
		return this;
	}
	IBuilder* SetIngr(string ingr) override
	{
		pizza->ingrs.push_back(ingr);
		return this;
	}
	Pizza* GetResult() override
	{
		return pizza;
	}
};