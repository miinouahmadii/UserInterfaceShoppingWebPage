#ifndef COMMENT_H
#define COMMENT_H

#include <string>
#include <vector>
#include <map>
using namespace std;


class comment {
public:
    comment(string _comment, string _user){
        user=_user;
        comments=_comment;
    }
    int return_id();
    string return_user();
    string return_comment();

private:
    int id;
    string user;
    string comments;

};
#endif