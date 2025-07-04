#include <cstdlib>
#include <iostream>
#include<vector>
#include<string>
#include <ctime> //library for the std::time function 
#include<limits>//for da most useless reqiurement of all time 
#include<atomic>//I AM ATOMIC💥☢️
#include <cctype> 

std::atomic<bool>stop_IT(false); //we could just have it as bool Stop_it = false no need to make it atomic cause we 
                                //dont have an overhead to worry about

class Hangman 
{

private:




public:
    


};

int random_number(int MaxRandomNumber)   //random number generator function
{
	//feedback: srand might stay the same if called multiple times in a short period, leading to the same random number being generated.
    //can use srand(static_cast<unsigned int>(time(0))) so we only seed once 
    std::srand(static_cast<unsigned int>(std::time(0))); //takes the current time as the base value to make the number truely random 	

    const int randomNum = std::rand() % MaxRandomNumber;
	//feedback: using % MaxRandomNumber ensures the random number is within the bounds of the array
    return randomNum;
}

const std::string& chooseWord() //make a function const if you are not changing any value again 
{

   static std::string words[] =    
    {
    "apple", "banana", "computer", "pencil", "guitar", "elephant",
    "mountain", "school", "window", "keyboard", "pirate", "jungle",
    "planet", "dragon", "bottle", "camera", "desert", "forest",
    "castle", "rocket"
    };

    int words_size = sizeof(words) / sizeof(words[0]);
    int random_num = random_number(words_size);
    const std::string& choosenword = words[random_num];

    return choosenword;
}

//Feedback: Dont actually require this .As we are just comparing two chars instead we can just add 
// bool check = guess == FinalWord[i]; Problem fixed smart solution

//bool checkischarpresent(char guess, char GuessingWord)  
//{
//
//    if (guess == GuessingWord)
//    {
//        return true;
//    }
//
//    else
//    {
//        return false;
//    }
//
//}

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

//Same thing as before ! Although feedback! 
//Feedback : use const and & as we are not making any changes to it 

//bool checkTheword(std::string guessedword, std::string FinalWord) 
//{
//
//    if (guessedword == FinalWord) 
//    {
//        return true;
//    }
//
//    return false;
//
//}


void printwin()
{
    std::cout << "OMG YOU DUN DID IT YOU SAVED THE MAN FROM |THE HANG WHOO WAY TO GO |" << std::endl;
    std::cout << "THANK YOU FOR WASTING YOUR TIME " << std::endl;
    std::cout << "See you NEXT TIME HEHEHEHEHEH []~(￣▽￣)~* " << std::endl;
    stop_IT = true;


}


void printlose ()
{
    std::cout << "OMG YOU KILLED THE MAN FROM HE GOT |THE HANG -ED |" << std::endl;
    std::cout << "THANK YOU FOR WASTING YOUR TIME YOU KILLED HIM ....I HOPE ITS RUBBING IN RIGHT NOW ....HE -- IS -- DEAD " << std::endl;
    std::cout << "See you NEXT TIME  o(≧口≦)o killed him you ******* ********* ****" << std::endl;
    stop_IT = true;
}

void push_element_in_array(char guess, const std::string& finalword, std::vector<char>& ptr_printedguess) //no need for string 
{
     
    for (int i = 0; i < finalword.size(); i++)
    {
    
        if (guess == finalword[i])
        {
            ptr_printedguess.at(i) = guess;
            
        }
        //else if(!std::isalpha(ptr_printedguess->at(i)))//useless check
        //{
        //    //ptr_printedguess->at(i) = '_';
        //}
      
    
    }
}

void print_vector(std::vector<char>& ptr_printedguess ) 
{
    for (char i:ptr_printedguess)
    {

        std::cout <<i;

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
    std::cout << FinalWord;
    int finalwordlength = FinalWord.length();//this too-> do the above ＼(ﾟｰﾟ＼)

    std::cout << "Your Word is :" << std::endl;

    for (int i = 0; i < finalwordlength; i++)
    {

        std::cout << " _ ";
        printedguess.push_back('_');

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
                bool checkwin = (guessedword == FinalWord);

                if (checkwin == true)
                {

                    printwin();

                }

            }

        }


        for (int i = 0; i < finalwordlength; i++) //Checking chars ----  here found it i need to remove these forloops and relapce them with something more readble
        {

            bool isPresent = (guess == FinalWord[i]);
            if (isPresent)
            {
                 
                std::cout << "The letter is present in the word" << std::endl;
                push_element_in_array(guess, FinalWord, printedguess);
                print_vector(printedguess);
                break;

            }

            else if (isPresent == false && i == finalwordlength - 1)
            {

                wrongAnswer(hangcount);
                hangcount--;
                

                if (hangcount < 0)
                {
                    print_vector(printedguess);
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
            print_vector(printedguess);
            printlose();

        }

    }


}

int main()
{
    onstartplay();
    
    return 0;

}

