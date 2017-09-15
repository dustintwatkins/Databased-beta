//
//  main.cpp
//  Databased 1.1
//
//  Created by Dustin Watkins on 7/10/17.
//  Copyright © 2017 Dustin Watkins. All rights reserved.
//

#include <iostream>
#include <fstream>
#include "Parser.h"
#include "Norms.h"
#include "Person.h"
#include "Rule.h"

using namespace std;


bool isInteger(string &name_select)
{
    if(name_select.empty() || ((!isdigit(name_select[0])) && (name_select[0] != '-') && (name_select[0] != '+'))) return false ;
    
    char * p ;
    strtol(name_select.c_str(), &p, 10) ;
    
    return (*p == 0) ;
}

int prep_eval(string &name_select, vector<Person> &employees)
{
    if(isInteger(name_select))
    {
        int input = stoi(name_select) - 1;
        cout << "Evaluating " << employees[input].get_name() << endl;
        return input;
    }
    else
    {
        for(unsigned int i = 0; i < employees.size(); i++)
        {
            if(employees[i].get_name() == name_select)
            {
                cout << "Evaluating " << employees[i].get_name() << endl;
                return i;
                
            }
        }
    }
    return -1;
}


void menu(Norms &norm, vector<Person> &employees)
{
    cout  << "" << endl;
    cout  << "" << endl;
    cout << "Welcome to Databased!" << endl;
    cout << "---------------------------------" << endl;
    cout << "*****" << "       ******" << endl;
    cout << "** ***" << "      ***  **" <<endl;
    cout << "**  ***" << "     ***   **" << endl;
    cout << "**   ***" << "    ***  **" << endl;
    cout << "**    ***" << "   *** ***" << endl;
    cout << "**   ***" << "    ***  ***" << endl;
    cout << "**  ***" << "     ***   ***" <<endl;
    cout << "** ***" << "      ***  ***" <<endl;
    cout << "*****" << "       ******" <<endl;
    cout << "---------------------------------" << endl;
    cout  << "" << endl;
    cout  << "" << endl;
    
    string menu_select;
    string name_select;
    
    cout << "What do you want to evaluate?" << endl;
    cout << "1 - Employee" << endl;
    cout << "2 - Team" << endl;
    cin >> menu_select;
    
    while(menu_select != "1" && menu_select != "2")
    {
        cout << "Invalid input" << endl;
        cout << "Please input 1 or 2" << endl;
        cout << "What do you want to evaluate?" << endl;
        cout << "1 - Employee" << endl;
        cout << "2 - Team" << endl;
        cin >> menu_select;
    }
    
    if(menu_select == "1")
    {
        bool boolean = true;
        while(boolean)
        {
            //Evaluate employee
            cout << "Who do you want to evaluate?" << endl;
            for(unsigned int i = 0; i < employees.size(); i++)
            {
                cout << i+1 << " - " << employees[i].get_name() << endl;
            }
            cin >> name_select;
            
            //check if valid input
            Rule r;
            if(!r.check_input(employees, name_select))
            {
                cout << "That employee does not exist" << endl;
            }
            else
            {
                boolean = false;
            }
        }
        int index = prep_eval(name_select, employees);
        //Evaluate employee here
        Person p = employees[index];
        Rule ru;
        ru.eval_employee(p, norm);
    }
    else if(menu_select == "2")
    {
        //Evaluate team
        cout << "Eval team" << endl;
        
        for(unsigned int i = 0; i < employees.size(); i++)
        {
            Person p = employees[i];
            cout << "Evaluating " << p.get_name() << endl;
            Rule r;
            r.eval_employee(p, norm);
        }
        
    }
}

int main(int argc, const char * argv[]) {
    
    string file = argv[1];
    
//    cout << "parse" << endl;
    Parser parse(file);
//    cout << "load" << endl;
    parse.loadData(file);
//    cout << "Done Loading" << endl;
    Norms norm = parse.normVect[0];
    vector<Person> employees = parse.personVect;
    
//    norm.outputNorms();
//    cout << "Outputting Employees..." << endl;
    cout << "Total employees = " << parse.personVect.size() << endl;
//    for(unsigned int i = 0; i < parse.personVect.size(); i++)
//    {
//        parse.personVect[i].outputInfo();
//    }
    menu(norm, employees);
    
    
    return 0;
}
