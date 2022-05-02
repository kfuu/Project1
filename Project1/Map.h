//#ifdef MAP_H
//#define MAP_H
#include <iostream>
#include <stdio.h>
#include "string"

using namespace std;

class Map
{
	private:
		string buffer;
		int buffersize;
	public:
		Map()
		{
			buffer = "";
			buffersize = 250;
		}
		void map(string key, string value);
		//void export(string key, string value);
		string getBuffer();
		int getBufferSize();
		void setBuffer(string);
		void setBufferSize(int);
	



};


//#endif // MAP_H