#ifndef REDUCE_H
#define REDUCE_H

#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include "FileManager.h"
#include <fstream>
#include <map>

using namespace std;

class Reduce
{
	public:
		string sortedString;

		vector<string> fileData;
		vector<tuple<string, string>> tokenList;
		map<string, vector<string>> frequencyMap;

		string inputdirectory, inputfile;
		string outputdirectory, outputfile;

		Reduce(string _inputdirectory, string _inputfile, string _outputdirectory, string _outputfile)
		{
			inputdirectory = _inputdirectory;
			inputfile = _inputfile;
			outputdirectory = _outputdirectory;
			outputfile = _outputfile;
		}

		void collectData();
		void sort();
		
		void parse_each();
		void reduce(string key, string ints);
		void reduce_export(string key, int n);
		
};

#endif