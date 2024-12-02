#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << endl;
}

void insertionSort(int arr[], int n)
{
    for (int i = 1; i < n; ++i) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}


int main() {
    std::ifstream inputFile("input.txt");
    if (!inputFile) {
        std::cerr << "Unable to open file input.txt" << std::endl;
        return 1;
    }

    std::vector<int> column1, column2;
    std::string line;
    while (std::getline(inputFile, line)) {
        std::istringstream iss(line);
        int num1, num2;
        if (!(iss >> num1 >> num2)) {
            std::cerr << "Error reading line: " << line << std::endl;
            continue;
        }
        column1.push_back(num1);
        column2.push_back(num2);
    }

    int length1 = column1.size();
    int length2 = column2.size();
    int* list1 = column1.data();
    int* list2 = column2.data();
    insertionSort(list1, length1);
    insertionSort(list2, length2);
    int distances[length1];
    for (int i = 0; i < length1; ++i){
        if (list1[i] > list2[i]){
            distances[i] = list1[i] - list2[i];
        }
        else{
            distances[i] = list2[i] - list1[i];
        }
    }
    int totalDistance = 0;
    for (int j = 0; j < length1; ++j){
        totalDistance = totalDistance + distances[j];
    }
    cout << totalDistance;
    return 0;
}
