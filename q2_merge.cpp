#include<iostream>
#include<fstream>
#include<math.h>
#include<cstdlib>
#include <sys/time.h>
#include <time.h>
#include <stdio.h>
#include<mpi.h>
using namespace std;
int operation_count=0;


/////////////////////
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
 
/////////////////////
int main(int x, char **k){
//ifstream inputff(k[1]);
char *the_algo=k[1];//which sort to use
int size=atoi(k[2]);// what is the size of array
int the_partition= atoi(k[3]);//what is the array partition
ifstream inp(k[1]);

//////////////////////////////////
	//abhi we need to read from the array
	int *array;
	int the_power=pow(2,size);
MPI_Init(&x,&k);
int rank, nproc ;
MPI_Comm_size(MPI_COMM_WORLD,&nproc);
MPI_Comm_rank(MPI_COMM_WORLD,&rank);

	

/////////////////////////////
 struct timeval start, end;
int p=pow(2,the_partition);
int *irecvBuf= new int [p]; 
// first we need to read arrays in a file
if(rank==0){
array= new int [the_power];

for(int i=0; i<the_power;i++){
	//idhar we need to populate it as well as write it in a file
		inp>>array[i];
		//array[i]= rand()%100;		
	}

}
///////////////////////////
//now we need to scatter the array to different processor 


	//Master process prepare message
	//if (rank==0) {
MPI_Scatter(array,pow(2,the_partition),MPI_INT,irecvBuf,pow(2,the_partition),MPI_INT,0,MPI_COMM_WORLD);

    gettimeofday( &start, NULL );
// phir uss ko merge sort bhi krna paray gaa
merge_sort(irecvBuf, 0, p-1);
MPI_Barrier(MPI_COMM_WORLD);
MPI_Gather(irecvBuf,pow(2,the_partition),MPI_INT,array,pow(2,the_partition),MPI_INT,0,MPI_COMM_WORLD);
//}
if (rank==0)
{

merge_sort(array, 0, the_power-1);
gettimeofday( &end, NULL );

    /* convert time to Gflop/s */
    double seconds = (end.tv_sec - start.tv_sec) +
            1.0e-6 * (end.tv_usec - start.tv_usec);
//cout<<seconds;
    double Gflops = 2e-9*operation_count/seconds;


for(int i=0; i<the_power;i++){
	//idhar we need to populate it as well as write it in a file
		
		//cout<<array[i]<<"\n";
//cout<< " Performance in Gflops FOR MERGE SORT\n"<<Gflops;
	}
cout<< " Performance in Gflops FOR MERGE SORT\n"<<Gflops;
}
//MPI_Gather(sendBuf,pow(2,9),MPI_INT,recvBuf,pow(2,11),MPI_INT,0,MPI_COMM_WORLD);

MPI_Finalize();

}
