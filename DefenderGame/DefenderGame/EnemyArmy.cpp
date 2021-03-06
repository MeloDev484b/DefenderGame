#include "EnemyArmy.h"
void EnemyArmy::rollArmySize() //Enemy function
{
	// Set total size of army - modify based on difficulty
	switch (difficultyModifier)
	{
	case 1:
		armySize = rand() % 20 + 5;
		break;
	case 2:
		armySize = rand() % 30 + 20;
		break;
	case 3:
		armySize = rand() % 40 + 20;
		break;
	}
}
void EnemyArmy::rollDirection() // Enemy Function - pick the locations where the army is divided into [0] - [3]
{
	int tempArmySize = armySize;
	for (int i = 0; i < soldiersAtLocation.size(); i++)
	{
		if (rollAd12() > 6 && tempArmySize > 0)
		{
			int amountOfSoliers = rand() % tempArmySize + 1;
			setSoldiersAtLocation(amountOfSoliers, i);
			tempArmySize -= amountOfSoliers;
		}
	}
}
void EnemyArmy::resetArmy() // Creates the enemy's army
{
	for (int i = 0; i < soldiersAtLocation.size(); i++)
	{
		setSoldiersAtLocation(0, i);
	}
}
void EnemyArmy::whereAreTheEnemies() // Display where enemies approach from
{
	std::cout << "- - - - - - - - - - - - - - - - - - - - - -\n";
	for (int i = 0; i < soldiersAtLocation.size(); i++)
	{
		if (getSoldiersAtLocation(i) > 0)
		{
			int enemies = getSoldiersAtLocation(i);
			std::string direction = getDirection(i);
			std::cout << "\n" << enemies << " enemy soldiers approach from the " << direction << "!\n\n";
		}
	}
	std::cout << "- - - - - - - - - - - - - - - - - - - - - -";
}
void EnemyArmy::alignDifficultyLevel(int difficultyLevel)
{
	difficultyModifier = difficultyLevel;
}