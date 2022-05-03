# Project1

To run the code for this project:

1. Clone the repository to your computer via ``git clone [repo link]``.
2. Currently the `intermediatefile.txt` (in `Intermediate_files` folder) and `outfile.txt` (in `Output_files` folder) have data/text in them for the purpose of showing the results of the test. However, when you run the code on a new text file, be sure to clear out the contents of the text files, just in case.
3. When you load in your own input text file into the `Input_files` folder, be sure to change to name it `infile.txt`. Name the existing file to a different name, such as `infile-old.txt` to avoid conflicts.
4. Navigate to the Project1 folder inside of the outside Project1 folder (where all the .cpp and .h files are) in your command line or terminal.
5. Type the command ``g++ Executive.cpp WorkFlow.cpp FileManager.cpp Reduce.cpp Map.cpp -o Executive`` to compile and create the executable file. (Of course make sure that you have g++ compiler installed already.)
7. Once the executable is created, run it with the command ``Executive.exe Input_files Output_files Intermediate_files``, where the three arguments are the input, output and intermediate directories.
8. When running, you will see a message on the black terminal window indicating the program is running. When the program is finished, a `SUCCESS.txt` file will be created in the `Output_files` folder, the sorted and aggregated results from the Reduce class will be in the `outfile.txt` file, and the intermediary data will be in the `intermediatefile.txt` file.
