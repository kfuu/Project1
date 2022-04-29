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
ifstream FileManager::openfileforreading()
{
	if (mode == 'r')
	{
		ifstream filehandler;
		filehandler.open(directoryname + fileName);
		if (filehandler.is_open())
		{
			return filehandler;
		}
		
	}
	
}
//open the file for wrting
ofstream FileManager::openfileforwriting()
{

	if (mode == 'w')
	{
		ofstream ofilehandler;
		ofilehandler.open(directoryname + fileName);
		if (ofilehandler.is_open())
		{
			return ofilehandler;
		}

	}
}
//open file for appending
ofstream FileManager::openfileforappending()
{
	if (mode == 'a')
	{
		ofstream ofilehandler;

		ofilehandler.open(directoryname + fileName, std::ios::app | std::ios_base::out);
		if (ofilehandler.is_open())
		{

			return ofilehandler;
		}
	}
}
//read a line from a file
string FileManager::readline(ifstream* ifilehandler)
{
	string outline = "";
	if (ifilehandler->good())
	{
		*ifilehandler >> outline;
		return "success";
	}
	else
	{
		return "there was an error";
	}
}
// close the outfile
string FileManager::closeoutfile(ofstream* ofilehandler)
{
	if (ofilehandler->good())
	{
		ofilehandler->close();
		return "success";
	}
	else
	{
		return " there was an error";
	}
}
//close the infile
string FileManager::closeinfile(ifstream* ifilehandler)
{
	if (ifilehandler->good())
	{
		ifilehandler->close();
		return "success";
	}
	else
	{
		return " there was an error";
	}
}
//write line  to the  file
string FileManager::writetoFile(ofstream* ofilehandler,string dataline)
{
	if (ofilehandler->good())
	{
		cout << " from exportrest " << dataline << endl;
		*ofilehandler << dataline + "\n";
		return "success";
	}
	else
	{
		return " there was an error";
	}
}
// append a line to the file
string FileManager::appendtofile(ofstream* ofilehandler,string dataline)
{
	if (ofilehandler->good())
	{
		*ofilehandler << dataline;
		return "success";
	}
	else
	{
		return " there was an error";
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

