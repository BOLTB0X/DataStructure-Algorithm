#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(void)
{
    vector<int> arr = { 1, 2, 2, 2, 3, 5, 7 };

	cout << "lower_bound(2) : " << lower_bound(arr.begin(), arr.end(), 2) - arr.begin() << '\n';
	cout << "lower_bound(11) : " << lower_bound(arr.begin(), arr.end(), 11) - arr.begin() << '\n';

    cout << "upper_bound(2) : " << upper_bound(arr.begin(), arr.end(), 2) - arr.begin() << '\n';
	cout << "upper_bound(11) : " << upper_bound(arr.begin(), arr.end(), 11) - arr.begin() << '\n';

    return 0;
}