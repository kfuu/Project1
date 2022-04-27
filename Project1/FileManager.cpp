#include "FileManager.h"


FileManager::FileManager(string s)
{
	/*
	Constructor
	*/
	filePath = s;
}

string FileManager::getFilePath() {
	/*
	This function returns the filePath member variable.
	*/

	return filePath;
}

void FileManager::setFilePath(string s) {
	/*
	This function sets the file path of the current instance.
	*/

	filePath = s;
}


void FileManager::readFile() {
	// fstream file_obj(fileName);
	// return file_obj;

	/*
	* This function reads in the contents of the file as
	* specified from the filePath. The contents are saved
	* into a vector by calling addToFileContent().
	*/

	string path = getFilePath();
	currentFile.open(path.c_str(), fstream::in);

	string input;
	for (int i = 0; getline(currentFile, input); i++) {
		addToFileContent(input);
	}

	currentFile.close();
	currentFile.clear();
}

void FileManager::addToFileContent(string s) {
	/*
	This function abstracts the interface for pushing back
	to a vector, in this case, fileContent. 
	*/

	fileContent.push_back(s);
}

string FileManager::readFileContentLine(size_t l) {
	/*
	This function can be called in main() once the file has been read with
	readFile(). This function returns the contents of the file
	at line l. 
	*/

	if (l > getFileSize()) {
		throw invalid_argument("Line number out of bounds.");
	}
	return fileContent[l];
}

int FileManager::getFileSize() {
	/*
	This function returns the size/length of the file once it has
	been read.
	*/

	return fileContent.size();
}