//
// Created by José Edmilson V. dos Santos Jr. on 2018-11-01.
//
#include <string>
#include <iostream>
#include <sstream>

using namespace std;

void addPath(string &path, const string &token) {
    if (path.empty()){
        //cout << "path empty "<< path << endl;
        path = token;
    }
    else
        path+= "." + token;
}


void removePath(string &path, const string &token) {
    unsigned long pos;
    pos = path.find(token);

    cout << pos << '\n';

    if (pos <= path.size()){ // if found
        if (pos == 0) {
            path.erase(pos - 1, token.size() + 1);
        }else{
            if(path.size() != token.size())
                path.erase(0, token.size()+1);
            else
                path = "";
        }
    }
}


int main(){

    using namespace std;

    std::string tag(R"(</tag1 >)");
    std::stringstream ss(tag);
    char cmd;

    std::string token;


    while (ss.good()){
        ss >> cmd;

        switch(cmd){
            case '<':
                ss >> token;
                if(token.at(0)=='/'){
                    //close tag
                    if(token.at(token.size()-1)=='>')
                        token = token.substr(1, token.size()-1);
                    else
                        token = token.substr(1, token.size());
                    cout << "closetag " << token << '\n';
                } else{
                    cout << "opentag "<< token << '\n';
                    break;
                }
            case '='://rvalue
                ss >> token;
                if (token.at(0)=='\"'){
                    token = token.substr(1,token.rfind('\"')-1);
                    cout << "value " << token << '\n';
                }
                break;
            default:
                ss >> token;
                token = cmd + token;
                cout << "property " << token << '\n';

        }

    }

    cout << "--------- add path ------" << endl;

    string path;

    addPath(path, "path1");
    cout << path << '\n';
    addPath(path, "path2");
    cout << path << '\n';
    addPath(path, "path3");
    cout << path << '\n';
    addPath(path, "path4");
    cout << path << '\n';
    addPath(path, "path5");
    cout << path << '\n';
    removePath(path, "path2");
    cout << "remove: " << path << '\n';
    removePath(path, "path1");
    cout << "remove: " << path << '\n';
    removePath(path, "path5");
    cout << "remove: " << path << '\n';
    removePath(path, "path7");
    cout << "remove: " << path << '\n';
    removePath(path, "path3");
    cout << "remove: " << path << '\n';
    removePath(path, "path4");
    cout << "remove: " << path << '\n';
    //un
    // signed long n = token.rfind('=');

    //std::cout << n << "\n";



    return 0;
}
