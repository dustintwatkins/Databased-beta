//
//  Parser.cpp
//  Databased 1.1
//
//  Created by Dustin Watkins on 7/11/17.
//  Copyright © 2017 Dustin Watkins. All rights reserved.
//

#include "Parser.h"
#include "Norms.h"
#include <cctype>

Parser::Parser(string file)
{
    
}

Parser::~Parser()
{
    
}

bool Parser::newLine(char c)
{
    if(c == '\n')
    {
        return true;
    }
    return false;
}

void Parser::loadData(string file)
{
//    cout << "loading Data... " << endl;
    ifstream inFile(file);
    
    string line;
    while(!inFile.eof())
    {
//        cout << "getting char..." << endl;
        char c = inFile.get();
//        cout << c << endl;
        
        if(newLine(c) || isspace(c))
        {
            //do nothing
            //go to next char
        }
        else
        {
            if(isalpha(c))
            {
                //Char is a letter
                //Parse for phrase
                isString(inFile, c);
            }
            else if(isdigit(c))
            {
//                cout << "isdigit...?" << endl;
                //Char is a digit
                // parse for data
                
            }
            
        }//end of first else statement
    }//End of while loop
}//End of loadData function

bool Parser::checkNorms()
{
    if(data == "Norms")
    {
        return true;
    }
    return false;
}

bool Parser::checkEmployee()
{
    if(data == "Employees")
    {
        return true;
    }
    return false;
}

void Parser::isString(ifstream& inFile, char c)
{
//    cout << "isstring... " << endl;
    bool boolean = true;
    while(boolean)
    {
        data += c;
        char p = inFile.peek();
        if(isalpha(p))
        {
            c = inFile.get();
        }
        else
        {
            //Exit loop
            boolean = false;
        }
        
    }
    if(checkNorms())
    {
//        cout << "is norms" << endl;
        //String is "Norms"
        //The following numbers are the industry norms
//        cout << "String is special 'Norms'" << endl;
        Norms norm = parseNorms(inFile, c);
        normVect.push_back(norm);
    }
    else if(checkEmployee())
    {
//        cout << "is employee" << endl;
        //string is a name of an employee
        while(c != '?')
        {
            Person p = parseEmployee(inFile, c);
            personVect.push_back(p);
            c = inFile.get();
        }
//        cout << personVect.size() << endl;
    }
    data.clear();
}

Norms Parser::parseNorms(ifstream& inFile, char c)
{
//    cout << "Entered Parse Norms" << endl;
    //Consume newline character
    c = inFile.get();
    if(c == '\n')
    {
        c = inFile.get();
    }
    
    vector<string> norms;
    vector<double> skills;
    string n;
    bool boolean = true;
    while(boolean)
    {
        double dub = 0;
        n += c;
        c = inFile.get();
        if(isspace(c))
        {
            skills.push_back(dub);
            norms.push_back(n);
            n.clear();
            c = inFile.get();
            
            if(isspace(c))
            {
                while(isspace(c))
                {
                    c = inFile.get();
                }
            }
        }
        if(c == '$')
        {
            boolean = false;
        }
    }//end of while loop
    
    for(unsigned int i = 0; i < norms.size(); i++)
    {
        skills[i] = stod(norms[i]);
//        cout << "skill " << i << " = " << skills[i] << endl;
    }
    
    double ansRate = skills[0];
    double setRate = skills[1];
    double showRate = skills[2];
    double opConv = skills[3];
    double closeRate = skills[4];
    double avgDealSize = skills[5];
    
    Norms* norm = new Norms(ansRate, setRate, showRate, opConv, closeRate, avgDealSize);

    return *norm;
//    Norms norm = new Norms
}

Person Parser::parseEmployee(ifstream& inFile, char c)
{
//        cout << "Entered parseEmployee... " << endl;
        c = inFile.get();

        if(c == '\n')
        {
            c = inFile.get();
        }

        vector<string> stats;
        vector<double> skills;
        string n;
        bool boolean = true;
        while(boolean)
        {
            double dub = 0;
            n += c;
            c = inFile.get();
            if(isspace(c))
            {
                skills.push_back(dub);
                stats.push_back(n);
                n.clear();
                c = inFile.get();
            
                if(isspace(c))
                {
                    while(isspace(c))
                    {
                        c = inFile.get();
                    }
                }
            }
            if(c == '$')
            {
                boolean = false;
            }
    
        }//end of inner while loop
    
        string name;
        for(unsigned int i = 0; i < stats.size(); i++)
        {
            if(i == stats.size() - 1)
            {
                name = stats[i];
            }
            else
            {
                skills[i] = stod(stats[i]);
            }
        }
    
        Person* p = new Person(skills[0], skills[1], skills[2], skills[3], skills[4], skills[5], name);
//        cout << "person created " << p->get_name() << endl;

    return *p;
}






























