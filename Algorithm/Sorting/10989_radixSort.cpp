#include <stdio.h>
int main(void){
  int n;
  int arr[10001] ={0,};
  
  scanf("%d", &n);
  for(int i=0;i<n;i++){
    int tmp;
    scanf("%d",&tmp);
    arr[tmp]++;
  }
  for (int i=0;i<10001;i++){
    if(arr[i]!= 0){
      for(int j=0;j<arr[i];j++){
        printf("%d\n", i);
      }
    }
  }
}
