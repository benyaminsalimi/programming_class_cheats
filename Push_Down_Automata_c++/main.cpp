//
//  main.cpp
//  nahid
//
//  Created by Benyamin Salimi on 6/21/16.
//  Copyright © 2016 Benyamin Salimi. All rights reserved.
//

#include <iostream>
#include <stdio.h>
using namespace std;

struct gozar
{
    char start;
    char next;
    char read;
    char pop;
    char push;
};

int main() {
    
    cout<<"Enter the number of alfabet: ";
    int asize=0;
    cin>> asize;
    ///
    cout<<"Enter the alfabet: ";
    char alefba[asize];
    cin>> alefba;
    ///
    cout<<"Enter the number of stat: ";
    int stat=0;
    cin>> stat;
    ///
    cout<<"Enter the number of GOZAR: ";
    int gsize=0;
    cin>> gsize;
   
    struct gozar gz[gsize];
    
    for (int i=0;i<gsize;i++)
    {
        cin >> gz[i].start;
        cin >> gz[i].next;
        cin >> gz[i].read;
        cin >> gz[i].pop;
        cin >> gz[i].push;
    }
    for (int i=0;i<gsize;i++)
    {
        cout  << gz[i].start << " ";
        cout  << gz[i].next << " ";
        cout  << gz[i].read <<" ";
        cout  << gz[i].pop << " ";
        cout  << gz[i].push << endl ;
    }
    
    cout<<"Enter the number of final: ";
    int fsize;
    cin>> fsize;
    ///
    cout<<"Enter the final: ";
    char final[fsize];
    cin>> final;
    
    cout<<"Enter start point: ";
    char starter;
    cin>> starter;
    
    
    ///
    cout<<"Enter the number of test: ";
    int tsize;
    cin>> tsize;
    
    cout<<"Enter the tests: ";
    char test[tsize];
        cin>>test;
    
    ///validation of test!
    for (int i=0;i<tsize;i++)
    {
        for(int j=0;j<asize;j++)
        {
            if(alefba[j] != test[i])
            {   cout<<"not ACC";
                return 0;
            }
        }
    }
///////paring test/////////
    char tvalid[tsize];
    int ivalid[tsize];
    int itop=0;
    for (int i=0; i<tsize;i++)
    {
        if (tvalid[itop]==test[i]) {
            ivalid[i]++;
        }
        tvalid[itop]=test[i]; itop++;
    }
//////// end paring now we have table to analize!
    char poshte[100];
    int top=-1;
    char move[100];
    int topmove=-1;
    bool testdone= false;
    int testcheck=0;///correnct location of testing
    while (testdone)
    {
        /// if we dont have any move then run starter move !
        if (topmove==-1)
        {
            for(int i=0;i<gsize;i++)
            {
                if (gz[i].start == starter)//find start
                {
                    if (gz[i].start==gz[i].next)// start poniting to his self
                    {
                        for (int j=0; j<gsize; j++)
                        {
                            if (i!=j and gz[j].read == tvalid[testcheck] )
                            {
                                /// do khate
                            }
                            
                        }
                        if (topmove==-1) {
                           /// hame harkata ro ba hamoon boro
                        }
                    }
                    else
                    {
                        for (int j=0; j<gsize; j++)
                        {
                            if ( gz[i].read == gz[j].read )
                            {
                                /// do khate
                            }
                        }
                        if (topmove==-1)
                        {
                            /// yek khate boro be gozar badi az start harkat kon
                        }
                    }
                }
            }
            
        }
        if (topmove==-1)/// ageh az halate shoro natoonim harkat konim
        {
            //check @ move
            for(int i=0;i<gsize;i++)
            {
                if (gz[i].start==starter and gz[i].read=='@')
                {
                    
                }
            }
            ///ba @ natoonest harkat kone
            if (topmove==-1) {
                
                cout<< "not ACC"; return 0;
            }
        }
        ////////end starter
        int temp;
        temp=topmove;
        for(int i=0;i<gsize;i++)
        {
            if(tvalid[testcheck]==gz[i].read and move[topmove]==gz[i].start)// dar an halat boodim va mitavanestim bekhanim
            {
                if (gz[i].start==gz[i].next)
                {
                    for (int j=0; j<gsize; j++)
                    {
                        if (j!=i and tvalid[testcheck]==gz[j].read)
                        {
                            //tvalid[ivalid-1] for gozar  i and 1 form j gozar! and testcheck++
                        }
                    }
                    ///tavlid[ivalid] form i gozar and testcheck++
                }
                else if (move[topmove]==gz[i].start )
                {
                    for (int j=0; j<gsize; j++)
                    {
                        if (tvalid[testcheck]==gz[i].read)
                        {
                            ///
                            //tvalid[ivalid-1] for gozar  i and 1 form j gozar! and testcheck++
                        }
                    }
                }
            }
            ///check @
            else if(move[topmove]==gz[i].start and gz[i].read=='@')
            {
                ///mitonim ba @ harkat konim
            }
            
            
        }
        ///rerror age na @ mishod harkt kard na ba khoondan chizi bayad berim biroon
        if (topmove==temp) {
            cout << "not ACC";
            return 0;
        
        }
        
        
        //// halate nahayi
        bool endmove=false;
        for (int k=0;k<fsize;k++)
        {
            if (move[topmove]==final[k])
                endmove=true;
        }
        
        ///test done we are done to moveing in tvalid
        if(testcheck==itop)
            testdone=true;
        
        if (testdone && endmove ) {
            ///poshte khali ast
            if (top==-1)
            {
                cout<< "ACC";
                return 0;;
            }
            else
            {
                cout <<" not ACC";
                return 0;
            }
        }
    }
    
    cout << "\n oh no wrong ! \n";

}
