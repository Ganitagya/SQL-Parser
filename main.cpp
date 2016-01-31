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

                check = word;
                for(unsigned int i=0; i < word.length(); i++)
                    check[i] = toupper(check[i]);

                if(check == "INSERT")
                {
                    myfile<<endl<<"--It is an insert query"<<endl;
                    yourfile >> word >>word;
                    myfile << "SELECT COUNT(*) cnt FROM " << word << " WHERE "<<endl;
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
    string::iterator iter;

    string column_name;                                 //buffer for column name
    int no_of_col = 0;                                  //stores the number of columns
    int no_of_values = 0;                               //stores the values
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

    //Till now we have fetched the column names
    //Now working on fetching the values and storing them

    while (*iter != '(')
    {
      iter++;
    }

    iter++;                                                 //To jump over 'VALUES ('

    column_name.clear();

    while(iter < condition.end() && no_of_col >0)
    {
        while(*iter != ',' && no_of_col>0 && *iter !=')')                                //&& *iter != ' ' && *iter != ')')//as they may come in between ''
        {
          if(*iter == 39)
          {
            do
            {
              column_name += *iter;
              iter++;
            }while(*iter != 39);

            column_name += *iter;
            iter++;
          }

          else
          {
            column_name += *iter;
            iter++;
          }
        }

        variables[no_of_values] += " = ";
        variables[no_of_values] += column_name;
        column_name.clear();

        no_of_col--;
        no_of_values++;

        iter++;
    }

    myfile<<variables[0]<<endl;
    for(int i= 1;i<no_of_values;i++)
    {
      myfile<<"AND "<<variables[i]<<endl;
    }
}
