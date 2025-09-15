#include "tasks.hpp"
#include <iostream>
#include <cmath>
#include <algorithm>
#include <unordered_map>
#include <stack>
#include <queue>
#include <string>
#include <algorithm>

// 1. Two Sum (Easy)
std::vector<int> lc_tasks::twoSum(std::vector<int>& nums, int target) {
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

// 9. Is Pal (Easy)
bool lc_tasks::isPalindrome(int x) {
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

// 9. Is Pal Stack Solution (Easy)
bool lc_tasks::is_pal2(int x) {
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


// 13. Roman to Integer
int lc_tasks::romanToInt(std::string s) {
    //1994
    //(5-1)+(100-10)+(1000-100)+(1000)
    // 1000 - 100 + 1000 - 10 + 100 - 1 + 5
    //LVIII
    //58
    //50+5+1+1+1
    std::stack<char> st;
    std::unordered_map<char, int> symbols{ {'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000} };
    int previous_number = 0;
    int counter = 0;

    for (char c : s) {
        st.push(c);
    }

    while (!st.empty()) {
        char el = st.top();
        st.pop();
        if (symbols[el] >= previous_number) {
            counter += symbols[el];
            previous_number = symbols[el];
        }
        else {
            counter -= symbols[el];
            previous_number = symbols[el];
        }
    }
    return counter;
}

//14. Longest Common Prefix (Easy)
std::string lc_tasks::longestCommonPrefix(std::vector<std::string>& strs) {
    // substr(pos, len)
    if (strs.size() == 1) return strs[0];

    for (const auto& s : strs) {
        if (s.empty()) return "";
    }

    std::sort(strs.begin(), strs.end(), [](const std::string& a, const std::string& b) {
        return a.length() < b.length();
        });

    std::queue<char> q;
    std::string res = ""; // вот тут шок информация
    int gc = 0;

    for (char c : strs[0]) q.push(c);

    while (!q.empty()) {
        char c = q.front(); q.pop();
        for (int i = 1; i < strs.size(); ++i) {
            if (strs[i][gc] == c) {
                if (i == strs.size() - 1) {
                    res.push_back(c);
                }
            }
            else {
                return res;
            }
        }
        gc++;
    }

    return res;
}

// 20. Valid Parentheses
bool lc_tasks::isValid(std::string s) {
    std::stack<char> st;
    std::string reference = "()[]{}"; // reference value

    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
            st.push(s[i]);
            continue;
        }
        if (s[i] == ')' || s[i] == '}' || s[i] == ']') {
            if (st.empty()) {
                return false;
            }

            // Саб нужно сделать из вернего элемента стака(открытая скобка) и s[i] сейчас которое (закрытая скобка) 
            std::string sub; // sub = "[]"
            sub += st.top();
            sub += s[i];

            // поиск под-строки в строке
            if (reference.find(sub) != std::string::npos) {
                //если найденно
                st.pop();
            }
            else {
                return false;
            }
        }
    }
    return st.empty();
}


// 21. Merge Two Sorted Lists
int lc_tasks::mergeTwoLists(int *list1, int *list2) {
    int x = 5;
    int y[500] = { 1,2,3,4,5,6,7 };

    int *px = &x;
    int *py = y;    

    std::cout << x << " - " << y << "\n";

    return 0;
}


// 3. Longest Substring Without Repeating Characters
int lc_tasks::lengthOfLongestSubstring(std::string s) {
    //"abcabcbb"
    int longest = 0;
    int left = 0;
    std::unordered_map<char, int> list;
    // list[s[left]] = left;
    
    for (int right = 0; right < s.size(); right++) {
        list.insert({s[right], right});
        if (list.size() == right - left + 1) {
            if (list.size() > longest) {
                longest = list.size(); 
            }
        }
        else {
            while (list.size() != right - left + 1) {
                list.erase(s[left]);
                left++;
                list.insert({s[right], right});
            }
        }
    }
    return longest;
}


// 26. Remove Duplicates from Sorted Array
int lc_tasks::removeDuplicates(std::vector<int>& nums){
    int k = 1;
    int left = 0;
    for (int right = 0; right < nums.size(); right++) {
        if (nums[right] != nums[left]) {
            k++;
            left++;
            nums[left] = nums[right];
        }
    }
    return k;
}