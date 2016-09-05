#include <iostream>
#include "../Student_info.h"

bool fgrade(const Student_info& s){

  return grade(s) < 60;
  
}

vector<Student_info> extract_fails(vector<Student_info>& students)
{
  vector<Student_info> pass, fail;

  vector<Student_info>::const_iterator iter = students.begin();

  while (iter != students.end()){
    if(fgrade(*iter)) {
      fail.push_back(*iter);
      iter = students.erase(iter);
    }
    else
      iter++;
  }
  return fail;
}

vector<string> split(const string& s) {

  vector<string> ret;

  string::size_type i, j;

  i = 0;

  while (i != s.size()) {
    while (i != s.size() && isspace(s[i]))
      i++;

    j = i;

    while (j != s.size() && isspace(s[j]))
      j++;

    if (i != j) {
      ret.push_back(s.substr(i, j));
      i = j;
    }
  }

  return ret;
}

typedef string::size_type string_size;

string_size width(const vector<string> s){
  string_size max_length = 0;

  for (vector<string>::const_iterator iter = s.begin(); iter != s.end(); iter++)
    max_length = max(max_length, (*iter).size());

  return max_length;

}

vector<string> frame(const vector<string>& v){
  vector<string> ret;
  string_size maxlen = width(v);
  string border(maxlen + 4, '*');

  ret.push_back(border);
  for(vector<string>::size_type i = 0; i != v.size(); i++)
    ret.push_back("* "+ v[i] + string(maxlen - v[i].size(), ' ') + " *");
  ret.push_back(border);

  return ret;
}

vector<string> vcat(vector<string>& top, vector<string>& down){

  vector<string> ret = top;

  for (string_size i = 0; i != down.size(); i++)
    ret.push_back(down[i]);

  return ret;
}

vector<string> hcat(vector<string>& left, vector<string>& right){

  vector<string> ret;

  string_size len = width(left) + 1;

  string_size i = 0, j = 0;

  while(i != left.size() || j != right.size()){

    string s;
    if (i != left.size()) {
      s = left[i];
      i++;
    }

    s += string(len-left[i].size(), ' ');

    if( j != right.size()){
      s += right[j];
      j++;
    }

    return ret;



  }


}