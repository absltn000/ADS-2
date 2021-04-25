// Copyright 2021 NNTU-CS

int countPairs1(int* arr, int len, int value) {
    int s = 0;
    for (int i = 0; i < len - 1; i++) {
        for (int j = i + 1; j < len; j++) {
            if (arr[i] + arr[j] == value) {
                s++;
            }
        }
    }
    return s;
}

int countPairs2(int* arr, int len, int value) {
    int s = 0;
    int s2 = 0;
    int k = 0;
    int i = 0, j = len - 1;
    while (i != j)
        if ((i != 0) && (arr[i] == arr[i - 1])) {
            s += s2;
            i++;
        }
        else if (arr[i] == arr[j]) {
            s += ((j - i) * (j - i + 1) / 2);
            break;
        }
        else if (arr[i] + arr[j] == value) {
            while (arr[i] + arr[j] == value) {
                j--;
                k++;
            }
            j++;
            s += k;
            s2 = k;
            k = 0;
            i++;
        }
        else if (arr[i] + arr[j] > value)
            j--;
        else
            i++;
    return s;
}

int countPairs3(int* arr, int len, int value) {
    int s = 0;
    for (int h = 0; h < len - 1; h++) {
        int i = h + 1;
        int j = len - 1;
        int index = -1;
        while (i <= j) {
            if (arr[i + (j - i + 1) / 2] + arr[h] == value) {
                index = i + (j - i + 1) / 2;
                break;
            }
            else {
                if (arr[i + (j - i + 1) / 2] + arr[h] < value)
                    i = i + (j - i + 1) / 2 + 1;
                else
                    j = i + (j - i + 1) / 2 - 1;
            }
        }
        bool error = true;
        if (index != -1) {
            for (int v = h + 1; v < len; v++) {
                if (arr[index] == arr[v]) {
                    s++;
                    error = false;
                }
                else if (!error) {
                    break;
                }
            }
        }
    }
    return s;
}
