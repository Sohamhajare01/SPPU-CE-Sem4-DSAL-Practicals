#include<iostream>
using namespace std;

void MaxHeapify(int a[], int i, int n){
    int j, temp;
    temp = a[i];
    j = 2 * i;

    while (j <= n){
        if (j < n && a[j + 1] > a[j])
            j = j + 1;

        if (temp > a[j])
            break;

        else if (temp <= a[j]){
            a[j / 2] = a[j];
            j = 2 * j;
        }
    }
    a[j / 2] = temp;
    return;
}
void MinHeapify(int a[], int i, int n){
    int j, temp;
    temp = a[i];
    j = 2 * i;

    while (j <= n){
        if (j < n && a[j + 1] < a[j])
            j = j + 1;

        if (temp < a[j])
            break;

        else if (temp >= a[j]){
            a[j / 2] = a[j];
            j = 2 * j;
        }
    }
    a[j / 2] = temp;
    return;
}
void MaxHeapSort(int a[], int n){
    int i, temp;
    for (i = n; i >= 2; i--){

        temp = a[i];
        a[i] = a[1];
        a[1] = temp;

        MaxHeapify(a, 1, i - 1);
    }
}
void MinHeapSort(int a[], int n){
    int i, temp;
    for (i = n; i >= 2; i--){

        temp = a[i];
        a[i] = a[1];
        a[1] = temp;

        MinHeapify(a, 1, i - 1);
    }
}
void Build_MaxHeap(int a[], int n){
    int i;
    for (i = n / 2; i >= 1; i--)
        MaxHeapify(a, i, n);
}
void Build_MinHeap(int a[], int n){
    int i;
    for (i = n / 2; i >= 1; i--)
        MinHeapify(a, i, n);
}

void displaySortedData(int arr[], int n, bool ascending)
{
    if (ascending){
        cout << "\nSorted Data : ASCENDING : ";
        for (int i = 1; i < n; i++)
            cout << "->" << arr[i];
    }else{
        cout << "\nSorted Data : DESCENDING: ";
        for (int i = 1; i < n; i++)
            cout << "->" << arr[i];
    }
}

int main()
{
    int choice;
    int n;
    int *arr = nullptr;

    do
    {
        cout << "\nMenu:\n";
        cout << "1. Input marks\n";
        cout << "2. Sort in ascending order\n";
        cout << "3. Sort in descending order\n";
        cout << "4. Display maximum and minimum marks\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter the number of Students : ";
            cin >> n;
            n++;
            if (arr != nullptr)
                delete[] arr;
            arr = new int[n];
            for (int i = 1; i < n; i++){
                cout << "Enter the marks of student " << i << ": ";
                cin >> arr[i];
            }
            break;
        case 2:
            if (arr == nullptr){
                cout << "Please input marks first." << endl;
                break;
            }
            Build_MaxHeap(arr, n - 1);
            MaxHeapSort(arr, n - 1);
            displaySortedData(arr, n, true);
            break;
        case 3:
            if (arr == nullptr){
                cout << "Please input marks first." << endl;
                break;
            }
            Build_MinHeap(arr, n - 1);
            MinHeapSort(arr, n - 1);
            displaySortedData(arr, n, false);
            break;
        case 4:
            if (arr == nullptr){
                cout << "Please input marks first." << endl;
                break;
            }
            Build_MaxHeap(arr, n - 1);
            MaxHeapSort(arr, n - 1);
            cout << "\nMaximum Marks : " << arr[1] << endl;
            Build_MinHeap(arr, n - 1);
            MinHeapSort(arr, n - 1);
            cout << "Minimum Marks : " << arr[1] << endl;
            break;
        case 5:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 5);

    if (arr != nullptr)
        delete[] arr;

    return 0;
}
