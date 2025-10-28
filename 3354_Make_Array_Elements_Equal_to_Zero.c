#include<stdio.h>
/*int checkAllZeros(int *a, int n){
    for(int i=0;i<n;i++){
        if(a[i]!=0) return 0;
    }
    return 1;
}

void copyArray(int *a,int *b, int n){
    for(int i=0;i<n;i++){
        b[i]=a[i];
    }  
}

int check(int* nums, int curr, int numsSize, int change){
    while(curr>=0 && curr<numsSize){
        if(nums[curr]==0){
            curr+=change;
        }else{
            nums[curr]--;
            change=(change==-1)?1:-1;
            curr+=change;
        }
    }
    int r=checkAllZeros(nums,numsSize);
    return r;
}

int countValidSelections(int* nums, int numsSize) {
    int res=0, curr=0;
    int copy[numsSize];
    while(curr<numsSize){
        if(nums[curr]==0){
            copyArray(nums,copy,numsSize);
            res+=check(copy,curr,numsSize,-1);
            copyArray(nums,copy,numsSize);
            res+=check(copy,curr,numsSize,1);
        }
        curr++;
    }
    return res;
}*/

int countValidSelections(int* nums, int numsSize) {
    int res=0, curr=0, left=0, right=0;
    for(int i=0;i<numsSize;i++){
        right+=nums[i];
    }
    while(curr<numsSize){
        if(nums[curr]==0){
            if(right==left || right-left==1)    res++;
            if(right==left || left-right==1)    res++;
        }
        right-=nums[curr];
        left+=nums[curr];
        curr++;
    }
    return res;
}

int main(){
    int array[]={1,0,2,0,3};
    // int n;
    // printf("\nEnter number of values: ");
    // scanf("%d",&n);
    // int arr[n];
    // printf("\nEnter the elements: ");
    // for(int i=0;i<n;i++){
    //     scanf("%d",&arr[i]);
    // }
    int r=countValidSelections(array,5);
    printf("\n%d",r);
    return 0;
}