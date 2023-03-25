#include<stdio.h>
#include <stdlib.h>
#include<time.h>
#include<limits.h>


#define CLOCKS_PER_MS (CLOCKS_PER_SEC/1000)

void insertionSort(unsigned long int (*sortedArr)[6], int N);
void bubbleSort(unsigned long int (*sortedArr)[6], int N);
void selectionSort(unsigned long int (*sortedArr)[6], int N);

int main(){
	
	int N;							//Number of Integers
	N=10000;
	int r, i, j;
	clock_t start, end;
	double cpu_time_used;
	unsigned long int sortedArr[N][6];
	unsigned long int max = ULONG_MAX;
	unsigned long int unsortedArr[N];          
	double runningTime[6];
	FILE* output;
	
											//generating an unsorted array

	//As of 3/15/2023, the maximum input is 500,000 without the use of static
	//unsigned long static int v[1000000] should be used for 1 million integers
	
	srand(time(0));
	for(i=0; i<N; i++){
		unsortedArr[i] = (rand()% max + 1);
	}
	
										//copying unsorted array to the 2D array to be used by the 6 sorting algorithms
	for(i=0; i<N; i++){
		for(j=0; j<6; j++){
			sortedArr[i][j] = unsortedArr[i];
		}
	}
	
	output = fopen("out.txt", "w");
	fprintf(output, "Unsorted array using random generated values\n\n");
	for(i=1; i<N+1; i++){
		fprintf(output, "%d ", unsortedArr[i-1]);
		if(i%50==0){
			fprintf(output, "\n");
		}
	} 
	
	for(i=0; i<6; i++){
		switch(i){
			case 0: fprintf(output,"\n\nSorted array using Insertion Sort Algorithm\n\n");
					start = clock();
					insertionSort(sortedArr, N);
					end = clock();
					for(j=1; j<N+1; j++){
						fprintf(output, "%d ", sortedArr[j-1][0]);
						if(j%50==0){
							fprintf(output, "\n");
						}
					}
					break;
					
			case 1: fprintf(output,"\n\nSorted array using Bubble Sort Algorithm\n\n");
					start = clock();
					bubbleSort(sortedArr, N);
					end = clock();
					for(j=1; j<N+1; j++){
						fprintf(output, "%d ", sortedArr[j-1][1]);
						if(j%50==0){
							fprintf(output, "\n");
						}
					}
					break;
			
			case 2: fprintf(output,"\n\nSorted array using Selection Sort Algorithm\n\n");
					start = clock();
					selectionSort(sortedArr, N);
					end = clock();
					for(j=1; j<N+1; j++){
						fprintf(output, "%d ", sortedArr[j-1][2]);
						if(j%50==0){
							fprintf(output, "\n");
						}
					}
					break;
		}
		cpu_time_used = ((double) (end - start))/ CLOCKS_PER_SEC; 
		runningTime[i] = cpu_time_used;
		printf("\n\n||The running time is %.10f", cpu_time_used);

		
	}
	

	return 0;
	
}


void generateSorted(){
	
}

void insertionSort(unsigned long int (*sortedArr)[6], int N){
	
	int i, key, initial, count=0;
    for(i=1; i<N; i++)
    {
        initial = sortedArr[i][0];
        key = i-1;
        while (key >=0 && sortedArr[key][0] >  initial)
        {
            sortedArr[key+1][0] = sortedArr[key][0];
            key = key - 1;
        }
        sortedArr[key+1][0] = initial;
    }
    
	
}

void bubbleSort(unsigned long int (*sortedArr)[6], int N){
	
	int i, n, temp;
	
	for (i = 0; i<N; i++)
    {
        for (n = 0; n < N - 1; n++)
        {
            if  (sortedArr[n][1] >  sortedArr[n+1][1])
            {
                temp = sortedArr[n][1];
                sortedArr[n][1] = sortedArr[n+1][1];
                sortedArr[n+1][1] = temp;
            }
        }
    }
	
}

void selectionSort(unsigned long int (*sortedArr)[6], int N){
	
	int i, position, swap, length;
	for (i = 0; i<N-1; i++)
    {
        position = i;
        for (length = i+1; length<N; length++)
        {
        	
            if (sortedArr[position][2] > sortedArr[length][2])
            {
                position = length;
            }
        }
        if (position != i)
        {
            swap = sortedArr[i][2];
            sortedArr[i][2] = sortedArr[position][2];
            sortedArr[position][2] = swap;
        }   
    }
	
}

void mergeSort(){
	
}

void heapSort(){
	
}

void quickSort(unsigned long int (*sortedArr)[6], int low, int high, int index){
    if (low < high) {
        int pivotIndex = partition(sortedArr, low, high, index);
        quickSort(sortedArr, low, pivotIndex - 1, index);
        quickSort(sortedArr, pivotIndex + 1, high, index);
    }
}

int partition(unsigned long int (*sortedArr)[6], int low, int high, int index) {
    unsigned long int pivot = sortedArr[high][index];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (sortedArr[j][index] < pivot) {
            i++;
            swap(&sortedArr[i][index], &sortedArr[j][index]);
        }
    }
    swap(&sortedArr[i + 1][index], &sortedArr[high][index]);
    return i + 1;
}

void swap(unsigned long int* a, unsigned long int* b) {
    unsigned long int temp = *a;
    *a = *b;
    *b = temp;
}
