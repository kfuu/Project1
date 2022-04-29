// Author: Jeff Ngeama
// Course: CIS 687
//Syracuse University
//Project 1
//Start Date: 04/22/22
//Last Updated Date: 04/28/22

#include "Map.h"

//This function takes a line of text and a key.The key is the name of the intermediate file.The function tokenizes the line of text
//and saves into the intermediate file.
//input: key - name of the intermediate file
//       value - line of text
// output: none
void Map::map(string key, string value)
{
	//Define all the punctution that are to be removed.
	string punction = "!,.;:'$@*&^()%#~?/";
	//This for loop will go through all the punctuations and remove them
	for (int i = 0; i < punction.length(); i++)
	{
		// get the next punctuation
		string letter = punction.substr(i, 1);
		//check if the punctuation is in the value variable
		std::size_t found = value.find(letter);
		//if it is in the value variable remove it
		while (found != std::string::npos)
		{
			value.replace(found, 1, "");
			found = value.find(letter);
		}
	}
	//covert all the upper case in the value variable to lower case
	for (size_t i = 0; i < value.length(); i++)
	{
		string letter = value.substr(i, 1);
		//check each character in the value variable
		char* ch = &letter[0];
		//If the the character is upper case convert it to lower case.
		if (isupper(*ch))
		{
			string s;
			//covert the string variable to character
			s.push_back(tolower(*ch));
			//covert it to lower case
			value.replace(i, 1,s);
		}
	}
	//tokenize the string variable value
	string word = "";
	// create a string array to hold all the words
	string wordArray[500];
	int j = 0;
	// set the number of words to zero at the begining
	int numWords = 0;
	size_t i = 0;
	string msg = "";
	//use the for for loop to go over the characters of value variable
	for ( i = 0; i < value.length(); i++)
	{
		string letter = value.substr(i, 1);
		//if the character is not a space,add it to the word
		if (letter != " ")
		{
			word = word + letter;
		}
		else
		{
			//if the character is a space,separate the word
			if (word.length() > 0)
			{
				wordArray[j] = word;
				// call the export method to add the word to the buffer
				// if the length of the buffer is greater than the buffer size,append the content to the intermediate file
				 msg = map_export(key, word);
				word = "";
				j = j + 1;		
			}
		}
		//closes the last word
		if (i == value.length() - 1)
		{
			wordArray[j] = word;
			msg = map_export(key, word);
			word = "";
			j = j + 1;
		}
	}
	// set the number of words to numwords.
	numWords = j;
	msg = exporttherest();
	cout << "this is out " << msg << endl;
}
//This export function buffers the output in memory and periodically writes the data to the disk.
//input: key - name of the intermediate file
//       value - a word
// output: none
string Map::map_export(string key, string value)
{
	//delete the contents of the intermediate file first
	 FileManager file(intermediatefiledirectory, intermediatefilename,'w');
	 ofstream ofilehandler = file.openfileforwriting();
	 file.closeoutfile(&ofilehandler);
	//add the value to the buffer
	string line =   "(" + value + ",1)\n";
	string msg = "";
	buffer = buffer + line;
	//if the length of the buffer is greater than buffer size,add buffer to the intermediate file
	if (buffer.length() > buffersize)
	{
		FileManager file(intermediatefiledirectory, intermediatefilename,'a');
		ofstream ofilehandler = file.openfileforappending();
		// write buffer to the intermediate file
		// Empty buffer
		msg = file.appendtofile(&ofilehandler,buffer);
		buffer = "";
		file.closeoutfile(&ofilehandler);	
	}
	return msg;
}
// get the Buffer value
string Map::getBuffer()
{
	return buffer;
}
//get the Buffersize
int Map::getBufferSize()
{
	return buffersize;
}
// set the Buffer value
void Map::setBuffer(string _buffer)
{
	buffer = _buffer;
}
// set the Buffersize
void Map::setBufferSize(int _buffersize)
{
	buffersize = _buffersize;
}
string Map::exporttherest()
{
	FileManager file(intermediatefiledirectory, intermediatefilename, 'a');
	ofstream ofilehandler = file.openfileforappending();
	string msg = "";
	if (ofilehandler.good())
	{
		// write buffer to the intermediate file
		// Empty buffer
		msg = file.appendtofile(&ofilehandler, buffer);
		buffer = "";
		file.closeoutfile(&ofilehandler);
		return msg;
	}
	
}