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
	DeusExMachina* deusExMachina2 = DeusExMachina::GetInstance();

	bool bSame = deusExMachina1 == deusExMachina2;
	assert(bSame);

	Airplane* airplane = new Airplane(5);
	Boat* boat = new Boat(5);
	Boatplane* boatplane = new Boatplane(5);
	Motorcycle* motorcycle = new Motorcycle();
	Sedan* sedan = new Sedan();
	Sedan* sedan2 = new Sedan();
	UBoat* uboat = new UBoat();

	bool bAdded = sedan2->AddTrailer(new Trailer(50));
	assert(bAdded);

	bAdded = sedan2->AddTrailer(new Trailer(60));
	assert(!bAdded);

	bAdded = deusExMachina1->AddVehicle(airplane);
	assert(bAdded);

	deusExMachina1->AddVehicle(boat);
	deusExMachina1->AddVehicle(boatplane);
	deusExMachina1->AddVehicle(motorcycle);
	deusExMachina1->AddVehicle(sedan);
	deusExMachina1->AddVehicle(sedan2);
	deusExMachina1->AddVehicle(uboat);
	deusExMachina1->AddVehicle(new Airplane(5));
	deusExMachina1->AddVehicle(new Airplane(5));
	deusExMachina1->AddVehicle(new Airplane(5));

	bAdded = deusExMachina1->AddVehicle(new Airplane(5));

	assert(!bAdded);

	
	deusExMachina1->RemoveVehicle(9);
	deusExMachina1->RemoveVehicle(8);
	deusExMachina1->RemoveVehicle(1);
	bool bRemoved = deusExMachina1->RemoveVehicle(7);
	//assert(bRemoved);

	bRemoved = deusExMachina1->RemoveVehicle(9);
	//assert(!bRemoved);

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

	//assert(deusExMachina1->GetFurthestTravelled() == boat);

	
	_CrtDumpMemoryLeaks();
	return 0;
	
}