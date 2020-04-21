/*
AUTHORS: Levana Sciari,Mayanne zeevi, Lior Samuel-Levy 

*/

#include <iostream>
#include <string>

using namespace std;

namespace family{

    class Tree{

        string name;
        Tree* father;
        Tree* mother;
        Tree* son;

        public:

        Tree(string nameYoung); // constructor
        ~Tree(); //Disconstructor

        Tree& addFather(string son, string f);
        Tree& addMother(string son, string m);
        string relation(string name);
        string find(string nameToFind);
        void display();
        void remove(string r);

        Tree* search (Tree* current , string name);
        void print2DUtil(Tree *root, int space);  
        string findRecursivy (Tree* current, string nameToFind);     


    };
    
}

