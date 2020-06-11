#include <iostream>
#include <vector>

//Example of a badly implemented Insertion Sort


void insertionSort(std::vector<int>& to_sort)
{
    int counter =0;
    std::cout << "Before:";
    for(auto& f:to_sort)
    {
        std::cout<< f << ",";
    }
    std::cout<<std::endl;
    for(int x=0;x<to_sort.size();x++)
    {
        if(to_sort[x+1]<to_sort[x])
        {
            int standort = to_sort[x];
            int kleiner = to_sort[x+1];
            to_sort[x]=kleiner;
            to_sort[x+1] =standort;
            x=0;
        }

        for(auto& f:to_sort)
        {
            std::cout<< f << ",";
        }
        std::cout<<std::endl;
        counter++;
    }
    std::cout << "After "<< counter << " sorts:";

    for(auto& f:to_sort)
    {
        std::cout<< f << ",";
    }
    std::cout<<std::endl;
}

int main()
{
    std::vector<int> example = {0, 10, 20, 1, 11, 21, 2,12, 22};
    insertionSort(example);
}
