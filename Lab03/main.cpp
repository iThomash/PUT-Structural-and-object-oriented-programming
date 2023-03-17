#include <iostream>
#include <vector>
#include <iterator>
#include <random>
#include <ctime>

using namespace std;

int randomInt(int min, int max) {
  static std::default_random_engine e{static_cast<long unsigned int>(time(0))};
  std::uniform_int_distribution<int> d{min, max};
  return d(e);
}

void print_vector(vector<int> v) {
    cout << "v = [";
    for (int i =0;i<v.size()-1;i++) {
        cout << v[i] << ", ";
    }
    cout << v[v.size()-1] <<"]";
}

void print_vector_iter(vector<int> v) {
    cout << "v = [";
    vector<int>::iterator ptr;
    for (ptr =v.begin();ptr<v.end()-1;ptr++) {
        cout << *ptr << ", ";
    }
    cout << *ptr <<"]";
}

int search_vector(vector<int> v, int x) {
    int i = -1;
    for (int i=0;i<v.size();i++)
        if (v[i]==x) return i;
    return i;
}


int main()
{
    //Exercise 1
    vector<int> vec;
    for (int i =0; i<40;i++) {
        vec.emplace_back(randomInt(-20, 20));
    }
    print_vector_iter(vec);
    cout << search_vector(vec, -8);


    return 0;
}
