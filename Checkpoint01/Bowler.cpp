#include "Bowler.h"
#include <fstream>
#include <vector>

std::string Bowler::GetName(void) const
{
    return BowlerName;
}

int Bowler::GetGamesBowled(void) const
{
    return NumofGamesPlayed;
}

int Bowler::GetTotalPins(void) const
{
    return TotalPinsScored;
}

double Bowler::GetAverage(void) const
{
    if ((TotalPinsScored > 0) && (NumofGamesPlayed > 0))
        return (static_cast<double>(TotalPinsScored) / static_cast<double>(NumofGamesPlayed));
    else
        return 0.0;
}

Bowler::Bowler(std::string FileName)
{
    int score;
    
    std::ifstream file(FileName);
    std::vector<int> Scores;
    TotalPinsScored = 0;
    NumofGamesPlayed = 0;
    
    // Check if file exists and can be opened
    if (!file) {
        BowlerName = "INPUT_FILE_MISSING";
    }
    else
    {
        //reading the first word as name
        file >> BowlerName;
        
        // Read scores separated by spaces
        while (file >> score)
        {
            Scores.push_back(score);
        }
        
        NumofGamesPlayed = static_cast<int>(Scores.size());
        
        for (int s : Scores) 
        {
            TotalPinsScored += s;
        }

        file.close(); // Close the file when done
    }
}

