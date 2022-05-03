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
#include <vector>
#include <fstream>


using namespace std;

class FileManager
{
	private:
		string directoryname;
		string fileName;
		char mode;
		
	public:
		fstream currentFile;
		vector<string> fileContent;

		FileManager(string _directorytype, string _filename, char _mode);
		void readFile();
		string readFileContentLine(size_t l);

		string closeinfile();
		string closeoutfile();

		string writetoFile(string);
		string appendtofile(string);

		//getters
		string getDirectoryName();
		string getFileName();
		char   getMode();
		// Setters
		void setDirectoryName(string);
		void setFileName(string);
		void setMode(char);
		
		void openfileforreading();
		void openfileforwriting();
		void openfileforappending();

};

#endif


