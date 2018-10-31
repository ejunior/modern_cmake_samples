//
// Created by José Edmilson V. dos Santos Jr. on 2018-10-27.
//

#include <cmath>
#include <cstdio>
#include <vector>
#include <tuple>
#include <iostream>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <regex>

using namespace std;

vector<int> parseInts(string str) {
    stringstream ss{str};
    vector<int> numbers;

    while (ss) {
        int a;
        char ch;
        ss >> a >> ch;
        numbers.push_back(a);
    }

    return numbers;
}


void changeInputBuffer(std::istream &stream, std::streambuf **original, ifstream &txtbufer) {
         *original = stream.rdbuf();
        stream.rdbuf(txtbufer.rdbuf());
}


void restoreInputBuffer(std::istream& stream, streambuf* orig) {
    stream.rdbuf(orig);
}



void readParameters(std::istream& stream, int &tagsQuantity, int &queriesQuantity) {
    stream >> tagsQuantity >> queriesQuantity;
    stream >> ws; // clean whitespaces from buffer
}


int main() {

    ifstream input("sample_input.txt");

    std::streambuf *orig;
    vector<string> tags{}, queries{};
    int tagsQuantity, queriesQuantity;


    changeInputBuffer(std::cin, &orig, input);

    readParameters( cin, tagsQuantity, queriesQuantity);

    for (int i = 0; i < tagsQuantity; i++) {
        string tag;
        getline(cin, tag);
        tags.push_back(tag);
    }

    for (int i = 0; i < queriesQuantity; i++) {
        string query{};
        getline(cin, query);
        queries.push_back(query);
    }

    for (string s: tags) {
        cout << "t: " << s << "\n";
    }

    for (string s: queries) {
        cout << "Q: " << s << "\n";
    }

    restoreInputBuffer(cin, orig);   //reset to standard input again

    return 0;

}