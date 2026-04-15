#include <stdio.h>
#include <string.h>

#define MAX 1000
#define NAME_LEN 50

int main() {
    int n;
    scanf("%d", &n);

    char names[MAX][NAME_LEN];
    int freq[MAX] = {0};
    int unique = 0;

    // Read names and count frequencies
    for (int i = 0; i < n; i++) {
        char temp[NAME_LEN];
        scanf("%s", temp);

        int found = -1;

        // Check if already exists
        for (int j = 0; j < unique; j++) {
            if (strcmp(names[j], temp) == 0) {
                found = j;
                break;
            }
        }

        if (found != -1) {
            freq[found]++;
        } else {
            strcpy(names[unique], temp);
            freq[unique] = 1;
            unique++;
        }
    }

    // Find winner
    char winner[NAME_LEN];
    int maxVotes = 0;

    for (int i = 0; i < unique; i++) {
        if (freq[i] > maxVotes) {
            maxVotes = freq[i];
            strcpy(winner, names[i]);
        } 
        else if (freq[i] == maxVotes) {
            if (strcmp(names[i], winner) < 0) {
                strcpy(winner, names[i]);
            }
        }
    }

    printf("%s %d", winner, maxVotes);

    return 0;
}