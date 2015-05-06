#ifndef MATRIX_H
#define MATRIX_H
#include <vector>
#include <iterator>
#include <set>
using namespace std;

class GMatrix{
    unsigned SIZE;
    unsigned int cliqueAmount;
    unsigned int amount_of_operations;
    float difficulty;

    vector<vector <bool> >M;

    bool is_here(set<unsigned> &candidates, set<unsigned> &Not)
    {
        for (set<unsigned>::const_iterator i = Not.begin(); i != Not.end(); ++i)
        {
            bool g = 0;
            for (set<unsigned>::const_iterator j = candidates.begin(); j != candidates.end(); ++j)
            {
                if (M[*i][*j] == 0)g = 1;
            }
            if (g == 0) return 0;
        }
        return 1;
    }


public:


    GMatrix()
    {
        SIZE = 0;
        cliqueAmount = 0;
        amount_of_operations = 0;
        difficulty = 0;
//        vector<bool> line ;
//        M.push_back(line);
    };
    GMatrix(GMatrix &)
    {

    }
    ~GMatrix()
    {
        M.clear();
    }
    void add(vector<bool> & line)
    {
        M.push_back(line);
        SIZE++;
    }
//    void addSIZEtoOperations()
//    {
//        amount_of_operations_ += SIZE*SIZE;
//    }

    bool get(unsigned i1, unsigned j1)
    {
        return M[i1][j1];
    }

    void extend(set<unsigned>candidates, set<unsigned>Not,vector<set<unsigned> > &clicks,set<unsigned> &compsub)
    {
        while (candidates.size() != 0 || is_here(candidates,Not))
        {
            //1
//            if (compsub.size())
//                     clicks.push_back(compsub);
            unsigned v = *(candidates.begin());
            unsigned clone_v = v;
            candidates.erase(candidates.begin());
            compsub.insert(v);

            //2

            set<unsigned> new_candidates = candidates;
            set<unsigned> new_not = Not;
            for (unsigned i = 0; i < SIZE; ++i)
            {
                amount_of_operations++;
                if (M[i][v] == 0)
                {

                    new_candidates.erase(i);
                    new_not.erase(i);
                }
            }
            //3

            if (new_candidates.size() == 0 )
            //4
            {
                clicks.push_back(compsub);
                cliqueAmount++;
            }//5
            else
                extend(new_candidates, new_not,clicks,compsub);
            amount_of_operations++;
            candidates.erase(v);
            compsub.erase(v);
            Not.insert(v);
            //6
        }
        amount_of_operations++;
        if (compsub.size())
        {
            clicks.push_back(compsub);
            cliqueAmount++;
        }
    }
     float getDifficulty()
    {
        difficulty = (amount_of_operations+0.0)/(cliqueAmount+0.0);
        return difficulty;
    }

    void outputAnalytics()
    {
        std::cout <<"all "<< cliqueAmount<<" cliques were found after " << amount_of_operations << " operations" << std::endl;
        std::cout <<"difficulty = operations / cliques  = "<< amount_of_operations << " / "<< cliqueAmount<<" = " << getDifficulty() << std :: endl;
        return;
    }
};
#endif // MATRIX_H

