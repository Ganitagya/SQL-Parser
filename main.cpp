#include"main.h"

int main()
{
    string word;
    word.clear();

    myfile.open("outputSQL.txt", ios::app);
    cout << "Entering into file creation Zone!!!" << endl;

    if(yourfile.is_open())
    {
        while(yourfile >> word)
        {
            checkQuery(word);
        }
    }

    myfile.close();
    yourfile.close();
    return 0;
}


void checkQuery(string word)
{
        string check;

                check = word.substr(0,6);
                for(int i=0; i < 6; i++)
                    check[i] = toupper(check[i]);

                if(check == "INSERT")
                {
                    myfile<<"--It is an insert query"<<endl;
                    yourfile >> word >>word;
                    myfile << "SELECT * FROM " << word << " WHERE ";
                    insert_to_select(genCondition());
                }
}

string genCondition()
{
    char ch;
    string condition;
    yourfile.get(ch);

    while(ch != ';')
    {
        condition += ch;
        yourfile.get(ch);
    }
    condition += ch;

    return condition;
}

void insert_to_select(string condition)
{
    string variables[100];
    //string values[100];
    string::iterator iter;

    string column_name;                                 //buffer for column name
    int no_of_col = 0;                                  //stores the number of columns
    int flag = 0;                                       //to check the completion of comditions

    for(iter = condition.begin(); iter <= condition.end() && flag == 0; iter++)
    {
        while(*iter != '(' )
            iter++;

        iter++;

        while(*iter != ')')                                 //insert will not have nested braces
        {
            while(*iter != ',' && *iter != ' ' && *iter != ')')
            {
                column_name += *iter;
                iter++;
            }

          //  variables[no_of_col] = column_name.c_str();

            variables[no_of_col] = column_name;
            column_name.clear();

            no_of_col++;                                       //for storing the next column name

            while(*iter != ',' && *iter != ')')
            {
                iter++;
            }

            if(*iter == ',') iter++;                        //to cross the comma

            while(*iter == ' ') iter++;                     //ignore spaces
        }
            flag = 1;
    }

    for(int i= 0;i<no_of_col;i++)
    {
      cout<<variables[i]<<endl;
    }
}
