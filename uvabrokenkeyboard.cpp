//
//  uvabrokenkeyboard.cpp
//  Solution
//
//  Created by Snehil Chopra on 9/26/18.
//  Copyright © 2018 Snehil Chopra. All rights reserved.
//

#include <stdio.h>
#include <list>
#include <iostream>
#include <string.h>
using namespace std;

int main()
{
    string frase;
    list<char> texto;
    list<char>::iterator it;
    while(getline(cin,frase))
    {
        texto.clear();
        it = texto.begin();
        for(int i=0;i<frase.size();++i)
        {
            if(frase[i]=='[')
                it = texto.begin();
            if(frase[i]==']')
                it = texto.end();
            if(frase[i]!='[' && frase[i]!=']')
                texto.insert(it,frase[i]);
        }
        for(it=texto.begin();it!=texto.end();it++)
            printf("%c",*it);
        printf("\n");
    }
    return 0;
}
