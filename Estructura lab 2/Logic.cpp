#include "Logic.h"

int Logic::delegate(std::string typeBuilder)
{
	if (typeBuilder == "Houses")
	{
		return 1;
	}
	else if (typeBuilder == "Apartments")
	{
		return 2;
	}
	else if (typeBuilder == "Premises")
	{
		return 3;
	}
	else
	{
		return -1;
	}
}

std::vector<std::string> Logic::logicHouse(std::vector<House> Houses, Input2 input2)
{
	std::vector<std::string> aceptedColors;
	std::vector<House> outputhouses;

	
	if (input2.mindanger == "Red")
	{
		aceptedColors.push_back("Red");
	}
	else if (input2.mindanger == "Orange")
	{
		aceptedColors.push_back("Red");
		aceptedColors.push_back("Orange");
	}
	else if (input2.mindanger == "Yellow")
	{
		aceptedColors.push_back("Red");
		aceptedColors.push_back("Orange");
		aceptedColors.push_back("Yellow");
	}
	else if (input2.mindanger == "Green")
	{
		aceptedColors.push_back("Red");
		aceptedColors.push_back("Orange");
		aceptedColors.push_back("Yellow");
		aceptedColors.push_back("Green");
	}


	for (const auto& currHouse : Houses)
	{
		for (const auto& color : aceptedColors)
		{
			if (currHouse.zoneDangerous == color)
			{
				if (currHouse.price <= input2.budget)
				{
					outputhouses.push_back(currHouse);
				}
			}
		}		
	}
	
	//ordenar menor a mayor precio
	if (outputhouses.size() > 0)
	{
		return ordershit(outputhouses);

	}
	else
	{
		std::vector<std::string> xd;
		return xd;
	}



}
std::vector<std::string> Logic::logicApartment(std::vector<Apartment> Apartments, Input2 input2)
{
	std::vector<Apartment> outputApartments;

	for (const auto& currApartment : Apartments)
	{
		if (currApartment.isPetFriendly == input2.wannaPetFriendly)
		{
			if (currApartment.price <= input2.budget)
			{
				outputApartments.push_back(currApartment);
			}
		}
	}

	//Ordenar de menor a mayor precio
	if (outputApartments.size() > 0)
	{
		return ordershit(outputApartments);
	}
	else
	{
		std::vector<std::string> xd;
		return xd;
	}

}
std::vector<std::string> Logic::logicPremises(std::vector<Premise> Premises, Input2 input2)
{
	std::vector<Premise> outputPremises;

	for (const auto& currPremise : Premises)
	{
		for (int i = 0; i < currPremise.comercialActivities.size(); i++)
		{
			if (currPremise.comercialActivities[i] == input2.comercialActivity && currPremise.price <= input2.budget)
			{
				outputPremises.push_back(currPremise);
				i = currPremise.comercialActivities.size();
			}
		}
	}

	//Ordenar de menor a mayor precio
	if (outputPremises.size() > 0)
	{
		return ordershit(outputPremises);
	}
	else
	{
		std::vector<std::string> xd;
		return xd;
	}

}


std::vector<std::string> Logic::ordershit(std::vector<Builds::House> Houses)
{
	for (int i = 0; i < Houses.size() - 1; i++) 
	{
		for (int j = 0; j < Houses.size() - 1; j++) 
		{
			if (Houses[j].price > Houses[j + 1].price) 
			{
				Builds::House temp = Houses[j];
				Houses[j] = Houses[j + 1];
				Houses[j + 1] = temp;
			}
		}
	}

	std::vector<std::string> output;

	for (const auto& currHouse : Houses)
	{
		output.push_back(currHouse.ID);
	}

	return output;
}

std::vector<std::string> Logic::ordershit(std::vector<Builds::Apartment> Apartments)
{
	for (int i = 0; i < Apartments.size() - 1; i++) 
	{
		for (int j = 0; j < Apartments.size() - 1; j++) 
		{
			if (Apartments[j].price > Apartments[j + 1].price) 
			{
				Builds::Apartment temp = Apartments[j];
				Apartments[j] = Apartments[j + 1];
				Apartments[j + 1] = temp;
			}
		}
	}

	std::vector<std::string> output;

	for (const auto& currApartment : Apartments)
	{
		output.push_back(currApartment.ID);
	}

	return output;
}

std::vector<std::string> Logic::ordershit(std::vector<Builds::Premise> Premises)
{
	for (int i = 0; i < Premises.size() - 1; i++)
	{
		for (int j = 0; j < Premises.size() - 1; j++)
		{
			if (Premises[j].price > Premises[j + 1].price)
			{
				Builds::Premise temp = Premises[j];
				Premises[j] = Premises[j + 1];
				Premises[j + 1] = temp;
			}
		}
	}

	std::vector<std::string> output;

	for (const auto& currPremise : Premises)
	{
		output.push_back(currPremise.ID);
	}

	return output;
}

