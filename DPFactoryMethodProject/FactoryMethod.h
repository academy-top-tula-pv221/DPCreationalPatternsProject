#pragma once
#include <iostream>

// abstract class Product
class Unit
{
protected:
	std::string name;
public:
	std::string& Name() { return name; }
	Unit(std::string name) : name{ name } {}
	virtual std::string ToString()
	{
		return "Unit: " + name;
	}
	virtual ~Unit() {};
};

// abstract interface Factory
class Factory
{
public:
	virtual Unit* CreateUnit() = 0;
	virtual ~Factory() {}
};

// Infantry
class InfantryUnit : public Unit
{
public:
	InfantryUnit() : Unit("Infantry") {}
};


class InfantryFactory : public Factory
{
public:
	Unit* CreateUnit() override
	{
		return new InfantryUnit();
	}
};

// Archer
class ArcherUnit : public Unit
{
public:
	ArcherUnit() : Unit("Archer") {}
};

class ArcherFactory : public Factory
{
public:
	Unit* CreateUnit() override
	{
		return new ArcherUnit();
	}
};

// Cavalry
class CavalryUnit : public Unit
{
public:
	CavalryUnit() : Unit("Cavalry") {}
};

class CavalryFactory : public Factory
{
public:
	Unit* CreateUnit() override
	{
		return new CavalryUnit();
	}
};


