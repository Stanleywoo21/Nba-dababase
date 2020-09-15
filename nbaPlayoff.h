#include <iostream>
#include <fstream>
#include <string>

class nbaPlayoff
{
//protected:
//    int year;
//    std::string champ;
//    std::string runnerUp;
//    std::string fMvp;
//    std::string points;
//    std::string rebounds;
//    std::string assists;
public:
    int year;
    std::string champ;
    std::string runnerUp;
    std::string fMvp;
    std::string points;
    std::string rebounds;
    std::string assists;
    nbaPlayoff();
    ~nbaPlayoff();

    void setYear(int x);
    void setChamp(std::string);
    void setfMvp(std::string);
    void setPoints(std::string);
    void setRebounds(std::string);
    void setAssists(std::string);
    void setRunnerup(std::string);

    int getYear(){return year;}
    std::string getChamp(){return champ;}
    std::string getRunnerUp(){return runnerUp;}
    std::string getFMvp(){return fMvp;}
    std::string getPoints(){return points;}
    std::string getRebounds(){return rebounds;}
    std::string getAss(){return assists;}
    void operator=(nbaPlayoff x);
    bool operator==(nbaPlayoff x);
//    bool operator<(nbaPlayoff& right);
//    bool operator>(nbaPlayoff& right);
    friend bool operator>(nbaPlayoff& x, nbaPlayoff& y);
    friend bool operator<(nbaPlayoff& x, nbaPlayoff& y);
    friend std::ostream& operator<<(std::ostream& out, nbaPlayoff* x);
    friend std::ostream& operator<<(std::ostream& out, nbaPlayoff& x);
    friend std::ofstream& operator<<(std::ofstream& out, nbaPlayoff* x);
    friend nbaPlayoff* operator>>(std::istream& in, nbaPlayoff* x);
    friend nbaPlayoff* operator>>(std::ifstream& in, nbaPlayoff* x);
    friend nbaPlayoff& operator>>(std::ifstream& in, nbaPlayoff& x);
};
