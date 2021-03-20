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
