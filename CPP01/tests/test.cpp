#include <bits/stdc++.h>
using namespace std;

int fixedPoint(vector<int> &arr) {

    int low = 0, high = arr.size() - 1;

    while (low <= high) {
        int mid = (low + high) / 2;
		cout<<mid<<endl;
        if (arr[mid] == mid)
            return mid;
        else if (arr[mid] < mid)
            low = mid + 1;
        else
            high = mid - 1;
    }

    // If no fixed point is found
    return -1;
}

int main()
{
    vector<int> arr = { -10, -5, 0, 3, 7};
    cout<<fixedPoint(arr);
    return 0;
}