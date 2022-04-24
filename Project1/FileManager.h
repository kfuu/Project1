#include <iostream>
#include <stdio.h>
#include <string>
#include <fstream>

using namespace std;

class FileManager
{
	private:
		string directorytype;
		string fileName;
		char mode;
	public:
		ifstream readfile(string fileName, char _mode);
};

