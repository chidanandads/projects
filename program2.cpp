#include <iostream>
#include <vector>

void merge(std::vector<int>& values, int left, int middle, int right) {
    std::vector<int> merged;
    int first = left;
    int second = middle + 1;

    while (first <= middle && second <= right) {
        if (values[first] <= values[second]) {
            merged.push_back(values[first++]);
        } else {
            merged.push_back(values[second++]);
        }
    }

    while (first <= middle) {
        merged.push_back(values[first++]);
    }
    while (second <= right) {
        merged.push_back(values[second++]);
    }

    for (int i = 0; i < static_cast<int>(merged.size()); ++i) {
        values[left + i] = merged[i];
    }
}

void mergeSort(std::vector<int>& values, int left, int right) {
    if (left >= right) {
        return;
    }

    const int middle = left + (right - left) / 2;
    mergeSort(values, left, middle);
    mergeSort(values, middle + 1, right);
    merge(values, left, middle, right);
}

int main() {
    int size;
    if (!(std::cin >> size) || size < 0) {
        return 1;
    }

    std::vector<int> values(size);
    for (int& value : values) {
        if (!(std::cin >> value)) {
            return 1;
        }
    }

    if (!values.empty()) {
        mergeSort(values, 0, static_cast<int>(values.size()) - 1);
    }

    for (int i = 0; i < static_cast<int>(values.size()); ++i) {
        if (i > 0) {
            std::cout << ' ';
        }
        std::cout << values[i];
    }
    std::cout << '\n';

    return 0;
}