#include "Builds.h"

void Builds::setService(std::string newName, bool newIsAvailable)
{
	Service NewService;

	NewService.name = newName;
	NewService.isAvailable = newIsAvailable;

	Services.push_back(NewService);
}

void Builds::setHouse(std::string newzonedangerous, std::string newadress, double newprice, std::string newcontactPhone, std::string newID)
{
	House NewHouse;

	NewHouse.zoneDangerous = newzonedangerous;
	NewHouse.adress = newadress;
	NewHouse.price = newprice;
	NewHouse.contactPhone = newcontactPhone;
	NewHouse.ID = newID;

	Houses.push_back(NewHouse);
}

void Builds::setApartment(bool newIsPetFriendly, std::string newadress, double newprice, std::string newcontactPhone, std::string newID)
{
	Apartment NewApartment;

	NewApartment.isPetFriendly = newIsPetFriendly;
	NewApartment.adress = newadress;
	NewApartment.price = newprice;
	NewApartment.contactPhone = newcontactPhone;
	NewApartment.ID = newID;

	Apartments.push_back(NewApartment);
}

void Builds::setPremises(std::vector<std::string> newcomercialActivities, std::string newadress, double newprice, std::string newcontactPhone, std::string newID)
{
	Premise NewPremise;

	NewPremise.comercialActivities = newcomercialActivities;
	NewPremise.adress = newadress;
	NewPremise.price = newprice;
	NewPremise.contactPhone = newcontactPhone;
	NewPremise.ID = newID;

	Premises.push_back(NewPremise);

}

void Builds::setInput2(double newbudget, std::string newcomercialactivity, std::vector<std::string> newreqservices, std::string newtypebuilder, std::string newmindanger, bool newwannaPetFriendly)
{
	Input2 NewInput2;

	NewInput2.budget = newbudget;
	NewInput2.comercialActivity = newcomercialactivity;
	NewInput2.requiredServices = newreqservices;
	NewInput2.typebuilder = newtypebuilder;
	NewInput2.mindanger = newmindanger;
	NewInput2.wannaPetFriendly = newwannaPetFriendly;

	Input2E = NewInput2;
}

Builds::Input2 Builds::getInput2()
{
	return Input2E;
}

std::vector<Builds::House> Builds::getHouses()
{
	return Houses;
}
std::vector<Builds::Apartment> Builds::getApartments()
{
	return Apartments;
}
std::vector<Builds::Premise> Builds::getPremises()
{
	return Premises;
}





