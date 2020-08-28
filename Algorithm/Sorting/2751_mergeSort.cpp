#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void mergeSort(int list[], int left, int right);
void merge(int list[], int leftStart, int leftEnd, int rightEnd);

int main(){
    int n, arr[1000001];
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    mergeSort(arr, 0, n-1);

    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
}
// 5 4 3 2 1
void mergeSort(int list[], int left, int right){
    int center = (left+right)/2;
    if(left < right){
        mergeSort(list, left, center);
        mergeSort(list, center+1, right);
        merge(list, left, center, right);
    }
}

void merge(int list[], int leftStart, int leftEnd, int rightEnd){
    int tmpList[1000001];
    int leftPos = leftStart, rightPos = leftEnd+1, tmpPos = leftStart;

    while(leftPos <= leftEnd && rightPos <= rightEnd){
        if (list[leftPos] <= list[rightPos])
            tmpList[tmpPos++] = list[leftPos++];
        else
            tmpList[tmpPos++] = list[rightPos++];
    }

    while(leftPos <= leftEnd)
        tmpList[tmpPos++] = list[leftPos++];

    while(rightPos <=rightEnd)
        tmpList[tmpPos++] = list[rightPos++];

    for(int i = leftStart; i<=rightEnd; i++) {
        list[i] = tmpList[i];
//        printf("%d ", list[i]);
    }
//    printf("\n");


}
