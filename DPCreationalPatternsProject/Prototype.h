#pragma once
#include <map>
#include <utility>
#include "FactoryMethod.h"

class Prototype
{
public:
	virtual Prototype* Clone() = 0;
};

enum UnitType
{
	Infantry,
	Archer,
	Cavalry
};

class StoreClones
{
	std::map<UnitType, Prototype*> clones;
public:
	
	Prototype* GetClone(UnitType type)
	{
		auto it = clones.find(type);
		if (it != clones.end())
			return it->second;

		Factory* factory;
		switch (type)
		{
		case Infantry:
			factory = new InfantryFactory();
			break;
		case Archer:
			factory = new ArcherFactory();
			break;
		case Cavalry:
			factory = new CavalryFactory();
			break;
		default:
			break;
		}
		
		auto data = std::make_pair(type, (Prototype*)factory->CreateUnit());

		clones.insert(data);
	}
};


