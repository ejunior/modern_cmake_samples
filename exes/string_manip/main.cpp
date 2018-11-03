//
// Created by José Edmilson V. dos Santos Jr. on 2018-10-27.
//

#include <vector>
#include <iostream>
#include <fstream>
#include <regex>
#include <sstream>
#include <map>
#include <iomanip>

using namespace std;

void addPath(string &path, const string &token) {
    if (path.empty()) {
        //cout << "path empty "<< path << endl;
        path = token;
    } else
        path += "." + token;
}


void removePath(string &path, const string &token) {
    unsigned long pos = path.rfind(token);

    if (path == token) {
        path = "";
        return;
    }

    if (pos == 0) {
        path.erase(0, token.size() + 1);
        return;
    }

    path.erase(pos - 1, token.size() + 1);
}

inline string cleanToken(string token) {
    if (token.at(token.size() - 1) == '>')
        token = token.substr(0, token.size() - 1); //clean empty tag

    if (token.at(0) == '\"')
        token = token.substr(1, token.rfind('\"') - 1);

    if (token.at(0) == '/')
        token = token.substr(1, token.size());

    return token;
}


inline void parseTag(string tagText, string &path, map<string, string> &properties) {
    stringstream ss{tagText};
    string token, property;
    char cmd;

    while (ss.good()) {
        ss >> cmd;

        try {
            switch (cmd) {
                case '<':

                    ss >> token;
                    if (token.at(0) == '/') { //closing tag
                        removePath(path, cleanToken(token));
                    } else {
                        addPath(path, cleanToken(token));
                    }
                    break;

                case '='://rvalue

                    ss >> token;
                    properties[property] = cleanToken(token);
                    break;

                default:

                    ss >> token;

                    token = cleanToken(cmd + token);
                    //cout << "property " << path + '~' + token << endl;
                    property = path + '~' + token;

            }
        } catch (std::out_of_range &oor) {
            cout << "erro " << oor.what() << endl;
        }
    }
}

inline void readParameters(std::istream &stream, int &tagsQuantity, int &queriesQuantity) {
    stream >> tagsQuantity >> queriesQuantity;
    stream >> ws; // clean whitespaces from buffer
}

inline void changeInputBuffer(std::istream &stream, std::streambuf **original) {
    auto input = new ifstream("sample_input2.txt");
    *original = stream.rdbuf();
    stream.rdbuf(input->rdbuf());
}

inline void restoreInputBuffer(std::istream &stream, streambuf *orig) {
    stream.rdbuf(orig);
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

    std::map<string, string> properties;
    string path;

    std::streambuf *orig;
    int tagsQuantity, queriesQuantity;
    vector<string> tags{}, queries{};

    changeInputBuffer(std::cin, &orig);

    readParameters(cin, tagsQuantity, queriesQuantity);

    tags = readLinesFromInput(tagsQuantity);

    queries = readLinesFromInput(queriesQuantity);

    for (string s: tags) {
        cout << ": " << s << "\n";
        parseTag(s, path, properties);

    }

    for (string s: queries) {
        cout << "q: " << properties[s] << "\n";
    }

    restoreInputBuffer(cin, orig);   //reset to standard input again


    return 0;

}