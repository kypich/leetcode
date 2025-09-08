#ifndef TASKS_HPP_
#define TASKS_HPP_ 1
#include <vector>
#include <string>


class lc_tasks {
public:
    static std::vector<int> twoSum(std::vector<int>& nums, int target);
    static bool isPalindrome(int x);
    static bool is_pal2(int x);
    static int romanToInt(std::string s);
    static std::string longestCommonPrefix(std::vector<std::string>& strs);
    static bool isValid(std::string s);
};

#endif