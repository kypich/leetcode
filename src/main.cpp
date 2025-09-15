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
        std::cout << lc_tasks::romanToInt("III") << std::endl;
        break;
    }

    case 14: {
        std::cout << "13. Roman to Integer (Easy)" << std::endl;
        std::vector<std::string> vec = { "flower","flow","flight" };
        std::cout << lc_tasks::longestCommonPrefix(vec) << std::endl;
        break;
    }

    case 20: {
        std::cout << "20. Valid Parentheses (Easy)" << std::endl;
        std::cout << std::boolalpha << lc_tasks::isValid("((") << std::endl;
        break;
    }

    case 21: {
        std::cout << "21. Merge Two Sorted Lists (Easy)" << std::endl;

        int nums1[3] = {1, 2, 4};
        int nums2[3] = {1, 3, 4};


        lc_tasks::mergeTwoLists(nums1, nums2);
        break;
    }

    case 3: {
        std::cout << "3. Longest Substring Without Repeating Characters (Medium)" << std::endl;
        std::cout << lc_tasks::lengthOfLongestSubstring("abcabcbb") << std::endl;
        break;
    }

    case 26: {
        std::cout << "26. Remove Duplicates from Sorted Array (Easy)" << std::endl;
        std::vector<int> nums = {0,0,1,1,1,2,2,3,3,4};
        std::cout << lc_tasks::removeDuplicates(nums) << std::endl;
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

    lcw_leetcode(26);

    return 0;
}