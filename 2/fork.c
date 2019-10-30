#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;
    int L[n1], R[n2];
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];
 
   
    i = 0; 
    j = 0;
    k = l; 
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {

        int m = l+(r-l)/2;
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
		merge(arr, l, m, r);
    }
}

void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int part (int arr[], int low, int high)
{
    int pivot = arr[high];   
    int i = (low - 1),j; 
 
    for ( j = low; j <= high- 1; j++)
    {
       
        if (arr[j] <= pivot)
        {
            i++;   
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        
        int pi = part(arr, low, high);
		quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void displayArray(int arr[], int size){
	for(int i = 0 ; i < size ; i++){
		printf("%d\t", arr[i]);
	}
	printf("\n");
}

int main(){

	int size, arr[20], f;
	
	system("clear");
	printf("======== Orphan and Zombie State ========\n");
	//taking array input from user
	printf("Enter size of array: ");
	scanf("%d", &size);
	printf("Array elements: ");
	for(int i = 0 ; i < size ; i++){
		scanf("%d", &arr[i]);
	}

	f = fork();

	if(f == 0){
		sleep(1);
		printf("Child process ---> Merge sort\n");
		mergeSort(arr, 0, size-1);
		printf("Sorted Array (Child) ---> ");
		displayArray(arr, size);
	}
	else{
	
		
		printf("Parent process ---> Quick sort\n");
		quickSort(arr, 0, size-1);
		printf("Sorted Array (Parent) ---> ");
		displayArray(arr, size);
	}
	system("ps -l");

	return 0;
}
