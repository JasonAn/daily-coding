#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

struct Student_info{
  string name;
  double midterm, final;
  vector<double> homework;
};

bool compare(const Student_info& x, const Student_info& y){

    return x.name < y.name;
}

double median(vector<double> vec)
{
  typedef vector<double>::size_type vec_sz;

  vec_sz size = vec.size();

  if (size == 0)
    throw domain_error("median of an empty vector");

    sort(vec.begin(), vec.end());

    vec_sz mid = size/2;

    return size%2 == 0?(vec[mid] + vec[mid-1])/2 : vec[mid];
}

double grade(double midterm, double final, double homework){
  return 0.2 * midterm + 0.4 * final + 0.4 * homework;
}

double grade(double midterm, double final, const vector<double>& hw){

  if (hw.size() == 0)
    throw domain_error("student has done no homework");

  return grade(midterm, final, median(hw));
}

double grade(const Student_info &s){
  return grade(s.midterm, s.final, s.homework);
}

istream& read_hw(istream& in, vector<double>& hw){

    if(in){

      hw.clear();

      double x;
      while(in >> x)
        hw.push_back(x);

        in.clear();
    }

}


istream& read(istream& is, Student_info& s)
{
  is >> s.name >> s.midterm >> s.final;

  read_hw(is, s.homework);

  return is;
}
