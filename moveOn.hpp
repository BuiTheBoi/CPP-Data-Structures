#include<iostream>
#include<string>

#pragma once

using namespace std;

/************************************
    Prompts user to press enter key.
    Clear the terminal to move on to
    the next task
*************************************/
void moveOn(){
    cout << "Press the enter key to continue" << endl;
    string empty;
    getline(cin, empty);
    system("clear");
}