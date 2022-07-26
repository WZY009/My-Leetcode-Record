#include "arrays.h"
#include <iostream>

void printRight(int n) {
    if (n <= 0) return;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            cout << "*";
        }
        cout << endl;
    }
}

void printRight_upsideDown_rightJustified(int n) {
    if (n <= 0) return;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i; j++) {
            cout << "*";
        }
        cout << endl;
    }
}

void printArray(const char arr[], int size) {
    if (size <= 0 || size > SIZE) return;
    for (int i = 0; i < size; i++) {
        cout << arr[i];
    }
    cout << endl;
}

void printArray(const char arr[][SIZE], int rows, int cols) {
    if (rows <= 0 || rows > SIZE || cols <= 0 || cols > SIZE) return;
    for (int i = 0; i < rows; i++) {
        printArray(arr[i], cols);
    }
}

void add(char arr[], int size, int val) {
    if (size <= 0 || size > SIZE) return;
    for (int i = 0; i < size; i++) {
        int character = (int)arr[i] + val;
        if (character < MIN_PRINTABLE_ASCII) {
            arr[i] = (char)(character + ASCII_PRINTABLE_RANGE);
        }
        else if (character > MAX_PRINTABLE_ASCII) {
            arr[i] = (char)(character - ASCII_PRINTABLE_RANGE);
        }
        else {
            arr[i] = (char)character;
        }
    }
    // printArray(arr, size);
}

void add(char arr[][SIZE], int rows, int cols, int val) {
    if (rows <= 0 || rows > SIZE || cols <= 0 || cols > SIZE) return;
    for (int i = 0; i < rows; i++) {
        add(arr[i], cols, val);
    }
     // printArray(arr, rows, cols);
}

void rotateLeft(char arr[], int size) {
    if (size < 0 || size > SIZE) return;
    for (int i = 1; i < size; i++) {
        char temp = arr[i];
        arr[i] = arr[i - 1];
        arr[i - 1] = temp;
    }
    // printArray(arr, size);
}

void rotateLeft(char arr[][SIZE], int rows, int cols) {
    if (rows <= 0 || rows > SIZE || cols <= 0 || cols > SIZE) return;
    for (int i = 0; i < rows; i++) {
        rotateLeft(arr[i], cols);
    }
    // printArray(arr, rows, cols);
}

void rotateRight(char arr[], int size) {
    if (size <= 0 || size > SIZE) return;
    for (int i = size - 2; i >= 0; i--) {
        char temp = arr[i + 1];
        arr[i + 1] = arr[i];
        arr[i] = temp;
    }
    // printArray(arr, size);
}

void rotateRight(char arr[][SIZE], int rows, int cols) {
    if (rows <= 0 || rows > SIZE || cols < 0 || cols > SIZE) return;
    for (int i = 0; i < rows; i++) {
        rotateRight(arr[i], cols);
    }
    // printArray(arr, rows, cols);
}

void reverse(char arr[], int size) {
    if (size <= 0 || size > SIZE) return;
    for (int i = 0, j = size - 1; i <= j; i++, j--) {
        char temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
    // printArray(arr, size);
}

void swapRange(char arr1[], int size1, int index1, char arr2[], int size2, int index2, int len) {
    if (size1 <= 0 || size1 > SIZE || size2 <= 0 || size2 > SIZE || index1 + len - 1 > size1 || index2 + len - 1 > size2) return;
    for (int i = index2 + len - 1; i >= index2; i--) {
        for (int j = index1; j <= index1 + len - 1; j++) {
            char temp = arr1[j];
            arr1[j] = arr2[i];
            arr2[i] = temp;
        }
    }
    // printArray(arr1, size1);
    // printArray(arr2, size2);
}

void swapWithinOneRow(char arr[], int size, int len) {
    if (size > SIZE || size <= 0) return;
    if (len > 0 && size > 0 && len <= (size >> 1)) {
        for (int i = 0; i < size - len - 1; i += len * 2) {
            swapRange(arr, size, i, arr, size, i + len, len);
        }
    }
    if (size >= 2 && size % 2 == 0 && len == 1) {
        char temp = arr[size - 2];
        arr[size - 2] = arr[size - 1];
        arr[size - 1] = temp;
    }
    // printArray(arr, size);
}

void swapRows(char arr[][SIZE], int rows, int cols) {
    if (rows <= 0 || rows > SIZE || cols <= 0 || cols > SIZE) return;
    for (int i = 0; i < rows - 1; i += 2) {
        swapRange(arr[i], cols, 0, arr[i + 1], cols, 0, cols);
    }
     //printArray(arr, rows, cols);
}

int main() {
    char c[SIZE] = {'a', '#', '~', ' ', '*'};
    char arr0[SIZE] = { '0', '1', '2', '3', '4', '5' };
    char arr1[SIZE] = { 'a', 'b', 'c', 'd', 'e', 'f'};
    char arr2[SIZE][SIZE] = { {'a', 'b', 'c'}, {'d', 'e', 'f'}, {'g', 'h', 'i'} };
    // printRight(3);
    // printRight_upsideDown_rightJustified(3);
    // printArray(arr2, 3, 3);
    // add(c, 5, 5);
    // add(arr1, 6, 1);
    // add(arr2, 3, 3, 35);
    // rotateLeft(arr1, 6);
    // rotateRight(arr1, 6);
    // rotateLeft(arr2, 3, 3);
    // rotateRight(arr2, 3, 3);
    // reverse(arr1, 6);
    // swapRange(arr0, 6, 0, arr1, 6, 2, 2);
    // swapWithinOneRow(arr0, 6, 1);
     swapRows(arr2, 3, 3);
}

