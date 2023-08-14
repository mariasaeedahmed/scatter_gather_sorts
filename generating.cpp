#include<iostream>
#include<fstream>
#include<math.h>
#include<cstdlib>
#include <sys/time.h>
#include <time.h>
#include <stdio.h>
using namespace std;
int main(){
	int the11= pow(2,11);
	cout<<the11;
	int *array11= new int [the11];

	int the13= pow(2,13);
	int *array13= new int [the13];

	int the15= pow(2,15);
	int *array15= new int [the15];

	int the17= pow(2,17);
	int *array17= new int [the17];

	ofstream output11("the11.txt");
	ofstream output13("the13.txt");
	ofstream output15("the15.txt");
	ofstream output17("the17.txt");
	for(int i=0; i<the11;i++){

	//idhar we need to populate it as well as write it in a file
		array11[i]=rand()%101;

		output11<<array11[i];

		if(i!=the11-1){
		output11<<" ";
		}
}

	for(int i=0; i<the13;i++){

	//idhar we need to populate it as well as write it in a file
		array13[i]=rand()%101;

		output13<<array13[i];

		if(i!=the13-1){
		output13<<" ";
		}

}
	for(int i=0; i<the15;i++){

	//idhar we need to populate it as well as write it in a file
		array15[i]=rand()%101;

		output15<<array15[i];

		if(i!=the15-1){
		output15<<" ";
		}
}


	for(int i=0; i<the17;i++){

	//idhar we need to populate it as well as write it in a file
		array17[i]=rand()%101;

		output17<<array17[i];

		if(i!=the17-1){
		output17<<" ";
		}
}
        
}
