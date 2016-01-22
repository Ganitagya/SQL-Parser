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
    char* variables[100];
    string values[100];
    string::iterator iter;
    int index = 0;
    int column = 0;                                     //stores the column name
    int flag = 0;                                       //to check the completion of comditions

    for(iter = condition.begin(); iter < condition.end(); iter++)
        myfile<<*iter;


    for(iter = condition.begin(); iter <= condition.end() && flag == 0; iter++)
    {
        while(*iter != '(' )
            iter++;

        iter++;
        
        while(*iter != ')')                                 //insert will not have nested braces
        {
            /*
            while(*iter != ',' || *iter != ' ')
            {
                variables[column][index++] += *iter;
                iter++;
            }

            variables[column][index] += '\0';
            column++;                                       //for storing the next column name
            index = 0;

            while(*iter != ',') iter++;
            iter++;                                         //to cross the comma

            while(*iter == ' ') iter++;                     //ignore spaces*/

            cout<<*iter++;
        }
            flag = 1;
    }
}

