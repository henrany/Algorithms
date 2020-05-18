#include<bits/stdc++.h>

using namespace std;

template<typename T>

vector<T> bubbleSort(vector<T> bubble){
    T temp;
    for(int i=0;i<bubble.size();i++){
        for(int j=0;j<bubble.size()-1;j++){
            if(bubble[j]>bubble[j+1]){
                temp = bubble[j];
                bubble[j] = bubble[j+1];
                bubble[j+1] = temp;
            }
        }
    }
    return bubble;
}

int main(){
    vector<int> bubble {1,3,8,2,9,2,5,6};
    cout<<"[ ";
    for(auto &i:bubbleSort(bubble)){
        cout<<i<<" ";
    }
    cout<<" ]\n";
}