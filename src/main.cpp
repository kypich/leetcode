#include <iostream>
#include "tasks/tasks.hpp"

// Web-site with all the cpp info: cppreference.com

int main() {
    // std::cout << "Hello world!" << std::endl;

    // ----------------------------------------------------
    // 1. Two Sum

    // std::vector nums = { 3, 2, 4 };

    // std::vector vec = twoSum(nums, 6);

    // for (int el : vec) {
    //     std::cout << el << " ";
    // }

    /*
        - C-style cast
        std::cout << (int)56.99;

        - Cpp-style:
        std::cout << static_cast<int>(56.99);
    */

    //------------------------------------------------------
    // 9. Palindrome Number

    // isPalindrome();

    std::cout << std::boolalpha << isPalindrome(11211) << std::endl;
    std::cout << std::boolalpha << is_pal2(11211) << std::endl;

    return 0;
}