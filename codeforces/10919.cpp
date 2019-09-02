#include <iostream>
#include <unordered_set>
using namespace std;

int main() {
    while(1){
        int chosen_num;
        cin >> chosen_num;

        //cout << "nuber of courses: " << chosen_num << endl;
        if (!chosen_num)
            break;
        //else
        //    cout << "more than 0" << endl;

        int categories;
        cin >> categories;
        
        unordered_set<int> course_numbers;

        for(int cur_course; chosen_num-- && cin >> cur_course;)
            course_numbers.insert(cur_course);


        bool completed = true;
        for(int i = 0; i < categories; i++) {
            int total, req;
            cin >> total >> req;

            while(total--){
                int tmp;
                cin >> tmp;
                if(course_numbers.find(tmp) != course_numbers.end())
                    req--;
            }

            if (req > 0)
                completed = false;
        }

        if(completed)
            cout << "yes" << endl;
        else
            cout << "no" << endl;

    }
}