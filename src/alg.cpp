// Copyright 2021 NNTU-CS

int findPairCountBasic(int *numbers, int size, int desiredSum) {
    int pairCounter = 0;
    for (int start = 0; start < size; start++) {
        for (int next = start + 1; next < size; next++) {
            if (numbers[start] + numbers[next] == desiredSum) {
                pairCounter++;
            }
        }
    }
    return pairCounter;
}

int findPairCountOptimized(int *numbers, int size, int desiredSum) {
    int pairCounter = 0;
    int upperLimit = size - 1;

    while (upperLimit > 0 && numbers[upperLimit] > desiredSum) {
        upperLimit--;
    }

    for (int base = 0; base < size; base++) {
        for (int current = upperLimit; current > base; current--) {
            if (numbers[base] + numbers[current] == desiredSum) {
                pairCounter++;
            }
        }
    }
    return pairCounter;
}

int findPairCountBinary(int *numbers, int size, int desiredSum) {
    int pairCounter = 0;

    for (int position = 0; position < size; position++) {
        int neededValue = desiredSum - numbers[position];
        int lowerBound = position + 1;
        int upperBound = size - 1;

        while (lowerBound <= upperBound) {
            int middle = lowerBound + (upperBound - lowerBound) / 2;
            if (numbers[middle] >= neededValue) {
                upperBound = middle - 1;
            } else {
                lowerBound = middle + 1;
            }
        }
        int startIndex = lowerBound;

        lowerBound = position + 1;
        upperBound = size - 1;

        while (lowerBound <= upperBound) {
            int middle = lowerBound + (upperBound - lowerBound) / 2;
            if (numbers[middle] <= neededValue) {
                lowerBound = middle + 1;
            } else {
                upperBound = middle - 1;
            }
        }
        int endIndex = upperBound;

        if (startIndex <= endIndex) {
            pairCounter += endIndex - startIndex + 1;
        }
    }
    return pairCounter;
}
