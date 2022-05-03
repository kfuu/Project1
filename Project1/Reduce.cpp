#include "Reduce.h"

void Reduce::collectData() {
	//create a file manager object
	FileManager fm(inputdirectory, inputfile, 'r'); // we are reading in the intermediate file here.
	fm.openfileforreading();
	fm.readFile();

	fileData = fm.fileContent;
}

void Reduce::sort() {
	// open the output file for writing the formatted data
	FileManager fm(inputdirectory, inputfile, 'w');
	fm.openfileforwriting();

	// first, convert string data to tupled data <string, int>
	for (string t : fileData) {
		string temp = t.erase(0, 1); // erase first parens
		temp.erase(temp.size() - 1); // erase last parens

		string leftString = "";
		string rightString = "";
		bool onLeftSide = true;

		for (int i = 0; i < temp.size(); i++) {
			if (temp[i] != ',' && onLeftSide) {
				leftString += temp[i];
			}

			if (temp[i] == ',') {
				onLeftSide = false;
			}

			if (temp[i] != ',' && !(onLeftSide)) {
				rightString += temp[i];
			}
		}
		tokenList.emplace_back(leftString, rightString);
	}

	for (tuple<string, string> token : tokenList) {
		string word = get<0>(token);
		string count = get<1>(token);
		
		if (!(frequencyMap.count(word))) {
			vector<string> v;
			v.push_back(count);
			frequencyMap.insert(pair<string, vector<string>>(word, v));
		}
		else {
			frequencyMap[word].push_back(count);

		}
	}

	map<string, vector<string>>::iterator it;
	for (it = frequencyMap.begin(); it != frequencyMap.end(); it++) {
		string word = it->first;
		string listOfOnes = "[";

		for (int n = 0; n < it->second.size(); n++) {
			listOfOnes += it->second[n];
			if (n + 1 != it->second.size()) {
				listOfOnes += ", ";
			}
		}
		listOfOnes += "]";
		
		sortedString += "(" + word + ", " + listOfOnes + "), ";
	}

	fm.writetoFile(sortedString);
}


void Reduce::parse_each() {
	FileManager fm(inputdirectory, inputfile, 'r');
	fm.openfileforreading();
	fm.readFile();

	string read_string = fm.fileContent[0];
	
	string leftString = "";
	string rightString = "";
	bool onLeftSide = true;

	for (int i = 0; i < read_string.size(); i++) {
		if (read_string[i] == '(') { // skips over the left parens
			onLeftSide = true;
		}
		else if (read_string[i] == ',' && read_string[i - 1] != ')' && onLeftSide) { // case of when we're at the comma inside the tuple
			onLeftSide = false;
			i++; // skip the space after comma
		}
		else if (read_string[i] == ')') { // when we reach the closed parens
			reduce(leftString, rightString);

			// reset
			leftString = "";
			rightString = "";
			onLeftSide = true;
		}
		else if (read_string[i] != ',' && read_string[i] != ' ' && onLeftSide) { // when we're on left side of tuple and it's not a , or ' '
			leftString += read_string[i];
		}
		else if (!(onLeftSide)) { // when we're on right side of tuple (including commas and spaces)
			rightString += read_string[i];
		}
		
	}

	// If reach here, then everything was outputted successfully.
	FileManager fm2(outputdirectory, "SUCCESS.txt", 'w');
	fm2.openfileforwriting();
	fm2.writetoFile("SUCCESS");
}

void Reduce::reduce(string key, string ints) {
	int sum = 0;
	for (int i = 0; i < ints.size(); i++) {
		if (ints[i] == '1') {
			sum += 1;
		}
	}

	reduce_export(key, sum);
}

void Reduce::reduce_export(string key, int n) {
	FileManager fm(outputdirectory, outputfile, 'a');
	fm.openfileforappending();

	string result = key + ": " + to_string(n) + "\n";

	fm.appendtofile(result);
}