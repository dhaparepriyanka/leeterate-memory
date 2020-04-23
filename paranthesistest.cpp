//
//  main.cpp
//  ParanthesisTest2
//
//  Created by Priyanka Dhapare on 19/04/20.
//  Copyright © 2020 Priyanka Dhapare. All rights reserved.
//

#include <iostream>
#include <string>
#include <stack>
using namespace std;



class Solution {
public:
   bool isValid(string s) {
             stack <char> stk1;
            stack <char> stk2;
            char curly1 {'{'};
            char curly2 {'}'};
            int flag {};
            
    // Adding contents of string to stack
            int i{0};
            for (char c: s){
                stk1.push(c);
                i++;
            }
            
    //function for checking stack validity

            while (!stk1.empty()){
                char c = stk1.top();
                if (c == ')' || c == curly2 || c ==']'){
                        stk2.push(stk1.top());
                        stk1.pop();
                    }
                
                else if (c == '('){
                            if (stk2.empty()){
                                //stk1.pop();
                                flag = 100;
                                break;
                            }
                            else if (stk2.top() == ')'){
                                stk2.pop();
                                stk1.pop();
                            }
                            else {
                                flag = 100;
                                break;
                            }
                }
        
                else if (c == curly1){
                            if (stk2.empty()){
                                //stk1.pop();
                                flag = 100;
                                break;
                            }
                            else if (stk2.top() == curly2){
                                stk2.pop();
                                stk1.pop();
                            }
                            else {
                                flag = 100;
                                break;
                            }
                        }
                
                else if (c == '['){
                            if (stk2.empty()){
                                //stk1.pop();
                                flag = 100;
                                break;
                            }
                            else if (stk2.top() == ']'){
                                stk2.pop();
                                stk1.pop();
                            }
                            else {
                                flag = 100;
                                break;
                            }
                        }
                
                }
       
            
    // returning true or false
       if ((flag == 100) || (stk1.size() != 0) || (stk2.size() != 0)){
                cout<<"false";
                return false;
            }
            else {
                cout<<"true";
                return true;
            }
            
        }
         
    };



int main() {
    // insert code here...
    Solution sol;
    sol.isValid("))");

    return 0;
}

