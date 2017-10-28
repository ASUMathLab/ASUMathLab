#include <iostream>
#include <algorithm>
#include<fstream>
#include<string>
#include "CMatrix.h"
#include "stdarg.h"
#include <map>
#include "stdio.h"

using namespace std;

string input;
char key;

//Create Map ( Key-Value pairs)
map<char, CMatrix> Matrix;
//Ex: Matrix ['A'] = CMatrix A

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


//Addition, Subtraction, Multiplication for 2 or more than 2 Matrices
CMatrix Calculate(string& input, CMatrix& temp)
{


	if (input[3] == '+')
	{
		temp = temp + Matrix[input[4]];
		input.erase(3, 2);
		if (input.length() > 4) // Check If More Operations Left
			Calculate(input, temp); // Coninue Calculating Next Term
	}
	else if (input[3] == '-')
	{
		temp = temp - Matrix[input[4]];
		input.erase(3, 2);
		if (input.length() > 4)
			Calculate(input, temp);
	}
	else if (input[3] == '*')
	{
		temp = temp * Matrix[input[4]];
		input.erase(3, 2);
		if (input.length() > 4)
			Calculate(input, temp);
	}
	return temp;
}

void main() {




	while (1)
	{
		getline(cin, input);

		if (input.empty())
			continue;

		if (input.length() == 1) //Print One Matrix 
		{
			key = input[0];
			cout << Matrix[key] << endl; //Print Matrix of given Input, Example of Input : A
		}
		else
		{
			if (input.find("[") != string::npos) //Store Matrix of given Input, Example of Input :  A = [8.9 7.3 4.8 2.4; 2.3 6.5 8.9 1.2; 4.9 3.8 7.2 7.5; 9.8 3.4 7.5 8.9]
			{

				int bracketOccurence = input.find("[");

				CMatrix temp(input.substr(bracketOccurence, input.length()));

				key = input[0];
				Matrix[key] = temp;

				//in case of more than one '=' , Example of Input : a = A = [8.9 7.3 4.8 2.4; 2.3 6.5 8.9 1.2; 4.9 3.8 7.2 7.5; 9.8 3.4 7.5 8.9]

				deleteWhiteSpaces(input);

				for (int i = 0; i < bracketOccurence; i++) {
					if (input[i] == '=')
					{
						key = input[i - 1];
						Matrix[key] = temp;
					}
				}

				cout << Matrix[key];

			}
			else if (input.length() > 2) //Operations , Condition is for errors only.
			{
				deleteWhiteSpaces(input);

				CMatrix temp = Matrix[input[2]];
				key = input[0];
				//Calculate 2 or more matrices
				Calculate(input, temp);
				Matrix[key] = temp;
				cout << Matrix[key];




				//without recursion function only 2 matrices..
				/*if (input.find("+") != string::npos)
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
				}*/
			}
			else
				continue;


		}


	}

}