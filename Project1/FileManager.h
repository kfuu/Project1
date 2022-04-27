#include <iostream>
#include <stdio.h>
#include <string>
#include <fstream>

using namespace std;

class FileManager
{
	private:
		//string directorytype;
		//string fileName; // not necessary unless we use the FileManager class to get and set the fileName?
		//char mode;
	public:
		fstream readfile(string fileName);
};

