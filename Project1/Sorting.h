// Author: Jeff Ngeama
// Course: CIS 687
//Syracuse University
//Project 1
//Start Date: 04/22/22
//Last Updated Date: 04/28/22

// This class will read the contents in the intermediate file and covert it into the format given in the assigment
//And write the formatted data into the output file
#ifndef SORTING_H
#define SORTING_H
#include <iostream>
#include <stdio.h>
#include <string>
#include "FileManager.h"
#include <vector>

using namespace std;
class Sorting
{
	private:
		// These are input and output directories and file names
		string inputdirectory;
		string inputfile;
		string outputdirectory;
		string outputfile;
		//vector to all data from the intermediate file
		vector<string> datavector;
		
		//
	public:
		//constructor will inialize the input and output directory files.
		Sorting(string _inputdirectory,string _inputfile,string _outputdirectory,string _outputfile)
		{
			inputdirectory = _inputdirectory;
			inputfile = _inputfile;
			outputdirectory = _outputdirectory;
			outputfile = _outputfile;
		}
		//This method will data from the intermediate file and fill the data vector
		void collectdata();
		//convert the data into the format necessary and write to the output directory
		void sortandwritedata(string outputdirectory, string outputfile);
		//getters
		string getInputdirectory();
		string getInputfile();
		string getOutputdirectory();
		string getOutputfile();

		//setters
		void setInputdirectory(string);
		void setInputfile(string);
		void setOutputdirectory(string);
		void setOutputfile(string);


};
#endif
