#pragma once
#include <vector>
#include "Slovo.h"
#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

class Zoznam
{
private:
	vector<Slovo*> zoznamSlov;
public:
	Zoznam();
	void upracZoznam();
	vector<Slovo*> najdiZhodu();
	void vypisZhodne();
	void nacitajSlova(const char* menoSuboru);
	void zapisDoSuboru(const char* menoSuboru);
	~Zoznam();
};

