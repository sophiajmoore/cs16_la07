// Funcions.cpp
// By: Sophia Moore
// Created on 11/19/20

void InitializeStructures(UndergradStudents us[], int &size) 
{
    size = 0;

    char exit_letter = 'X'; // adding x to a string so i can compare it with first_name later on
    string exit;
    exit.append(1, exit_letter);

    UndergradStudents student; // making a student
    cout << "Enter first name for student " << size+1 << " (or X to quit): ";
    getline(cin, student.first_name);

    while (student.first_name != exit  && size < 20)
    {
        cout << "Enter last name for student " << size+1 << ": ";
        getline(cin, student.last_name);
        cout << "Enter major for student " << size+1 << ": ";
        getline(cin, student.major);
        cout << "Enter GPA Year 1 for student " << size+1 << ": ";
        cin >> student.gpa1;
        cin.get();
        cout << "Enter GPA Year 2 for student " << size+1 << ": ";
        cin >> student.gpa2;
        cin.get();
        cout << "Enter GPA Year 3 for student " << size+1 << ": ";
        cin >> student.gpa3;
        cin.get();
        cout << "Enter GPA Year 4 for student " << size+1 << ": ";
        cin >> student.gpa4;
        cout << endl;
        cin.get();
        student.id_number = size+1;

        us[size] = student;

        size++;

        // instead of making another student, i'm just adjusting the OG student
        // Also first name is down here so the loop checks if first name is x before 
        // doing anything else
        if (size < 20)
        {
            cout << "Enter first name for student " << size+1 << " (or X to quit): ";
            getline(cin, student.first_name);
        }

    }

    // using bubblesort function
    BubbleSort(us, size);

    return;
}

void WriteResults(ofstream &outf, UndergradStudents us[], int size) 
{
    // opening ofstream
    outf.open("Results.txt");
    double average_gpa;

    // making doubles have 2 decimal places
    outf.setf(ios::fixed);
    outf.setf(ios::showpoint);
    outf.precision(2);

    outf << "These are the sorted results:\n";
    for (int i = 0; i < size; i++)
    {
        average_gpa = AverageGPA(us[i].gpa1, us[i].gpa2, us[i].gpa3, us[i].gpa4);
        outf << "ID# " << us[i].id_number << ", "
            << us[i].last_name << ", "
            << us[i].first_name << ", "
            << us[i].major << ", "
            << "Average GPA: " << average_gpa << endl;
    }

    // closing ofstream!
    outf.close();
    return;
}

void BubbleSort(UndergradStudents us[], int size)
{
    UndergradStudents temp;
    for (int i = size-1; i >= 0; i--)
    {
        for (int j = 1; j <= i; j++)
        {
            if (us[j-1].last_name > us[j].last_name) // sorting by last name!
            {
                temp = us[j-1];
                us[j-1] = us[j];
                us[j] = temp;
            }
        }
    }
}

double AverageGPA(double gpa1, double gpa2, double gpa3, double gpa4)
{
    double average_gpa = (gpa1+gpa2+gpa3+gpa4)/4;

    return average_gpa;
}
