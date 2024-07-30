#include <iostream>

class Bowler
{
public:
    
    Bowler(std::string FileName);
    
    std::string GetName(void) const;
    
    int GetGamesBowled(void) const;
    
    int GetTotalPins(void) const;
    
    double GetAverage(void) const;
    
private:
    std::string BowlerName;
    int NumofGamesPlayed;
    int TotalPinsScored;
    
};
