#include <iostream>
#include <string>
#include <sstream>
#include <vector>


int main()
{
	using namespace std;

	// Get user input
	cout << "Enter a word or phrase to be reversed: ";
	string strBuf;
	getline(cin, strBuf);

	int numChars = strBuf.size();

	// Put the data into a stringstream
	istringstream ssBuf;
	ssBuf.str(strBuf);

	// Push back each character into our stack
	vector<char> vecBuf;
	for (int count = 0; count < numChars; ++count)
		vecBuf.push_back(ssBuf.get());

	// Print the reversed string
	for (int count = 0; count < numChars; ++count)
	{
		cout << vecBuf.back();
        vecBuf.pop_back();
	}
    cout << "\n";

	return 0;
}
