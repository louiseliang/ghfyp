//
//  main.cpp
//  top
//
//  Created by Louise Leung on 1/8/14.
//  Copyright (c) 2014 Louise Leung. All rights reserved.
//

#include <iostream>
#include <iomanip>
#include <cmath>
#include <fstream>
#include <string>
#include <cstring>
#include <vector>
#include <map>
#include <algorithm>
#include <sstream>

using namespace std;
int toInt(char c)
{
    if(c=='-'){return 0;}
	if(c=='A'){return 1;}
    if(c=='C'){return 2;}
	if(c=='D'){return 3;}
	if(c=='E'){return 4;}
    if(c=='F'){return 5;}
    if(c=='G'){return 6;}
    if(c=='H'){return 7;}
    if(c=='I'){return 8;}
    if(c=='K'){return 9;}
    if(c=='L'){return 10;}
    if(c=='M'){return 11;}
    if(c=='N'){return 12;}
    if(c=='P'){return 13;}
    if(c=='Q'){return 14;}
    if(c=='R'){return 15;}
    if(c=='S'){return 16;}
    if(c=='T'){return 17;}
    if(c=='V'){return 18;}
    if(c=='W'){return 19;}
    if(c=='Y'){return 20;}
    
    return 21;
}


int main(int argc, const char * argv[])
{
    //input diffMatrix
    vector<double> difflog;
    vector<string> sline;
    
    ifstream in;
    in.open("/Users/Louiseleung/Desktop/diffLogMatrix.txt");
    
    if(!in){
        cout <<"failed"<<endl;
    }else{
        double a;
        while(in>>a){
            difflog.push_back(a);
            //cout<</*"a="<<setiosflags(ios::fixed)<<setprecision(15)<<*/a<<endl;
        }
    }
    //cout << "diffMatrix input finished" <<endl;
    in.close();
    
    double ** diff = new double *[21];
    
    for(int i=0;i<21;i++){
        diff[i] = new double[21];
    }
    
    for(int i=0;i<21;i++){
        for(int j=0;j<21;j++){
            diff[i][j]=difflog[i*21+j];
        }
    }
    
    //input MSA
    
    /*char* pathForMSA = new char[100];
    cin >> pathForMSA;
    
    in.open(pathForMSA);*/
    in.open("/Users/Louiseleung/Desktop/combined3pyj-PF09200.afas");
    if(!in)
        cout << "Can not open the MSA file"<< endl;
    else
    {
        string c;
        string ul;
        in>> ul;
        string tmp="";
        while(in >> c)
        {
            if(c[0]!='>')
            {
                tmp+=c;
            }
            else
            {
                sline.push_back(tmp);
                tmp="";
            }
        }
        //cout << "MSA input finished"<<endl;
        sline.push_back(tmp);
    }
    in.close();

    vector<vector<double>> score;
    int col = (int)sline[0].size();//96
    int row = (int)sline.size();//3

    for(int i1=0;i1<col;i1++){
        vector<double> scorecol;
        for(int i2=i1;i2<col;i2++){
            double sc=0;
            for(int j1=0;j1<row;j1++){
                for(int j2=j1;j2<row;j2++){
                    sc+=diff[toInt(sline[j1][i1])][toInt(sline[j2][i1])]+diff[toInt(sline[j1][i2])][toInt(sline[j2][i2])];
                }
            }
            scorecol.push_back(sc);
        }
        score.push_back(scorecol);
    }
    
    for(int i=0;i<score.size();i++){
        for(int j=0;j<score[i].size();j++){
            cout <<i<<"\t"<<j<<"\t"<<score[i][j]<<endl;
        }
    }
        //cout << score[0].size()<<" "<<score.size()<<endl;
    //cout << "MSA input finished"<<endl;
}

