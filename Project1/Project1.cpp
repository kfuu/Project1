#include <iostream>
#include <stdio.h>
#include "string"
#include "FileManager.h"
#include <vector>

using namespace std;
int main(int argc, char* argv[])
{
	FileManager fm("test.txt");
	fm.readFile();

	vector<string> v;
	for (int i = 0; i < fm.getFileSize(); i++) {
		string s = fm.readFileContentLine(i);
		v.push_back(s);
		cout << s << endl;
	}

	for (string s : v) {
		cout << s << endl;
	}

		

	/*if (argc < 3)
	{
		cout << " Three arguments are expected. Exiting..." << endl;
		return 0;
	}*/
}