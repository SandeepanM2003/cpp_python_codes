#include<iostream>
#include<vector>

using namespace std;

int main(){

    int n; // size of array
    cin>>n;

    int nums[n];
    for(int i = 0;i<n;i++){
        cin>>nums[i]; // input of numbers
    }

    int target;
    cin>>target; // input of target

    vector<int>v; // vector to store the required indices

    for(int i = 0;i<n;i++){
        for(int j = i+1;j<n;j++){
            if(nums[i] + nums[j] == target){
                v.push_back(i);
                v.push_back(j);
                /*
                it is mentioned that only each input would have exactly one solution, 
                and you may not use the same element twice.
                */ 

            }
        }
    }

    for(int i : v){
        cout<<i<<" "; // enhanced for loop to print the indices 
    }


    return 0;
}