/*
You are given N integers in the sorted order. Then you are given Q queries. In each query you will be given an integer and you have to tell whether that integer is present in the array, if so you have to tell at which index it is present and if it is not present you have to tell the index at which the smallest integer that is just greater than the given number is present.
Lower bound is a function that can be used with a sorted vector. Learn how to use lower bound to solve this problem by Clicking Here.

Input Format

The first line of the input contains the number of integers N. The next line contains N integers in sorted order. The next line contains Q, the number of queries. Then Q lines follow each containing a single integer Y.
If the same number is present multiple times, you have to print the first index at which it occurs.
The input is such that you always have an answer for each query.

Constraints:

1 <= N <= 10^5
1 <= Xi <= 10^9 ,where Xi is ith element in the array.
1 <= Q <= 10^5
1 <= Y <= 10^9

Output Format

For each query you have to print "Yes"(without the quotes)if the number is present and at which index(1-based) it is present separated by a space.
If the number is not present you have to print "No"(without the quotes) followed by the index of the next smallest number just greater than that number.
You have to output each query in a new line.

Sample Input

 8
 1 1 2 2 6 9 9 15
 4
 1
 4
 9
 15
Sample Output

 Yes 1
 No 5
 Yes 6
 Yes 8
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    
    int num_of_integers, num;
    
    cin >> num_of_integers; // Input number of integers in the vector.
    vector<int> v;
    /*
        Vectors use contiguous storage locations for their elements, which
        means that their elements can also be accessed using offsets on regular
        poiners to its elements, more more efficiently as in arrays. We use
        vectors because they have everything arrays have but they also guarantee
        that the elements will be contiguously stored in memory.
        Using arrays are a C-style way of coding and vectors are C++ which
        utilizes the STL library which is much better.
    */
    //vector<int> v is a single vector. (1D vectors)
    //vector<int> V[] is an array of vectors. (2D array of vectors)
    //vector< vector<int> > V is a vector of vectors. (2D vector of vectors)
    
    //Input all numbers into the 1D-vector.
    for(int i = 0; i < num_of_integers; i++){
        cin >> num;
        v.push_back(num);
    }
    
    int num_of_queries ,val;
    cin >> num_of_queries; //Input how many queries
    
    //Search if it exists. If it doesn't find one that is
    //just greater than it and print it's index.
    for(int i = 0; i < num_of_queries; i++){
        cin >> val; //Input numbers to be searched.
        vector<int>::iterator low = lower_bound(v.begin(), v.end(), val);
        if (v[low - v.begin()] == val)
            cout << "Yes " << (low - v.begin()+1) << endl;
        else
            cout << "No " << (low - v.begin()+1) << endl;
    }
    return 0;
}
