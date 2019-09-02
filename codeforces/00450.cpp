#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;


struct employee {
    string title;
    string first_name;
    string last_name;
    string address;
    string h_phone;
    string w_phone;
    string box;
    string department;

    /*employee() {};
    employee(const employee& other) : title(other.title), first_name(other.first_name), \
    last_name(other.last_name), address(other.address), h_phone(other.h_phone), w_phone(other.w_phone), \
    box(other.box), department(other.department)
    {}
    */

    bool operator < (const employee &other) const {
        return this->last_name < other.last_name;
    }

};


int main() {
    // dummy department number
    string D;
    getline(cin, D); 

    vector<employee> all_employees;
    employee tmp;

    string cur_dep, cur_employee;

    getline(cin, cur_dep);
    while(getline(cin, cur_employee)) {
        if(cur_employee == "") {
            getline(cin, cur_dep);
            continue;
        }

        vector<string> tokens;
        size_t start = 0, end = 0;
        while ((end = cur_employee.find(',', start)) != string::npos) {
            tokens.push_back(cur_employee.substr(start, end - start));
            start = end + 1;
        }
        tokens.push_back(cur_employee.substr(start));

        tmp.title = tokens[0];
        tmp.first_name = tokens[1];
        tmp.last_name = tokens[2];
        tmp.address = tokens[3];
        tmp.h_phone = tokens[4];
        tmp.w_phone = tokens[5];
        tmp.box = tokens[6];
        tmp.department = cur_dep;

        all_employees.push_back(tmp);
        //cout << "pushing" << endl;
    }

    std::sort(all_employees.begin(), all_employees.end());

    //cout << all_employees.size() << endl;
    //return 0;

    for(employee emp: all_employees) {
        cout << "----------------------------------------" << endl;
        cout << emp.title << " " << emp.first_name << " " << emp.last_name << endl;
        cout << emp.address << endl;

        cout << "Department: " << emp.department << endl;
        cout << "Home Phone: " << emp.h_phone << endl;
        cout << "Work Phone: " << emp.w_phone << endl;
        cout << "Campus Box: " << emp.box << endl;
    }
    return 0;
}