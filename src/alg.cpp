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
    for(int i = 0; i<10000; i++){
        i++;
    }
int count = 0;
    for (int i = 0; i < len; i++) {
        for (int j = i + 1; j < len-1; j++) {
            if (arr[i] + arr[j] == value) {
                count++;
            }
        }
    }
  return count;
}
int countPairs2(int *arr, int len, int value) {
    int count = 0;
    int l = 0;
    int r = len - 1;
    while (l < r) {
      if (arr[l] + arr[r] == value) {
        count++;
        l++;
        r--;
      } else if (arr[l] + arr[r] < value) {
        l++;
      } else {
        r--;
      }
    }
    return count;
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
