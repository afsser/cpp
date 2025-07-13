#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <string>
#include <cstdio>

int main(int argc, char **argv) {
    if (argc != 2) {
        std::cout << "./rpn_tester <number of operators>\n";
        return 1;
    }
    int n_ops = std::atoi(argv[1]);
    if (n_ops < 1) {
        std::cout << "Number of operators must be >= 1\n";
        return 1;
    }
    srand(time(NULL));
    std::string operators = "+-*/";
    std::vector<std::string> nums;
    std::vector<std::string> ops;

    // Generate N+1 numbers (from 1 to 9)
    for (int i = 0; i < n_ops + 1; ++i) {
        char buf[4];
        sprintf(buf, "%d", 1 + rand() % 9);
        nums.push_back(std::string(buf));
    }
    // Generate N operators
    for (int i = 0; i < n_ops; ++i)
        ops.push_back(std::string(1, operators[rand() % 4]));

    // Build expression: start with two numbers, then alternate
    std::string expr = nums[0] + " " + nums[1];
    int num_idx = 2, op_idx = 0;
    while (op_idx < n_ops) {
        expr += " " + nums[num_idx++];
        expr += " " + ops[op_idx++];
    }

    std::cout << expr << std::endl;
    return 0;
}