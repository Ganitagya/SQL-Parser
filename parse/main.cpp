#include"main.h"

int main()
{
    string word;
    word.clear();

    segregate input;
    parser segregated_input;
    //myfile.open("outputSQL.txt", ios::app);
    cout << "Entering into separate input file creation Zone!!!" << endl;
    input.create_separate_inputs();

    cout<<endl<<"Entering into parsing the segregated input files Zone!!!"<<endl;
    segregated_input.input_to_select();


   // myfile.close();

    return 0;
}

/*

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


*/


/*
void insert_to_select(string condition)
{
    string variables[100];
    string::iterator iter;

    string column_name;                                 //buffer for column name
    column_name.clear();
    int no_of_col = 0;                                  //stores the number of columns
    int no_of_values = 0;                               //stores the values
    int flag = 0;                                       //to check the completion of conditions

    for(iter = condition.begin(); iter <= condition.end() && flag == 0; iter++)
    {
        while(*iter != '(' )
            iter++;

        iter++;

        while(*iter != ')')                              //insert will not have nested braces
        {
            while(*iter != ','  && *iter != ')')             //while(*iter != ',' && *iter != ' ' && *iter != ')')
            {
                column_name += *iter;
                iter++;
            }

            variables[no_of_col] = column_name;

           // cout<<column_name<<endl;

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
              //changes
              if(*iter == '(')
              {
                  column_name += *iter;
                  iter++;
                  while(*iter != ')')
                  {
                      column_name += *iter;
                        iter++;
                  }
              }
              //changes
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

    ///////////////////////////////////////////////////////////////myfile<<variables[0]<<endl;
    for(int i= 1;i<no_of_values;i++)
    {
      /////////////////////////////////////////////////////////////myfile<<"AND "<<variables[i]<<endl;
    }
    ///////////////////////////////////////////////////////////////myfile<<")\""<<endl<<"runSQL\necho $RESULT\n";
}

*/


void delete_to_select(string condition)
{
    string::iterator iter;
    static int del_count;

    cout<<++del_count<<endl;


    for(iter = condition.begin(); iter < condition.end(); iter++)
    {
        if(*iter != ';')
        {
            //////////////////////////////////////////////////////////////////////myfile<<*iter;
        }
    }
   //////////////////////////////////////////////////////////////////////////////// myfile<<")\""<<endl<<"runSQL\necho $RESULT\n";

}


void update_to_select(string condition, string updated_word)
{
    /*string word;
    word.clear();

    string::iterator iter;
    //cout<<condition<<endl<<updated_word;

    //myfile<<updated_word;

    for(iter = condition.begin(); iter < condition.end(); )
    {
        while(*iter != ' ' && *iter != '=')
        {
            word += *iter;
            iter++;
        }

        if(word == updated_word)
        {
            while(*iter != 'a' || *iter != 'A')
        }

        else
        {
            myfile<<word;
            myfile<<*iter;
            iter++;
            word.clear();
        }


    }
*/

cout<<"Update query not updated"<<endl;
}
