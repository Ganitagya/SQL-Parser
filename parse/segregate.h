#ifndef SEGREGATE_H
#define SEGREGATE_H

#include"main.h"
using namespace std;

class segregate
{
    public:
        segregate();
        virtual ~segregate();
        void create_separate_inputs();
    protected:
    private:
        ofstream ip_del_file;
        ofstream ip_ins_file;
        ofstream ip_up_file;

        int ins_count;
        int del_count;
        int update_count;
        int comment_count;

        //ifstream yourfile("inputSQL.txt");
        /*In-class initialization of non-static members can be performed using brace or equal initializers.
          The 3rd case is an instance of using equal. To do the 1st or 2nd correctly, use braces like this :
        */
};

#endif // SEGREGATE_H
