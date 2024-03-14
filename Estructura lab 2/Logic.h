#pragma once
#include "Builds.h"
#include <vector>
class Logic : Builds
{

public:
	std::vector<std::string> logicHouse(std::vector<House> Houses, Input2 input2);
	std::vector<std::string> logicApartment(std::vector<Apartment> Apartments, Input2 input2);
	std::vector<std::string> logicPremises(std::vector<Premise> Premises, Input2 input2);
	std::vector<std::string> ordershit(std::vector<Apartment> Apartments);
	std::vector<std::string> ordershit(std::vector<House> Houses);
	std::vector<std::string> ordershit(std::vector<Premise> Premises);




	int delegate(std::string typeBuilder);


};

