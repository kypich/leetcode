#include <iostream>
#include "tasks/tasks.hpp"

// Web-site with all the cpp info: cppreference.com

// Your leetcode worksheet
void lcw_leetcode(const int option) {
    switch (option) {
    case 1: {
        std::cout << "1. Two Sum (Easy)" << std::endl;
        std::vector nums = { 3, 2, 4 };
        std::vector vec = lc_tasks::twoSum(nums, 6);
        for (int el : vec) {
            std::cout << el << " ";
        }
        break;
    }

    case 9: {
        std::cout << "9. Is Palindrome (Easy)" << std::endl;
        std::cout << std::boolalpha << lc_tasks::isPalindrome(11211) << std::endl;
        std::cout << std::boolalpha << lc_tasks::is_pal2(11211) << std::endl;
        break;
    }

    case 13: {
        std::cout << "13. Roman to Integer (Easy)" << std::endl;
        std::cout << lc_tasks::romanToInt("VI") << std::endl;
        break;
    }

    default: {
        std::cout << "Invalid LC task number" << std::endl;
        break;

    }
    }
}

int main() {

    /*
        - C-style cast
        std::cout << (int)56.99;

        - Cpp-style (static):
        std::cout << static_cast<int>(56.99);
    */

    lcw_leetcode(13);

    return 0;
}