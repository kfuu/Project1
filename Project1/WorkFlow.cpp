#include "WorkFlow.h"
#include "FileManager.h"

void WorkFlow::run(string a1, string a2, string a3, string a4) { // a1 = argv0, a2 = argv1, etc.
	// File paths and file name set up & initialization
	string totalDirectory = a1;
	string currentDirectory = "";

	string inputDirectory = currentDirectory + a2;
	string outputDirectory = currentDirectory + a3;
	string intermediateDirectory = currentDirectory + a4;

	string infile = "infile.txt";
	string outfile = "outfile.txt";
	string intermediatefile = "intermediatefile.txt";

	// Running map
	Map mapobj(inputDirectory, outputDirectory, intermediateDirectory, infile, outfile, intermediatefile);

	FileManager fm(inputDirectory, infile, 'r');
	fm.openfileforreading();
	fm.readFile();

	vector<string> fileContent = fm.fileContent;
	for (string s : fileContent) {
		mapobj.map(intermediatefile, s);
	}

	// Running reduce
	Reduce reducer(intermediateDirectory, intermediatefile, outputDirectory, outfile);
	reducer.collectData();
	reducer.sort();
	reducer.parse_each();
}