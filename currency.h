//
//  currency.h
//  CIS_22C
//
//  Created by Stanley Woo on 6/10/20.
//  Copyright © 2020 Stanley Woo. All rights reserved.
//

//#ifndef currency_h
//#define currency_h
//#include <iostream>
//
//class Currency
//{
//protected:
//    int wholeVal;
//    int coinVal;
//public:
//    virtual std::string getNoteName() { return " "; }
//    virtual std::string getCoinName() { return " "; }
//    virtual int getWholeVal() { return wholeVal; }
//    virtual int getCoinVal() { return coinVal; }
//    virtual void setNoteName(std::string n) { return; }
//    virtual void setCoinName(std::string c) { return; }
//    virtual void setNoteValue(int note)
//    {
//        wholeVal = note;
//    }
//    virtual void setCoinValue(int coin)
//    {
//        coinVal = coin;
//    }
//    Currency();
//    Currency(int wVal, int cVal);
//
//    /*
//    Pre: istream object passed by reference, Currency object passed by reference
//    Post: Note name, note value, coin value, and coin name inputted
//    Return istream object passed by reference
//    */
//    friend std::istream& operator>> (std::istream& in, Currency& right);
//    /*
//    Pre: ostream object passed by reference, Currency object passed by reference
//    Post: Note name, note value, coin value, and coin name outputted
//    Return ostream object passed by reference
//    */
//    friend std::ostream& operator<< (std::ostream& out, Currency& right);
//    /*
//    Pre: 2 Currency objects passed by reference
//    Post: Note and coin values of 2nd Currency object added to 1st Currency object
//    Return 1st Currency object passed by reference
//    */
//    friend Currency operator+ (Currency& c1, Currency& c2);
//    /*
//    Pre: 2 Currency objects passed by reference
//    Post: Note and coin values of 2nd Currency object subtracted from 1st Currency object
//    Return 1st Currency object passed by reference
//    */
//    friend Currency operator- (Currency& c1, Currency& c2);
//    /*
//    Pre: 2 Currency objects passed by reference
//    Post: Compares 1st Currency object's note and coin values with 2nd Currency object's
//    Return true if 1st Currency object is less than 2nd Currency object, false otherwise
//    */
//    bool operator< (Currency& right) const;
//    /*
//    Pre: 2 Currency objects passed by reference
//    Post: Compares 1st Currency object's note and coin values with 2nd Currency object's
//    Return true if 1st Currency object is greater than 2nd Currency object, false otherwise
//    */
//    bool operator> (Currency& right) const;
//    /*
//    Pre: 2 Currency objects passed by reference
//    Post: Compares to see if both Currency objects are equal
//    Return true if Currency objects are equal, false otherwise
//    */
//    bool operator== (Currency& right) const;
//    /*
//    Pre: 2 Currency objects passed by reference
//    Post: Compares to see if Currency objects are not equal
//    Return true if Currency objects are not equal, false otherwise
//    */
//    bool operator!= (Currency& right) const;
//};
//
//
//class Dollar : public Currency
//{
//protected:
//    std::string noteName;
//    std::string coinName;
//    std::string getNoteName() { return noteName; }
//    std::string getCoinName() { return coinName; }
//    int getWholeVal() { return wholeVal; }
//    int getCoinVal() { return coinVal; }
//    void setNoteName(std::string n) { noteName = "Dollar"; }
//    void setCoinName(std::string c) { coinName = "cent"; }
//public:
//    Dollar() : Currency() {}
//    Dollar(std::string nName, int wVal, int cVal, std::string cName) : Currency(wVal, cVal)
//    {
//        noteName = nName;
//        coinName = cName;
//    }
//};
//
//class Pound : public Currency
//{
//protected:
//    std::string noteName;
//    std::string coinName;
//    std::string getNoteName() { return noteName; }
//    std::string getCoinName() { return coinName; }
//    int getWholeVal() { return wholeVal; }
//    int getCoinVal() { return coinVal; }
//    void setNoteName(std::string n) { noteName = n; }
//    void setCoinName(std::string c) { coinName = c; }
//public:
//    Pound() : Currency() {}
//    Pound(std::string nName, int wVal, int cVal, std::string cName) : Currency(wVal, cVal)
//    {
//        noteName = nName;
//        coinName = cName;
//    }
//};
//
//class Yen : public Currency
//{
//protected:
//    std::string noteName;
//    std::string coinName;
//    std::string getNoteName() { return noteName; }
//    std::string getCoinName() { return coinName; }
//    int getWholeVal() { return wholeVal; }
//    int getCoinVal() { return coinVal; }
//    void setNoteName(std::string n) { noteName = n; }
//    void setCoinName(std::string c) { coinName = c; }
//public:
//    Yen() : Currency() {}
//    Yen(std::string nName, int wVal, int cVal, std::string cName) : Currency(wVal, cVal)
//    {
//        noteName = nName;
//        coinName = cName;
//    }
//};
//
//class Rupee : public Currency
//{
//protected:
//    std::string noteName;
//    std::string coinName;
//    std::string getNoteName() { return noteName; }
//    std::string getCoinName() { return coinName; }
//    int getWholeVal() { return wholeVal; }
//    int getCoinVal() { return coinVal; }
//    void setNoteName(std::string n) { noteName = n; }
//    void setCoinName(std::string c) { coinName = c; }
//public:
//    Rupee() : Currency() {}
//    Rupee(std::string nName, int wVal, int cVal, std::string cName) : Currency(wVal, cVal)
//    {
//        noteName = nName;
//        coinName = cName;
//    }
//};
//
//class Real : public Currency
//{
//protected:
//    std::string noteName;
//    std::string coinName;
//    std::string getNoteName() { return noteName; }
//    std::string getCoinName() { return coinName; }
//    int getWholeVal() { return wholeVal; }
//    int getCoinVal() { return coinVal; }
//    void setNoteName(std::string n) { noteName = n; }
//    void setCoinName(std::string c) { coinName = c; }
//public:
//    Real() : Currency() {}
//    Real(std::string nName, int wVal, int cVal, std::string cName) : Currency(wVal, cVal)
//    {
//        noteName = nName;
//        coinName = cName;
//    }
//};
//
//
//#endif /* currency_h */
