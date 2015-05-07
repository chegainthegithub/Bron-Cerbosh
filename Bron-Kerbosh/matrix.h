#ifndef MATRIX_H
#define MATRIX_H
#include <vector>
#include <iterator>
#include <set>
using namespace std;

class GMatrix{

    unsigned SIZE;
    unsigned int cliqueAmount;
    unsigned int difficulty;

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
    float getDifficultyPerClique()
   {
       float difficultyPerClique = (difficulty+0.0)/(cliqueAmount+0.0);
       return difficultyPerClique;
   }

   void signal_inside()
   {
       std::cout << "inside"<<std::endl;
   }
   void signal_outside()
   {
       std::cout << "outside" << std::endl;
   }

   void outputAnalytics()
   {
       std::cout <<" Q = "<< cliqueAmount<<" , D = " << difficulty << " , N = " << SIZE << std::endl;
       std::cout <<"c  = D / Q  = "<< difficulty << " / "<< cliqueAmount<<" = " << getDifficultyPerClique() << " = N + 1" << std :: endl;
       return;
   }

    GMatrix():SIZE(1)
    {
        //SIZE = 1;
        cliqueAmount = 0;
        difficulty = 0;
        vector<bool> line  ;
        line.push_back(1);
        M.push_back(line);
    }
    GMatrix(GMatrix &)
    {

    }
    ~GMatrix()
    {
        M.clear();
    }
    void add(std::vector<bool> & line)
        {
            ++SIZE;
            M.push_back(line);
            for (unsigned i = 0; i < SIZE - 1; ++i)
            {
                M[i].push_back(line[i]);
            }
            M[SIZE - 1].push_back(true);
        }


//    void addSIZEtoOperations()
//    {
//        amount_of_operations_ += SIZE*SIZE;
//    }

    void out()
        {
            for (int i = 0; i < SIZE; ++i)
            {
                for (int j = 0; j < SIZE; ++j)
                {
                    std::cout << M[i][j] << ' ';
                }
                std::cout << std::endl;
            }
        }



    bool get(unsigned i1, unsigned j1)
    {
        return M[i1][j1];
    }


    void extend(set<unsigned>candidates, set<unsigned>Not,vector<set<unsigned> > &cliques,set<unsigned> &compsub)
    {
        //signal_inside();
        while (candidates.size() != 0 || is_here(candidates,Not))
        {
            //1
//            if (compsub.size())
//                     clicks.push_back(compsub);
            unsigned v = *(candidates.begin());
            // unsigned clone_v = v;
            candidates.erase(candidates.begin());
            compsub.insert(v);

            //2

            set<unsigned> new_candidates = candidates;
            set<unsigned> new_not = Not;
            for (unsigned i = 0; i < SIZE; ++i)
            {
                difficulty++;
                if (M[i][v] == 0)
                {

                    new_candidates.erase(i);
                    new_not.erase(i);
                }
            }
            //3

            if (new_candidates.size() == 0 & new_not.size() == 0)
            //4
            {
                cliques.push_back(compsub);
                cliqueAmount++;
            }//5
            else
            {
                extend(new_candidates, new_not,cliques,compsub);
                            cliques.push_back(compsub);
                            cliqueAmount++;
            }
            difficulty++;
            candidates.erase(v);
            compsub.erase(v);
            Not.insert(v);
            //6
        }
         // signal_outside();
      //  amount_of_operations++;
//          if (compsub.size())
//        {
//            clicks.push_back(compsub);
//            cliqueAmount++;
//        }
    }

};
#endif // MATRIX_H

