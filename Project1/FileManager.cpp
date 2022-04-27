#include "FileManager.h"


// constructor
FileManager::FileManager(string s)
{
	filePath = s;
}

string FileManager::getFilePath() {
	return filePath;
}

void FileManager::setFilePath(string s) {
	filePath = s;
}


void FileManager::readFile() {
	// fstream file_obj(fileName);
	// return file_obj;

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
	fileContent.push_back(s);
}

int FileManager::getFileSize() {
	return fileContent.size();
}