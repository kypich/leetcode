#include "tasks.hpp"
#include <iostream>
#include <cmath>
#include <algorithm>
#include <unordered_map>
#include <stack>
#include <string>

std::vector<int> twoSum(std::vector<int>& nums, int target) {
    // std::vector<int> result;
    // for (size_t i = 0; i < nums.size(); ++i) {
    //     for (size_t j = i + 1; j < nums.size(); ++j) {
    //         if (nums[i] + nums[j] == target) {
    //             result.push_back(i);
    //             result.push_back(j);
    //             return result;
    //         }
    //     }
    // }
    // return result;

    // T 1
    for (size_t i = 0; i < nums.size(); ++i) {
        auto it = find(nums.begin(), nums.end(), target - nums[i]);
        if (it != nums.end() && (it - nums.begin() != static_cast<int>(i))) {
            return { static_cast<int>(i), static_cast<int>(it - nums.begin()) };
        }
    }



    // T 2
    std::unordered_map<int, int> num_c;

    for (size_t i = 0; i < nums.size(); ++i) {
        int c = target - nums[i];

        if (num_c.count(c)) {
            return { static_cast<int>(num_c[c]), static_cast<int>(i) };
        }

        num_c[nums[i]] = i;
    }

    return {};
}

bool isPalindrome(int x) {
    if (x < 0) {
        return false;
    }
    else {
        std::string s1 = std::to_string(x);
        std::string s2 = s1;
        std::reverse(s1.begin(), s1.end());
        if (s1 != s2) {
            return false;
        }
    }
    return true;
}

bool is_pal2(int x) {
    std::stack<char> st;
    std::string s = std::to_string(x);

    for (char c : s) {
        st.push(c);
    }

    for (size_t i = 0; i < s.length() / 2; ++i) {
        if ((int)st.top() != s[(int)i]) return false;
        st.pop();
    }

    return true;
}


