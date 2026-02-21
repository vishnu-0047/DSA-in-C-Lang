#include<stdio.h>


void swap(char *a,char *b) {
    char temp=*a; //here, we use pointer to directly change the value
    *a=*b;      // not only inside the function
    *b=temp;
}
int partition(char arr[],int low,int high) {
    char pivot=arr[low];
    int start=low;
    int end=high;
    while (start<end) {
        while (arr[start]<=pivot && start<high) {
            start++; //start< high used to prevent accessing
                    // out of bounds.
        }
        while (arr[end]>pivot) {
            end--;
        }
        if (start<end) {
            swap(&arr[start],&arr[end]);
        }
    }
    swap(&arr[end],&arr[low]);
    return end; // the array is divided with respect to this value only
}
void quickSort(char arr[], int low, int high) {
    if (low<high) {
        int loc=partition(arr,low,high);
        quickSort(arr,low,loc-1);
        quickSort(arr,loc+1,high);
    }
}
int main() {
    char arr[6];
    int length=sizeof(arr)/sizeof(arr[0]);
    //srand(time(0)); //new random number every time
    printf("Enter charcter element values:");
    for(int i=0;i<length;i++) {
        scanf(" %c",&arr[i]); // random numbers maxrange is 100
    }
        printf("-----QUICK SORT-----\n");
    printf("Array before sorting:\n");
    for (int i=0;i<length;i++) printf("%c ",arr[i]);
    quickSort(arr,0,length-1);
    printf("\nArray after sorting:\n");
    for(int i=0;i<length;i++) {
        printf("%c ",arr[i]);
    }
}
