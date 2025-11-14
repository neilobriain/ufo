#include <iostream>
#include <vector>
#include <string>
#include "ufo_functions.hpp"

int main(int argc, char *argv[])
{
    // Set codeword as specified, otherwise get a random word from dictionary
    std::string codeword;
    codeword = (argc > 1) ? argv[1] : get_codeword();

    // Set user answer size
    std::string answer = "";
    for (int i = 0; i < codeword.length(); i++)
    {
        answer += "_";
    }

    int misses = 0;
    bool guess = false;
    std::vector<char> incorrect;
    char letter;

    greet();

    while (answer != codeword && misses < 7)
    {
        display_misses(misses);
        display_status(incorrect, answer);
        std::cout << "\nPlease enter your guess: ";
        std::cin >> letter;

        for (int i = 0; i < codeword.length(); i++)
        {
            if (letter == codeword[i])
            {
                answer[i] = letter;
                guess = true;
            }
        }
        if (guess)
        {
            std::cout << "\nCorrect!\n";
        }
        else
        {
            std::cout << "\nIncorrect! The tractor beam pulls your person in further.\n";
            incorrect.push_back(letter);
            misses++;
        }

        // Reset the guess
        guess = false;
    }

    end_game(answer, codeword);

    return 0;
}
