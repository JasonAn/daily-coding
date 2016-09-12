//
// Created by an on 9/11/2016.
//
#include <iostream>
#include <vector>

#ifndef CHAP9_MAIN_H
#define CHAP9_MAIN_H


class Student_info {
public:
    Student_info(): midterm(0), final(0);
    Student_info(std::istream&);

    double grade() const;
    std::istream& read(std::istream&);
    std::string name() const {return n};
    bool valid() const{return !homework.empty();}

private:
    std::string n;
    double midterm, final;
    std::vector<double> homework;

};



istream& Student_info::read(std::istream& in){

    in >> name >> midterm >> final;
    read_hw(in, homework);
    return in;
}

double Student_info::grade() const{
    return ::grade(midterm, final, homework);



};

bool compare(const








             Student_info &, const Student_info&)



#endif //CHAP9_MAIN_H
