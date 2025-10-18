#include <stdio.h>
#include <stdlib.h>

// Comparison function for qsort
int comp(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

// Function to find maximum distinct elements after modification
int maxDistinctElements(int* nums, int numsSize, int k) {
    // Sort the array
    qsort(nums, numsSize, sizeof(nums[0]), comp);

    int min = nums[0] - k; // Lowest possible starting value
    int count = 1;         // At least one distinct number

    for (int i = 1; i < numsSize; i++) {
        // If current range allows new distinct value
        if (min < nums[i] + k) {
            count++;
            // Move min to next valid position
            if (min < nums[i] - k) {
                min = nums[i] - k;
            } else {
                min++;
            }
        }
    }

    return count;
}

// Driver code to test
int main() {
    int nums[] = {1, 2, 2, 3, 3, 4};
    int k = 2;
    int n = sizeof(nums) / sizeof(nums[0]);

    int result = maxDistinctElements(nums, n, k);
    printf("Maximum distinct elements: %d\n", result);

    return 0;
}
