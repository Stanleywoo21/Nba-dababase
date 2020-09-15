#include "nbaPlayoff.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

/* default constructor
Pre:
Post:
Return:
*/
nbaPlayoff::nbaPlayoff()
{
    year = 0;
    champ = "";
    runnerUp = "";
    fMvp = "";
    points = "";
    rebounds = "";
    assists = "";
}

/*
 destructor
 */
nbaPlayoff::~nbaPlayoff()
{

}

/* set year
Pre: int x - int of year
Post:
Return:
*/
void nbaPlayoff::setYear(int x) {
    year = x;
}

/* set Champ
Pre: string x - data champ
Post:
Return:
*/
void nbaPlayoff::setChamp(std::string x) {
    champ = x;
}

/* set fMVP
Pre: string x - data fmvp
Post:
Return:
*/
void nbaPlayoff::setfMvp(std::string x) {
    fMvp = x;
}

/* set Points
Pre: string x - data points leader
Post:
Return:
*/
void nbaPlayoff::setPoints(std::string x) {
    points = x;
}

/* set rebounds
Pre: string x - data rebound leader
Post:
Return:
*/
void nbaPlayoff::setRebounds(std::string x) {
    rebounds = x;
}

/* set runnerup
Pre: string x - data runnerup
Post:
Return:
*/
void nbaPlayoff::setRunnerup(std::string x) {
    runnerUp = x;
}

/* set Points
Pre: string x - data assist leader
Post:
Return:
*/
void nbaPlayoff::setAssists(std::string x) {
    assists = x;
}

/* ==operator
Pre: x - an nbaPlayoff obj
Post:
Return: true the both years  are the same, else false.
*/
bool nbaPlayoff::operator==(nbaPlayoff x) {
    if (year == x.year) {
        return true;
    }
    else {
        return false;
    }
}

/* output the nbaPlayoff obj
Pre: x - pointer of nbaPlayoff
     out - ofsream
Post:
Return:
*/
std::ofstream& operator<<(std::ofstream& out, nbaPlayoff* x) {
    out << x->year << " " << x->champ << " " << x->runnerUp << " " << x->fMvp << " " << x->points << " " << x->rebounds << " " << x->assists << std::endl;

    return out;
}

/* output the nbaPlayoff obj
Pre: x - pointer of nbaPlayoff
     out - ofsream
Post:
Return:
*/
std::ostream& operator<<(std::ostream& out, nbaPlayoff* x) {
    out << x->year << " " << x->champ << " " << x->runnerUp << " " << x->fMvp << " " << x->points << " " << x->rebounds << " " << x->assists;

    return out;
}

/* output the nbaPlayoff obj
Pre: x - reerence of nbaPlayoff
     out - ofsream
Post:
Return:
*/
std::ostream& operator<<(std::ostream& out, nbaPlayoff& x) {
    out << x.year << " " << x.champ << " " << x.runnerUp << " " << x.fMvp << " " << x.points << " " << x.rebounds << " " << x.assists;
    std::cout << std::endl;
    return out;
}

/* input the nbaPlayoff obj
Pre: x - pointer of nbaPlayoff
    in - istream
Post:
Return:
*/
nbaPlayoff* operator>>(std::istream& in, nbaPlayoff* x) {
    int year;
    std::string c, rup, fmvp, points, rebo, ass;

    in >> year >> c >> rup >> fmvp >> points >> rebo >> ass;

    x->year = year;
    x->champ = c;
    x->runnerUp = rup;
    x->fMvp = fmvp;
    x->points = points;
    x->rebounds = rebo;
    x->assists = ass;

    return x;
}

/* input the nbaPlayoff obj
Pre: x - pointer of nbaPlayoff
    in - istream
Post:
Return:
*/
nbaPlayoff* operator>>(std::ifstream& in, nbaPlayoff* x) {
    int year;
    std::string c, rup, fmvp, points, rebo, ass;

    in >> year >> c >> rup >> fmvp >> points >> rebo >> ass;

    x->setYear(year);
    x->setChamp(c);
    x->setfMvp(fmvp);
    x->setPoints(points);
    x->setRebounds(rebo);
    x->setAssists(ass);
    x->setRunnerup(rup);

    return x;
}

/* input the nbaPlayoff obj
Pre: x - reference of nbaPlayoff
    in - istream
Post:
Return:
*/
nbaPlayoff& operator>>(std::ifstream& in, nbaPlayoff& x) {
    int year;
    std::string c, rup, fmvp, points, rebo, ass;

    in >> year >> c >> rup >> fmvp >> points >> rebo >> ass;

    x.year = year;
    x.champ = c;
    x.runnerUp = rup;
    x.fMvp = fmvp;
    x.points = points;
    x.rebounds = rebo;
    x.assists = ass;

    return x;
}

/* assign operator -> it assigns data to a new nba obj.
Pre: x - nbaPlayoff obj
Post:
Return:
*/
void nbaPlayoff::operator=(nbaPlayoff x) {
    this->year = x.year;
    this->champ = x.champ;
    this->runnerUp = x.runnerUp;
    this->fMvp = x.fMvp;
    this->points = x.points;
    this->rebounds = x.rebounds;
    this->assists = x.assists;
}

/* operator<
Pre: x - reference of nbaPlayoff
    y - reference of nbaPlayoff
Post:
Return: returns true if x < y. else false
*/
bool operator<(nbaPlayoff& x, nbaPlayoff& y) {
    std::ostringstream streamX;
    streamX << x.getChamp() << x.getYear();
    std::string stringX = streamX.str();
    
    std::ostringstream streamY;
    streamY << y.getChamp() << y.getYear();
    std::string stringY = streamY.str();
    return stringX < stringY;
}

/* operator>
Pre: x - reference of nbaPlayoff
    y - reference of nbaPlayoff
Post:
Return: returns true if x > y. else false
*/
bool operator>(nbaPlayoff& x, nbaPlayoff& y) {
    std::ostringstream streamX;
    streamX << x.champ << x.year;
    std::string stringX = streamX.str();
    
    
    std::ostringstream streamY;
    streamY << y.champ << y.year;
    std::string stringY = streamY.str();
    
    return stringX > stringY;
}
