#include <stdio.h>

#define MAX 1000

int maxLen(int arr[], int n) {
    int sum = 0, maxLen = 0;

    int hash[2 * MAX + 1];
    
    for (int i = 0; i < 2 * MAX + 1; i++) {
        hash[i] = -2;
    }

    int offset = MAX;

    for (int i = 0; i < n; i++) {
        sum += arr[i];

        if (sum == 0) {
            maxLen = i + 1;
        }

        if (hash[sum + offset] != -2) {
            int prevIndex = hash[sum + offset];
            if (i - prevIndex > maxLen) {
                maxLen = i - prevIndex;
            }
        } else {
            hash[sum + offset] = i;
        }
    }

    return maxLen;
}

int main() {
    int arr[] = {15, -2, 2, -8, 1, 7, 10, 23};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("%d\n", maxLen(arr, n)); 

    return 0;
}