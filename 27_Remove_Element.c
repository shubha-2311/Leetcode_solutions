#include<stdio.h>

int removeElement(int* nums, int numsSize, int val) {
    int i = 0;
    for (int j = 0; j < numsSize; j++) {
        if (nums[j] != val) {
            nums[i] = nums[j];
            i++;
        }
    }
    return i;
}
int main() {
    int nums[] = {0,1,2,2,3,0,4,2};
    int n = sizeof(nums) / sizeof(nums[0]);
    int val=2;

    int k = removeElement(nums, n, val);
    printf("Unique count: %d\n", k);
    printf("Array after removing duplicates: ");
    for (int i = 0; i < k; i++) {
        printf("%d ", nums[i]);
    }
    printf("\n");
    return 0;
}