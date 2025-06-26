#include <cstdlib>
#include <iostream>
#include<vector>
#include<string>
#include <ctime> //library for the std::time function 

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


void wrongAnswer(int attemptNum) {


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


int main()
{
    std::cout << "Welcome to Hangman XoX" << std::endl;
    std::cout << "You have 5 tries to guess the word. Every wrong guess will bring the man closer to | THE HANG | " << std::endl;
    std::cout << "Will you guess right and save the man , OR WILL YOU LET HIM DIE A SLOW GRUESOME DEATH  " << std::endl;
    std::cout << "HANGMAN  " << std::endl;


    std::cout << std::endl;

    std::string FinalWord = chooseWord(); //need to store this globally maybe in side a class to get global access 
    int finalwordlength = FinalWord.length();//this too-> do the above ＼(ﾟｰﾟ＼)

    std::cout << "Your Word is :"<<std::endl;

    for (int i = 0; i < finalwordlength; i++) {
       
        
        std::cout << " _ "<<FinalWord[i];

    }
    std::cout << std::endl;

    //TODO : Add the entire above code to a onStartplay
   
    int num = -1;
        int attemptnum = 5;
    while (true)
    {
        char guess;
        if (attemptnum == 5)
        {
            std::cout << "Enter your first letter: ";
        }
        else if (attemptnum <4)
        {
            std::cout << "Are you ready to guess the word "<<std::endl;
            std::cout << "Enter 1 if you are ready to guess or Enter 2 if you want to continue guessing the letters." << std::endl;

                std::cin >> num;
                if (num > 2 || num < 1) {
                
                    std::cout << "Wrong number try to enter '1' or '2' how hard can it be ." << std::endl;



                }
            {
            
            
            }

        }

        std::cin >> guess;


        for (int i = 0; i < finalwordlength; i++)
        {

            bool check = checkischarpresent(guess, FinalWord[i]);
            if (check == true)
            {

                std::cout << "The letter is present in the word";
                attemptnum--;
                break;
               
            }

            else if (check == false && i == finalwordlength-1)
            {
                wrongAnswer(attemptnum);
                attemptnum--;

                break;

            }
            else 
            {
                continue;  //Dont judge me for this line I already know  ........  stop laughing it is here for visual purpose ಥ_ಥ
            }

        }
        

    }
    
    return 0;

}

