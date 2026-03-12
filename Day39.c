#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int num;
    int freq;
} Pair;

int* topKFrequent(int* nums, int numsSize, int k, int* returnSize) {

    Pair *map = (Pair*)malloc(numsSize * sizeof(Pair));
    int mapSize = 0;

    // Count frequencies
    for(int i = 0; i < numsSize; i++){
        int found = 0;

        for(int j = 0; j < mapSize; j++){
            if(map[j].num == nums[i]){
                map[j].freq++;
                found = 1;
                break;
            }
        }

        if(!found){
            map[mapSize].num = nums[i];
            map[mapSize].freq = 1;
            mapSize++;
        }
    }

    // Create buckets
    int **bucket = (int**)calloc(numsSize + 1, sizeof(int*));
    int *bucketSize = (int*)calloc(numsSize + 1, sizeof(int));

    for(int i = 0; i < mapSize; i++){
        int f = map[i].freq;

        bucket[f] = realloc(bucket[f], (bucketSize[f] + 1) * sizeof(int));
        bucket[f][bucketSize[f]++] = map[i].num;
    }

    int *result = (int*)malloc(k * sizeof(int));
    int count = 0;

    for(int i = numsSize; i >= 0 && count < k; i--){
        for(int j = 0; j < bucketSize[i] && count < k; j++){
            result[count++] = bucket[i][j];
        }
    }

    *returnSize = k;
    return result;
}