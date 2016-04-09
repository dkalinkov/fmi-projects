#include <iostream>
#include <fstream>
#include <stdlib.h>
#include "Person.h"
#include "Community.h"
using std::cout;
using std::endl;
using std::vector;

void writeInFile(char*, const Community&);

int main()
{
	try
	{
	    char fileName[] = "com-info.txt";

		Person pesho("pesho", "8578213741", "u tqh si jivee", Baker, 518);
		Person tosho("tosho", "9191198191", "hamalskata", Baker, 189);
		Person gosho("pesho", "9484166161", "sunny beach", Baker, 789);
		Person grozo("grozo", "8894951989", "sunny beach", Baker, 326);
		gosho.SetName("gosho");

		Community sik("SIK", "10.10.10", gosho, 100);
		sik.AddMember(tosho);
		Community vis = sik;
		vis.SetName("VIS");
		vis.RemoveMember(gosho.GetEGN());
		vis.AddMember(pesho);
		vis.AddMember(grozo);

		cout << vis.GetComCount();

		writeInFile(fileName, vis);
	}
	catch (std::exception& ex)
	{
		cout << ex.what();
	}

	return 0;
}

void writeInFile(char* fileName, const Community& com)
{
    std::ofstream file(fileName);
    if(file.is_open())
    {
        file << com;
    }

    file.close();
}
