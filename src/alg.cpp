// Copyright 2021 NNTU-CS
int binfound(int *arr, int l, int r, int val) {
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (arr[mid] == val) {
            return mid;
        } else if (arr[mid] < val) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    return -1;
}
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
  for (int i = 0; i < len; i++) {
    int index = binfound(arr, i + 1, len - 1, value - arr[i]);
    if (index >= 0) {
      count++;
    }
  }
  return count;
}
