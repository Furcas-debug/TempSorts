#include <iostream>
#include <vector>
#include <string>


class Sort
{
public:

    template <class T>
    static void BubbleSort(std::vector<T>& arr)
    {
        BubbleSortHelper(arr, arr.size());
    }

    template <class T>
    static void BubbleSort(T* arr, int size)
    {
        BubbleSortHelper(arr, size);
    }


    template <class T>
    static void ShellSort(std::vector<T>& arr)
    {
        ShellSortHelper(arr, arr.size());
    }

    template <class T>
    static void ShellSort(T* arr, int size)
    {
        ShellSortHelper(arr, size);
    }

private:

    Sort() = default;
    Sort(const Sort& r) = default;
    Sort(Sort&& r) = default;


    template <class T>
    static void BubbleSortHelper(T& arr, int size)
    {
        for (int i = 0; i < size; ++i)
        {
            for (int j = 0; j < size - 1; ++j)
            {
                if (arr[j] > arr[j + 1])
                {
                    std::swap(arr[j], arr[j + 1]);
                }
            }
        }
    }

    template <class T>
    static void ShellSortHelper(T& arr, int size)
    {
        int end = size - 1;

        int h = 1;
        while (h <= end / 9)
            h = 3 * h + 1;

        for (; h > 0; h /= 3)
        {
            for (int i = h; i <= end; ++i)
            {
                int j = i;

                auto tmp = arr[i]; // Copy
                while (j >= h && tmp < arr[j - h])
                {
                    arr[j] = arr[j - h];
                    j -= h;
                }

                arr[j] = tmp;
            }
        }
    }
};





int main() {
    std::vector<int> numbers = { 8, 234, 5435345, 4, 5 };
    std::vector<std::string> words = {"Z", "B", "A", "J", "M"};
    int *arr = new int[5];

    arr[0] = 5;
    arr[1] = 1;
    arr[2] = 8;
    arr[3] = 10;
    arr[4] = 2;

    int arr2[5] =
    {
        5,
        1,
        8,
        10,
        2
    };

    //std::vector<std::string> words = {"Z", "D", "S", "A"};

    Sort::BubbleSort(numbers);
    Sort::BubbleSort(arr, 5);
    Sort::ShellSort(arr2, 5);
    Sort::ShellSort(words);
    std::cout << "Vector: " << std::endl;
    for (auto& e : words)
    {
        std::cout << e << std::endl;
    }

    std::cout << std::endl;

    std::cout << "Static array: " << std::endl;
    for (int i : arr2)
    {
        std::cout << i << std::endl;
    }

    std::cout << std::endl;

    std::cout << "Dynamic array: " << std::endl;
    for (int i = 0; i < 5; ++i)
    {
        std::cout << arr[i] << std::endl;
    }

    return 0;
}
