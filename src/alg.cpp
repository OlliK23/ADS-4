// Copyright 2021 NNTU-CS
int countPairs1(int *arr, int len, int value) {
    int count = 0;
    for (int i = 0; i < len-1; i++) {
        for (int j = i + 1; j < len; j++) {
            if (arr[i] + arr[j] == value) {
                count++;
            }
        }
    }
  return count;
}
int countPairs2(int *arr, int len, int value) {
    int c = 0;
    int r = len-1;
    while (arr[r] > value) {
        r--;
    }
    for (int i = 0; i < r; i++) {
        for (int j = r; j > i; j--) {
            if (arr[i] + arr[j] == value) {
                c++;
            }
        }
    }
    return c;
}

int countPairs3(int *arr, int len, int value) {
    int count = 0;
    int ind = 0;
    int l = 0;
    int r = len - 1;
  for (int i = 0; i < len; i++) {
      while (l <= r) {
        int mid = l + (r - l) / 2;
        if (arr[mid] == value) {
            ind = mid;
        } else if (arr[mid] < value) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    return -1;
    if (ind >= 0) {
      count++;
    }
  }
  return count;
}
