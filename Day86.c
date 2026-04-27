#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int low = 0, high = n;
    int ans = 0;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if ((long long)mid * mid == n) {
            ans = mid;
            break;
        }
        else if ((long long)mid * mid < n) {
            ans = mid;        // store possible answer
            low = mid + 1;    // go right
        }
        else {
            high = mid - 1;   // go left
        }
    }

    printf("%d", ans);
    return 0;
}