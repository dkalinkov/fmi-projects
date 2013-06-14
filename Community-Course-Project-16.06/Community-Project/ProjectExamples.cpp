#include <iostream>
#include <stdlib.h>
#include "Person.h"
using std::cout;
using std::endl;

void main()
{
	Person pesho("pesho", "8578213741", "u tqh si jivee", Baker, 518);

	Person gosho(pesho);
	gosho.SetName("gosho");

	Person tosho = gosho;
	tosho.SetName("tosho");

	cout << tosho << endl << gosho << endl << pesho;
}