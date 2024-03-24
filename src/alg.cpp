// Copyright 2021 NNTU-CS
int countPairs1(int *arr, int len, int value) {
    int c = 0;
    int i = 0;
    while (i < len) {
        int j = i + 1;
        while (j < len) {
            if ((arr[i] + arr[j]) == value) {
                c++;
            }
            j++;
        }
        i++;
    }
    return c;
}
int countPairs2(int *arr, int len, int value) {
    int c = 0;
    int r = len - 1;
    do {
        r = r - 1;
    } while (arr[r] > value);
    int i = 0;
    while (i < r) {
        int j = r;
        while (j > i) {
            if (arr[j] + arr[i] == value) {
                c++;
            }
            j--;
        }
        i++;
    }
    return c;
}

int binsearch(int *arr, int size, int value) {
    int count = 0;
    int l = 0;
    int r = size - 1;
    while (l <= r) {
        int mid = l + r / 2;
        if (arr[mid] == value) {
            count++;
            int i = mid + 1;
            while (i < size && arr[i] == value) {
                count++;
                i++;
            }
            i = mid - 1;
            while (i >= 0 && arr[i] == value) {
                count++;
                i--;
            }
            return count;
        } else if (arr[mid] < value) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    return 0;
}

int countPairs3(int *arr, int len, int value) {
    int c = 0;
    int i = 0;
    while (i < len) {
        int num = value - arr[i];
        c = c + binsearch(&arr[i + 1], len - i - 1, num);
        i++;
    }
    return c;
}
