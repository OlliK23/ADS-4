// Copyright 2021 NNTU-CS
#include <unistd.h>
int binfound(int* arr, int left, int right, int val) {
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == val) {
            return mid;
        }else if (arr[mid] < val) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    return -1;
}
int countPairs1(int* arr, int len, int value) {
    sleep(10);
    int count = 0;
    for (int i = 0; i < len; i++) {
        for (int j = i + 1; j < len - 1; j++) {
            if (arr[i] + arr[j] == value) {
                count++;
            }
        }
    }
    return count;
}
int countPairs2(int* arr, int len, int value) {
int count = 0;
    int left = 0;
    int right = len - 1;
    while (arr[right] > value) {
        right--;
    }
    for (int i = 0; i < right; i++) {
        for (int j = right; j > i; j--) {
            if (arr[i] + arr[j] == value) {
                count++;
            }
        }
  }
  return count;
}

int countPairs3(int* arr, int len, int value) {
    int count = 0;
    for (int i = 0; i < len; i++) {
        int index = binfound(arr, i + 1, len - 1, value - arr[i]);
        if (index >= 0) {
            count++;
        }
    }
    return count;
}
