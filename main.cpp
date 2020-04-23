//
//  main.cpp
//  MinStack
//
//  Created by Priyanka Dhapare on 19/04/20.
//  Copyright © 2020 Priyanka Dhapare. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class MinStack {
public:
    vector <int> vec;
    MinStack() {
        
    }
    
    void push(int x) {
        vec.push_back(x);
    }
    
    void pop() {
        vec.pop_back();
        
    }
    
    int top() {
        size_t n = vec.size();
        return vec.at(n-1);
    }
    
    int getMin() {
        return *min_element(vec.begin(), vec.end());
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
