// THIS FILE MAY NOT BE MODIFIED IN ANY WAY
// THIS FILE MAY NOT BE MODIFIED IN ANY WAY
// THIS FILE MAY NOT BE MODIFIED IN ANY WAY
// YOUR CODE IN FILES Bowler.h and Bowler.cpp MUST WORK WITH THIS UNMODIFIED FILE,
// ALONG WITH THE 6 ACCOMPANYING TEXT FILES THAT CONTAIN BOWLER DATA
// PLEASE SUBMIT ALL 9 FILES IN A ZIP FILE TO BLACKBOARD IN YOUR 3 HOUR TIME FRAME

#include <algorithm>
#include <cassert>
#include <iomanip>
#include <iostream>
#include <vector>
#include "Bowler.h"

// PRINT EVERY BOWLER IN A VECTOR IN A NICE WAY
void PrintBowlersAsTable(const std::vector<Bowler>& bowlers)
{
	std::cout << std::endl;
	std::cout << "NAME            PINS  GAMES   AVERAGE" << std::endl;
	std::cout << "----            ----  -----   -------" << std::endl;
	for (const Bowler& bowler : bowlers)
	{
		std::cout << std::left << std::setw(14) << bowler.GetName();
		std::cout << std::right << std::setw(6) << bowler.GetTotalPins();
		std::cout << std::setw(7) << bowler.GetGamesBowled();
		std::cout << std::setw(10) << bowler.GetAverage();
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

// BINARY OPERATOR FOR SORTING BY AVERAGE AS FOUND DOWN BELOW
bool SortBowlersByAverage(const Bowler& a, const Bowler& b)
{
	return a.GetAverage() > b.GetAverage();
}

int main()
{
	// TESTING THE "INPUT FILE IS MISSING" CASE
	Bowler sward = Bowler("sward.txt");
	assert(sward.GetName() == "INPUT_FILE_MISSING");
	assert(sward.GetTotalPins() == 0);
	assert(sward.GetGamesBowled() == 0);
	assert(sward.GetAverage() == 0.0);
	std::cout << "INPUT FILE MISSING CASE HANDLED PROPERLY" << std::endl;

	// TESTING "RANDOM" FILE INPUT
	Bowler abigail = Bowler("abigail.txt");
	assert(abigail.GetName() == "Abigail");
	assert(abigail.GetTotalPins() == 164);
	assert(abigail.GetGamesBowled() == 2);
	assert(abigail.GetAverage() == 82.0);
	std::cout << std::endl << "RANDOM INPUT FILE CASE HANDLED PROPERLY" << std::endl;

	// FILE INPUT FOR THE TOP FIVE BOWLERS AND THEIR SCORES
	std::vector<Bowler> bowlers;
	bowlers.push_back(Bowler("bolleby.txt"));
	bowlers.push_back(Bowler("tackett.txt"));
	bowlers.push_back(Bowler("butturff.txt"));
	bowlers.push_back(Bowler("russo.txt"));
	bowlers.push_back(Bowler("sterner.txt"));

	// PRINT THE VECTOR IN A NICE WAY
	PrintBowlersAsTable(bowlers);

	// TEST YOUR FUNCTIONS FOR CORRECTNESS
	assert(bowlers[0].GetName() == "Kim*Bolleby");
	assert(bowlers[1].GetGamesBowled() == 18);
	assert(bowlers[2].GetTotalPins() == 4108);
	assert(bowlers[3].GetAverage() == 229.22222222222222);
	assert(bowlers[4].GetName() == "Jason*Sterner");

	// SORT THE VECTOR BY BOWLER AVERAGE
	std::sort(bowlers.begin(), bowlers.end(), SortBowlersByAverage);
	
	// PRINT THE VECTOR AGAIN IN A NICE WAY
	std::cout << "AFTER SORTING BY AVERAGE" << std::endl;
	PrintBowlersAsTable(bowlers);

	// TEST YOUR FUNCTIONS FOR CORRECTNESS ONCE AGAIN
	assert(bowlers[0].GetName() == "EJ*Tackett");
	assert(bowlers[1].GetGamesBowled() == 18);
	assert(bowlers[2].GetTotalPins() == 4126);
	assert(bowlers[3].GetAverage() == 228.83333333333333);
	assert(bowlers[4].GetName() == "Jakob*Butturff");

	// DID YOU IMPLEMENT EVERYTHING AS EXPECTED TO GET HERE WITH THE PRINT STATEMENTS?
	std::cout << "LOOKING PRETTY GOOD IF THIS PRINTS OUT!!!" << std::endl;

	// CLOSEOUT
	return 0;
}