#pragma once
#include <string>

using namespace std;
class Slovo
{

private:
	string slovo;
	int pocet = 0;
public:
	Slovo(string pSlovo, int pPocet) { slovo = pSlovo; pocet = pPocet; };
	int getPocetZnakov() { return slovo.length(); };
	string getSlovo() { return slovo; };
	int getPocet() { return pocet; }
	void setPocet(int pPocet) { pocet = pocet + pPocet; };
	~Slovo();};

