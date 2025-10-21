#include <stdio.h>
int removeDuplicates(int* nums, int numsSize) {
    if (numsSize == 0) return 0;
    int k = 0;
    for (int i = 1; i < numsSize; i++) {
        if (nums[i] != nums[k]) {
            k++;
            nums[k] = nums[i];
        }
    }
    return k + 1;
}
int main() {
    int nums[] = {0,0,1,1,1,2,2,3,3,4};
    int n = sizeof(nums) / sizeof(nums[0]);

    int k = removeDuplicates(nums, n);
    printf("Unique count: %d\n", k);
    printf("Array after removing duplicates: ");
    for (int i = 0; i < k; i++) {
        printf("%d ", nums[i]);
    }
    printf("\n");
    return 0;
}