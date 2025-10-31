#include <stdio.h>
#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* getSneakyNumbers(int* nums, int numsSize, int* returnSize) {
    int *res = (int*)malloc(2 * sizeof(int));
    int temp[numsSize-2];
    int count = 0;

    // Initialize temp to track occurrences
    for (int i = 0; i < numsSize-2; i++)
        temp[i] = 2;

    // Detect duplicates
    for (int i = 0; i < numsSize; i++) {
        if (--temp[nums[i]] <= 0) {
            res[count++] = nums[i];
            if (count == 2)
                break;
        }
    }

    *returnSize = count;
    return res;
}

int main() {
    int nums[] = {7, 1, 5, 4, 3, 4, 6, 0, 9, 5, 8, 2};
    /*
    int n;
    printf("\nEnter the length of the array: ");
    scanf("%d",&n);
    int arr[n];
    printf("\nEnter the elements of the array: ");
    for(int i=0;i<n;i++){
    scanf("%d",&arr[i]);*/
    int n = sizeof(nums) / sizeof(nums[0]);
    int returnSize;
    int *ans = getSneakyNumbers(nums, n, &returnSize);

    printf("Sneaky numbers are: ");
    for (int i = 0; i < returnSize; i++)
        printf("%d ", ans[i]);
    printf("\n");

    free(ans);
    return 0;
}
