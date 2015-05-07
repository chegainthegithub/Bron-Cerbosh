#include <iostream>
#include <set>
#include "Matrix.h"
#include <string>

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

    vector<set<unsigned> > clicks;
    set<unsigned> Not;
    set<unsigned> candidates;
    for (unsigned i = 0; i < SIZE; ++i)
    {
        candidates.insert(i);
    }
    set<unsigned> example;
    data.extend(candidates, Not, clicks,example);
    for (unsigned i = 0; i < clicks.size(); ++i)
    {
        for (set<unsigned>::const_iterator j = clicks[i].begin(); j != clicks[i].end(); ++j)
        {
            cout << *j << ' ';
        }
        cout << endl;
    }
    //data.addSIZEtoOperations();
    data.outputAnalytics();
    cout << "do you want to solve another graph? "<<endl;
    string answerYesNo = "";
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
