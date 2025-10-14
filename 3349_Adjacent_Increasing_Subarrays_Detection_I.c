#include<stdio.h>


int hasIncreasingSubarrays(int* nums, int numsSize, int k) {
    int prev=0,start=0;
    for(int i=1;i<=numsSize;i++){
        if(i==numsSize || nums[i]<=nums[i-1]){
            int len=i-start;
            if(prev>=k && len >=k || len>=2*k) return 1;
            prev=len;
            start=i;
        }
    }
    return 0;
}

int main(){
    int n,k;
    printf("\nEnter value for n and k: ");
    scanf("%d %d",&n,&k);
    printf("\nEnter the values of the array: ");
    int arr[n];
    for(int i=0;i<n;i++)
        scanf("%d",&arr[i]);
    for(int i=0;i<n;i++)
        printf("%d ",arr[i]);
    int res=hasIncreasingSubarrays(arr,n,k);
    if(res==1) printf("True");
    else printf("False");
    return 0;
}