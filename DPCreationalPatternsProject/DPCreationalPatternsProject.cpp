// DPCreationalPatternsProject
#include <iostream>
#include <vector>
#include <chrono>

//#include "FactoryMethod.h"
//#include "AbstractFactory.h"
//#include "Builder.h"
#include "Prototype.h"

using namespace std;

void FactoryMethosExample()
{
	/* Factory Methos Example
	*
	vector<Factory*> factories;
	factories.push_back(new InfantryFactory());
	factories.push_back(new ArcherFactory());
	factories.push_back(new CavalryFactory());

	vector<Unit*> army;
	for (int i = 0; i < 10; i++)
		army.push_back(factories[rand() % factories.size()]->CreateUnit());

	for (auto unit : army)
		cout << unit->ToString() << "\n";
	*/
}

void AbstractFactoryExample()
{
	/* for Abstract Factory
class Army
{
	string title;
	vector<InfantryUnit*> infantries;
	vector<ArcherUnit*> archers;
	vector<CavalryUnit*> cavalries;

	AbstractFactory* factory;
public:
	Army(AbstractFactory* factory, string title, int iCount, int aCount, int cCount)
		: factory{ factory }, title { title	}
	{
		for (int i = 0; i < iCount; i++)
			infantries.push_back(factory->CreateInfantryUnit());
		for (int i = 0; i < aCount; i++)
			archers.push_back(factory->CreateArcherUnit());
		for (int i = 0; i < cCount; i++)
			cavalries.push_back(factory->CreateCavalryUnit());
	}
	~Army()
	{
		for (int i = 0; i < infantries.size(); i++)
			delete infantries[i];
		for (int i = 0; i < archers.size(); i++)
			delete archers[i];
		for (int i = 0; i < cavalries.size(); i++)
			delete cavalries[i];
	}

	void PrintConsole()
	{
		cout << "Army: " << title << "\n";
		for (int i = 0; i < infantries.size(); i++)
			cout << "\t" << infantries[i]->ToString() << "\n";
		for (int i = 0; i < archers.size(); i++)
			cout << "\t" << archers[i]->ToString() << "\n";
		for (int i = 0; i < cavalries.size(); i++)
			cout << "\t" << cavalries[i]->ToString() << "\n";
	}
};
*/
// Abstract Factory Example
/*
Army armyRomeOne(new FactoryRome(), "9 legion", 5, 5, 3);
armyRomeOne.PrintConsole();

Army armyCarthageOne(new FactoryCarthage(), "12 falanga", 7, 5, 4);
armyCarthageOne.PrintConsole();
*/
}

void BuilderExample()
{
	/*
	class GavayPizza
	{
		Pizza* pizza;
	public:
		Pizza* GetPizza()
		{
			IBuilder* builder = new PizzaBuilder();
			return (Pizza*)builder->SetSize(30)
				->SetBase("pshenica")
				->SetMainIngr("chicken")
				->SetIngr("ananas")
				->GetResult();
		}
	};

	IBuilder* builder = new PizzaBuilder();

	Pizza* pizza1 = (Pizza*)builder->SetBase("pshenica")
								   ->SetSize(30)
								   ->SetMainIngr("tomato")
								   ->GetResult();
	cout << pizza1->ToString() << "\n\n";

	builder->SetNew();
	builder->SetBase("rosh");
	builder->SetSize(45);
	builder->SetIngr("kolbaski");
	builder->SetIngr("mozarella");

	Pizza* pizza2 = (Pizza*)builder->GetResult();
	cout << pizza2->ToString() << "\n\n";

	Pizza* pizza3 = (new GavayPizza())->GetPizza();
	cout << pizza3->ToString() << "\n\n";
	*/
}

void PrototypeExample()
{
	class Army
	{
		string title;
		vector<InfantryUnit*> infantries;
		vector<ArcherUnit*> archers;
		vector<CavalryUnit*> cavalries;

	public:
		Army(string title, int iCount, int aCount, int cCount)
			: title{ title }
		{
			Factory* factory;
			factory = new InfantryFactory();
			for (int i = 0; i < iCount; i++)
				infantries.push_back((InfantryUnit*)factory->CreateUnit());
			delete factory;

			factory = new ArcherFactory();
			for (int i = 0; i < aCount; i++)
				archers.push_back((ArcherUnit*)factory->CreateUnit());
			delete factory;

			factory = new CavalryFactory();
			for (int i = 0; i < cCount; i++)
				cavalries.push_back((CavalryUnit*)factory->CreateUnit());
			delete factory;
		}

		Army(int iCount, int aCount, int cCount, string title)
		{
			StoreClones store;
			for (int i = 0; i < iCount; i++)
				infantries.push_back((InfantryUnit*)store.GetClone(UnitType::Infantry));
			for (int i = 0; i < aCount; i++)
				archers.push_back((ArcherUnit*)store.GetClone(UnitType::Archer));
			for (int i = 0; i < cCount; i++)
				cavalries.push_back((CavalryUnit*)store.GetClone(UnitType::Cavalry));
		}

		~Army()
		{
			for (int i = 0; i < infantries.size(); i++)
				delete infantries[i];
			for (int i = 0; i < archers.size(); i++)
				delete archers[i];
			for (int i = 0; i < cavalries.size(); i++)
				delete cavalries[i];
		}

		void PrintConsole()
		{
			cout << "Army: " << title << "\n";
			for (int i = 0; i < infantries.size(); i++)
				cout << "\t" << infantries[i]->ToString() << "\n";
			for (int i = 0; i < archers.size(); i++)
				cout << "\t" << archers[i]->ToString() << "\n";
			for (int i = 0; i < cavalries.size(); i++)
				cout << "\t" << cavalries[i]->ToString() << "\n";
		}
	};

	/*const auto start1 = std::chrono::steady_clock::now();
	Army army1("army1", 1000, 1000, 1000);
	const auto end1 = std::chrono::steady_clock::now();
	cout << std::chrono::duration_cast<std::chrono::microseconds>(end1 - start1).count() << "\n";


	const auto start2 = std::chrono::steady_clock::now();
	Army army1(1000, 1000, 1000, "army2");
	const auto end2 = std::chrono::steady_clock::now();
	cout << std::chrono::duration_cast<std::chrono::microseconds>(end2 - start2).count() << "\n";*/

}


int main()
{
	srand(time(nullptr));
	
	//BuilderExample();
	PrototypeExample();
	
}
