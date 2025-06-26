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



int main()
{
    std::cout << "Welcome to Hangman XoX" << std::endl;
    std::cout << std::endl;

    std::string FinalWord = chooseWord(); //need to store this globally maybe in side a class to get global access 
    int finalwordlength = FinalWord.length();//this to do the above ＼(ﾟｰﾟ＼)

    std::cout << "Your Word is :"<<std::endl;

    for (int i = 0; i < finalwordlength; i++) {
       
        
        std::cout << " _ "<<FinalWord[i];

    }
    std::cout << std::endl;

    //TODO : Add the entire above code to a onStartplay
    char guess;
    std::cout << "Enter your first character :"; 
    std::cin >> guess;

    for (int i = 0; i < finalwordlength; i++)
    {

        bool check = checkischarpresent(guess, FinalWord[i]);
        if (check == true)
        {

            std::cout << "The letter is present in the word";

        }

        else 
        {
           std::cout << "The letter is not present in the word" << std::endl;
           std::cout << "   _____" << std::endl;
           std::cout << "  |     |" << std::endl;
           std::cout << "  |     O" << std::endl;
           std::cout << "  |" << std::endl;
           std::cout << "  |" << std::endl;
           std::cout << "  |" << std::endl;
           std::cout << "  |" << std::endl;

           break;
           
        }

    }

    
    return 0;

}

