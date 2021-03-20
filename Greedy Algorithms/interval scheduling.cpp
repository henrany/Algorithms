#include<bits/stdc++.h>

std::vector<std::pair<std::string,std::pair<int,int>>>schedule;
void addJobs(int n){
    std::string a;
    int start=0,finish=0;
    std::cout<<"Enter the the schedule, the starting time and the finishing time \n";
    for(int i=0;i<n;i++){
        std::cin>>a>>start>>finish;
        schedule.push_back(std::make_pair(a,std::make_pair(start,finish)));
    }
}

bool sortFinish(const std::pair<std::string,std::pair<int,int>> &a, const std::pair<std::string,std::pair<int,int>> &b){
    return  (a.second.second < b.second.second);
}

void printIntervals(int n){
    std::vector<std::string> aux;
    std::sort(schedule.begin(),schedule.end(),sortFinish);
    aux.push_back(schedule[0].first);
    int c=0;
    for(int i=1;i<n;i++){
        if(schedule[i].second.first >= schedule[c].second.second){
            aux.push_back(schedule[i].first);
            c = i;
        }
    }
    for(int i=0;i<aux.size();i++){
        std::cout<<aux[i]<<" ";
    }
    std::cout<<"\n";
}

int main(){
    std::cout<<"Enter the number of jobs\n";
    int n;
    std::cin>>n;
    addJobs(n);
    printIntervals(n);
    schedule.clear();
}