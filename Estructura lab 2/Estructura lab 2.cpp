#include <iostream>
#include <json/json.h>
#include <fstream>
#include "Builds.h"
#include "Logic.h"
#include <iostream>


int main()
{
    
    std::string filepath;
    std::ifstream file;
    std::string line;
    Json::Value actualJson;
    Json::Reader reader;   
    std::vector<std::string> Outputsfinal;

    int currline = 0;


    do
    {
        std::system("cls");
        std::cout << "Por favor ingresar el path de su archivo jsonl" << std::endl;
        std::cin >> filepath;
        file.open(filepath);

    } while (file.fail());



    while (getline(file, line))
    {
        Builds newBuild;
        Logic newLogic;
        
        reader.parse(line, actualJson);
        const Json::Value& input1 = actualJson["input1"];       


        for (const auto& item : input1)
        {
            
            //Parseo services
            const Json::Value& Services = item["services"];
            
            for (const auto& eachService : Services.getMemberNames())
            {
                newBuild.setService(eachService, Services[eachService].asBool());
            }
            
            //Parseo builds
            const Json::Value& buildings = item["builds"];

            //Parseo Houses
            const Json::Value& Houses = buildings["Houses"];

            for (const auto& eachHouse : Houses)
            {
                
                newBuild.setHouse(eachHouse["zoneDangerous"].asString(), eachHouse["address"].asString(), eachHouse["price"].asDouble(), eachHouse["contactPhone"].asString(), eachHouse["id"].asString());
                
            }

            //Parseo Apartments
            const Json::Value& Apartments = buildings["Apartments"];

            for (const auto& eachApartment : Apartments)
            {
                newBuild.setApartment(eachApartment["isPetFriendly"].asBool(), eachApartment["address"].asString(), eachApartment["price"].asDouble(), eachApartment["contactPhone"].asString(), eachApartment["id"].asString());
            }

            //Parseo Premises
            const Json::Value& Premises = buildings["Premises"];

            for (const auto& eachPremise : Premises)
            {
                std::vector <std::string> Activities;

                for (const auto& currActivity : eachPremise["commercialActivities"])
                {
                    Activities.push_back(currActivity.asString());
                }

                newBuild.setPremises(Activities, eachPremise["address"].asString(), eachPremise["price"].asDouble(), eachPremise["contactPhone"].asString(), eachPremise["id"].asString());
            }
        }

        //Parseo Input2

        const Json::Value& input2 = actualJson["input2"];

        for (const auto& item : input2)
        {
            const Json::Value& RequiredServices = input2["requiredServices"];
            std::vector <std::string> reqServices;
            for (const auto& service : RequiredServices)
            {
                reqServices.push_back(service.asString());
            }

            newBuild.setInput2(input2["budget"].asDouble(), input2["commercialActivity"].asString(), reqServices, input2["typeBuilder"].asString(), input2["minDanger"].asString(), input2["wannaPetFriendly"].asBool());
        }     


       //Aquí lo zampo la lógica

        Builds::Input2 Wea = newBuild.getInput2();
        std::vector<std::string> output;

        if (Wea.typebuilder == "Houses")
        {
            if (newBuild.getHouses().size() > 0)
            {
                output = newLogic.logicHouse(newBuild.getHouses(), Wea);
            }
        }
        else if (Wea.typebuilder == "Apartments")
        {
            if (newBuild.getApartments().size() > 0)
            {
                output = newLogic.logicApartment(newBuild.getApartments(), Wea);
            }

        }
        else if (Wea.typebuilder == "Premises") 
        {
            if (newBuild.getPremises().size() > 0)
            {
                output = newLogic.logicPremises(newBuild.getPremises(), Wea);
            }
        }

        std::string Outputxd = "[";

        for (const auto& item : output)
        {
            if (item != output[output.size() - 1])
            {
                Outputxd = Outputxd + item + ", ";

            }
            else
            {
                Outputxd = Outputxd + item;

            }
            
        }

        Outputxd = Outputxd + "]";

        Outputsfinal.push_back(Outputxd);
        
        currline++;
    }


    std::ofstream OutputFile;

    OutputFile.open("C:\\Users\\Public\\Documents\\OutputFileLab2.txt");

    for (int i = 0; i < Outputsfinal.size(); i++)
    {
        OutputFile << Outputsfinal[i] << "\n";
    }

    OutputFile.close();
    
    
}

