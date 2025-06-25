#include <cstdlib>
#include <iostream>
#include<vector>
#include<string>
#include <ctime> //library for the std::time function 

class Hangman {
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

    for (int i = 0; i < finalwordlength; i++) {

        if (guess == FinalWord[i]){
            std::cout << "Its the correct letter  " << std::endl;
            break;
        }
        else {
            std::cout << "The letter is wrong try again " << std::endl;
            break;
      }
    }

    
    return 0;

}

