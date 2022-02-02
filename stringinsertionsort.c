#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define CHARACTERS 100


void readArray(char *arr[], int num){
        char temp[CHARACTERS];
        int i, length;

        for(i=0; i<num; i++){
                printf("Enter string %d of array: ", (i+1));
                scanf("%s", temp);
                length = strlen(temp);

                arr[i] = (char*)malloc(sizeof(char)*length);

                strcpy(arr[i], temp);
        }
}

//Display Array function
void displayArray(char *arr[], int num){
        int i;
        for(i=0; i<num; i++){
                printf("%s\n", arr[i]);
        }
}

//Logic for insertion sort
void insertionSort(char *arr[], int num){
        int i, k;
        char temp[CHARACTERS];
        for(i=1; i<num; i++)
        {
              k = i;
              while(k > 0 && strcmp(arr[k], arr[k-1]) < 0)
              {
                  strcpy(temp, arr[k]);
                  strcpy(arr[k], arr[k-1]);
                  strcpy(arr[k-1], temp);
                  k--;
              }
        }
}


/* main method */
int main(int args, char** argv){
        int num, i;
        printf("Enter number of elements in array: ");
        scanf("%d", &num);
        char** arr = (char**)malloc(sizeof(char*) * num);

        readArray(arr, num);

        printf("\nBefore sorT:\n");

        displayArray(arr,num);

        insertionSort(arr,num);

        printf("\nAfter sorting:\n");

        displayArray(arr,num);

        for(i=0; i<num; i++){
          free(arr[i]);
        }
        free(arr);

        return 0;
}
