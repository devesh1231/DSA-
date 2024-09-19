#include <vector>
#include <string>
#include <unordered_map>
// one of the best question in dsa use recursion tree to undersatnd this 

using namespace std;

class Solution {
public:
    unordered_map<string, vector<int>> memo;

    vector<int> diffWaysToCompute(string expression) {
        // Check if the result for this expression is already computed
        if (memo.find(expression) != memo.end()) {
            return memo[expression];
        }

        vector<int> ans;

        // Iterate through the expression to find operators
        for (int i = 0; i < expression.length(); i++) {
            char current = expression[i];
            if (current == '+' || current == '-' || current == '*') {
                // Recursively compute the left and right parts
                vector<int> left = diffWaysToCompute(expression.substr(0, i));
                vector<int> right = diffWaysToCompute(expression.substr(i + 1));

                // Combine the results from left and right sub-expressions
                for (auto l : left) {
                    for (auto r : right) {
                        if (current == '+') {
                            ans.push_back(l + r);
                        } else if (current == '-') {
                            ans.push_back(l - r);
                        } else if (current == '*') {
                            ans.push_back(l * r);
                        }
                    }
                }
            }
        }

        // If ans is still empty, the expression is a single number
        if (ans.empty()) {
            ans.push_back(stoi(expression));
        }

        // Store the result in the memoization map
        memo[expression] = ans;

        return ans;
    }
};
