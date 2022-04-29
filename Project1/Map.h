// Author: Jeff Ngeama
// Course: CIS 687
//Syracuse University
//Project 1
//Start Date: 04/28/22
//Last Updated Date: 04/25/22

#ifndef MAP_H
#define MAP_H
#include <iostream>
#include <stdio.h>
#include <string>
#include "FileManager.h"
#include <fstream>

using namespace std;
 
//This class holds word and value for each occurrence of each word in a given line of data. That is this class can be used to
//tokenize a line of data into words.The punctuations are removed from words and coverted to lower case.
//The words are written into an intermediate file.
class Map
{
	//
	private:
		//These are the private date members of the map class
		string buffer;
		int buffersize;
		string infiledirectory, outfiledirectory, intermediatefiledirectory;
		string infilename, outfilename, intermediatefilename;
	public:
		// constructor
		Map(string _infiledirectory, string _outfiledirectory, string _intermediatefiledirectory,
			string _infilename,string _outfilename,string _intermediatefilename)
		{
			buffer = "";
			buffersize = 250;
			infiledirectory = _infiledirectory;
			outfiledirectory = _outfiledirectory;
			intermediatefiledirectory = _intermediatefiledirectory;
			infilename = _infilename;
			outfilename = _outfilename;
			intermediatefilename = _intermediatefilename;

		}
		//tokenize the value into words and save them in the intermediate file
		void map(string key, string value);
		//Add the words to the buffer and save them in the intermediate file
		string map_export(string key, string value);
		string getBuffer();
		int getBufferSize();
		//set the buffer to a given value
		void setBuffer(string);
		//set the buffer size to a given value
		void setBufferSize(int);
		// To sort and aggregate the values in the intermediate file
		string exporttherest();



};


#endif // MAP_H