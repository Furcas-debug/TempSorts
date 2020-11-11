#include <iostream>
#include <vector>
#include <string>

class ISort{

public:
    void virtual getArray() = 0;
    virtual void sortArray() = 0;
};
/*
class Shell_sort :public ISort{
public:

    template <typename T>
    virtual  sortArray(std::vector<T> &aVector) override {
        unsigned end = aVector.size() - 1;

        unsigned h;
        for(h = 1; h <= end/9; h = 3*h+1)
            ;

        for(; h > 0; h /= 3)
            for(auto i = h; i <= end; i++)
            {
                unsigned j = i;
                T v = aVector[i];
                while(j >= h && v < aVector[j - h])
                {
                    aVector[j] = aVector[j - h];
                    j -= h;
                }
                aVector[j] = v;
            }
    }
};
*/


template <class T> class Shell_sort {
public:
    T aVector;

    Shell_sort(T &vector){
        aVector = vector;
    }
    void shell_sort (){
        unsigned end = aVector.size() - 1;

        unsigned h;
        for(h = 1; h <= end/9; h = 3*h+1)
            ;

        for(; h > 0; h /= 3)
            for(auto i = h; i <= end; i++)
            {
                unsigned j = i;
                T v = aVector[i];
                while(j >= h && v < aVector[j - h])
                {
                    aVector[j] = aVector[j - h];
                    j -= h;
                }
                aVector[j] = v;
            }

    }

};


template <class T> void show(std::vector<T> &aVector){
    for(int n=0; n<aVector.size(); n++ )
        std::cout << aVector[n] << "\t";
    std::cout << std::endl;
}

template <class T> void bubleSort(std::vector<T> &aVector){
    show(aVector);
    T s;
    for (int i = 0; i < aVector.size() - 1; ++i) {
        for (int j = 0; j < aVector.size() - 1; ++j) {
            if (aVector[j] > aVector[j+1]){
                std::swap(aVector[j], aVector[j+1]);
            }
        }
    }
    show(aVector);
}




template <class T> void shell_sort (std::vector<T> &aVector){
    unsigned end = aVector.size() - 1;

    unsigned h;
    for(h = 1; h <= end/9; h = 3*h+1)
        ;

    for(; h > 0; h /= 3)
        for(auto i = h; i <= end; i++)
        {
            unsigned j = i;
            T v = aVector[i];
            while(j >= h && v < aVector[j - h])
            {
                aVector[j] = aVector[j - h];
                j -= h;
            }
            aVector[j] = v;
        }

}

class Test{
public:

    void LetsGo(ISort &array){
        std::cout  << "send array " << std::endl;
        array.getArray();
        std::cout << "sorting..." << std::endl;
        array.sortArray();
    }
};

template<typename T>
void swap(T &aValue1, T &aValue2)
{
    T tmp;
    tmp = aValue1;
    aValue1 = aValue2;
    aValue2 = tmp;
}
template <typename T>
void shell_sort1(std::vector<T> &aVector)
{
    unsigned end = aVector.size() - 1;

    unsigned h;
    for(h = 1; h <= end/9; h = 3*h+1)
        ;

    for(; h > 0; h /= 3)
        for(auto i = h; i <= end; i++)
        {
            unsigned j = i;
            T v = aVector[i];
            while(j >= h && v < aVector[j - h])
            {
                aVector[j] = aVector[j - h];
                j -= h;
            }
            aVector[j] = v;
        }
}



const int size = 5;

int main() {
    std::vector<int> numbers = { 8, 234, 5435345, 4, 5 };
    std::vector<std::string> words = {"Z", "D", "S", "A"};
    //Shell_sort s1;


    Test test1;

    //test1.LetsGo(s1);


    std::vector<unsigned> v;

    //shell_sort(numbers);
    //bubleSort(words);
    Shell_sort obj1(numbers);
    obj1.shell_sort();
    show(numbers);
    return 0;
}
