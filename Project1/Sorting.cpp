// Author: Jeff Ngeama
// Course: CIS 687
//Syracuse University
//Project 1
//Start Date: 04/22/22
//Last Updated Date: 04/28/22


#include "Sorting.h"

using namespace std;

void Sorting::collectdata()
{
	// create an obj of the file manager
	// Open interfile for reading
	string word = "";
	int index = 0;
	string wordcountstring = "";
	//create a file manager object
	FileManager fileintermediate(inputdirectory, inputfile, 'r');
	
	string line = "";
	//open the file for reading
	ifstream ifilehandler = fileintermediate.openfileforreading();
	line = fileintermediate.readline(&ifilehandler);
	// read all the data from intermediate file and fill the data vector vector
	while (line != "")
	{
		datavector.push_back(line);
		line = fileintermediate.readline(&ifilehandler);
	}
	//close the file 
	fileintermediate.closeinfile(&ifilehandler);
}

void Sorting::sortandwritedata(string outputdirectory, string outputfile)
{
	// open the output file for writing the formatted data
	FileManager fileout(outputdirectory, outputfile, 'w');
	int inputlength = datavector.size();
	string wordarray[200];
	string frequencyarray[200];
	string word = "";
	string value = "";
	int wordsize = 0;
	int j = 0;
	int l = 0;
	//remove the paratheses and extract the value key value pair
	for (int i = 0; i < inputlength; i++)
	{
		word = datavector[i];
		word.erase(0, 1);
		wordsize = word.size();
		word.erase(wordsize - 3, 3);
		wordarray[j] = word;
		frequencyarray[j] = "";
		j = j + 1;
	}
	// process words in the array
	//convert the words into the required format
	for (int i = 0; i < j; i++)
	{
		word = wordarray[i];
		for (int k = 0; k < j; k++)
		{
			if (wordarray[k] == word)
			{			
				frequencyarray[l] = frequencyarray[l] + ",1";
				l = l + 1;
			}
			else
			{
				frequencyarray[l] = word + "[,1";
			}
		}
	}
	//open outfile for writing
	ofstream ofilehandler = fileout.openfileforwriting();
	for (int i = 0; i < l; i++)
	{
		word = frequencyarray[i] + "]";
		//write the word to the output file
		fileout.writetoFile(&ofilehandler, word);
	}
	fileout.closeoutfile(&ofilehandler);
}

string Sorting::getInputdirectory()
{
	return inputdirectory;
}
string Sorting::getInputfile()
{
	return inputfile;
}
string Sorting::getOutputdirectory()
{
	return outputdirectory;
}
string Sorting::getOutputfile()
{
	return outputfile;
}

//setters
void Sorting::setInputdirectory(string _inputdirectory)
{
	inputdirectory = _inputdirectory;
}
void Sorting::setInputfile(string _inputfile)
{
	inputfile = _inputfile;
}
void Sorting::setOutputdirectory(string _outputdirectory)
{
	outputdirectory = _outputdirectory;
}
void Sorting::setOutputfile(string _outputfile)
{
	outputfile = _outputfile;
}



