#include<stdio.h>
/*int minNumberOperations(int* target, int targetSize) {
    int initial[targetSize];
    for(int i=0;i<targetSize;i++){
        initial[i]=0;
    }
    int count=0;
    for(int i=0;i<targetSize;i++){
        while(target[i]>initial[i]){
            for(int j=i;j<targetSize;j++){
                if(target[j]>initial[j]){
                    initial[j]++;
                }else{
                    break;
                }
            }
            count++;
        }
    }
    return count;
}*/

int minNumberOperations(int* target, int targetSize) {
    int count=target[0];
    for(int i=1;i<targetSize;i++){
        if(target[i]>target[i-1])
            count+=target[i]-target[i-1]; // without if statement it will do same on count+=max(target[i]-target[i-1],0)...
    }
    return count;
}

int main(){
    int n;
    printf("\nEnter the length of the array: ");
    scanf("%d",&n);
    int array[n];
    printf("\nEnter the elements of the array: ");
    for(int i=0;i<n;i++){
        scanf("%d",&array[i]);
    }
    printf("\nThe output is :%d",minNumberOperations(array,n));
    return 0;
}