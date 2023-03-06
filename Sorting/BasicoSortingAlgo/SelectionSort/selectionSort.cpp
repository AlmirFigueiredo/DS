#include <iostream>
using namespace std;

//When you are sorting, it's too common to swap elements, so you should start creating a swap function:
void swap(int array[], int x, int y) {
    //To swap two elements, you should create a temp value to store one value:
    int temp = array[x];
    array[x] = array[y];
    array[y] = temp;
}
//In the selection sort you need to find the position of the smallest, so you can create this function:
int posOfSmallest(int array[], int start, int end) {
    int smallest = start;
    for(int i = start; i <= end; i++) {
        if(array[i] < array[smallest]) {
            smallest = i; 
        } 
    }
    return smallest;
}

//Create the sorting function, in this case, I'll use the selectionSort:
void selectionSort(int array[], int size) {
    for(int i = 0; i < size; i++) { //To the loop starting with the first element to the last
        int j = posOfSmallest(array, i, size-1);
        swap(array, i, j);
    }

}

void displayArray(int array[], int size) {
    for(int i = 0; i < size; i++) {
        cout << array[i];
        if(i < size-1) {
            cout << ", ";
        }else {
            cout << endl;
        }
    }

}

int main() {
    //Create a non-ordered array to test the sorting:
    int array[] = {30, 10, 50, 5, 45, 0};
    int size = sizeof(array)/sizeof(int);
    cout << "Before sorting:" << endl;
    displayArray(array, size);
    cout << "After sorting:" << endl;
    selectionSort(array, size);
    displayArray(array, size);
    return 0;
}