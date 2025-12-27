#include <bits/stdc++.h>

using namespace std;

class Student
{
public:
    string name;
    int roll;
    int marks;
    Student(string s, int r, int m)
    {
        name = s;
        roll = r;
        marks = m;
    }
};

class cmp
{
public:
    bool operator()(Student &l, Student &r)
    {
        if (l.marks == r.marks)
            return l.roll > r.roll;
        else
            return l.marks < r.marks;
    }
};

int main()
{
    int n;
    cin >> n;
    priority_queue<Student, vector<Student>, cmp> pq;
    while (n--)
    {
        string s;
        int roll, marks;
        cin >> s >> roll >> marks;
        Student obj = Student(s, roll, marks);
        pq.push(obj);
    }
    int q;
    cin >> q;
    while (q--)
    {
        int c;
        cin >> c;
        if (c == 0)
        {
            string s;
            int roll, marks;
            cin >> s >> roll >> marks;
            pq.push(Student(s, roll, marks));
            cout << pq.top().name << " " << pq.top().roll << " " << pq.top().marks << endl;
        }
        else if (c == 1)
        {
            if (pq.empty())
                cout << "Empty\n";
            else
                cout << pq.top().name << " " << pq.top().roll << " " << pq.top().marks << endl;
        }
        else
        {
            if (pq.empty())
                cout << "Empty\n";
            else
            {
                pq.pop();
                if (pq.empty())
                    cout << "Empty\n";
                else
                    cout << pq.top().name << " " << pq.top().roll << " " << pq.top().marks << endl;
            }
        }
    }
}
