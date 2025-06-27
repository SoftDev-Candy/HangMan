#include <cstdlib>
#include <iostream>
#include<vector>
#include<string>
#include <ctime> //library for the std::time function 
#include<limits>//for da most useless reqiurement of all time 
#include<atomic>//I AM ATOMIC💥☢️
#include <cctype> 

std::atomic<bool>stop_IT(false);

class Hangman 
{

private:




public:
    


};

int random_number(std::string words[],int size)  //random number generator function
{

    std::srand(std::time({})); //takes the current time as the base value to make the number truely random
    const int randomNum = std::rand() % size;
    
    return randomNum;
}

std::string chooseWord()
{

    std::string words[] =
    {
    "apple", "banana", "computer", "pencil", "guitar", "elephant",
    "mountain", "school", "window", "keyboard", "pirate", "jungle",
    "planet", "dragon", "bottle", "camera", "desert", "forest",
    "castle", "rocket"
    };

    int words_size = sizeof(words) / sizeof(words[0]);
    int random_num = random_number(words, words_size);
    std::string choosenword = words[random_num];

    return choosenword;
}

bool checkischarpresent(char guess, char GuessingWord)
{

    if (guess == GuessingWord)
    {
        return true;
    }

    else
    {
        return false;
    }

}

void wrongAnswer(int attemptNum) 
{
    switch (attemptNum) {

    case 5:
        std::cout << "   _____" << std::endl;
        std::cout << "  |     |" << std::endl;
        std::cout << "  |     O" << std::endl;
        std::cout << "  |" << std::endl;
        std::cout << "  |" << std::endl;
        std::cout << "  |" << std::endl;
        std::cout << "  |" << std::endl;
        break;

    case 4:
        std::cout << "   _____" << std::endl;
        std::cout << "  |     |" << std::endl;
        std::cout << "  |     O" << std::endl;
        std::cout << "  |     |" << std::endl;
        std::cout << "  |" << std::endl;
        std::cout << "  |" << std::endl;
        std::cout << "  |" << std::endl;
        break;


    case 3:

        std::cout << "   _____" << std::endl;
        std::cout << "  |     |" << std::endl;
        std::cout << "  |     O" << std::endl;
        std::cout << "  |    /|" << std::endl;
        std::cout << "  |" << std::endl;
        std::cout << "  |" << std::endl;
        std::cout << "  |" << std::endl;
        break;

    case 2:
        std::cout << "   _____" << std::endl;
        std::cout << "  |     |" << std::endl;
        std::cout << "  |     O" << std::endl;
        std::cout << "  |    /|\\" << std::endl;
        std::cout << "  |" << std::endl;
        std::cout << "  |" << std::endl;
        std::cout << "  |" << std::endl;
        break;

    case 1:
        std::cout << "   _____" << std::endl;
        std::cout << "  |     |" << std::endl;
        std::cout << "  |     O" << std::endl;
        std::cout << "  |    /|\\" << std::endl;
        std::cout << "  |    /" << std::endl;
        std::cout << "  |" << std::endl;
        std::cout << "  |" << std::endl;
        break;

    case 0:
        std::cout << "   _____" << std::endl;
        std::cout << "  |     |" << std::endl;
        std::cout << "  |     O" << std::endl;
        std::cout << "  |    /|\\" << std::endl;
        std::cout << "  |    / \\" << std::endl;
        std::cout << "  |" << std::endl;
        std::cout << "  |" << std::endl;
        break;

    }

}

bool checkTheword(std::string guessedword, std::string FinalWord) 
{

    if (guessedword == FinalWord) 
    {
        return true;
    }

    return false;

}


void printwin()
{
    std::cout << "OMG YOU DUN DID IT YOU SAVED THE MAN FROM |THE HANG WHOO WAY TO GO |" << std::endl;
    std::cout << "THANK YOU FOR WASTING YOUR TIME " << std::endl;
    std::cout << "See you NEXT TIME HEHEHEHEHEH []~(￣▽￣)~* " << std::endl;
    stop_IT = true;


}


void printlose ()
{
    std::cout << "OMG YOU KILLED THE MAN FROM HE GOT |THE HANG -ED |";
    std::cout << "THANK YOU FOR WASTING YOUR TIME YOU KILLED HIM ....I HOPE ITS RUBBING IN RIGHT NOW ....HE -- IS -- DEAD " << std::endl;
    std::cout << "See you NEXT TIME  o(≧口≦)o killed him you ******* ********* ****" << std::endl;
    stop_IT = true;
}

void push_element_in_array(char guess, std::string finalword, std::vector<char>* ptr_printedguess, int stringsize) {

    for (int i = 0; i < stringsize; i++)
    {
    
        if (guess == finalword[i])
        {
            ptr_printedguess->insert(ptr_printedguess->begin()+i, guess);
            
        }
        else if(std::isalpha(ptr_printedguess->at(i)) != '_')
        {
            ptr_printedguess->insert(ptr_printedguess->begin() + i, '_');
        }
        else
        {
            continue;
        }
    
    }
}

void print_vector(std::vector<char>* ptr_printedguess , int size) 
{
    for (int i = 0; i < size; i++)
    {

        std::cout << ptr_printedguess->at(i);

    }
    std::cout << std::endl;

}


void onstartplay(){

    std::cout << "Welcome to Hangman XoX" << std::endl;
    std::cout << "You have 5 tries to guess the word. Every wrong guess will bring the man closer to | THE HANG | " << std::endl;
    std::cout << "Will you guess right and save the man , OR WILL YOU LET HIM DIE A SLOW GRUESOME DEATH  " << std::endl;
    std::cout << "HANGMAN  " << std::endl;


    std::cout << std::endl;

    std::vector<char>printedguess;
    std::string FinalWord = chooseWord(); //need to store this globally maybe in side a class to get global access 
    int finalwordlength = FinalWord.length();//this too-> do the above ＼(ﾟｰﾟ＼)

    std::cout << "Your Word is :" << std::endl;

    for (int i = 0; i < finalwordlength; i++)
    {

        std::cout << " _ ";
        printedguess.push_back(' _ ');

    }
    std::cout << "The Word has " << finalwordlength << " Characters ,  start guessing The man dingo ,dies in 5 ! ";
    std::cout << std::endl;

    //TODO : Add the entire above code to a onStartplay

    int num = 0;
    int attemptnum = 0;
    int hangcount = 5;

    while (!stop_IT)  // the while loop is here //TODO -- Make this into a function.
    {
        char guess = ' ';
        std::string guessedword;
        if (attemptnum == 0)
        {
            std::cout << "Enter your first letter: " << std::endl;
            std::cin >> guess;
            attemptnum++;

        }
        else if (attemptnum == 1)
        {
            std::cout << "Enter your second letter: " << std::endl;
            std::cin >> guess;
            attemptnum++;
        }
        else if (attemptnum == 2)
        {
            std::cout << "Enter your third letter: " << std::endl;
            std::cin >> guess;
            attemptnum++;
        }

        else if (attemptnum >= 3)
        {
            std::cout << "Are you ready to guess the word " << std::endl;
            std::cout << "Enter 1 if you are ready to guess or Enter 2 if you want to continue guessing the letters." << std::endl;

            std::cin >> num;//single line calls are so hard to track my god ^_____^ this mfer took me 10 mins to find -> HERE IT YOU BLIND **** ******** **** Donut  **** coding *********
            while (num < 1 || num > 2 || std::cin.fail())
            {

                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Wrong number try to enter '1' or '2' how hard can it be ." << std::endl;
                std::cin >> num;

            }

            if (num == 1)
            {
                std::cout << "You've entered one ..GOOD JOB You know how to read instructions ...unlike some other 'PEOPLE'" << std::endl;
                std::cout << "Enter the letter: " << std::endl;
                std::cin >> guess;
                attemptnum++;
            }

            else if (num == 2)
            {
                std::cout << "You've entered two ..Guess the word you have one try guess the wrong and the man hangs " << std::endl;                
                std::cout << "Guess the word : " ;

                std::cin >> guessedword;
                bool checkwin = checkTheword(guessedword, FinalWord);

                if (checkwin == true)
                {

                    printwin();

                }

            }

        }


        for (int i = 0; i < finalwordlength; i++) //Checking chars ----  here found it i need to remove these forloops and relapce them with something more readble
        {

            bool check = checkischarpresent(guess, FinalWord[i]);
            if (check == true)
            {
                 
                std::cout << "The letter is present in the word" << std::endl;
                push_element_in_array(guess, FinalWord, &printedguess, finalwordlength);
                print_vector(&printedguess, finalwordlength);
                break;

            }

            else if (check == false && i == finalwordlength - 1)
            {

                wrongAnswer(hangcount);
                hangcount--;
                

                if (hangcount < 0)
                {
                    print_vector(&printedguess, finalwordlength);
                    printlose();
                }

                break;

            }
            else
            {
                continue;  //Dont judge me for this line I already know  ........  stop laughing it is here for visual purposes ಥ_ಥ
            }

        }

        if (hangcount < 0)
        {
            print_vector(&printedguess, finalwordlength);
            printlose();

        }

    }


}

int main()
{
    onstartplay();
    
    return 0;

}

