#include "HED.h"

void HEDFunc::populateList(std::string fileName)
{
	std::ifstream HEDFile(fileName.c_str());
	std::vector<std::string> script;
	std::string temp = "";
	int lineCount = 0;
	int intGarbage = 0;
	int entID = 0;

	if (!HEDFile)
		throw "HED File " + fileName + " not found!";

	while (!HEDFile.eof())
	{
		getline(HEDFile, temp);
		//remove comments from the line
		if ((intGarbage = temp.find("//")) != -1)
		{
			temp = temp.substr(0, intGarbage);
		}
		
		if ((intGarbage = temp.find("\t")) != -1)
		{
			temp.erase(intGarbage,1);
		}
		
		if (temp.substr(0,1) != "\n" && temp != "" && temp != " ")
			script.push_back(temp);
		lineCount++;
		
	}

	HEDFile.close();

	//go through the script and get the entity classes and IDs

	for (int i = 0; i < script.size(); i++)
	{
		temp = script[i].substr(0,4);
		if (temp == "ent_")
		{
			temp = script[i].substr(4,1);
			entID = atoi(script[i].c_str());

			intGarbage = script[i].find("CBase");
			temp = script[i].substr(intGarbage, script[i].length() - intGarbage);

			list.entData.addToDictionary(entID, temp);
//			script.clear();
		}
	}
}

CHED::CHED()
{
	using namespace HEDFunc;

	_DB.insert(entityMap::value_type(0, &instantiator<CBasePlayer>));
	_DB.insert(entityMap::value_type(1, &instantiator<CBaseNPC>));
}

CHED::~CHED()
{
	_DB.clear();
}

CBaseTheoryEnt * CHED::createEnt(int ID, std::string name, float x, float y, std::vector<std::string> params)
{
	CBaseTheoryEnt * temp = _DB[ID]();
	temp->initialize(name, x, y, params);
	return temp;
}
