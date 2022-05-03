#include "Executive.h"

using namespace std;

int main(int argc, char* argv[])
{
	// command line arguments are pre-set in Visual Studio
	if (argc < 3)
	{
		cout << " Three arguments are expected. Exiting..." << endl;
		return 0;
	}

	cout << "MapReduce program is currently running to aggragate all occurrences of each word in the text file provided. Please wait a moment." << endl;

	WorkFlow wf("test");
	wf.run(argv[0], argv[1], argv[2], argv[3]);

}