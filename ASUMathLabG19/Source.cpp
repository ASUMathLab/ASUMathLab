#include <iostream>
#include <algorithm>
#include<fstream>
#include<string>
#include "CMatrix.h"
#include "stdarg.h"
#include <map>
#include "stdio.h"

using namespace std;

void deleteWhiteSpaces(string& input)
{
	int length = input.length();
	for (int i = 0; i < length; i++) {
		if (input[i] == ' ')
		{
			input.erase(i, 1);
			length--;
			i--;
		}
	}
}

void main() {

	string input;
	char key;

	map<char, CMatrix> Matrix;

	
	
	while (1)
	{
		getline(cin, input);

		if (input.length() == 1)
		{
			key = input[0];
			cout << Matrix[key] << endl;
		}
		else
		{
			if(input.find("[") != string::npos)
			{
			
				int bracketOccurence = input.find("[");

				CMatrix temp(input.substr(bracketOccurence, input.length()));

				key = input[0];
				Matrix [key] = temp;
				
				//in case of more than 1 ='s
				
				deleteWhiteSpaces(input);

				for (int i = 0; i < bracketOccurence; i++) {
					if (input[i] == '=')
					{
						key = input[i-1];
						Matrix[key] = temp;
					}
				}

				cout << Matrix[key];

			}
			else
			{
				deleteWhiteSpaces(input);
				if (input.find("+") != string::npos)
				{
					CMatrix temp = Matrix[input[2]] + Matrix[input[4]];
					key = input[0];
					Matrix[key] = temp;
					cout << Matrix[key];
				}
				else if ((input.find("-") != string::npos))
				{
					CMatrix temp = Matrix[input[2]] - Matrix[input[4]];
					key = input[0];
					Matrix[key] = temp;
					cout << Matrix[key];
				}
				else if ((input.find("*") != string::npos))
				{
					CMatrix temp = Matrix[input[2]] * Matrix[input[4]];
					key = input[0];
					Matrix[key] = temp;
					cout << Matrix[key];
				}
			}

			
		}

	}

}



