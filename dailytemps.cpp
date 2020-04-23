//
//  main.cpp
//  DailyTempereatures
//
//  Created by Priyanka Dhapare on 21/04/20.
//  Copyright © 2020 Priyanka Dhapare. All rights reserved.
//

#include <iostream>
#include <vector>
#include <stack>
using namespace std;


class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        
        int n = static_cast<int>(T.size());
        vector<int> result (n, 0);
        
        for (int i = n-2; i>=0; i-- ){
            
            if(T.at(i)<T.at(i+1)){
                result.at(i) = 1;
            }
            
            else {
                for (int j=i+1; (j<n-1 && result.at(j)!=0) ; j = j + result.at(j)){
                    if ( T.at(i)<T.at(j+ result.at(j)) ){
                        result.at(i) = j + result.at(j) - i;
                        break;
                    }
                }
            }
            
            
        }
        
        
        for(auto c: result){cout<<c<<" ";}
        
        return result;
    }
};


int main(int argc, const char * argv[]) {
    
    vector<int> vec{73, 74, 75, 71, 71, 72, 76, 73};
    
    Solution sol;
    sol.dailyTemperatures(vec);
    
    return 0;
}
