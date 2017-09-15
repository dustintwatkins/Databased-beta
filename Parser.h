//
//  Parser.h
//  Databased 1.1
//
//  Created by Dustin Watkins on 7/11/17.
//  Copyright © 2017 Dustin Watkins. All rights reserved.
//

#ifndef Parser_h
#define Parser_h

#include <stdio.h>
#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include "Norms.h"
#include "Person.h"

using namespace std;

class Parser
{
public:
    Parser(string);
    ~Parser();
    
    vector<Norms> normVect;
    vector<Person> personVect;
    string data;
    bool newLine(char c);
    void loadData(string file);
    
    void isString(ifstream& inFile, char c);
    bool checkNorms();
    bool checkEmployee();
    //bool checkTeam();
    Norms parseNorms(ifstream& inFile, char c);
    Person parseEmployee(ifstream& inFile, char c);
    
};

#endif /* Parser_h */
