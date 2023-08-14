#include<iostream>
#include<fstream>
#include<math.h>
#include<cstdlib>
#include <sys/time.h>
#include <time.h>
#include <stdio.h>
using namespace std;
int operation_count=0;






//////////////////////////

void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
operation_count++;
operation_count++;
operation_count++;

    int left_half[n1], right_half[n2];

    for (int i = 0; i < n1; i++){
operation_count++;
        left_half[i] = arr[left + i];
operation_count++;
}

    for (int j = 0; j < n2; j++){
operation_count++;
        right_half[j] = arr[mid + 1 + j];
operation_count++;
operation_count++;
}
    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (left_half[i] <= right_half[j]) {
            arr[k] = left_half[i];
            i++;
operation_count++;
        }
        else {
            arr[k] = right_half[j];
            j++;
operation_count++;
        }
        k++;
operation_count++;
    }

    while (i < n1) {
        arr[k] = left_half[i];
        i++;
        k++;
operation_count++;
operation_count++;
    }

    while (j < n2) {
        arr[k] = right_half[j];
        j++;
        k++;
operation_count++;
operation_count++;
    }
}

void merge_sort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
operation_count++;
operation_count++;
operation_count++;
        merge_sort(arr, left, mid);
        merge_sort(arr, mid + 1, right);
operation_count++;

        merge(arr, left, mid, right);
    }
}











//////////////////////////
 
int partition(int array[], int st, int end)
{
	int checker = 0;
     int piv_point = array[st];
    operation_count++;
    for (int i = st + 1; i <= end; i++) {
operation_count++;
        if (array[i] <= piv_point){

            checker=checker+1;
operation_count++;
}
    }
operation_count++;
    int pivind = st + checker;
    swap(array[pivind], array[st]);
    int i = st;
    int j = end;
 
    while (i < pivind && j > pivind) {
 
        while (array[i] <= piv_point) {
operation_count++;
            i++;
        }
 
        while (array[j] > piv_point) {
operation_count++;
            j--;
        }
 
        if (i < pivind && j > pivind) {
            swap(array[i], array[j]);
operation_count++;
operation_count++;
i=i+1;
j=j-1;
        }
    }
 
    return pivind;
}
 
void qsort(int array[], int st, int end)
{
 
    
    if (st >= end)
        return;
    int the_part = partition(array, st, end);
	operation_count++;
    qsort(array, st, the_part  - 1);
        operation_count++;
    qsort(array, the_part  + 1, end);
}
 
int main(int x, char **k){
	//first thing we need to do is create an array
	//abhi we need to read from the array
int *array;
int the_power;
ifstream inputff(k[1]);
//ofstream outputff(k[1]);


	cout<<k[1];
 cout<<"fff"<<k[1][4];
string file_merge;
string file_quick;
 if(k[1][4]=='1'){
cout<<"psodif";
   	the_power= pow(2,11);
	file_merge="output_quick11.txt";
	file_quick="output_merge11.txt";
        

}
else  if(k[1][4]=='3'){
   	the_power= pow(2,13);
file_merge="output_quick13.txt";
	file_quick="output_merge13.txt";


}
else  if(k[1][4]=='5'){
   	the_power= pow(2,15);
file_merge="output_quick15.txt";
	file_quick="output_merge15.txt";


}
else  if(k[1][4]=='7'){
   	the_power= pow(2,17);
file_merge="output_quick17.txt";
	file_quick="output_merge17.txt";


}

ofstream outputff(file_quick);
ofstream outmerge(file_merge);
cout<<the_power;
 array= new int [the_power];
int *array_merge= new int [the_power];
// now we populate the array
for(int i=0; i<the_power;i++){

	//idhar we need to populate it as well as write it in a file
		
		inputff>>array[i];


		
	}
for(int i=0; i<the_power;i++){

	//idhar we need to populate it as well as write it in a file
		
		array_merge[i]=array[i];


		
	}

 struct timeval start, end;

    gettimeofday( &start, NULL );
cout<<"the power"<<the_power<<"\n";


 qsort(array, 0, the_power-1);
 gettimeofday( &end, NULL );

    /* convert time to Gflop/s */
    double seconds = (end.tv_sec - start.tv_sec) +
            1.0e-6 * (end.tv_usec - start.tv_usec);
cout<<seconds;
    double Gflops = 2e-9*operation_count/seconds;
 cout<< " Performance in Gflops FOR QUICK SORT\n"<<Gflops;

for(int i=0; i<the_power;i++){

	//idhar we need to populate it as well as write it in a file
		//array[i]=rand()%101;
		outputff<<array[i];

		if(i!=the_power-1){
		outputff<<",";
		}
	}

  // ab file main store hogayee hai now we need to convert aagay
  // now we need to write the code for sorting 
  //QUICK SORT

operation_count=0;
gettimeofday( &start, NULL );

 //qsort(array, 0, the_power-1);
merge_sort(array, 0, the_power-1);
 gettimeofday( &end, NULL );

    /* convert time to Gflop/s */
   seconds = (end.tv_sec - start.tv_sec) +
            1.0e-6 * (end.tv_usec - start.tv_usec);

   Gflops = 2e-9*operation_count/seconds;
 cout<< " Performance in Gflops FOR MERGE SORT\n"<<Gflops;


for(int i=0; i<the_power;i++){

	//idhar we need to populate it as well as write it in a file
		//array[i]=rand()%101;
		outmerge<<array_merge[i];

		if(i!=the_power-1){
		outputff<<",";
		}
	}




}
