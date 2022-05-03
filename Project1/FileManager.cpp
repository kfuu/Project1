// Author: Jeff Ngeama
// Course: CIS 687
//Syracuse University
//Project 1
//Start Date: 04/22/22
//Last Updated Date: 04/28/22

#include "FileManager.h"

// constructor ,initialize the directory name and file name
FileManager::FileManager(string _directoryname, string _filename, char _mode)
{
	directoryname = _directoryname;
	fileName = _filename;
	mode = _mode;
}
// open the file for reading
void FileManager::openfileforreading()
{
	if (mode == 'r')
	{
		currentFile.open(directoryname + '/' + fileName, std::fstream::in);
	}
	
}
//open the file for wrting
void FileManager::openfileforwriting()
{

	if (mode == 'w')
	{
		currentFile.open(directoryname + '/' + fileName, std::fstream::out);
	}
}
//open file for appending
void FileManager::openfileforappending()
{
	if (mode == 'a')
	{
		currentFile.open(directoryname + '/' +  fileName, std::fstream::app);
	}
}


//read a line from a file
void FileManager::readFile()
{
	if (currentFile.is_open()) {
		string input;
		for (int i = 0; getline(currentFile, input); i++) {
			fileContent.push_back(input);
		}
	}

	closeinfile();
}
string FileManager::readFileContentLine(size_t l) {
	/*
	This function can be called in main() once the file has been read with
	readFile(). This function returns the contents of the file
	at line l.
	*/

	if (l > fileContent.size()) {
		throw invalid_argument("Line number out of bounds.");
	}
	return fileContent[l];
}


// close the outfile
string FileManager::closeoutfile()
{
	if (currentFile.is_open()) {
		currentFile.close();
	}
	else { return "Error"; }
	return "Success";
}

//close the infile
string FileManager::closeinfile()
{
	if (currentFile.is_open()) {
		currentFile.close();
	}
	else { return "Error"; }
	return "Success";
}


//write line  to the  file
string FileManager::writetoFile(string dataline)
{
	if (currentFile.is_open()) {
		currentFile << dataline + "\n";
		currentFile.flush();
		closeoutfile();
		return "Success";
	}
	else {
		return "Error";
	}
	

}
// append a line to the file
string FileManager::appendtofile(string dataline)
{
	if (currentFile.is_open()) {
		currentFile << dataline;
		currentFile.flush();
		closeoutfile();
		return "Success";
	}
	else {
		return "Error";
	}

}


// get the file directory name
string FileManager::getDirectoryName()
{
	return directoryname;
}
//get file name
string FileManager::getFileName()
{
	return fileName;
}

char   FileManager::getMode()
{
	return mode;
}



void FileManager::setDirectoryName(string _directoryname)
{
	directoryname = _directoryname;
}

void FileManager::setFileName(string _filename)
{
	fileName = _filename;
}

void FileManager::setMode(char _mode)
{
	mode = _mode;
}

