#include<stdio.h>

int maxIncreasingSubarrays(int* nums, int numsSize) {
    int k=0,prevLen=0,len=1;
    for(int i=1;i<numsSize;i++){
        if(nums[i]>nums[i-1]) len++;
        else{
            prevLen=len;
            len=1;
        }
        int halfLen = len/2;
        int min = len<prevLen?len:prevLen;  //min between len and Previous_len
        int currentseq = min>halfLen?min:halfLen;
        if(k<currentseq) k=currentseq;
    }
    return k;
}

int main(){
    int n,k;
    printf("\nEnter value for n: ");
    scanf("%d",&n);
    printf("\nEnter the values of the array: ");
    int arr[n];
    for(int i=0;i<n;i++)
        scanf("%d",&arr[i]);
    k=maxIncreasingSubarrays(arr,n);
    printf("%d",k);
    return 0;
}