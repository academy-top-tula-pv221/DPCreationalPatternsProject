#pragma once
#include <iostream>

class Unit
{
protected:
	std::string name;
public:
	std::string& Name() { return name; }
	Unit(std::string name) : name{ name } {}
	virtual void Print()
	{
		std::cout << "Unit: " << name;
	}
	virtual ~Unit() {};
};

class InfantryUnit : public Unit
{
public:
	InfantryUnit() : Unit("Infantry") {}
};

class ArcherUnit : public Unit
{
public:
	ArcherUnit() : Unit("Archer") {}
};

class CavalryUnit : public Unit
{
public:
	CavalryUnit() : Unit("Cavalry") {}
};

enum UnitType
{
    Infantry,
    Archer,
    Cavalry
};

Unit* CreateUnit(UnitType type)
{
    Unit* unit;
    switch (type)
    {
    case Infantry:
        unit = new InfantryUnit();
        break;
    case Archer:
        unit = new ArcherUnit();
        break;
    case Cavalry:
        unit = new CavalryUnit();
        break;
    default:
        throw std::exception("error type of unit");
        break;
    }
    return unit;
}

