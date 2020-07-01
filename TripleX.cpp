#include <iostream> //PREPROCESSOR DIRECTIVE (for printing to terminal)
#include <ctime> // accessing computer's time to use time in srand later

using namespace std;

void PrintIntro(int Difficulty)
{
    //Prints welcome messages to the terminal
    cout << "\n                                              |>>>\n";
    cout << "                                                |\n";
    cout << "                                            _  _|_  _\n";
    cout << "                                           |;|_|;|_|;|\n";
    cout << "                                           \\.    .  /\n";
    cout << "                                            \\:  .  /\n";
    cout << "                                             ||:   |\n";
    cout << "                                             ||:.  |\n";
    cout << "                                             ||:  .|\n";
    cout << "                                             ||:   |\n";
    cout << "                                             ||: , |\n";
    cout << "                                             ||:   |\n";
    cout << "                                             ||: . |\n";
    cout << "              __                            _||_   |\n";
    cout << "     ____--`~    '--~~__            __ ----~    ~`---,              ___\n";
    cout << "-~--~                   ~---__ ,--~'                  ~~----_____-~'   `~----~~\n";
    cout << "You arrive to the wizard's tower but find the entrance locked with a level " << Difficulty << " code."; //whole line is called an EXPRESSION STATEMENT (has ; after it)
    cout << std::endl; // endl - END LINE
    cout << "You need to enter the correct numbers to approach the wizard...\n\n"; // \n ends line as well. double gives two
}

bool PlayGame(int Difficulty)
{
    PrintIntro(Difficulty);

    const int CodeA = rand() % Difficulty + Difficulty; //DECLARATION STATEMENT
    const int CodeB = rand() % Difficulty + Difficulty;
    const int CodeC = rand() % Difficulty + 1; // % divides random number and gives remainder. this will give a value between 1 and Difficulty. avoid 0s by +1

    const int CodeSum = CodeA + CodeB + CodeC;
    const int CodeProduct = CodeA * CodeB * CodeC;
    
    //Print sum and product to the terminal, one below the other
    cout << std::endl;
    cout << "+ There are 3 numbers in the code.";
    cout << "\n+ The numbers add up to: " << CodeSum; // can use \n at the start of a new line as well
    cout << "\n+ If you multiply the numbers you get: " << CodeProduct << std::endl;
    
    int GuessA, GuessB, GuessC;    

    cin >> GuessA >> GuessB >> GuessC;    

    int GuessSum = GuessA + GuessB + GuessC;
    int GuessProduct = GuessA * GuessB * GuessC;

    if (GuessSum == CodeSum && GuessProduct == CodeProduct)
    {
        cout << "\nYou successfully open the door!";
        return true;
    }
    else
    {
        cout << "\nA huge anvil drops from the sky and you narrownly avoid being splattered. the door is still locked.";
        return false;
    }
}

int main() //MAIN FUNCTION
{ 
    srand(time(NULL)); // seeding rand - creates new random sequence based on time of day. otherwise random numbers will be the same every time we play

    int LevelDifficulty = 1;
    const int MaxDifficulty = 5;

    while (LevelDifficulty <= MaxDifficulty) //loop the game till all levels completed.
    {
        bool bLevelComplete = PlayGame(LevelDifficulty);
        cin.clear(); //clears any errors, no endless loop if player enters anything other than an int
        cin.ignore(); //discards the buffer

        if (bLevelComplete)
        {
            ++LevelDifficulty;
        }
        
    }

    cout <<"\n...";
    cout <<"\nYou find the wizard in his chair. He is dead. Your quest is futile.";
    cout << endl;

    return 0; // RETURN STATEMENT
}

/*
NOTES
std - STANDARD is a namespace. Avoids the conflict of code being 
    the same name, allows us to tell the difference
:: - Scope Operator - use this to access namespace
    telling the compiler to check for code inside the namespace 
cout - C OUT allows us to CHARACTER OUTPUT, to output to the console, to write in the terminal
cin - CHARACTER INPUT
<< - INSERTION OPERATOR inserting (thing) to the output stream, output whatever is to the right of them
>> - EXTRACTION OPERATOR - extract characters from the input stream, assignt them to whatever is to the right of them
% - MODULUS OPERATOR - divides by number after it and returns remainder.

VARIABLES
+ UNREAL ENGINE USES UpperCamelCase 
+ Must declare them first. By declaring you are reserving space in the computer's memory for it.
+ Can be changed at Runtime
+ When reassigning values, do it before that value is used for anything. Otherwise it will remain the default.

= equal sign is an ASSIGNMENT OPERATOR
CONST - constant, does not allow value to change after it has been declared and initialized.

int a = 0; <--- initialized (given a value) if no value it is uninitialized. 

*/