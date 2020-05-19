#include<bits/stdc++.h>

using namespace std;

template<typename T>

vector<T> selectionSort(vector<T> selection){
    T temp;
    for(int i=0;i<selection.size()-1;i++){
        T min = i;
        for(int j=min+1;j<selection.size();j++){
            if(selection[j] < selection[min]){
                temp = selection[j];
                selection[j] = selection[min];
                selection[min] = temp; 
            }
        }
    }
    return selection;
}

int main(){
    vector<int> select {50,50,50,3,3,3,4,5,6,3,2,4,6,3,12,6,6,4,};
    for(auto &i:selectionSort(select)){
        cout<<i<<" ";
    }
    cout<<"\n";
}