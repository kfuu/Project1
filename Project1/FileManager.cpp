#include "FileManager.h"

fstream FileManager::readfile(string fileName) {
	fstream file_obj(fileName);
	return file_obj;
}