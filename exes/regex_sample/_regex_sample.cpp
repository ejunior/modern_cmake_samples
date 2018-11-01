//
// Created by José Edmilson V. dos Santos Jr. on 2018-10-27.
//

#include <vector>
#include <iostream>
#include <fstream>
#include <regex>
#include <sstream>

using namespace std;


vector<string> keys, values;
string name;

void parseTag(string tagText) {
    int index = 0;

    stringstream ss{tagText};
    string token;

    while (ss >> token) {
        if (token.substr(0, 2) == "</") {
            //todo: encolher a hierarquina dos nomes
            //name.replace("","")

        } else if (token.substr(0, 1) == "<") {
            token = token.substr(1, token.size());
            name += (name.empty())? token: "."+ token;
            cout << name <<'\n';
        }
        else if(token.find('='))
            cout << token << '\n';
    }
}


inline void changeInputBuffer(std::istream &stream, std::streambuf **original) {
    auto input = new ifstream("sample_input.txt");
    *original = stream.rdbuf();
    stream.rdbuf(input->rdbuf());
}


void restoreInputBuffer(std::istream &stream, streambuf *orig) {
    stream.rdbuf(orig);
}


inline void readParameters(std::istream &stream, int &tagsQuantity, int &queriesQuantity) {
    stream >> tagsQuantity >> queriesQuantity;
    stream >> ws; // clean whitespaces from buffer
}


inline vector<string> readLinesFromInput(int lines) {
    vector<string> v;
    for (int i = 0; i < lines; i++) {
        string query{};
        getline(cin, query);
        v.push_back(query);
    }
    return v;
}

int main() {

    std::streambuf *orig;
    int tagsQuantity, queriesQuantity;
    vector<string> tags{}, queries{};

    changeInputBuffer(std::cin, &orig);

    readParameters(cin, tagsQuantity, queriesQuantity);

    tags = readLinesFromInput(tagsQuantity);

    queries = readLinesFromInput(queriesQuantity);

    for (string s: tags) {
        parseTag(s);
        cout << ": " << s << "\n";
    }

    for (string s: queries) {
        cout << "q: " << s << "\n";
    }

    restoreInputBuffer(cin, orig);   //reset to standard input again


    return 0;

}