#include <iostream>
#include <string>
using namespace std;

template <class T>
int binarySearch(T A[], int n, T value)
{
    int low = 0;
    int high = n - 1;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (A[mid] == value)
        {
            return mid;
        }

        else if (A[mid] < value)
            low = mid + 1;

        else
            high = mid - 1;
    }

    return -1;
}

template <class T>
void printSearchResult(int index, T key)
{
    if (index == -1)
    {
        cout << key << " not found\n";
    }
    else
    {
        cout << key << " found at index " << index << endl;
    }
}

// added the size of the array as a parameter in the function
int main()
{
    // Test with integer array
    int intArray[5] = { 11, 12, 22, 25, 64 };
    int intKey = 22;
    int intIndex = binarySearch(intArray, 5,intKey);
    printSearchResult(intIndex, intKey);

    // Test with float array
    float floatArray[4] = { 0.57, 1.62, 2.71, 3.14 };
    float floatKey = 2.71;
    int floatIndex = binarySearch(floatArray, 4,floatKey);
    printSearchResult(floatIndex, floatKey);

    // Test with string array
    string stringArray[4] = { "apple", "banana", "grape", "orange" };
    string stringKey = "grape";
    int stringIndex = binarySearch(stringArray, 4,stringKey);
    printSearchResult(stringIndex, stringKey);

    return 0;
}