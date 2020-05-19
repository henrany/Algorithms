#include<bits/stdc++.h>

using namespace std;

template<typename T>

vector<T> selectionSort(vector<T> selection){
    T temp;
    for(int i=0;i<selection.size();i++){
        T min = i;
        for(int j=min;j<selection.size()-1;j++){
            if(selection[j] > selection[j+1]){
                temp = selection[min];
                selection[min] = selection[j+1];
                selection[j+1] = temp; 
            }
        }
    }
    return selection;
}

int main(){
    vector<int> select {9,8,7,6,5,4,3,2,1,3,3,3,3,3};
    for(auto &i:selectionSort(select)){
        cout<<i<<" ";
    }
    cout<<"\n";
}