#include "catch.hpp"
#include "main.h"


SCENARIO("Exam 03")
{
    GIVEN("Problem 01")
    {
        std::cout << "-----------------------------" << std::endl;
        std::cout << "Problem 01" << std::endl;
        WHEN("Creating 2 matrices. The first is 2x3, and the second is 3x2")
        {
            problem_01::Matrix<int> m1(2, 3);
            problem_01::Matrix<int> m2(3, 2);

            m1.fill_int_random();
            m2.fill_int_random();

            std::cout << "m1 values:" << std::endl;
            m1.print_values();

            std::cout << "m2 values:" << std::endl;
            m2.print_values();

            THEN("Multiply both matrices")
            {
                problem_01::Matrix<int> m3 = m1 * m2;
                std::cout << "m3 values:" << std::endl;
                m3.print_values();
            }
        }
    }

    GIVEN("Problem 02")
    {
        std::cout << "-----------------------------" << std::endl;
        std::cout << "Problem 02" << std::endl;
        WHEN("")
        {
            std::deque <int> deque_1;
            deque_1.push_back(5);
            deque_1.push_back(1);
            deque_1.push_back(4);
            deque_1.push_back(8);
            deque_1.push_back(2);
            deque_1.push_back(4);

            std::cout << "First Deque" << std::endl;
            problem_02::show_dq(deque_1);
            THEN("")
            {
                std::deque<int> new_deque = problem_02::function(deque_1, 3);
                std::cout << "New Deque" << std::endl;
                problem_02::show_dq(new_deque);
            }
        }
    }

    GIVEN("Problem 03")
    {
        WHEN("")
        {
            THEN("")
            {
                REQUIRE(true);
            }
        }
    }
}