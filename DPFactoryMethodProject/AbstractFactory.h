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
	virtual std::string ToString() = 0;
	virtual ~Unit() {};
};

// Infantry
class InfantryUnit : public Unit
{
public:
	InfantryUnit() : Unit("Infantry") {}
	std::string ToString() override
	{
		return "Unit Infantry";
	}
};


// Archer
class ArcherUnit : public Unit
{
public:
	ArcherUnit() : Unit("Archer") {}
	std::string ToString() override
	{
		return "Unit Archer";
	}
};

// Cavalry
class CavalryUnit : public Unit
{
public:
	CavalryUnit() : Unit("Cavalry") {}
	std::string ToString() override
	{
		return "Unit Cavalry";
	}
};


// Rome units
class InfantryUnitRome : public InfantryUnit
{
public:
	std::string ToString() override
	{
		return InfantryUnit::ToString() + " Rome";
	}
};

class ArcherUnitRome : public ArcherUnit
{
public:
	std::string ToString() override
	{
		return ArcherUnit::ToString() + " Rome";
	}
};

class CavalryUnitRome : public CavalryUnit
{
public:
	std::string ToString() override
	{
		return CavalryUnit::ToString() + " Rome";
	}
};


// Carthage units
class InfantryUnitCarthage : public InfantryUnit
{
public:
	std::string ToString() override
	{
		return InfantryUnit::ToString() + " Carthage";
	}
};

class ArcherUnitCarthage : public ArcherUnit
{
public:
	std::string ToString() override
	{
		return ArcherUnit::ToString() + " Carthage";
	}
};

class CavalryUnitCarthage : public CavalryUnit
{
public:
	std::string ToString() override
	{
		return CavalryUnit::ToString() + " Carthage";
	}
};


class AbstractFactory
{
};

