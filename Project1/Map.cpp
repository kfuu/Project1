#include "Map.h"


void Map::map(string key, string value)
{
	string punction = "!,.;:'$@*&^()%#~?/";
	for (int i = 0; i < punction.length(); i++)
	{
		string letter = punction.substr(i, 1);
		std::size_t found = value.find(letter);
		while (found != std::string::npos)
		{
			value.replace(found, 1, "");
			found = value.find(letter);
		}
	}
	for (size_t i = 0; i < value.length(); i++)
	{
		string letter = value.substr(i, 1);
		char* ch = &letter[0];
		if (isupper(*ch))
		{
			string s;
			s.push_back(tolower(*ch));
			value.replace(i, 1,s);
		}
	}
	string word = "";
	string wordArray[500];
	int j = 0;
	int numWords = 0;
	for (size_t i = 0; i < value.length(); i++)
	{
		string letter = value.substr(i, 1);
		if (letter != " ")
		{
			word = word + letter;
		}
		else
		{
			if (word.length() > 0)
			{
				wordArray[j] = word;
				export(key, word);
				word = "";
				j = j + 1;		
			}
		}
	}
	numWords = j;
}

void Map::export(string key, string value)
{
	buffer = buffer + ":" + value;
	// To be continued
}

string Map::getBuffer()
{
	return buffer;
}
int Map::getBufferSize()
{
	return buffersize;
}
void Map::setBuffer(string _buffer)
{
	buffer = _buffer;
}

void Map::setBufferSize(int _buffersize)
{
	buffersize = _buffersize;
}


// Below sample code to use in some main function for invoking file manager object.
// For the actual process of going through the file and reading 
// in individual lines, I did not feel that it should be in the
// FileManager class, since it should only be "managing files".
// So, either we create a separate class for parsing, or maybe we implement
// it in the Workflow class?

//FileManager fm;
//fstream file = fm.readFile("test.txt");
//
//string input;
//while (file >> input) {
//	cout << input << endl;
//}

// Or use getline()