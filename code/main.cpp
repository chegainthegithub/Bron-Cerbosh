
#include <iostream>
#include <set>
#include "Matrix.h"

using namespace std;

int main(){
while (true)
{
    cout << "Write start size of graph\n";
    unsigned SIZE;
    GMatrix data;
    cin >> SIZE;
    for (unsigned i = 0; i < SIZE; ++i)
    {
        vector<bool> line;
        for (unsigned j = 0; j < SIZE ; ++j)
        {
            bool a;
            cin >> a;
            line.push_back(a);
        }
        data.add(line);
    }
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
    system("pause");
}
    return 0;
}
