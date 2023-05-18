#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> array = {4,-1,2,11,-6,2};
    int th = 2;
    cout << count_if(array.begin(), array.end(), [th](int arg){return abs(arg)>=th;});
    return 0;
}
