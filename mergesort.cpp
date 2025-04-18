#include <vector>
#include <iostream>
using namespace std;

void mergealgo(int* arr, int start, int mid, int end) {
    int i = start, j = mid + 1;
    vector<int> v;
    while (i <= mid && j <= end) {
        if (arr[i] <= arr[j]) {
            v.push_back(arr[i]);
            i++;
        } else {
            v.push_back(arr[j]);
            j++;
        }
    }

   while (i <= mid) {
        v.push_back(arr[i]);
        i++;
    }
    while (j <= end) {
        v.push_back(arr[j]);
        j++;
    }

       for (int i= 0; i < v.size(); i++) {
        arr[start + i] = v[i];
    }
}

void merge(int* arr, int start, int end) {
    if (start < end) {
        int mid = start + (end - start) / 2;

        // Recursively sort the first and second halves
        merge(arr, start, mid);
        merge(arr, mid + 1, end);

        // Merge the sorted halves
        mergealgo(arr, start, mid, end);
    }
}

void display(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[] = {4, 5, 1, 10, 7, 9, 5};
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << "Before sorting, data is: ";
    display(arr, size);

    merge(arr, 0, size - 1);

    cout << "\nAfter sorting, data is: ";
    display(arr, size);

    return 0;
}
