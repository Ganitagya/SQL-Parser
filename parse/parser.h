#ifndef PARSER_H
#define PARSER_H

#include<iostream>
#include"main.h"
using namespace std;

class parser
{
    public:
        parser();
        virtual ~parser();

        string genCondition();
        void input_to_select();
        void insert_to_select(string);
        void delete_to_select(string);
        void update_to_select(string, string);

    protected:
    private:

};

#endif // PARSER_H
