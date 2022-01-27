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
	 
	fstream output_file;
	output_file.open("cout.txt", ios::out);
	fstream input_file;
	input_file.open("cin.txt", ios::in);

	// backup existing stream buffers 
	streambuf* cin_old_streambuf = cin.rdbuf();
	streambuf* cout_old_streambuf = cout.rdbuf();

	// Get output stream buffer of file and redirect to cout
	streambuf* output_file_streambuf = output_file.rdbuf();
	cout.rdbuf(output_file_streambuf);

	// Get input stream buffer of file and redirect to cin
	streambuf* input_file_streambuf = input_file.rdbuf();
	cin.rdbuf(input_file_streambuf);


	/* What ever you do with cin and cout will write to file. */
	/* Scenario 1: using getline to read data from input stream */
	string line;
	getline(cin, line); // Note: getline will read \n but it won't print/write to string or terminal.
	cout << line;
	getline(cin, line);
	cout << line;
	getline(cin, line);
	cout << line;
	getline(cin, line);
	cout << line;
	/* Scenario 1 output of cout file looks like below with above code
	   My name is raviMy age is 45
	*/

	/*
	 Scenario 2: using cin to read data from input stream
	*/
	/*
	string line;
	cin >> line;
	cout << line;
	cin >> line;
	cout << line;
	cin >> line;
	cout << line;

	cout << line;
	cin >> line;
	cout << line;
	cin >> line;
	cout << line;
	*/
	/*
		Scenario 2: output of cout file looks like below with above code
					MynameisisraviMy
	*/

	// Redirect cin and cout to default.
	cout.rdbuf(cout_old_streambuf);
	cin.rdbuf(cin_old_streambuf);
	cout << "printing output console " << endl;

	output_file.close();
}