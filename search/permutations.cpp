#include<bits/stdc++.h>

void print(int arr[], int size){
    int i,j;
    for(i=0; i<size; i++){
       std::cout<<arr[i]<<" ";
    }
    std::cout<<"\n";
}

//function to swap the variables
void swap(int *a, int *b){
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

//permutation function
void permutation(int *arr, int start, int end){
    if(start==end){
        print(arr, end+1);
        return;
    }
    for(int i=start;i<=end;i++){
        //swapping numbers
        swap((arr+i), (arr+start));
        //fixing one first digit
        //and calling permutation on
        //the rest of the digits
        permutation(arr, start+1, end);
        swap((arr+i), (arr+start));
    }
}

int main(){
    //taking input to the array
    int size;
    std::cin>>size;
    int i;
    int arr[size];
    for(i=0;i<size;i++)
        std::cin>>arr[i];
    //calling permutation function
    permutation(arr, 0, size-1);
    return 0;
}