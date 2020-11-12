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

template <class T>
void show_vectors(std::vector<T> &aVector){
    for(auto &e: aVector)
        std::cout << e << std::endl;

}
template <class T>
void show_array(T *array, int size){
    for (int i = 0; i < size; ++i) {
        std::cout << array[i] << std::endl;
    }
}
class Tests{
private:
    static void test1(){
        std::cout << "test 1" << std::endl;
        std::vector<int> numbers = { 8, 234, 5435345, 4, 5 };
        std::cout << "input" << std::endl;
        show_vectors(numbers);
        Sort::ShellSort(numbers);
        std::cout << "output" << std::endl;
        show_vectors(numbers);
    }
    static void test2(){
        std::cout << "test 2" << std::endl;
        std::vector<std::string> words = {"Z", "B", "A", "J", "M"};
        std::cout << "input" << std::endl;
        show_vectors(words);
        Sort::ShellSort(words);
        std::cout << "output" << std::endl;
        show_vectors(words);
    }
    static void test3(){
        std::cout << "test 3" << std::endl;
        int arr[5] =
                {
                        5,
                        1,
                        8,
                        10,
                        2
                };
        std::cout << "input" << std::endl;
        show_array(arr, 5);
        Sort::BubbleSort(arr, 5);
        std::cout << "output" << std::endl;
        show_array(arr, 5);
    }
    static void test4(){
        std::cout << "test 4" << std::endl;
        char arr[5]=
                {
                        'x',
                        'a',
                        'b',
                        'k',
                        'w'
                };
        std::cout << "input" << std::endl;
        show_array(arr, 5);
        Sort::BubbleSort(arr, 5);
        std::cout << "output" << std::endl;
        show_array(arr, 5);
    }
public:
    static void run_tests(){
        test1();
        test2();
        test3();
        test4();
    }

};

int main() {

    Tests::run_tests();

    return 0;
}