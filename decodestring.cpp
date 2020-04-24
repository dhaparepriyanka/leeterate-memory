//
//  main.cpp
//  DecodeString
//
//  Created by Priyanka Dhapare on 21/04/20.
//  Copyright © 2020 Priyanka Dhapare. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;


class Solution {
public:
    string decodeString(string s) {
        string numstr{""}, alphastr{""}, finalstr{""};
       // vector<char> vec;
        int num {}, flag{100};
        
        
        //decode
        for (int i=0; s[i]!= '\0'; i++){
            //for digit
            if (isdigit(s[i])!= 0){
                numstr += s[i];
                flag =0;
            }
            
            //for open braces
            else if (s[i] == '['){
                if (numstr.length()==0){num = 1;}
                else{
                    num = stoi(numstr);
                    numstr = "";
                }
            }
            
            //for alphabet
            else if (isalpha(s[i])!=0){
                if(flag ==100){
                    finalstr += s[i];
                }
                else {
                    alphastr += s[i];
                }
            }
            
            //for close braces
            else if (s[i]==']'){
                while (num!=0){
                    finalstr += alphastr;
                    num--;
                }
                alphastr = "";
                flag = 100;
            }
            
            
            
        }//for loop end
                
        return finalstr;
    }
};

int main(int argc, const char * argv[]) {
    Solution sol;
    sol.decodeString("2[ab]4[c][ef]");
    
    return 0;
}
