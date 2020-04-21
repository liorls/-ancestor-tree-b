// /*
// AUTHORS: Levana Sciari,Mayanne zeevi, Lior Samuel-Levy 

// */ 

// #include <iostream>
// #include <string>
// #include <stdexcept>
// #include "FamilyTree.hpp"

// using namespace std;
// using namespace family;

//         Tree::Tree(string text){ //constructor - the young!

//         }
//         Tree& Tree::addFather(string son, string f){

//             return *this;
//         }
//         Tree& Tree::addMother(string son, string m){

//             return *this;
//         }
//         string Tree::relation(string name){

//             return "relation";
//         }
//         string Tree::find(string y){

//             return "find";
//         }
//         void Tree::display(){

//         }
//         void Tree::remove(string r){

//         }


#include <iostream>


#include "FamilyTree.hpp"

using namespace std;
using namespace family;

 Tree& Tree::addFather(string son, string father){

    Tree* add = search (this, son);
    if(add == NULL)
        throw runtime_error {"There is no son named "+ son};
    if(add->father !=NULL)
        throw runtime_error {"There is already a father to "+ son};
    
    if(add !=NULL && add->father == NULL){
        add->father = new Tree (father);
        add->father->son = add;
    }

    return *this;
}
 Tree& Tree::addMother(string son, string mother){

    Tree* add = search (this, son);

    if(add == NULL)
         throw std::runtime_error {"There is no son named "+ son};
    if(add->mother !=NULL)
         throw std::runtime_error {"There is already a mother to "+ son};
    
    if(add !=NULL && add->mother == NULL){
        add->mother = new Tree (mother);
        add->mother->son = add; 
    }
         
    return *this;
}

void Tree::display(){
printTree(this);
}

string Tree::relation(string name){

    if(this->name == name) return "me";

    Tree* dest = search(this, name);

    if(dest==NULL) return "unrelated";

    int counter =0;
    
    
    string relation="";
    while(dest->name!= this->name){
        counter++;
        if(counter==1)
            {
                if(dest->son->mother!= NULL && dest->son->mother->name ==name)
                    relation="mother";
                if(dest->son->father!= NULL && dest->son->father->name == name)
                    relation="father"; 
            }
        if(counter == 2)
            relation ="grand" + relation;
        dest=dest->son;
    }

    while(counter>2){
        relation="great-" + relation;
        counter--;
    }
return relation;
}

string Tree::find (string relation){
 if(relation == "me") return this->name;
 if(relation == "mother" && this->mother!=NULL) return this->mother->name;
 if(relation == "father" && this->father!=NULL) return this->father->name;

if(relation.find("mother") != std::string::npos && relation.find("father") != std::string::npos )
     throw runtime_error {"There is no relation "+ relation};
 string name =findRel(this, relation);
 if(name == "")
    throw runtime_error {"There is no relation "+ relation};
 else
    return name;
}

string Tree::findRel (Tree* current, string relation){
    if (current == NULL) return "";
   
    if(relation == "grandmother")
    {
        if(current->mother!=NULL && current->mother->mother!= NULL)return current->mother->mother->name;
        if(current->father!=NULL && current->father->mother!= NULL)return current->father->mother->name;
        return "";
    }
    else if(relation == "grandfather"){
        if(current->mother!=NULL && current->mother->father!= NULL)return current->mother->father->name;
        if(current->father!=NULL && current->father->father!= NULL)return current->father->father->name;
        return "";
    }
    string sub1= findRel(current->father, relation.substr(6));
    if(sub1!="") return sub1;
    string sub2= findRel(current->mother, relation.substr(6));
    if(sub2!="") return sub2;
    
    
    return sub1+sub2;
}

void Tree::remove(string name){
    if(this->name == name)
         throw runtime_error {"This is unvalid to remove the root! "};
    Tree* toRemove = search (this, name);
    if(toRemove == NULL){
        throw runtime_error {"There is no person in the tree named: "+name};
        return;
    }
    if(toRemove->son!=NULL)
    {    
        if(toRemove->son->father != NULL && toRemove->son->father->name == name)
            toRemove->son->father=NULL;
        else if(toRemove->son->mother != NULL && toRemove->son->mother->name == name)
            toRemove->son->mother=NULL;
    }
    delete toRemove;
 
}

Tree* Tree::search (Tree* current, string name ){
    if(current==NULL) return NULL;          
    if(current->name ==name) return current;

    else{
        
        Tree* sub1= search(current->father, name);
        Tree* sub2= search(current->mother,name);
        if(sub1 != NULL) return sub1;
        if(sub2 != NULL) return sub2;
    }
    return NULL;
}



//https://stackoverflow.com/questions/36802354/print-binary-tree-in-a-pretty-way-using-c
void Tree::printTree(const std::string& prefix, const Tree* node, bool isLeft)
{
    if( node != nullptr )
    {
        std::cout << prefix;

        std::cout << (isLeft ? "├──" : "└──" );

        // print the value of the node
        std::cout << node->name << std::endl;

        // enter the next tree level - left and right branch
        printTree( prefix + (isLeft ? "│   " : "    "), node->father, true);
        printTree( prefix + (isLeft ? "│   " : "    "), node->mother, false);
    }
}

void Tree::printTree(const Tree* node)
{
    printTree("", node, false);    
}
