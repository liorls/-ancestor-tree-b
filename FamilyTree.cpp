// /*
// AUTHORS: Levana Sciari,Mayanne zeevi, Lior Samuel-Levy 

// */ 

// #include <iostream>
// #include <string>
// #include <stdexcept>
// #include "FamilyTree.hpp"

// using namespace std;
// using namespace family;

//         Tree::Tree(string nameYoung){ //constructor - the young!
//             this->name = nameYoung;
//             this->father = NULL;
//             this->mother = NULL;
//             this->son = NULL;
//         }
//         Tree::~Tree(){
//             delete this->father;
//             delete this->mother;
//         }

//         Tree& Tree::addFather(string son, string f){
//             Tree* addF = search (this, son);
//             if(addF == NULL) throw runtime_error("No son named: " + son);
//             if(addF->father != NULL) throw runtime_error("To" + son + "has a father");
//             if(addF != NULL && addF->father == NULL){
//                 addF->father = new Tree (f);
//                 addF->father->son = addF;
//             }
//             return *this;
//         }

//         Tree& Tree::addMother(string son, string m){
//             Tree* addM = search (this, son);
//             if(addM == NULL) throw runtime_error("No son named: " + son);
//             if(addM->mother != NULL) throw runtime_error("To" + son + "has a mother");
//             if(addM != NULL && addM->mother == NULL){
//                 addM->mother = new Tree (m);
//                 addM->mother->son = addM;
//             }
//             return *this;
//         }

//         string Tree::relation(string relative)
// {
//     string ans = "unrelated";

//     if (relative == name)
//     {
//         ans = "me";
//         return ans;
//     }

//     if (father != nullptr)
//     {
//         ans = father->relation(relative);

//         if (ans != "unrelated")
//         {
//             if (ans == "me")
//                 ans = "father";
//             else if (ans == "father" || ans == "mother")
//                 ans = "grand" + ans;
//             else
//                 ans = "great-" + ans;
//         }
//     }
//     if ((ans == "unrelated") && (mother != nullptr))
//     {
//         ans = mother->relation(relative);

//         if (ans != "unrelated")
//         {
//             if (ans == "me")
//                 ans = "mother";
//             else if ((ans == "mother") || (ans == "father"))
//                 ans = "grand" + ans;
//             else
//                 ans = "great-" + ans;
//         }
//     }
//     return ans;
// }

//         string Tree::find(string relation){

//             if(relation == "me") return this->name;
//  if(relation == "mother" && this->mother!=NULL) return this->mother->name;
//  if(relation == "father" && this->father!=NULL) return this->father->name;

// if(relation.find("mother") != std::string::npos && relation.find("father") != std::string::npos )
//      throw runtime_error {"There is no relation "+ relation};
//  string name =findRel(this, relation);
//  if(name == "")
//     throw runtime_error {"There is no relation "+ relation};
//  else
//     return name;
//         }
// string Tree::findRel (Tree* current, string relation){
//     if (current == NULL) return "";
   
//     if(relation == "grandmother")
//     {
//         if(current->mother!=NULL && current->mother->mother!= NULL)return current->mother->mother->name;
//         if(current->father!=NULL && current->father->mother!= NULL)return current->father->mother->name;
//         return "";
//     }
//     else if(relation == "grandfather"){
//         if(current->mother!=NULL && current->mother->father!= NULL)return current->mother->father->name;
//         if(current->father!=NULL && current->father->father!= NULL)return current->father->father->name;
//         return "";
//     }
//     string sub1= findRel(current->father, relation.substr(6));
//     if(sub1!="") return sub1;
//     string sub2= findRel(current->mother, relation.substr(6));
//     if(sub2!="") return sub2;
    
    
//     return sub1+sub2;
// }
//             // if(nameToFind == "me") return this->name;
//             // if(nameToFind == "father") return this->father;
//             // if(nameToFind == "me") return this->name;
//             // return "find";
 
        

//         void Tree::remove(string name){
//             if(this->name == name)
//                 throw runtime_error("You can't remove the root\n");
//             Tree* removeName = search(removeName,name);
//             if(removeName == NULL) 
//                  throw runtime_error("There is no such name in the family: " + name);
//             return;
//  if(removeName->son!=NULL)
//     { 
//             if(removeName->mother != NULL && removeName->mother->name == name)
//                 removeName->mother = NULL;
//             else if (removeName->father != NULL && removeName->father->name == name)
//                 removeName->father = NULL;
//     }
//             delete removeName;
//         }

//         void Tree::display(){

//             print2DUtil(this,0);
//         }

//         // I used the site - https://www.geeksforgeeks.org/print-binary-tree-2-dimensions/  
//         void Tree::print2DUtil(Tree *root, int space){  
//         // Base case  
//         if (root == NULL)  
//             return;  
//         // Increase distance between levels  
//         space += 10;  
//         // Process right child first  
//         print2DUtil(root->father, space);
//         // Print current node after space  
//         cout << endl;  
//         for (int i = 10; i < space; i++)  
//             cout << " ";  
//             cout << root->name << endl;  
//         // Process left child  
//         print2DUtil(root->mother, space);
//         }  
 
//         Tree* Tree::search (Tree* current , string name){
//             if(current == NULL) return NULL;
//             if(current->name == name) return current;
//             else{
//                 Tree* fatherSide = search(current->father,name);
//                 Tree* motherSide = search(current->mother,name);
//                 if(fatherSide != NULL) return fatherSide;
//                 if(motherSide != NULL) return motherSide;

//             }
            
//             return NULL;
//         }

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
            this->name = nameYoung;
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
                addF->father = new Tree (f);
                addF->father->son = addF;
            }
            return *this;
        }

        Tree& Tree::addMother(string son, string m){
            Tree* addM = search (this, son);
            if(addM == NULL) throw runtime_error("No son named: " + son);
            if(addM->mother != NULL) throw runtime_error("To" + son + "has a mother");
            if(addM != NULL && addM->mother == NULL){
                addM->mother = new Tree (m);
                addM->mother->son = addM;
            }
            return *this;
        }

        string Tree::relation(string name){
        string ans = "unrelated";
        if (name == this->name){
            ans = "me";
            return ans;
        }

        if (father != nullptr){
        ans = father->relation(name);

            if (ans != "unrelated"){
                if (ans == "me")
                    ans = "father";
                else if (ans == "father" || ans == "mother")
                    ans = "grand" + ans;
                else
                    ans = "great-" + ans;
            }
        }

        if ((ans == "unrelated") && (mother != nullptr)){
        ans = mother->relation(name);

            if (ans != "unrelated"){
                if (ans == "me")
                    ans = "mother";
                else if ((ans == "mother") || (ans == "father"))
                    ans = "grand" + ans;
                else
                    ans = "great-" + ans;
            }
        }
        return ans;
        }

        string Tree::find(string nameToFind){

        if(nameToFind == "me") return this->name;
        if(nameToFind == "mother" && this->mother!=NULL) return this->mother->name;
        if(nameToFind == "father" && this->father!=NULL) return this->father->name;

        if(nameToFind.find("mother") != std::string::npos && nameToFind.find("father") != std::string::npos )
            throw runtime_error {"There is no relation "+ nameToFind};

        string name =findRecursivy(this, nameToFind);
        if(name == "")
            throw runtime_error {"There is no relation "+ nameToFind};
        else
            return name;
        }

        string Tree::findRecursivy (Tree* current, string nameToFind){
        if (current == NULL) return "";
   
        if(nameToFind == "grandmother"){
        if(current->mother!=NULL && current->mother->mother!= NULL)return current->mother->mother->name;
        if(current->father!=NULL && current->father->mother!= NULL)return current->father->mother->name;
        return "";
        }
        else if(nameToFind == "grandfather"){
            if(current->mother!=NULL && current->mother->father!= NULL)return current->mother->father->name;
            if(current->father!=NULL && current->father->father!= NULL)return current->father->father->name;
        return "";
        }

        string sub1= findRecursivy(current->father, nameToFind.substr(6));
        if(sub1!="") return sub1;
        string sub2= findRecursivy(current->mother, nameToFind.substr(6));
        if(sub2!="") return sub2;
    
    
        return sub1+sub2;
        }

        void Tree::remove(string name){
            if(this->name == name)
                throw runtime_error("You can't remove the root\n");
            Tree* removeName = search(this,name);
            if(removeName == NULL) 
                 throw runtime_error("There is no such name in the family: " + name);
            return;

           if(removeName->son!=NULL)
    {    
        if(removeName->son->father != NULL && removeName->son->father->name == name)
            removeName->son->father=NULL;
        else if(removeName->son->mother != NULL && removeName->son->mother->name == name)
            removeName->son->mother=NULL;
    }
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
