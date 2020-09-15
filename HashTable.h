#include "HashNodeLink.h"
//#include "nbaPlayoff.h"
#include <iostream>
#include <string>
#include <fstream>

class HashTable {
private:
    HashNodeLink** arr; 
    int tableSize;
    int longest;
    int count;
    int collisions;
    double lf;
public:
    HashTable(int size) {//constructor
        tableSize = size;
        arr = new HashNodeLink*[tableSize];
        for (int i = 0; i < tableSize; i++) {
            arr[i] = NULL;
        }

        count = 0;
        collisions = 0;
        lf = 0;
        longest = 0;
    }

    ~HashTable() {//destructor
        for (int i = 0; i < tableSize; i++) {
            delete arr[i];
        }
        delete[] arr;
        std::cout << "Deleted Table" << std::endl;
    }

    int getAverageNodes();

    int getLongest();

    int getCount();

    int getCollisions();

    double loadFactor();

    int hashFunc(nbaPlayoff* v);

    void insert(nbaPlayoff* v);

    bool search(nbaPlayoff* v);

    bool searchRecur(HashNode* x, HashNode* previous , nbaPlayoff* find);

    bool searchKey(int key);

    void searchOptionEight(nbaPlayoff* x);

    void searchOptionEightRecur(HashNode* x, HashNode* previous, nbaPlayoff* find);

    void remove(nbaPlayoff* x);

    void removeRecur(HashNode* x, HashNode* previous, nbaPlayoff* find);

    void deletion(HashNode* x, HashNode* previous, nbaPlayoff* find);

    void printTable();

    void printToFile(std::ofstream& out);

    void printRecur(HashNode* x);

    void printTableFile(HashNode* x, std::ofstream& out);

    void printEfficiencies();

    void reOrg(HashNode* previous, HashNode* current, nbaPlayoff* find);
};

/*
-- returns count
*/
int HashTable::getCount() {
    return count;
}

/*
-- returns collisions
*/
int HashTable::getCollisions() {
    std::cout << "We Had " << collisions << " Collisions!" << std::endl;
    return collisions;
}

/*
-- returns load factor
*/
double HashTable::loadFactor() {
    double loaded = 0;
    for (int i = 0; i < tableSize; i++) {
        if (arr[i] != NULL) {
            loaded++;
        }
    }
    lf = (loaded / tableSize) * 100;
    std::cout << "Current Load Factor Is: %" << lf << std::endl;
    return lf;
}

/*
-- Calculates the average nodes per list
*/
int HashTable::getAverageNodes() {
    int total = 0;
    for (int i = 0; i < tableSize; i++) {
        if (arr[i] != NULL) {
            total += arr[i]->getListCount();
        }
    }
    std::cout << "Average Nodes Per Linked List Is: " << (total / count) << std::endl;
    return (total / count);
}
/*
-- Calculates the longest linked list
*/
int HashTable::getLongest() {
    for (int i = 0; i < tableSize; i++) {
        if (arr[i] != NULL) {
            if (arr[i]->getListCount() > longest) {
                longest = arr[i]->getListCount();
            }
        }
    }
    std::cout << "Longest Linked List Is: " << longest << std::endl;
    return longest;
}

/*
-- does hash func shit LOL
*/
int HashTable::hashFunc(nbaPlayoff* v) {
    return ((v->getYear() + (v->getChamp().length() * 2))) % tableSize;
}

/*
-- removes data from hash table
*/
void HashTable::remove(nbaPlayoff* x) {
    int key = hashFunc(x);
    if (arr[key] != NULL) {
        removeRecur(arr[key]->head, arr[key]->head, x);
    }
    else {
        std::cout << "Value Not Found!" << std::endl;
    }
}

/*
--Recursive Func that finds Value and calls delete
*/
void HashTable::removeRecur(HashNode* x, HashNode* previous, nbaPlayoff* find) {
    if (x != NULL) {
        if (*x->value == *find) {
            deletion(x, previous, find);
            count--;
        }
        else if (x->next != NULL)
        {
            removeRecur(x->next, x, find);
        }
        else {
            std::cout << "Value Not Found" << std::endl;
        }
    }
    else {
        std::cout << "Value Not Found" << std::endl;
    }
}

/*
-- Deletion used for removeRecur
*/
void HashTable::deletion(HashNode* x, HashNode* previous, nbaPlayoff* find) {
    int key = hashFunc(find);
    if (x != previous) {
        if (x->next != NULL) {
            previous->next = x->next;
            delete x;
            int temp = arr[key]->getListCount();
            temp--;
            arr[key]->setListCount(temp);
            //inbetween
        }
        else {
            previous->next = NULL;
            arr[key]->tail = previous;
            delete x;
            int temp = arr[key]->getListCount();
            temp--;
            arr[key]->setListCount(temp);
            //tail
        }
    }
    else if (x == arr[key]->head) {
        if (arr[key]->head->next == NULL) {
            delete arr[key];
            arr[key] = NULL;
        }
        else {
            arr[key]->head = x->next;
            delete x;
            int temp = arr[key]->getListCount();
            temp--;
            arr[key]->setListCount(temp);
        }
        //head
    }
    else {
        std::cout << "shit broke lmao" << std::endl;
    }
}

/*
-- removes data from hash table
*/
void HashTable::searchOptionEight(nbaPlayoff* x) {
    int key = hashFunc(x);
    if (arr[key] != NULL) {
        searchOptionEightRecur(arr[key]->head, arr[key]->head, x);
    }
    else {
        std::cout << "Value Not Found!" << std::endl;
    }
}

/*
--Recursive Func that finds Value and calls delete
*/
void HashTable::searchOptionEightRecur(HashNode* x, HashNode* previous, nbaPlayoff* find) {
    if (x != NULL) {
        if (*x->value == *find) {
            std::ofstream ofile;
            ofile.open("output.txt", ios::out | ios::app | ios::binary);

            std::cout << "Saved To File" << std::endl;
            ofile << x->value << std::endl;

            ofile.close();
        }
        else if (x->next != NULL)
        {
            searchOptionEightRecur(x->next, x, find);
        }
        else {
            std::cout << "Value Not Found" << std::endl;
        }
    }
    else {
        std::cout << "Value Not Found" << std::endl;
    }
}

/*
-- Inserts data into hash table
*/
void HashTable::insert(nbaPlayoff* v) {
    int key = hashFunc(v);
    if (arr[key] == NULL) {
        arr[key] = new HashNodeLink();
        HashNode* h = new HashNode(key, v);
        arr[key]->setHead(h);
        arr[key]->setTail(h);
        int temp = arr[key]->getListCount();
        temp++;
        arr[key]->setListCount(temp);
        count++;
    }
    else {
        HashNode* t = new HashNode(key, v);
        t->next = arr[key]->head;
        arr[key]->head = t;
        int temp = arr[key]->getListCount();
        temp++;
        arr[key]->setListCount(temp);
        collisions++;
    }
}

/*
-- searches hash table for key

    @Notes Not really used
*/
bool HashTable::searchKey(int key) {
    if (arr[key] != NULL) {
        return true;
    }
    else {
        return false;
    }
}

/*
-- Searchs HashTable for class and preforms reOrg if not found at the front of the list
*/
bool HashTable::search(nbaPlayoff* x) {
    int key = hashFunc(x);
    if (arr[key] != NULL) {
        if (searchRecur(arr[key]->head, arr[key]->head, x)) {
            std::cout << "Found Value @ Index: " << key << std::endl;
            return true;
        }
        else {
            std::cout << "Value Not Found!" << std::endl;
            return false;
        }
    }
    else {
        std::cout << "Value Not Found!" << std::endl;
        return false;
    }
}

/*
-- recursively moves through lists to find class and preforms reOrg
*/
bool HashTable::searchRecur(HashNode* x, HashNode* previous ,nbaPlayoff* find) {
    if (x != NULL) {
        if (*x->value == *find) {
            reOrg(previous, x, find);
            return true;
        }
        if (x->next != NULL) {
            return searchRecur(x->next, x, find);
        }
        else {
            return false;
        }
    }
    else {
        return false;
    }
}

/*
-- The Famous ReOrg that took me too long haha

    @notes: moves searched values to the front of list
*/
void HashTable::reOrg(HashNode* previous, HashNode* current, nbaPlayoff* find) {
    int key = hashFunc(find);
    if (current != previous) {
        if (current->next != NULL) {
            previous->next = current->next;
            current->next = arr[key]->head;
            arr[key]->head = current;
        }
        else {
            previous->next = NULL;
            arr[key]->tail = previous;
            current->next = arr[key]->head;
            arr[key]->head = current;
        }
    }
    else if(current == arr[key]->head){
        return;
    }
    else {
        return;
    }
}

/*
-- prints hash table with NULLs to console
*/
void HashTable::printTable() {
    for (int i = 0; i < tableSize; i++) {
        if (arr[i] != NULL) {
            std::cout << arr[i]->head->value << std::endl;
            printRecur(arr[i]->head->next);
        }
        else {
            std::cout << "NULL " << std::endl;
        }
    }
    std::cout << std::endl;
}

/*
-- prints hash table with NULLs to output file
*/
void HashTable::printToFile(std::ofstream& out) {
    for (int i = 0; i < tableSize; i++) {
        if (arr[i] != NULL) {
            out << arr[i]->head->value;
            printTableFile(arr[i]->head->next, out);
        }
        else {
            out << "NULL " << std::endl;
        }
    }
}

/*
-- recursive print to output file
*/
void HashTable::printTableFile(HashNode* x, std::ofstream& out) {
    if (x != NULL) {
        out << "--" << x->value << std::endl;
        printTableFile(x->next, out);
    }
    else {
        return;
    }
}

/*
-- recursive print to console
*/
void HashTable::printRecur(HashNode* x) {
    if (x != NULL) {
        std::cout << "--" << *x->value << std::endl;
        printRecur(x->next);
    }
    else {
        return;
    }
}

/*
-- Prints All Efficiency values
*/
void HashTable::printEfficiencies() {
    getCollisions();
    std::cout << std::endl;
    loadFactor();
    std::cout << std::endl;
    getLongest();
    std::cout << std::endl;
    getAverageNodes();
}
