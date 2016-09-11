#include <iostream>

bool space(char c)
{
    return isspace(c);
}

bool not_space(char c)
{
    return !isspace(c);
}

vector<string> split(const string& str)
{
    typedef string::const_iterator iter;
    vector<string> ret;

    iter i = str.begin();

    while (i != str.end()){

        i = find_if(i, str.end(), not_space);

        iter j = find_if(i, str.end(), space);

        if (i != str.end())
            ret.push_back(string(i, j));

        i = j;

    }

    return ret;
}


bool not_url_char(char c) {

    static const string url_ch = "abcdef";

    return !(isalnum(c) || find (url_ch.begin(), url_ch.end(), c) != url_ch.end());


}

string::const_iterator url_end(string::const_iterator b, string_const_iterator e) {
    return find_if(b, e, not_url_char);

}

vector<string> find_urls(const strings& s)
{

    vector<string> ret;
    typedef string::const_iterator iter;

    iter b = s.begin(), e = s.end();

    while( b != e )
    {
        b = url_end(b, e);

        if (b != e) {
            iter after = url_end(b, e);

                ret.push_back(string(b, after)); // double check is a choice.

                b = after;
            }
        }

    return ret;

    }

string::const_iterator url_beg(string::const_iterator b, string::const_iterator e) {

    static const string seg = "://";

    typedef string::const_iterator iter;

    iter i = b;

    while(i = search(i, e, seg.begin(), seg.end())){

        if (i != b && i + sep.size() != e) {

            iter beg = i;

            while (beg != b && isalpha(beg[-1]))
                --beg;

            if (beg != i && !not_url_char(i[sep.size()]))
                return beg;

        }

        i += sep.size();

    }

    return e;

}

double median_analysis(const vector<Student_info> & students){

    vector<double> grades;

    transform(students.begin(), students.end(), back_inserter(grades), grade)
}

double grade_aux(const Student_info& s)
{
    try{
        return grades(s);
    }

    catch (domain_error){
        return grade(s.midterm, s.final, 0)
    }
}


double optimistic_median(const Student_info& s){

    vector<double> nonzero;
    remove_copy(s.homework.begin(), s.homework.end(), back_inserter(nonzero), 0);

    if (nonzero.empty())
        return grade(s.midterm, s.final, 0);
    else
        return grade(s.midterm, s.final, median(nonzero));
}