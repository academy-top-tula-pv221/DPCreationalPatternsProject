// DPCreationalPatternsProject
#include <iostream>
#include "FactoryMethod.h"
#include <vector>

using namespace std;

int main()
{
	srand(time(nullptr));

	vector<Factory*> factories;
	factories.push_back(new InfantryFactory());
	factories.push_back(new ArcherFactory());
	factories.push_back(new CavalryFactory());

	vector<Unit*> army;
	for (int i = 0; i < 10; i++)
		army.push_back(factories[rand() % factories.size()]->CreateUnit());

	for (auto unit : army)
		cout << unit->ToString() << "\n";
}
