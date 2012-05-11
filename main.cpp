#include <Windows.h>
#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <iterator>
#include <vector>

using namespace std;

void main(int argc, char* argv[]) {
	if(!(argc==2)) {//Check for one arg.
		printf("Incorrect use of command.");
		return;
	}

	FILE *list = fopen(argv[1], "r"); //Create file out of listed path.

	if(list == NULL) { //If file does not exist, return.
		printf("File does not exist.");
		return;
	}
	
	string fileS;
	char c;
	while((c=fgetc(list)) != EOF) {
		fileS += c;
	}

	vector<string> urls;

	istringstream iss(fileS);
	copy(istream_iterator<string>(iss),
         istream_iterator<string>(),
         back_inserter<vector<string> >(urls));

	for(int a = 0; a < urls.size(); a++) {
		cout << "Opening '" << urls[a] << "' in browser...\n";
		const char* tempURL = urls[a].c_str();
		ShellExecuteA(NULL, "open", tempURL, NULL,  NULL, SW_SHOWNORMAL);
	}

	return;

}