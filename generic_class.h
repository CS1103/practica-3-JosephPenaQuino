#ifndef PRACTICA_3_JOSEPHPENAQUINO_GENERIC_CLASS_H
#define PRACTICA_3_JOSEPHPENAQUINO_GENERIC_CLASS_H

#include <stdexcept>
#include <iostream>
#include <random>

struct frequencies
{
    double relative_frequency;
    double absolute_frequency;

    frequencies() : relative_frequency{0}, absolute_frequency{0} {}
    frequencies(double r, double a) : relative_frequency{r}, absolute_frequency{a} {}
};

namespace problem_01
{
    template <class T>
    class Temp {
    private:
        int * data;

    public:
        explicit Temp(int* data) : data{data} { }

        int operator[] (int index) {
            return data[index];
        }

    };

    template <class T>
    class Matrix
    {
    private:
        T ** data;

    public:

        int rows;
        int columns;

        Matrix(int rows, int columns) : rows{rows}, columns{columns}
        {
            data = new T * [rows];
            for(int i = 0; i < rows; ++i)
                data[i] = new T[columns];
        }

        void fill_int_random()
        {
            std::default_random_engine generator;
            std::uniform_int_distribution<int> distribution(1,5);
            for (int r = 0; r < rows; ++r)
                for (int c = 0; c < columns; ++c)
                    data[r][c] = distribution(generator);
        }

        Matrix operator * (Matrix & other)
        {
            if (columns != other.rows)
                throw std::invalid_argument( "Size error" );
            else
            {
                Matrix new_matrix(rows, other.columns);
                for (int r = 0; r < rows; ++r)
                {
                    for (int c = 0; c < other.columns; ++c)
                    {
                        new_matrix.set_value(r, c, T());
                        for (int s = 0; s < columns; ++s)
                        {
                            new_matrix.set_value(r, c, new_matrix[r][c] + data[r][s] * other[s][c]);
                        }
                    }
                }
                return new_matrix;
            }

        }

        void set_value(int r, int c, T value)
        {
            if (r < rows && c < columns)
                data[r][c] = value;
        }

        Temp<T> operator[] (int index) {
            return Temp<T>(data[index]);
        }

        void print_values()
        {
            for (int r = 0; r < rows; ++r)
            {
                for (int c = 0; c < columns; ++c)
                    std::cout << data[r][c] << " ";
                std::cout << std::endl;
            }
        }
    };
}

#endif //PRACTICA_3_JOSEPHPENAQUINO_GENERIC_CLASS_H
