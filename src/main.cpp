#include "CMatrix.cpp"
#include "CMatrix.h"
#include <iostream>
#include<string>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char** argv){
	// cout<<"Program Name:\n"<<argv[0]<<endl;
  //       string * operation = new string[9];
	// if(argc > 1){
	// 	cout<<"Number of arguments: "<<argc - 1<<endl;
	// 	ifstream infile(argv[1]);
	// 	string a;
	// 	if(!infile.bad()) {
	// 		cout << atof(" 4.9") + 1 << endl;
	// 		infile.close();
  //
  //
	// 	} else {
	// 			cout << "aw3a yad" << endl;
	// 		}
  //
	// 	cout << operation[0] << endl;


		// Test Case


		CMatrix k("[1.2 5.7 4.2 1.4; 6.3 2.5 8.1 3.1; 6.4 2.8 7.1 8.1; 3.2 5.1 7.2 6.2]");

		cout << k << endl;

	// } else {
	// // Abied or Ezzat
  //   		cout << "File has Error" << endl;
	// }
	return 0;
}
