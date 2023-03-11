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
    std::fstream file("C:/Users/iThomash/Desktop/Politechnika Poznanska/Programowanie strukturalne i obiektowe/Lab02/data/kursy_usd_eur.csv", std::fstream::in);
    std::vector<Exchange_rate> rates;
    if (file.is_open()) {
        std::string line;
        std::getline(file, line); // wczytuje pierwszą linię z nagłówkiem i ją ignoruje
        while (std::getline(file, line)) {//wczytuje kolejne linie aż do końca pliku
            std::stringstream str(line);//tworzy strumień, którego źródłem jest wczytana linia

            Exchange_rate er;
            std::getline(str, er.date, ','); //wczytuje date (pierwszy element wiersza)
            std::string double_str;
            std::getline(str, double_str, ',');  // wczytuje kurs USD (jako tekst)
            er.usd = std::stod(double_str);      //zamiana na string->double
            std::getline(str, double_str, ',');  // wczytuje kurs EUR (jako tekst)
            er.eur = std::stod(double_str);      //zamiana na string->double
            std::getline(str, er.table_id, ','); // wczytuje ostatnią kolumnę z numerem tabeli NBP
            rates.emplace_back(er); //dodaje element do kolekcji
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

double pow(double base, int power) {
   if (power == 0) return 1;
   else return (base * pow(base, power-1));
}

double poly(double x,vector<double> p) {
    double y=0.0;
    for (int i =0; i<=p.size()-1; i++) {
        y+=pow(x, p.size()-i-1) * p[i];
    }
    return y;
}

vector<double> zero(double &x_min, double &x_max, vector<double> &p, double &step) {
    vector<double> zeros;
    double x1 = x_min, x2 = x_min+step;
    while (x1<=x_max) {
        x1 = x1 + step;
        x2 = x2 + step;
        if (poly(x1, p) * poly(x2, p) == 0) {
            zeros.emplace_back(x1);
        } else if (poly(x1, p)*poly(x2, p) < 0) {
            zeros.emplace_back(x1);

        }
        //stricte optymalizacja
        if (zeros.size() == p.size()-1) break;
    }
    return zeros;
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

    //Exercise 9


    //Exercise 10
    vector<double> coefficients;
    int n;
//    cout << "Wprowadz najwieksza liczbe przy potedze x: ";
//    cin >> n;
//    int i = n;
//    while(i>=0) {
//        double num;
//        cout << "Wprowadz liczbe przy x^" << i << ": ";
//        cin >> num;
//        coefficients.emplace_back(num);
//        i--;
//    }

    //asumptions
    double x_min = -100.0;
    double x_max = 100.0;
    double step = 0.1;
    double approx = 1e-9;

    coefficients = {1, -21, 100};

    vector<double> zeros = zero(x_min, x_max, coefficients, step);
    for (int i =0;i<zeros.size();i++) {
        //tutaj mamy juz mniej wiecej dokladne miejsca zerowe ktore moga byc w przedziale od x do x + step
        //np. 0.6 do 0.7
        cout << zeros[i] << "\n";
    }


    return 0;
}
