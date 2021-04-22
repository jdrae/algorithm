#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int n;
int* arr;

int main(){
    ios::sync_with_stdio(false);
	cin.tie(NULL);

    cin >> n;
    arr = new int[n](); // initialize with 0
    for(int i = 0; i<n; i++)
        cin >> arr[i];



    for(int i = 0; i<n; i++)
        cout << arr[i];
    delete[] arr;
}