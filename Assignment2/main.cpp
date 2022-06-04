#include <cassert>
#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <crtdbg.h>
#include "Vehicle.h"
//#include "Airplane.h"
//#include "Boat.h"
//#include "Boatplane.h"
//#include "Motorcycle.h"
//#include "Sedan.h"
//#include "UBoat.h"
//#include "Trailer.h"
//#include "DeusExMachina.h"
//#include "Person.h"
//
//#define _CRTDBG_MAP_ALLOC
//#ifdef _DEBUG
//#define DEBUG_NEW new(_NORMAL_BLOCK, __FILE__, __LINE__)
//#define new DEBUG_NEW
//#endif
//
//#define STR(name) #name
//
//using namespace assignment2;
//using namespace std;
//
//int main()
//{
//	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
//	const char* MAX_SPEED_LABLE = "Max Speed: ";
//	const char* CUR_P_LABLE = "Current Person: ";
//	const unsigned int MAX_CAPACITY = 10;
//
//	Sedan se;
//	Trailer trail(10);
//	se.AddTrailer(&trail);
//	
//
//
//	Airplane test1(10);
//	test1.AddPassenger(new Person("aa", 13));
//	test1.AddPassenger(new Person("bb", 3));
//	Boat test2(15);
//	Boat test3(20);
//	Boatplane test = test1 + test2;
//	Boatplane test4 = test1 + test3;
//
//	Airplane test44(100);
//	Boatplane test3333 = test44  + test2;
//
//	Vehicle* air = new Airplane(MAX_CAPACITY);
//
//	Person* toAdd;
//	const unsigned int personWeight = 10;
//
//	for (size_t i = 0; i < MAX_CAPACITY + 10; i++)
//	{
//		toAdd = new Person(STR(i), i);
//		if (air->AddPassenger(toAdd) == false)
//		{
//			delete toAdd;
//		}
//
//		cout << MAX_SPEED_LABLE << air->GetMaxSpeed() << endl;
//		toAdd = NULL;
//		assert(air->AddPassenger(toAdd) == false); // 빌드봇은 이런 테스트 안함
//		
//	}
//
//	cout << CUR_P_LABLE << air->GetPassengersCount() << endl;
//	while (air->RemovePassenger(0))
//	{
//		cout << CUR_P_LABLE << air->GetPassengersCount() << endl;;
//	}
//	delete air;
//
//	Airplane dockingTest1(10);
//	Boat dockingTest2(10);
//
//	/*Person* overlapTest = new Person("Overlap Test", 100);
//	air->AddPassenger(overlapTest);
//	air->AddPassenger(overlapTest);*/
//	//assert(air->GetPassengersCount() == 1); // 빌드봇은 이런 테스트 안함
//
//
//	for (size_t i = 0; i < 5; i++)
//	{
//		dockingTest1.AddPassenger(new Person(STR(i), i));
//		dockingTest2.AddPassenger(new Person(STR(i), i));
//	}
//
//	const Person* comp1 = dockingTest1.GetPassenger(0);
//	Boatplane bp1 = dockingTest1 + dockingTest2;
//	const Person* comp2 = bp1.GetPassenger(0);
//
// 	Boatplane bp2 = dockingTest2 + dockingTest1;
//
//	assert(comp1 == comp2); // 빌드봇은 이런 테스트 안함
//	assert(dockingTest1.GetPassengersCount() == 0);
//	assert(dockingTest2.GetPassengersCount() == 0);
//	assert(bp1.GetPassengersCount() == 10);
//	assert(bp2.GetPassengersCount() == 0);
//
//	Boatplane copyConstuctorTest(bp1);
//	               
//	for (size_t i = 0; i < bp1.GetPassengersCount(); i++)
//	{
//		const Person* p1 = bp1.GetPassenger(i);
//		const Person* p2 = copyConstuctorTest.GetPassenger(i);
//		assert(p1 != p2);
//	}
//	assert(bp1.GetMaxPassengersCount() == copyConstuctorTest.GetMaxPassengersCount());
//	assert(bp1.GetPassengersCount() == copyConstuctorTest.GetPassengersCount());
//	assert(bp1.GetMaxSpeed() == copyConstuctorTest.GetMaxSpeed());
//
//	Sedan sedanTest;
//	Trailer* t1 = new Trailer(10);
//	Trailer* t2 = new Trailer(20);
//
//	assert(sedanTest.AddTrailer(t1));
//	assert(!sedanTest.AddTrailer(t1));
//	assert(!sedanTest.AddTrailer(t2));
//	assert(sedanTest.RemoveTrailer());
//	assert(sedanTest.AddTrailer(t2));
//	assert(sedanTest.RemoveTrailer());
//
//	DeusExMachina* d = DeusExMachina::GetInstance();
//	Vehicle* demAirplain = new Airplane(MAX_CAPACITY);
//	Vehicle* demBoat = new Airplane(MAX_CAPACITY);
//	Vehicle* demBoatplain = new Boatplane(MAX_CAPACITY);
//	Vehicle* demMotorcycle = new Motorcycle();
//	Vehicle* demSedan1 = new Sedan();
//	Vehicle* demSedan2 = new Sedan();
//	Trailer* demTrailer = new Trailer(10);
//	static_cast<Sedan*>(demSedan2)->AddTrailer(demTrailer);
//	Vehicle* demUBoat = new UBoat();
//
//	d->AddVehicle(demAirplain);
//	d->AddVehicle(demBoat);
//	d->AddVehicle(demBoatplain);
//	d->AddVehicle(demMotorcycle);
//	d->AddVehicle(demSedan1);
//	d->AddVehicle(demSedan2);
//	d->AddVehicle(demUBoat);
//
//	for (size_t i = 0; i < 7; i++)
//	{
//		Vehicle* tempVPointer = d->GetVehicle(i);
//		for (size_t j = tempVPointer->GetPassengersCount(); j < tempVPointer->GetMaxPassengersCount(); j++)
//		{
//			tempVPointer->AddPassenger(new Person(STR((i + j)), 10));
//		}
//	}
//
//
//	for (size_t i = 0; i < 10; i++)
//	{
//		d->Travel();
//	}
//
//	for (size_t i = 0; i < 7; i++)
//	{
//		delete d->GetVehicle(i);
//	}
//
//	
//	
//	return  0;
//	
//}
#include <cassert>
#include <iostream>

#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

#include "Vehicle.h"
#include "Airplane.h"
#include "Boat.h"
#include "Boatplane.h"
#include "Motorcycle.h"
#include "Sedan.h"
#include "Trailer.h"
#include "UBoat.h"
#include "DeusExMachina.h"
#include "Person.h"

using namespace assignment2;

int main()
{

	Airplane testAP(10);
	testAP.AddPassenger(new Person("1", 100));
	testAP.AddPassenger(new Person("2", 200));
	testAP.AddPassenger(new Person("3", 300));
	testAP.AddPassenger(new Person("4", 400));

	Boat testB(3);
	testB.AddPassenger(new Person("Boat1", 110));
	testB.AddPassenger(new Person("Boat2", 220));
	testB.AddPassenger(new Person("Boat3", 330));

	Boatplane testBP = testAP + testB;

	Boat qwe(2);
	qwe.AddPassenger(new Person("QQQ", 1000));
	assert(qwe.GetSailSpeed() == 20);
	Person* p = new Person("Bob", 85);
	assert(p->GetName() == std::string("Bob"));
	assert(p->GetWeight() == 85);

	qwe = qwe;

	Boatplane asds(20);
	asds.AddPassenger(new Person("QQQ", 1000));
	assert(asds.GetSailSpeed() == 20);
	Person* p2 = new Person("James", 75);
	Person* p3 = new Person("Tina", 52);

	Person* p4 = new Person("Peter", 78);
	Person* p5 = new Person("Jane", 48);
	Person* p6 = new Person("Steve", 88);

	Airplane a(5);
	a.AddPassenger(p);
	a.AddPassenger(p2);
	a.AddPassenger(p3);

	Airplane g = a;

	Boatplane pop(10);
	pop.AddPassenger(new Person("QQQQQ", 10000));
	std::cout << pop.GetSailSpeed() << std::endl;
	std::cout << pop.GetFlySpeed() << std::endl;

	Airplane c(10);
	c.AddPassenger(new Person("QQ", 10));
	c.AddPassenger(new Person("BB", 35));
	c.AddPassenger(new Person("FGG", 451));
	g = c;
	g = g;
	assert(a.GetMaxPassengersCount() == 5);
	assert(a.GetPassengersCount() == 3);
	assert(a.GetPassenger(1) == p2); 
	assert(a.GetFlySpeed() == 648);
	assert(a.GetDriveSpeed() == 59);
	assert(a.GetMaxSpeed() == 648);

	assert(a.RemovePassenger(3) == false);
	assert(a.RemovePassenger(0) == true);
	
	UBoat zzz();
	
	Boat b(5);
	b.AddPassenger(p4);
	b.AddPassenger(p5);
	b.AddPassenger(p6);

	Boatplane bp = a + b;


	DeusExMachina* deusExMachina1 = DeusExMachina::GetInstance();

	deusExMachina1->AddVehicle(new Airplane(5));
	deusExMachina1->AddVehicle(new Boat(5));
	deusExMachina1->AddVehicle(new Boatplane(5));
	deusExMachina1->AddVehicle(new Motorcycle());
	deusExMachina1->AddVehicle(new Sedan());

	Sedan* sedan1 = new Sedan();
	sedan1->AddTrailer(new Trailer(50));

	deusExMachina1->AddVehicle(sedan1);
	deusExMachina1->AddVehicle(new UBoat());


	deusExMachina1->Travel(); // 모든 운송 수단이 이동
	deusExMachina1->Travel(); // Boat, Motorcycle, 두 Sedan, UBoat가 이동
	deusExMachina1->Travel(); // Motorcycle, 두 Sedan이 이동
	deusExMachina1->Travel(); // Boat, Motorcycle, 두 Sedan이 이동
	deusExMachina1->Travel(); // UBoat만 빼고 전부 이동
	deusExMachina1->Travel(); // 어떤 운송 수단도 움직이지 않음
	deusExMachina1->Travel(); // Boat, Motorcycle, 트레일러 안 달린 Sedan, UBoat가 이동
	deusExMachina1->Travel(); // Boat, Motorcycle, 두 Sedan, UBoat가 이동
	deusExMachina1->Travel(); // Airplane, Boatplane, Motorcycle, 두 Sedan이 이동
	deusExMachina1->Travel(); // Boat, Motorcycle, 두 Sedan이 이동
	deusExMachina1->Travel(); // Boat, Motorcycle, 두 Sedan이 이동
	deusExMachina1->Travel(); // 트레일러 달린 Sedan만 이동

	deusExMachina1->GetFurthestTravelled();
	//assert(deusExMachina1->GetFurthestTravelled() == boat);

	DeusExMachina* DetestDEM = DeusExMachina::GetInstance();
	
	
	_CrtDumpMemoryLeaks();
	return 0;
	
}