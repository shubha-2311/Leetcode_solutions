#include <stdio.h>
#include <string.h>

int numberOfBeams(char** bank, int bankSize) {
    int total = 0, previous = 0;
    char *row;
    for (int i = 0; i < bankSize; i++) {
        row = *(bank + i);
        int device = 0;
        for (int j = 0; row[j] != '\0'; j++)
            if (row[j] == '1')
                device += 1;
        if (device > 0) {
            total += device * previous;
            previous = device;
        }
    }
    return total;
}

int main() {
    char *bank[] = {"011001", "000000", "010100", "001000"};
    int bankSize = 4;

    int result = numberOfBeams(bank, bankSize);
    printf("Total Laser Beams: %d\n", result); // Output: 8

    return 0;
}
