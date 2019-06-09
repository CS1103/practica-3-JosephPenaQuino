#ifndef PRACTICA_3_JOSEPHPENAQUINO_STL_DEQUE_H
#define PRACTICA_3_JOSEPHPENAQUINO_STL_DEQUE_H

#include <iostream>
#include <deque>
#include <iterator>
#include <vector>
#include <set>

namespace problem_02
{
    class my_set
    {
    private:
        int max;
        int min;
        bool is_void;
    public:
        explicit my_set(int val) : max{val}, min{val}, is_void(false){}
        explicit my_set() : max{0}, min{0}, is_void{true} {}

        void insert_value(int new_val)
        {
            if (is_void)
            {
                max = new_val;
                min = new_val;
                is_void = false;
            }
            else
            {
                if (new_val > max)
                    max = new_val;
                else if (new_val < min)
                    min = new_val;
            }

        }
        int get_sum()
        {
            return max + min;
        }
    };

    void show_dq(std::deque <int> g)
    {
        std::deque <int> :: iterator it;
        for (it = g.begin(); it != g.end(); ++it)
            std::cout << '\t' << *it;
        std::cout << '\n';
    }

    std::deque<int> function(std::deque<int> d, int number)
    {
        std::deque<int> new_deque;
        std::deque<int>::iterator it;

        const int array_size= d.size() + 1 - number;
        my_set arr[array_size];

        int cnt = 0;
        for (it = d.begin(); (it) != d.end(); ++it)
        {
            for (int i = 0; i < array_size; ++i)
            {
                if ((cnt-i) >= 0 && (cnt-i) < number)
                    arr[i].insert_value(*it);
            }
            ++cnt;
        }

        for(int i = 0; i < array_size; ++i)
            new_deque.push_back(arr[i].get_sum());

        return new_deque;
    }
}
#endif //PRACTICA_3_JOSEPHPENAQUINO_STL_DEQUE_H
