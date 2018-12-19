#include "Zoznam.h"
int main() {
	Zoznam *z = new Zoznam();
	z->nacitajSlova("slova.txt");
	z->upracZoznam();
	z->zapisDoSuboru("vystup.txt");
	z->vypisZhodne();
	delete z;
	return 0;
}