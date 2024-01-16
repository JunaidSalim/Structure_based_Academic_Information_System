#include <iostream>
#include <string>
using namespace std;

struct Course
{
    int ID;
    string CourseName;
    string teacher;
    int fee;
    int creditHours;
    void PrintAll()
    {
        cout<<"ID: "<<ID<<endl;
        cout<<"Course Name: "<<CourseName<<endl;
        cout<<"Teacher: "<<teacher<<endl;
        cout<<"Fee: "<<fee<<endl;
        cout<<"Credit Hours: "<<creditHours<<endl;
    }

};

struct CourseList
{
    Course courses[5];
    int a = 0;
    void PrintAll()
    {
        for(int i = 0; i<5; i++)
        {
            if(courses[i].CourseName.empty())
                cout<<endl;
            else
            {
                cout<<"Course "<<i+1<<": "<<endl;
                courses[i].PrintAll();
                cout<<endl;
            }
        }
    }

    void Add(Course info, int index)
    {
        if(a<5)
            courses[index]=info;
        else
            cout<<"The array is out of space.";
        
    }

    bool Delete(string teacher)
    {
        bool found = false;
        for(int i = 0; i<5; i++)
        {
            if(courses[i].teacher == teacher)
            {
                courses[i].ID = 0;
                courses[i].CourseName.clear();
                courses[i].teacher.clear();
                courses[i].fee = 0;
                courses[i].creditHours = 0;
                found = true;
            } 
        }
        return found;
    }

    void Sort(int choice)
    {
        Course temp[1];
        if (choice == 8) //ascending --> low to high
        {
            for(int i = 0; i<5; i++)
            {
                for(int k = 0; k<5; k++)
                {
                    if (courses[k].ID>courses[k+1].ID)
                    {
                        temp[0] = courses[k];
                        courses[k] = courses[k+1];
                        courses[k+1]= temp[0];
                    }
                }
            }
        }
        else if (choice == 9) //descending --> high to low
        {
            for(int i = 0; i<5; i++)
            {
                for(int k = 0; k<5; k++)
                {
                    if (courses[k].ID<courses[k+1].ID)
                    {
                        temp[0] = courses[k];
                        courses[k] = courses[k+1];
                        courses[k+1]= temp[0];
                    }
                }
            }
        }
    }


};

struct Student
{
    int ID;
    string StdName;
    int RollNo;
    void PrintAll()
    {
        cout<<"ID: "<<ID<<endl;
        cout<<"Student Name: "<<StdName<<endl;
        cout<<"Roll Number: "<<RollNo<<endl;
    }
};

struct StudentList
{
    Student std[5];
    int i = 0;
    void PrintAll()
    {
        for(int i = 0; i<5; i++)
        { 
            if(std[i].StdName.empty())
                cout<<endl;
            else
            {
                cout<<"Student "<<i+1<<": "<<endl;
                std[i].PrintAll();
                cout<<endl;
            }
        }
    }
    void Add(int ID, string name, int rollno)
    {
        if (i<=5)
        {
            std[i].ID = ID;
            std[i].StdName = name;
            std[i].RollNo = rollno;
            i++;
        }
    }

    bool Delete(int ID)
    {
        bool found = false;
        for(int i = 0; i<5; i++)
        {
            if(std[i].ID == ID)
            {
                std[i].ID = 0;
                std[i].StdName.clear();
                std[i].RollNo = 0;
                found = true;
            }
            
        }
        return found;
        
    }
    
};


int main()
{
    int input, id, rollno, index, i, std_size = 0, crs_size = 0;
    string name, coursename, teacher;
    StudentList std_list;
    CourseList crs_list;
    Course course;
    bool found_std, found_crs;
    while(true)
    {
        cout << "==============================================" << endl;
        cout << "                Main Menu" << endl;
        cout << "==============================================" << endl;
        cout << " 1. Add New Student" << endl;
        cout << " 2. Delete Existing Student" << endl;
        cout << " 3. Show All Students" << endl;
        cout << " 4. Add New Course" << endl;
        cout << " 5. Delete Existing Course" << endl;
        cout << " 6. Show Particular Course" << endl;
        cout << " 7. Show All Courses" << endl;
        cout << " 8. Sort Courses in Ascending Order" << endl;
        cout << " 9. Sort Courses in Descending Order" << endl;
        cout << "10. Exit" << endl;
        cout << "==============================================" << endl;
        cout << "Enter your choice: ";
        cin >> input;

        switch (input)
        {
            case 1: //add new student
                cout<<"Enter ID: ";
                cin>>id;
                cin.ignore();
                cout<<"Enter name: ";
                getline(cin, name);
                cout<<"Enter roll number: ";
                cin>>rollno;
                
                std_list.Add(id, name, rollno);
                std_size++;
                break;
            case 2: //delete existing student
                cout<<"Enter ID: ";
                cin>>id;
                found_std = std_list.Delete(id);
                if (found_std == true)
                {
                    std_size--;
                    cout<<"Deleted."<<endl;
                }
                else
                    cout<<"Student not found."<<endl;
                break;
            case 3: //show all students
                if(std_size == 0)
                    cout<<"There are no students found in the record."<<endl;
                else
                    std_list.PrintAll();
                break;
            case 4:
                cout<<"Enter ID: ";
                cin>>course.ID;
                cout<<"Enter course name: ";
                cin>>course.CourseName;
                cin.ignore();
                cout<<"Enter teacher name: ";
                getline(cin, course.teacher);
                cout<<"Enter fee: ";
                cin>>course.fee;
                cout<<"Enter credit hours: ";
                cin>>course.creditHours;
                cout<<"Enter index in array: ";
                cin>>index;
                
                crs_list.Add(course, index);
                crs_list.a++;
                crs_size++;
                break;
            case 5: //delete existing course
                cout<<"Enter teacher name: ";
                cin>>teacher;
                found_crs = crs_list.Delete(teacher);
                if (found_crs == true)
                {
                    crs_size--;
                    cout<<"Deleted."<<endl;
                }
                else
                    cout<<"Course not found."<<endl;
                break;
            case 6:
                cout<<"Enter which array index you would like to access: ";
                cin>>i;
                if (crs_list.courses[i].teacher.empty())
                    cout<<"No record found at particular index."<<endl;
                else
                    crs_list.courses[i].PrintAll();
                break;
            case 7: //show all courses
                if(crs_size == 0)
                    cout<<"There are no courses found in the record."<<endl;
                else
                    crs_list.PrintAll();
                break;
            case 8:
                if(crs_size < 2)
                    cout<<"Array does not have enough courses to sort."<<endl;
                else
                    {
                        crs_list.Sort(8);
                        cout<<"Array has been sorted in ascending order."<<endl;
                    }
                break;
            case 9:
                if(crs_size < 2)
                    cout<<"Array does not have enough courses to sort."<<endl;
                else
                    {
                        crs_list.Sort(9);
                        cout<<"Array has been sorted in descending order."<<endl;
                    }
                break;
            case 10:
                return 0;
            default:
                cout<<"Invalid request. Please try again."<<endl;
                break;
        }
    }
 
}
