#include<bits/stdc++.h>

using namespace std;

template<typename T>

void bubbleSort(vector<T> bubble){
    for(int i=0;i<bubble.size();i++){
        for(int j=0;j<bubble.size()-1;j++){
            if(bubble[j]>bubble[j+1]){
                T temp = bubble[j];
                bubble[j] = bubble[j+1];
                bubble[j+1] = temp;
            }
        }
    }
}

int main(){
    vector<int> bubble {1,3,8,2,9,2,5,6};
    bubbleSort(bubble);
    cout<<"[ ";
    for(auto &i: bubble){
        cout<<i<<" ";
    }
    cout<<" ]\n";
}