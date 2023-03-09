#include <iostream>
#include <vector>
#include <cctype>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

bool is_palindrome(string str) {
    string fixed = "";
    for (int i = 0;i < str.length();i++) {
        if (str[i] != ' ') fixed += tolower(str[i]);
    }
    cout << fixed << " ";
    for (int i = 0;i < fixed.length()/2;i++) {
        if (fixed[i] != fixed[fixed.length() - i - 1]) return false;
    }
    return true;
}

vector<size_t> find_all(string text, char looking_for) {
    vector<size_t> vec;
    for (int i = 0;i < text.length(); i++) {
        if (text[i] == looking_for) vec.push_back(i);
    }

    return vec;
}

void print_vector(vector<size_t> vec) {
    for (int i = 0;i < vec.size();i++) {
        cout << vec[i] << " ";
    }
}
void print_vector(vector<string> vec) {
    for (int i = 0;i < vec.size();i++) {
        cout << vec[i] << " ";
    }
}
void print_vector(vector<int> vec) {
    for (int i = 0;i < vec.size();i++) {
        cout << vec[i] << " ";
    }
}

string find_longest_word(string text) {
    int index = -1, length = 0;
    int maxLength = 0;
    string word;
    for (int i = 0;i < text.length();i++) {
        if (text[i] != ' ') {
            length += 1;
        }
        else
        {
            length = 0;
        }
        if (maxLength < length) {
            index = i - length;
            maxLength = length;
        }
    }

    return text.substr(index + 1, maxLength);
}

vector<string> split(string sentence, char separator = ' ') {
    vector<string> vec;
    int index = -1;
    int length = 0;
    for (int i = 0;i < sentence.length();i++) {
        if (sentence[i] != separator) {
            length += 1;
        }
        else
        {
            vec.push_back(sentence.substr(index + 1, length));
            length = 0;
            index = i;
        }
    }
    vec.push_back(sentence.substr(index + 1, length));
    return vec;
}

string find_and_replace(string text, string from, string to) {
    string sentence = text, tempText="";
    while (sentence!=tempText) {
        size_t found = sentence.find(from);
        if (found != string::npos) {
            sentence = sentence.substr(0, found) + to + sentence.substr(found + from.length());
        }
        else {
            tempText = sentence;
        }
    }
    return sentence;
}

vector<int> bubble_sort(vector<int> vec) {
    for (int i = 0;i < vec.size();i++) {
        for (int j = i + 1;j < vec.size();j++) {
            if (vec[i] > vec[j]) {
                int temp = vec[j];
                vec[j] = vec[i];
                vec[i] = temp;
            }
        }
    }
    return vec;
}

int binarySearch(vector<double> array, double x) {
    int low = 0;
    int high = array.size() - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        //cout << low << " " << mid << " " << high << " value: " << (array[mid]<x) << "\n";
        if (array[mid] == x) return mid;

        if (array[mid] < x) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return -1;
}

struct Exchange_rate
{
    string date;
    double usd;
    double eur;
    string table_id;
};

void print_rates(vector<Exchange_rate> rates) {
    for (int i = 0; i < rates.size();i++) {
        cout << rates[i].date << ";" << rates[i].eur << "," << rates[i].table_id << "," << rates[i].usd << "\n";
    }
}

vector<Exchange_rate>  read_file() {
    fstream file("./data/kursy_usd_eur.csv", fstream::in);
    vector<Exchange_rate> rates;
    if (file.is_open()) {
        string line;
        getline(file, line);
        while (getline(file, line)) {
            stringstream str(line);

            Exchange_rate er;
            getline(str, er.date, ',');
            string double_str;
            getline(str, double_str, ',');
            er.usd = stod(double_str);
            getline(str, double_str, ',');
            er.eur = stod(double_str);
            getline(str, er.table_id, ',');
            rates.emplace_back(er);
        }
    }
    return rates;
}

void sort_usd(vector<Exchange_rate> &rates) {
    for (int i = 0;i < rates.size() ;i++) {
        for (int j = i; j < rates.size(); j++) {
            if (rates[i].usd > rates[j].usd) {
                Exchange_rate temp = rates[j];
                rates[j] = rates[i];
                rates[i] = temp;
            }
        }
    }
}

void sort_eur(vector<Exchange_rate>& rates) {
    for (int i = 0;i < rates.size();i++) {
        for (int j = i; j < rates.size(); j++) {
            if (rates[i].eur > rates[j].eur) {
                Exchange_rate temp = rates[j];
                rates[j] = rates[i];
                rates[i] = temp;
            }
        }
    }
}

void print_top(vector<Exchange_rate>& rates, int n =10) {
    for (int i = rates.size() -1; i > rates.size() - n;i--) {
        cout << rates[i].date << "\n";
    }
}

int binary_search(vector<Exchange_rate> array, double x) {
    int low = 0;
    int high = array.size() - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (array[mid].usd == x) return mid;

        if (array[mid].usd < x) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }

    return -1;
}

int main(void) {

    //Exercise 1
    /*
    string word = "racecar";
    if (is_palindrome(word)) {
        cout << "To palindrom!" << endl;
    }
    else {
        cout << "Nope" << endl;
    }
    string sentence = "Never odd or even";
    cout << is_palindrome(sentence);
    */

    //Exercise 2
    /*
    string input = "Ala ma kota";
    vector<size_t> pos = find_all(input, 'a');
    print_vector(pos);
    */

    //Exercise 3
    /*
    std::string input = "Ala ma kota kot jezdzia na Roombie";
    std::string longest = find_longest_word(input);
    cout << longest;
    */

    //Exercise 4
    /*
    std::string sentence = "Ala ma kota";
    std::vector<std::string> words = split(sentence);
    print_vector(words); cout << "\n";
    std::string csv = "Mount Everest,8848,1953";
    std::vector<std::string> data = split(csv, ',');
    print_vector(data);
    */

    //Exercise 5
    //Nie dziala na rekurencyjnych przypadkach XD
    /*
    string input = "Ala ma kota, kot zjadl Ale!";
    string output = find_and_replace(input, "kot", "hefalump");
    cout << output;
    */

    //Exercise 6
    /*
    vector<int> v = { 0 ,100 , 12, 32 ,41, 2, 41, 56, 12 , 13 };
    vector<int> sorted = bubble_sort(v);
    print_vector(sorted);
    */

    //Exercise 7
    /*
    vector<double> set_of_number = { 1, 1.2, 1.3, 1.5, 1.8, 2 };
    cout << binarySearch(set_of_number, 1.8);
    */

    //Exercise 8

    vector<Exchange_rate> rates = read_file();
    cout << rates[0].usd;

    /*
    sort_usd(rates);
    //print_top(rates);

    //sort_eur(rates);
    //print_top(rates);
    double ex = 3.9011;
    int index = binary_search(rates, ex);
    if (index != -1) cout << rates[index].date << " " << rates[index].eur << " " << rates[index].table_id << " " << rates[index].usd;
    else cout << "No results found";
    */



    return 0;
}
