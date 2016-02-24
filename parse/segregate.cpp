#include "segregate.h"

segregate::segregate()
{
    //ctor
    ip_del_file.open("input_for_del.sql", ios::out);
    ip_ins_file.open("input_for_ins.sql", ios::out);
    ip_up_file.open("input_for_update.sql", ios::out);

    ins_count = 0;
    del_count = 0;
    update_count = 0;
    comment_count = 0;
}

segregate::~segregate()
{
    //dtor
    ip_del_file.close();
    ip_ins_file.close();
}

void segregate::create_separate_inputs()
{
    ifstream yourfile("inputSQL.txt");

    string word;
    string check;
    char ch;

    if(yourfile.is_open())
    {
        while(yourfile >> word)
        {
            check = word;
            for(unsigned int i=0; i < word.length(); i++)
                check[i] = toupper(check[i]);

            if(check == "INSERT")
            {
                ins_count++;

                ip_ins_file<< endl<<check;
                yourfile.get(ch);
                ip_ins_file.put(ch);
                while(ch != ';')
                {
                    yourfile.get(ch);
                    ip_ins_file.put(ch);
                }
            }

            if(check == "DELETE")
            {
                del_count++;

                ip_del_file<< endl<<check;
                yourfile.get(ch);
                ip_del_file.put(ch);
                while(ch != ';')
                {
                    yourfile.get(ch);
                    ip_del_file.put(ch);
                }
            }

            if(check == "UPDATE")
            {
                update_count++;

                ip_up_file<< endl<<check;
                yourfile.get(ch);
                ip_up_file.put(ch);
                while(ch != ';')
                {
                    yourfile.get(ch);
                    ip_up_file.put(ch);
                }
            }



            if(check.substr (0, 2) == "--")
            {
                comment_count++;

                yourfile.get(ch);

                while(ch != '\n')
                {
                    yourfile.get(ch);
                }
            }
        }
    }
    yourfile.close();
    cout<<"The Total no of Insert Queries are : "<<ins_count;
    cout<<endl<<"The Total no of Delete Queries are : "<<del_count;
    cout<<endl<<"The Total no of Update Queries are : "<<update_count;
    cout<<endl<<"The Total no of Comments are : "<<comment_count;
}
