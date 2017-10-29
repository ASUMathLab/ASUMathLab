#include "CMatrix.cpp"
#include "CMatrix.h"
#include <iostream>
#include<string>

int main(int argc, char** argv){
	cout<<"Program Name:\n"<<argv[0]<<endl;
	if(argc > 1){
		cout<<"Number of arguments: "<<argc - 1<<endl;
		int i;
		cout<<"Arguments are:\n";
		for(i = 0; i < argc; i++){
			cout<<argv[i]<<endl;
		}
	}
	return 0;
}
