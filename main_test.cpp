#include "catch.hpp"
#include "main.h"

SCENARIO("Exam 03")
{
    GIVEN("Problem 01")
    {
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
        WHEN("")
        {
            THEN("")
            {
                REQUIRE(true);
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