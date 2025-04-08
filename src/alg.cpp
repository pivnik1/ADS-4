// Copyright 2021 NNTU-CS

int countPairs1(int *arr, int len, int value) {
    int count = 0;
    for (int i = 0; i < len; i++) {
        for (int j = i + 1; j < len; j++) {
            if (arr[i] + arr[j] == value) {
                count++;
            } else if (arr[i] + arr[j] > value) {
                break;
            }
        }
    }
    return count;
}

int countPairs2(int *arr, int len, int value) {
    int count = 0;
    int left = 0;
    int right = len - 1;

    while (left < right) {
        int sum = arr[left] + arr[right];
        if (sum == value) {
            int l = arr[left], r = arr[right];
            int leftCount = 0, rightCount = 0;

            while (left < right && arr[left] == l) {
                left++;
                leftCount++;
            }
            while (right >= left && arr[right] == r) {
                right--;
                rightCount++;
            }

            if (l != r) {
                count += leftCount * rightCount;
            } else {
                count += (leftCount * (leftCount - 1)) / 2;
            }
        } else if (sum < value) {
            left++;
        } else {
            right--;
        }
    }

    return count;
}

int countPairs3(int *arr, int len, int value) {
    int count = 0;
    for (int i = 0; i < len - 1; i++) {
        int target = value - arr[i];
        int left = i + 1;
        int right = len - 1;

        int first = -1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (arr[mid] == target) {
                first = mid;
                right = mid - 1;
            } else if (arr[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        if (first == -1) continue;

        left = first;
        right = len - 1;
        int last = first;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (arr[mid] == target) {
                last = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        count += (last - first + 1);
    }
    return count;
}
