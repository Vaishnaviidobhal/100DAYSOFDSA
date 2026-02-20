#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int count = 0;
    int sum = 0;

    // assuming sum range won't exceed this (for simplicity)
    int freq[20001] = {0};  
    int offset = 10000; // to handle negative sums

    freq[offset] = 1; // sum = 0 initially

    for(int i = 0; i < n; i++) {
        sum += arr[i];

        if(freq[sum + offset] > 0) {
            count += freq[sum + offset];
        }

        freq[sum + offset]++;
    }

    printf("%d", count);

    return 0;
}