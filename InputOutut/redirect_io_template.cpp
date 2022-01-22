/*
* (c) Venkata Ravi Kumar A
* 
* Template code for C++ IO system to redirect input and output.
* 
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
	 
	fstream file;
	file.open("cout.txt", ios::out);
	string line;

	// backup existing stream buffers 
	streambuf* cin_old_streambuf = cin.rdbuf();
	streambuf* cout_old_streambuf = cout.rdbuf();

	// Get stream buffer of file and redirect to cout
	streambuf* file_streambuf = file.rdbuf();
	cout.rdbuf(file_streambuf);

	/* What ever you do with cout will write to file. */

	// Redirect cout to default console.
	cout.rdbuf(cout_old_streambuf);
	cout << "printing to default output console " << endl;

	file.close();
	return 0;
}