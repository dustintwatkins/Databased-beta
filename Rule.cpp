//
//  Rule.cpp
//  Databased 1.1
//
//  Created by Dustin Watkins on 7/12/17.
//  Copyright © 2017 Dustin Watkins. All rights reserved.
//

#include "Rule.h"

bool Rule::check_input(vector<Person> &employees, string &name_selector)
{
    for(unsigned int i = 0; i < employees.size(); i++)
    {
        if(name_selector == employees[i].get_name())
        {
            return true;
        }
    }
    
    int input = stoi(name_selector) - 1;
    for(unsigned int j = 0; j < employees.size(); j++)
    {
        if(input >= 0 && input < employees.size())
        {
            return true;
        }
    }
    return false;
}

Skill Rule::createSkill(string &name, double &increase, int &pLevel)
{
    Skill s;
    
    s.name = name;
    s.increase = increase;
    s.pLevel = pLevel;
    
    return s;
}

void Rule::eval_employee(Person &p, Norms &norm)
{
    //1. double diff = norm - actual
    //2. double increase = diff / actual
    //3. double increase = increase * 100
    // this gives you percent increase to reach norm
    // to find #1 skill to improve..
    //4. iterate through skills that have have >= 0 increase and corresponding
    
    vector<Skill> skills;
    
    if(norm.get_answerRate() > p.get_answerRate())
    {
        double difference = norm.get_answerRate() - p.get_answerRate();
//        cout << "difference = " << difference << endl;
        double ansRateIncrease = (difference / p.get_answerRate()) * 100;
//        cout << "answerRateIncrease = " << ansRateIncrease << endl;
//        cout << "ansrateincrease = " << ansRateIncrease << endl;
        
        string str = "Answer Rate";
        int pLevel = norm.get_p_ansRate();
        Skill s = createSkill(str, ansRateIncrease, pLevel);
        skills.push_back(s);
    }
    else
    {
//        cout << "answer rate is above expected value!" << endl;
    }
    
    if(norm.get_setRate() > p.get_setRate())
    {
        double diff2 = norm.get_setRate() - p.get_setRate();
        double setRateInccrease = (diff2 / p.get_setRate()) * 100;
//        cout << "set rate increase = " << setRateInccrease << endl;
        string str = "Set Rate";
        int pLevel = norm.get_p_setRate();
        Skill s = createSkill(str, setRateInccrease, pLevel);
        skills.push_back(s);
    }
    else
    {
//        cout << "Set rate is above expected value!" << endl;
    }
    
    if(norm.get_showRate() > p.get_showRate())
    {
        double diff3 = norm.get_showRate() - p.get_showRate();
        double showRateIncrease = (diff3 / p.get_showRate()) * 100;
//        cout << "Show rate increase = " << showRateIncrease << endl;
        
        string str = "Show Rate";
        int pLevel = norm.get_p_showRate();
        Skill s = createSkill(str, showRateIncrease, pLevel);
        skills.push_back(s);
    }
    else
    {
//        cout << "Show rate is above expected value!" << endl;
    }
    
    if(norm.get_opConversion() > p.get_opConversion())
    {
        double diff4 = norm.get_opConversion() - p.get_opConversion();
        double opConvIncrease = (diff4 / p.get_opConversion()) * 100;
//        cout << "Op Conversion incrase = " << opConvIncrease << endl;
        
        string str = "Opportunity Conversion";
        int pLevel = norm.get_p_opConv();
        Skill s = createSkill(str, opConvIncrease, pLevel);
        skills.push_back(s);
    }
    else
    {
//        cout << "Opportunity Conversion rate is above expected value!" << endl;
    }
    
    if(norm.get_closeRate() > p.get_closeRate())
    {
        double diff5 = norm.get_closeRate() - p.get_closeRate();
        double closeRateIncrease = (diff5 / p.get_closeRate()) * 100;
//        cout << "close rate Increase = " << closeRateIncrease << endl;
        
        string str = "Close Rate";
        int pLevel = norm.get_p_closeRate();
        Skill s = createSkill(str, closeRateIncrease, pLevel);
        skills.push_back(s);
    }
    else
    {
//        cout << "Close rate is above expected value!" << endl;
    }
    
    if(norm.get_avgDealSize() > p.get_avgDealSize())
    {
        double diff6 = norm. get_avgDealSize() - p.get_avgDealSize();
        double avgDealIncrase = (diff6 / p.get_avgDealSize()) * 100;
//        cout << "ave deal size = " << avgDealIncrase << endl;
        
        string str = "Average Deal Size";
        int pLevel = norm.get_p_avgDealSize();
        Skill s = createSkill(str, avgDealIncrase, pLevel);
        skills.push_back(s);
    }
    else
    {
//        cout << "Avg deal size is above expected value!" << endl;
    }
    
//    cout << "Outputting skills " << endl;
//    for(unsigned int i = 0; i < skills.size(); i++)
//    {
//        cout << skills[i].get_name() << " increase percentage =  " << skills[i].get_incrase() << " precedence = " << skills[i].get_pLevel() << endl;
//    }

    eval_skills(skills);
}

void Rule::eval_skills(vector<Skill> &skills)
{
    vector<Skill> order;
    while(!skills.empty())
    {
        Skill max = skills[0];
        for(unsigned int i = 1; i < skills.size(); i++)
        {
//            cout << "max = " << max.get_name() << " skills = " << skills[i].get_name() << endl;
            if(max.get_pLevel() < skills[i].get_pLevel() && max.get_incrase() >= skills[i].get_incrase())
            {
            }
            else if(max.get_incrase() == skills[i].get_incrase())
            {
                if(max.get_pLevel() < skills[i].get_pLevel())
                {
                    max = skills[i];
                }
            }
            else if(max.get_pLevel() > skills[i].get_pLevel())
            {
//                cout << "max.get_plevel() = " << max.get_pLevel() << endl;
//                cout << "skills[i].get_plevel() = " << skills[i].get_pLevel() << endl;
                double scalar = max.get_pLevel() / skills[i].get_pLevel();
                double first = scalar * max.get_incrase();
                double second = scalar * skills[i].get_incrase();
                if(second > first)
                {
                    max = skills[i];
//                    cout << "New max " << max.get_name() << endl;
                }
            }
            else if(max.get_pLevel() < skills[i].get_pLevel())
            {
                double newMax = (max.get_incrase() * skills[i].get_pLevel()) / max.get_pLevel();
                if(newMax < skills[i].get_incrase())
                {
                    max = skills[i];
//                    cout << "new max " << skills[i].get_name() << endl;
                }
                else if(newMax == skills[i].get_incrase())
                {
                    //Default to lowest precedence level?
                    
                }
            }
            //add case for if precedence levels are equal
            else if(max.get_pLevel() == skills[i].get_pLevel())
            {
                if(max.get_incrase() < skills[i].get_incrase())
                {
                    max = skills[i];
                }
            }
        }
        
        int index = findIndex(skills, max);
        order.push_back(max);
        skills.erase(skills.begin() + index);
    }// end of while loop
    
    for(unsigned int i = 0; i < order.size(); i++)
    {
        cout << order[i].get_name() << endl;
    }
}

int Rule::findIndex(vector<Skill> &skills, Skill &name)
{
    int val = 0;
    
    for(unsigned int i = 0; i < skills.size(); i++)
    {
        if(name.get_name() == skills[i].get_name())
        {
            val = i;
        }
    }
    return val;
}











