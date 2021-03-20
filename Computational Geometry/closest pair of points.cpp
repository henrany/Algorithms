#include<bits/stdc++.h>
#define max 100000000
using namespace std;

struct Point{
    int x;
    int y;
};
// Function for calculation the the distance 
double distance(Point p1, Point p2){
    return sqrt(pow((p1.x-p2.x),2)+ pow((p1.y - p2.y),2));
}

double bruteForceApproach(Point p[], int n){
    // initailize minimum distance as the maximum distance
    double min = max;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(distance(p[i],p[j]) < min){
                min = distance(p[i],p[j]);
            }
        }
    }
    return min;
}

// fuction to be used to sort the x coordinates 
int compareXcoordinates(const void *x1, const void *x2){
    Point *p1 = (Point *)x1;
    Point *p2 = (Point *)x2;
    return (p1->x - p2->y);
}

//function to be used to sort the y coordinates
int compareYCoordinates(const void *y1, const void *y2){
    Point *p1 = (Point *)y1;
    Point *p2 = (Point *)y2;
    return (p1->y - p2->y);
}

// finding the min between two values
double min(double x, double y){
    return (x<y)?x:y;
}

double halveClosest(Point strip[],int size,double d){
    double min = d;
    //if the closest point is in the halve of both sides
    // i.e within the minimum distance returned by the recursion
    // then sort the y coordinates 
    qsort(strip,size,sizeof(Point),compareYCoordinates);
    for(int i=0;i<size;i++){
        for(int j=i+1;j<size && (strip[j].y - strip[i].y) < min;j++){
            if(distance(strip[i],strip[j]) < min){
                min = distance(strip[i], strip[j]);
            }
        }
    }
    return min;
}

double closestUtility(Point p[], int n){
    //if the total pair of points is less than 3
    //then there is no need to use divide and conquer as memory will be wasted 
    //instead its better to use the brute force approach
    if(n <= 3){
        return bruteForceApproach(p,n);
    }
    //get the middle position of the points 
    //this will be used to divide the the arry into two halves 
    int mid = n/2;
    //get the midpoint element
    Point midPoint = p[mid];
    //do a recursive call on both halves of the element
    //the left half starts at the the initial position to the middle
    double leftHalve = closestUtility(p,mid);
    //the right half start from the middle to the end
    double righthalve = closestUtility(p+mid,n-mid);
    //get the minimum distance in the two halves 
    double dist = min(leftHalve,righthalve);
    Point strip[n];
    int j = 0;
    for(int i=0;i<n;i++){
        //if the closest points are between the two halves 
        if(abs(p[i].x - midPoint.x) < dist){
            strip[j] = p[i];
            j++;
        }
    }
    return min(dist,halveClosest(strip,j,dist));
}

//get the closest point
double closestPoint(Point p[], int n){
    //sort acording to the x coordinates 
    qsort(p,n,sizeof(Point),compareXcoordinates);
    return closestUtility(p,n);
}

int main(){
    Point p[] = {{2, 3}, {12, 30}, {40, 50}, {5, 1}, {12, 10}, {3, 4}}; 
    int n = sizeof(p) / sizeof(p[0]); 
    cout << "The smallest distance is " << closestPoint(p, n)<<"\n"; 
    return 0;
}