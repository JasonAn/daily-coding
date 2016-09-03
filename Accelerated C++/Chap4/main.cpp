#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>

#include "main.h"

using namespace std;


int main(){


  vector<Student_info> students; // student_info class or struct

  Student_info record;

  string::size_type maxlen = 0;

  while (read(cin, record)){ // read function?

    maxlen = max(maxlen, record.name.size());
    students.push_back(record);
  }

  sort(students.begin(), students.end(), compare);

  for (vector<Student_info>::size_type i = 0; i != students.size(); i++){

    cout << students.size();

    cout << students[i].name << string(maxlen + i - students[i].name.size(), ' '); // what is this string?

    try{
        double final_grade = grade(students[i]);
        cout << final_grade;
    }catch(domain_error e){
      cout << e.what();   // this module useful
    }
    cout << endl;
  }

  return 0;
}
