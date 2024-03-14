#pragma once
#include <iostream>
#include <vector>

class Builds 
{
public:
	struct Build
	{
		std::string adress;
		double price;
		std::string contactPhone;
		std::string ID;
	};

	struct House : Build
	{
		std::string zoneDangerous;
	};

	struct Apartment : Build
	{
		bool isPetFriendly;
	};

	struct Premise : Build
	{
		std::vector <std::string> comercialActivities;
	};

	struct Service
	{
		std::string name;
		bool isAvailable;
	};
	struct Input2
	{
		double budget;
		std::string comercialActivity;
		std::vector<std::string> requiredServices;
		std::string typebuilder;
		std::string mindanger;
		bool wannaPetFriendly;
	};

private:
		
	std::vector <House> Houses;
	std::vector <Apartment> Apartments;
	std::vector <Premise> Premises;
	std::vector <Service> Services;
	Input2 Input2E;
		 
public:
	void setService(std::string newName, bool newIsAvailable);
	void setHouse(std::string newzonedangerous, std::string newadress, double newprice, std::string newcontactPhone, std::string newID);
	void setApartment(bool newIsPetFriendly, std::string newadress, double newprice, std::string newcontactPhone, std::string newID);
	void setPremises(std::vector<std::string> newcomercialActivities, std::string newadress, double newprice, std::string newcontactPhone, std::string newID);
	void setInput2(double newbudget, std::string newcomercialactivity, std::vector<std::string> newreqservices, std::string newtypebuilder, std::string newmindanger, bool newwannaPetFriendly);
	Input2 getInput2();
	std::vector<House> getHouses();
	std::vector<Apartment> getApartments();
	std::vector<Premise> getPremises();
	


};

