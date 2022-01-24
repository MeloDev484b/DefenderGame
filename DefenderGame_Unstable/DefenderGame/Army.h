#ifndef ARMY_H
#define ARMY_H

#include <iostream>
#include <string>
#include <array>
using namespace std;

const int DIRECTION_ARRAY_SIZE = 4;
const int ARRAY_LOOP_CONST = 3;
const int ENEMY_MULTIPLIER = 40;

class Army
{
public:
	Army(int armySize, int archerAmount);
	int getArmySize() const;
	void setArmySize(int newArmySize);
	int getArcherAmount() const;
	void setArcherAmount(int newArcherAmount);
	void rollArmySize();
	void rollDirection();
	int getSoldiersAtLocation(int arrayPosition) const;
	void setSoldiersAtLocation(int soldiers, int arrayPosition);
	void setDifficultyModifier(int newDifficulty);
	string getDirection(int arrayPosition);
	void resetArmy();
	void whereAreTheEnemies();
private:
	int difficultyModifier = 1;
	int armySize;
	int archerAmount = 0;
	array <int, 4> soldiersAtLocation{0, 0, 0, 0};
	//[0] amount of soldiers located in the North, [1] amount of soldiers located in the East
	//[2] amount of soldiers located in the South, [3] amount of soldiers located in the West

	//Array of directions for use in functions
	const array <string, DIRECTION_ARRAY_SIZE> directions{ "North","East","South","West" };
};



#endif //ARMY_H