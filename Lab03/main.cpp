#include <iostream>
#include <vector>
#include <iterator>
#include <random>
#include <ctime>
#include <list>
#include <algorithm>
#include <iomanip>

using namespace std;

int randomInt(int min, int max) {
  static std::default_random_engine e{static_cast<long unsigned int>(time(0))};
  std::uniform_int_distribution<int> d{min, max};
  return d(e);
}

void print_vector(vector<int> v) {
    cout << "\nv = [";
    for (int i =0;i<v.size()-1;i++) {
        cout << v[i] << ", ";
    }
    cout << v[v.size()-1] <<"]\n";
}

void print_vector_iter(vector<int> v) {
    cout << "\nv = [";
    vector<int>::iterator ptr;
    for (ptr =v.begin();ptr<v.end()-1;ptr++) {
        cout << *ptr << ", ";
    }
    cout << *ptr <<"]\n";
}

vector<int> search_vector_and_delete(vector<int> v, int x) {
    //reimplemented version of exercise 1
    vector<int>::iterator ptr;
    while (ptr != v.end()) {
        ptr = find(v.begin(), v.end(), x);
        if (ptr != v.end()) {
            v.erase(ptr);
        }

    }
    return v;
}

void print_vector_iter(list<int> v) {
    cout << "\nv = [";
    for (auto it = v.begin();it!=v.end();it++) {
        cout << " " << *it ;
    }
    cout <<"]\n";
}

list<int> search_vector_and_delete(list<int> v, int x) {
    for (auto it = v.begin();it!=v.end();it++) {
        if (*it==x) {
            v.erase(it);
        }
    }
    return v;
}

int min(vector<int> v) {
    vector<int>::iterator ptr;
    ptr = min_element(v.begin(), v.end());
    return *ptr;
}

int max(vector<int> v) {
    vector<int>::iterator ptr;
    ptr = max_element(v.begin(), v.end());
    return *ptr;
}

enum class TypRosliny { Owoc, Warzywo };

struct Roslina {
    TypRosliny typ;
    std::string nazwa;
};

using Koszyk = std::vector<Roslina>;

int main()
{
    //Exercise 1
    /*
    vector<int> vec;
    for (int i =0; i<40;i++) {
        vec.emplace_back(randomInt(-20, 20));
    }
    print_vector_iter(vec);
    print_vector(search_vector_and_delete(vec, 0));
    */

    //Exercise 2
    /*
    std::list<int> lst;
    for (int i =0; i<40;i++) {
        lst.emplace_back(randomInt(-20, 20));
    }
    print_vector_iter(lst);
    print_vector_iter(search_vector_and_delete(lst, 0));
    */

    //Exercise 3
    /*
    vector<int> vec;
    for (int i =0; i<40;i++) {
        vec.emplace_back(randomInt(-20, 20));
    }
    print_vector_iter(vec);
    print_vector_iter(search_vector_and_delete(vec, 0));
    */

    //Exercise 4
    /*
    vector<int> vec;
    for (int i =0; i<40;i++) {
        vec.emplace_back(randomInt(-20, 20));
    }
    print_vector(vec);
    cout << "Min: " << min(vec) << " \nMax: " << max(vec) << "\n";
    auto [min, max] = minmax_element(begin(vec), end(vec));
    cout << "Min: " << *min << " \nMax: " << *max << "\n";
    */

    //Exercise 5
    //Nie chce mi sie

    //Exercise 6
    //Tez mi sie nie chce

    //Exercise 7
    //O ciekawsze zadanie
    Koszyk koszyk;

    return 0;
}
