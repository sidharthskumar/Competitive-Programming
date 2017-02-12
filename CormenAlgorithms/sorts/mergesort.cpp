
#include <iostream>
#include <vector>
#include <cmath>
#include <limits>

template<typename T>
void merge(std::vector<T>& numbers, int p, int q, int r)
{
    int n1 = q - p + 1;  // Number of elements to be sorted in leftVector
    int n2 = r - q;      // Number of elements to be sorted in rightVector

    std::vector<T> leftVector(n1 + 1); // Add one element for the sentinel value
    std::vector<T> rightVector(n2 + 1);

    for (int i = 0; i < n1; i++)
    {
        leftVector[i] = numbers[p + i];
    }

    for (int j = 0; j < n2; j++)
    {
        rightVector[j] = numbers[q + j + 1];
    }

    leftVector[n1] = std::numeric_limits<T>:: max(); // Sentinel value added at the end of the vector
    rightVector[n2] = std::numeric_limits<T>:: max();
    int i = 0;
    int j = 0;

    for (int k = p; k <= r; k++)
    {
        if (leftVector[i] <= rightVector[j])
        {
            numbers[k] = leftVector[i];
            i++;
        }
        else
        {
            numbers[k] = rightVector[j];
            j++;
        }
    }
}

template <typename T>
void mergeSort(std::vector<T>& numbers, int p, int r)
{
    if (p < r)
    {
        int q = floor((p + r) / 2);
        mergeSort(numbers, p, q);
        mergeSort(numbers, q + 1, r);
        merge(numbers, p, q, r);
    }
}



int main() {
    int n;
    std::cin>>n;
    std::vector<int> numbers (n);
    for(int i=0;i<n;i++)
        std::cin>>numbers[i];
    mergeSort(numbers, 0, numbers.size()- 1);
    for(int i=0;i<n;i++)
        std::cout<<numbers[i];
    return 0;
}
