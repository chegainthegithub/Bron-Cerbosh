#include <iostream>
#include <set>
#include "Matrix.h"
#include <string>
#include <fstream>

using namespace std;

int main()
{
while (true)
{
    cout << "Write start size of graph\n";
    int SIZE = 0;
    GMatrix data;
    while(true)
    {
        cin >> SIZE;
        if (SIZE>0)
            break;
        else
            cout << "SIZE must be a postive integer "<<endl;
    }
    for (unsigned i = 0; i < SIZE - 1; ++i)
        {
            std::vector<bool> line;
            for (unsigned j = 0; j < i + 1; ++j)
            {
                bool a;
                std::cin >> a;
                line.push_back(a);
            }
            data.add(line);
        }


    std::cout<<std::endl;
    data.out();
    std::cout<<std::endl;

    vector<set<unsigned> > cliques;
    set<unsigned> Not;
    set<unsigned> candidates;
    for (unsigned i = 0; i < SIZE; ++i)
    {
        candidates.insert(i);
    }
    set<unsigned> example;
    data.extend(candidates, Not, cliques,example);
    for (unsigned i = 0; i < cliques.size(); ++i)
    {
        for (set<unsigned>::const_iterator j = cliques[i].begin(); j != cliques[i].end(); ++j)
        {
            cout << *j << ' ';
        }
        cout << endl;
    }
    string answerYesNo = "";
    data.outputAnalytics();

    cout << "do you want to save log ?"<<endl;
            cin>>answerYesNo;
            cout<<endl;
    if (answerYesNo == "Yes" || answerYesNo == "yes")
    {
        string fileName = "1.txt";
        cout << "input file name to save in: ";
        cin >> fileName;
        fileName +=".graph";
        const char * fileName_local = fileName.c_str();
        ofstream fbuffer(fileName_local);
        fbuffer << "your GRAPH: "<<endl;
        for (int i = 0;i<SIZE;i++)
        {
            for (int j = 0;j<SIZE;j++)
            {
                fbuffer<<data.get(i,j) << " ";
            }
            fbuffer << endl;
        }
        fbuffer << "your CLIQUES: " << endl;
        for (unsigned i = 0; i < cliques.size(); ++i)
        {
            for (set<unsigned>::const_iterator j = cliques[i].begin(); j != cliques[i].end(); ++j)
            {
                fbuffer << *j << ' ';
            }
            fbuffer << endl;
        }
        fbuffer.close();
    }

    cout << "do you want to solve another graph? "<<endl;
    cin>>answerYesNo;
    cout<<endl;
    if (answerYesNo == "No" || answerYesNo == "no")
    {
        cout<<"Goodbye"<<endl;
        break;
    }
}
    return 0;
}
