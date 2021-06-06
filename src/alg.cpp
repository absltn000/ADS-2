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
  int i = 0;
  int j = len - 1;
  int middle;
  while (i < j) {
    middle = (i + j) / 2;
    if (arr[middle] <= value)
      i = middle + 1;
    else
      j = middle;
  }
  while (j > 0) {
    while (i < j) {
      if (arr[i] + arr[j] == value) {
        s++;
      }
      ++i;
    }
    i = 0;
    j--;
  }
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
      } else {
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
        } else if (!error) {
          break;
        }
      }
    }
  }
  return s;
}
