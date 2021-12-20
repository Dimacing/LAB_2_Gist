#include <iostream>
using namespace std;
#include <time.h>
#include <chrono>
#define nameang "Dima","Vanya","Vika","Danil","Andrey","Anton","Arkadiy","Artur", "Boris","Vadim"

class person{
public:
    int age ;
    string name;
    int size;
    int start_age;
};

void sort(person *data, int size) {
    int i = 0;
    int j = size - 1;
    int mid = data[size / 2].age;
    do {
        while (data[i].age < mid) {
            i++;
        }
        while (data[j].age > mid) {
            j--;
        }
        if (i <= j) {
            swap(data[i], data[j]);
            i++;
            j--;
        }
    } while (i <= j);
    if (j > 0) {
        sort(data, j + 1);
    }
    if (i < size) {
        sort(&data[i], size - i);
    }
}

void print_person(const person *data)
{
    for(int i = 0; i < data->size;i++)
    {
        cout << "# " << i+1 <<endl;
        cout << "Name: " << data[i].name << endl << "Age: " << data[i].age<< endl;
    }
}

person* rand_person()
{
    srand(time(nullptr));
    cout<<" Size person: ";
    int size;
    cin >> size;
    string ang[] = {nameang};
    person *data =  new person[size];
    cout << "Diapazon age: " ;
    int  diap_age[2];
    cin >> diap_age[0];
    cin >> diap_age[1];

    for (int i = 0; i < size; i++)
    {
        if (diap_age[1] ==  diap_age[0])
        {
            data[i].age = diap_age[0];
            data[i].name = ang[rand() % 9];
            data[i].size  = size;
            data[i].start_age = diap_age[0];
        }
        data[i].age = diap_age[0] + rand() % ((diap_age[1] - diap_age[0]) + 1);
        data[i].name = ang[rand() % 9];
        data[i].size  = size;
        data[i].start_age = diap_age[0];
    }
    sort(data,size);
    return data;
}

person* console_person()
{
    cout<<" Size person: ";
    int size;
    cin >> size;
    person *data = new person[size];
    for (int i = 0; i < size; i++)
    {
        cout << " Person #" << i+1 << " " << endl;
        cout << " Name: ";
        cin >> data[i].name ;
        cout << "Age: ";
        cin >> data[i].age;
        data[i].size  = size;
    }
    sort(data,size);
    data->start_age = data[0].age;
    return data;

}