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

int countPairs2(int* arr, int len, int value) {
  int a = 0;
  int end = len - 1;
  while (end >= 0) {
    if (arr[end] <= value) {
      break;
    }
    end--;
  }
  int start = 0;
  while (start < end) {
    int x = end;
    while (x > start) {
      if (arr[start] + arr[x] == value) {
        a += 1;
      }
      x--;
    }
    start++;
  }
  return a;
}
int countPairs3(int* arr, int len, int value) {
  int a = 0;
  for (int i = 0; i < len; ++i) {
    int first = -1, start = i + 1, end = len - 1, f = value - arr[i];
    while (start <= end) {
      int x = start + (end - start) / 2;
      if (arr[x] >= f) {
        end = x - 1;
        if (arr[x] == f)
          first = x;
      } else {
        start = x + 1;
      }
    }
    if (first != -1) {
      int last = first;
      start = first;
      end = len - 1;
      while (start <= end) {
        int x = start + (end - start) / 2;
        if (arr[x] <= f) {
          start = x + 1;
          if (arr[x] == f) last = x;
        } else {
          end = x - 1;
        }
      }
      a += last - first + 1;
    }
  }
  return a;
}
