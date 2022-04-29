// Author: Jeff Ngeama
// Course: CIS 687
//Syracuse University
//Project 1
//Start Date: 04/22/22
//Last Updated Date: 04/28/22

#include <iostream>
#include <stdio.h>
#include <string>
#include "Map.h"

using namespace std;
int main(int argc, char* argv[])
{
	if (argc < 3)
	{
		cout << " Three arguments are expected. Exiting..." << endl;
		return 0;
	}
	string infile = "infile.txt";
	string outfile = "outfile.txt";
	string intermediatefile = "intermediatefile.txt";
	//cout << "arg 0 "  << argv[0] << endl;
	//cout << "arg 1 " << argv[1] << endl;
	//cout << " inter " << argv[2] << endl;
	//cout << "Third argument " << argv[3] << endl;
	//cout << outfile << endl;
	//cout << infile << endl;
	//cout << intermediatefile << endl;
	Map mapobj(argv[1],argv[2],argv[3],infile,outfile,intermediatefile);
	 mapobj.map(argv[0], "Cricket is ? A popular sSport in       Australia@@?");
}