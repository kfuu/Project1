#include <iostream>
#include <stdio.h>
#include <string>
#include <fstream>
#include <vector>

#ifndef FILEMANAGER_H
#define FILEMANAGER_H

using namespace std;

class FileManager
{
	private:
		
		string filePath;
		vector<string> fileContent; // temporary place to hold content

		
	public:
		fstream currentFile;

		FileManager(string s); // constructor

		string getFilePath();
		void setFilePath(string s);

		void readFile();
		//void writeFile();
		//bool fileExists();
		void addToFileContent(string s);
		int getFileSize();
		
};

#endif