/*
AUTHORS: Levana Sciari,Mayanne zeevi, Lior Samuel-Levy 

*/ 

#include <iostream>
#include <string>
#include <stdexcept>
#include "FamilyTree.hpp"

using namespace std;
using namespace family;

        Tree::Tree(string nameYoung){ //constructor - the young!
            this->name = name;
            this->father = NULL;
            this->mother = NULL;
            this->son = NULL;
        }
        Tree::~Tree(){
            delete this->father;
            delete this->mother;
        }

        Tree& Tree::addFather(string son, string f){
            Tree* addF = search (this, son);
            if(addF == NULL) throw runtime_error("No son named: " + son);
            if(addF->father != NULL) throw runtime_error("To" + son + "has a father");
            if(addF != NULL && addF->father == NULL){
                addF->father = new Tree ("father");
                addF->father->son = addF;
            }
            return *this;
        }

        Tree& Tree::addMother(string son, string m){
            Tree* addM = search (this, son);
            if(addM == NULL) throw runtime_error("No son named: " + son);
            if(addM->mother != NULL) throw runtime_error("To" + son + "has a mother");
            if(addM != NULL && addM->mother == NULL){
                addM->mother = new Tree ("mother");
                addM->mother->son = addM;
            }
            return *this;
        }

        string Tree::relation(string name){

            return "relation";
        }

        string Tree::find(string name){

            return "find";
        }

        void Tree::remove(string name){
            if(this->name == name)
                throw runtime_error("You can't remove the root\n");
            Tree* removeName = search(removeName,name);
            if(removeName == NULL) 
                 throw runtime_error("There is no such name in the family: " + name);
            return;

            if(removeName->mother != NULL && removeName->mother->name == name)
                removeName->mother == NULL;
            else if (removeName->father != NULL && removeName->father->name == name)
                removeName->father == NULL;

            delete removeName;
        }

        void Tree::display(){

            print2DUtil(this,0);
        }

        // I used the site - https://www.geeksforgeeks.org/print-binary-tree-2-dimensions/  
        void Tree::print2DUtil(Tree *root, int space){  
        // Base case  
        if (root == NULL)  
            return;  
        // Increase distance between levels  
        space += 10;  
        // Process right child first  
        print2DUtil(root->father, space);
        // Print current node after space  
        cout << endl;  
        for (int i = 10; i < space; i++)  
            cout << " ";  
            cout << root->name << endl;  
        // Process left child  
        print2DUtil(root->mother, space);
        }  
 
        Tree* Tree::search (Tree* current , string name){
            if(current == NULL) return NULL;
            if(current->name == name) return current;
            else{
                Tree* fatherSide = search(current->father,name);
                Tree* motherSide = search(current->mother,name);
                if(fatherSide != NULL) return fatherSide;
                if(motherSide != NULL) return motherSide;

            }
            
            return NULL;
        }


