#include<stdio.h>

void oddEven(int arr[], int size, int odd[], int even[]) {
    int countOdd = 0, countEven = 0;
    
    for(int i = 0; i < size; i++){
        if(arr[i] % 2 == 0){
            even[countEven] = arr[i];
            countEven++;
        }else{
            odd[countOdd] = arr[i];
            countOdd++;
        }
    }
    printf("Even Numbers: ");
    for(int j = 0; j < countEven; j++) {
        if(even[j] != 0 && j < countEven) {
            printf("%d ", even[j]);
        }
    }
    printf("\n");
    
    printf("Odd Numbers: ");
    for(int k = 0; k < countOdd; k++) {
        if(odd[k] != 0 && k < countOdd) {
            printf("%d ", odd[k]);
        }
    }
    printf("\n");
}

void posSum(int arr[], int size) {
    int sum = 0;
    printf("Positive numbers and their indices are:\n");
    for(int i = 0; i < size; i++){
        if(arr[i] > 0){
            sum += arr[i];
            printf("Number: %d, Index: %d\n", arr[i], i);
        }
    }
    printf("Sum of positive numbers: %d\n", sum);
}

void negSum(int arr[], int size) {
    int sum = 0;
    printf("Negative numbers and their indices are:\n");
    for(int i = 0; i < size; i++){
        if(arr[i] < 0){
            sum += arr[i];
            printf("Number: %d, Index: %d\n", arr[i], i);
        }
    }
    printf("Sum of negative numbers: %d\n", sum);
}
int main() {
    int arr[] = {-1, 3, -6, 5, -2, 4, -7, 9, -8};
    int size = sizeof(arr)/sizeof(arr[0]);
    posSum(arr, size);
    negSum(arr, size);
    return 0;
}
