#include "Zoznam.h"
//#include <string.h>


Zoznam::Zoznam()
{
}
bool wayToSort(Slovo *s1, Slovo *s2) { return s1->getPocetZnakov() < s2->getPocetZnakov(); };
void Zoznam::upracZoznam()
{
	sort(zoznamSlov.begin(), zoznamSlov.end(), wayToSort);
}

vector<Slovo*> Zoznam::najdiZhodu()
{	
	vector<Slovo*> pomocny;
	vector<Slovo*> dalsi;
	int pocet = 1;
	char *retazec = nullptr;
	char *retazec2 = nullptr;
	for (unsigned int i = 0; i < zoznamSlov.size(); i++)
	{
		pomocny.push_back(zoznamSlov[i]);
	}
	for (unsigned int i = 0; i < pomocny.size(); i++)
	{
		for (unsigned int j = 0; j < pomocny.size(); j++)
		{
			if (i != j) {
				retazec = new char[pomocny[i]->getSlovo().length() + 1];
				strcpy(retazec, pomocny[i]->getSlovo().c_str());
				retazec2 = new char[pomocny[j]->getSlovo().length() + 1];
				strcpy(retazec2, pomocny[j]->getSlovo().c_str());
				if (strcmp(retazec, retazec2) == 0)
				{
					pocet++;
					pomocny.erase(pomocny.begin() + j);
					j--;
				}
				delete retazec;
				delete retazec2;
			}
		}
		dalsi.push_back(new Slovo(pomocny[i]->getSlovo(), pocet));
		pocet = 1;
	}
	return dalsi;
}

void Zoznam::vypisZhodne()
{
	vector<Slovo*> zhodne = najdiZhodu();
	for (unsigned int i = 0; i < zhodne.size(); i++)
	{
		if (zhodne[i]->getPocet() > 1)
		{
			cout << zhodne[i]->getPocet() << ": " << zhodne[i]->getSlovo() << endl;
		}
	}
	for (auto &p : zhodne)
	{
		delete p;
	}

}

void Zoznam::nacitajSlova(const char * menoSuboru)
{
	ifstream citac;
	citac.open(menoSuboru);
	string riadok;
	while (getline(citac, riadok)) {
		zoznamSlov.push_back(new Slovo(riadok, 1));
	}
	if (citac.is_open()) citac.close();
}

void Zoznam::zapisDoSuboru(const char* menoSuboru)
{
	fstream zapisovac(menoSuboru);
	for (unsigned int i = 0; i < zoznamSlov.size(); i++)
	{
		zapisovac << zoznamSlov[i]->getSlovo() << endl;
	}
	if (zapisovac.is_open()) zapisovac.close();
}


Zoznam::~Zoznam()
{
	for (auto &p : zoznamSlov)
	{
		delete p;
	}
}
