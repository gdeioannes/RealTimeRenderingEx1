//============================================================================
// Name        : ExTestCases.cpp
// Author      : Gabriel De Ioannes
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int main() {

	string text="0000";
	for(int a=0; a<4;a++){
		for(int b=0; b<4;b++){
			string text="0000";
			text[a]='1';
			text[b]='1';
			cout << text << "\n";
		}
	}

	return 0;
}
