#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include<bits/stdc++.h>
#include "doctest.h"
#include "../sorting/bubbleSort.cpp"
#include "../sorting/insertionSort.cpp"
#include "../sorting/selectionSort.cpp"
#include "../search/search.cpp"
#include "../NumberTheory/moduloPower.cpp"

TEST_CASE("1 : Testing bubbleSort with integers"){
    vector<int> data {1,4,6,3,5,7,3,8};
    vector<int> answer {1,3,3,4,5,6,7,8};
    CHECK(bubbleSort(data) == answer);
}

TEST_CASE("2: Testing bubbleSort with doubles"){
    vector<double> data {1.3,1.8,1.2,1.4,1.5};
    vector<double> answer {1.2,1.3,1.4,1.5,1.8};
    CHECK(bubbleSort(data) == answer);
}

TEST_CASE("3: Testing linear search"){
    vector<int> data {1, 4, 6, 3, 5, 7, 3, 8};
    CHECK(search::linearSearch(data,8) == true);
    CHECK(search::linearSearch(data,10) == false);
    CHECK(search::linearSearch(data,30) == false);
}

TEST_CASE("4: Testing binary search algorithm"){
    vector<int> data {1, 4, 6, 3, 5, 7, 3, 8};
    CHECK(search::binarySearch(data,30) == false);
    CHECK(search::binarySearch(data,3) == true);
    CHECK(search::binarySearch(data,5) == true);
}

TEST_CASE("5: Testing the module power of a big number"){
    CHECK(modpow(2,4,3) == 1);
    CHECK(modpow(4,5,6) == 4);
    CHECK(modpow(6,9,7) == 6);
}

TEST_CASE("6: Testing insertion Sort"){
    vector<int> data{1, 4, 6, 3, 5, 7, 3, 8};
    vector<int> answer{1, 3, 3, 4, 5, 6, 7, 8};
    CHECK(insertionSort(data) == answer);
}

TEST_CASE("7: Testing selection sort"){
    vector<int> data{1, 4, 6, 3, 5, 7, 3, 8};
    vector<int> answer{1, 3, 3, 4, 5, 6, 7, 8};
    CHECK(selectionSort(data) == answer);
}

TEST_CASE("8: Testing Selection sort for decimal numbers"){
    vector<double> data{1.3, 1.8, 1.2, 1.4, 1.5};
    vector<double> answer{1.2, 1.3, 1.4, 1.5, 1.8};
    CHECK(selectionSort(data) == answer);
}