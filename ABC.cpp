
#include <iostream>;

using namespace std;

void intro()
{
    cout << endl;
    cout << "Welcome to the testing facility.\n";
    cout << "Please answer all the following questions: \n";
}

string Questions[4] = {"What is your name?", "How old are you?", "What is your profession?", "Are you married? Y/N"};
string Answers[4] = {"Name: ", "Age: ", "Profession: ", "Married Y/N: "};
const int MAX_NAME_LENGTH = 100;
const int MAX_PROFESSION_LENGTH = 100;
int Age;
string Married;
bool AnsweredAll = false;        

char Name[MAX_NAME_LENGTH], Profession[MAX_PROFESSION_LENGTH];    

void AnsweringQuestions()
{

    intro();    

    cout << endl;
    cout << Questions[0] << endl;
    cin.getline(Name, MAX_NAME_LENGTH);    
    
    cout << Questions[2] << endl;
    cin.getline(Profession, MAX_PROFESSION_LENGTH);

    cout << Questions[1] << endl;
    cin >> Age;

    cout << Questions[3] << endl;
    cin >> Married;
    cout << endl;

    AnsweredAll = true;

}

int main()
{        
    AnsweringQuestions();
    string DetailsCorrect;
    while (AnsweredAll == false)
    {
        cin.clear();
        cin.ignore();
    }

    if(AnsweredAll == true)
    {
        cout << endl;
        cout << "Are these details correct?\n";
        cout << Answers[0] << Name << endl;
        cout << Answers[1] << Age << endl;
        cout << Answers[2] << Profession << endl;
        cout << Answers[3] << Married << endl;
        cin >> DetailsCorrect;

        if(DetailsCorrect == "Yes")
        {
            //do nothing
        }
        else
        {
            
        }
        
    }
     
    return 0;
}

// Write a program to: 
// - Ask question
// Wait for input answer
// once all done, print as if form and end program