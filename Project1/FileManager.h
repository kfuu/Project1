// Author: Jeff Ngeama
// Course: CIS 687
//Syracuse University
//Project 1
//Start Date: 04/22/22
//Last Updated Date: 04/28/22

#ifndef FILEMANAGER_H
#define FILEMANAGER_H
#include <iostream>
#include <stdio.h>
#include <string>
#include <fstream>


using namespace std;

class FileManager
{
	private:
		string directoryname;
		string fileName;
		char mode;
		//ifstream ifilehandler;
		//ofstream ofilehandler;

	public:
		FileManager(string _directorytype, string _filename, char _mode);
		string readline(ifstream* ifilehandler);
		string closeinfile(ifstream*);
		string closeoutfile(ofstream*);
		string writetoFile(ofstream*,string);
		string appendtofile(ofstream*,string);
		//getters
		string getDirectoryName();
		string getFileName();
		char   getMode();
		// Setters
		void setDirectoryName(string);
		void setFileName(string);
		void setMode(char);
		ifstream openfileforreading();
		ofstream openfileforwriting();
		ofstream openfileforappending();



};

#endif


