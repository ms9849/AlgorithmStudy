#include <string>
#include <map>
using namespace std;

int solution(string dirs) {
	int iAnswer = 0;
	int iCmdSize = dirs.length();
	pair<int, int> CurLocation = { 0, 0 };
	map<pair<pair<int, int>, pair<int, int>>, int> mapVisitedRoads = {};

	for (int i = 0; i < iCmdSize; ++i)
	{
		pair<int, int> NextLocation = CurLocation;
			
		switch (dirs[i])
		{
		case 'L':
			NextLocation.first += -1;

			if ((NextLocation.first >= -5 && NextLocation.first <= 5) &&
				(NextLocation.second >= -5 && NextLocation.second <= 5))
			{
				if (mapVisitedRoads[{ CurLocation, NextLocation }] != 1 &&
					mapVisitedRoads[{ NextLocation, CurLocation }] != 1)
				{
					mapVisitedRoads[{ CurLocation, NextLocation }] = 1;
					mapVisitedRoads[{ NextLocation, CurLocation }] = 1;

					iAnswer++;
					CurLocation = NextLocation;
				}
				else 
					CurLocation = NextLocation;
			}
			else
				continue;

			break;

		case 'R':
			NextLocation.first += 1;

			if ((NextLocation.first >= -5 && NextLocation.first <= 5) &&
				(NextLocation.second >= -5 && NextLocation.second <= 5))
			{
				if (mapVisitedRoads[{ CurLocation, NextLocation }] != 1 &&
					mapVisitedRoads[{ NextLocation, CurLocation }] != 1)
				{
					mapVisitedRoads[{ CurLocation, NextLocation }] = 1;
					mapVisitedRoads[{ NextLocation, CurLocation }] = 1;

					iAnswer++;
					CurLocation = NextLocation;
				}
				else
					CurLocation = NextLocation;
			}
			else
				continue;

			break;

		case 'U':
			NextLocation.second += 1;

			if ((NextLocation.first >= -5 && NextLocation.first <= 5) &&
				(NextLocation.second >= -5 && NextLocation.second <= 5))
			{
				if (mapVisitedRoads[{ CurLocation, NextLocation }] != 1 &&
					mapVisitedRoads[{ NextLocation, CurLocation }] != 1)
				{
					mapVisitedRoads[{ CurLocation, NextLocation }] = 1;
					mapVisitedRoads[{ NextLocation, CurLocation }] = 1;

					iAnswer++;
					CurLocation = NextLocation;
				}
				else
					CurLocation = NextLocation;
			}
			else
				continue;

			break;

		case 'D':
			NextLocation.second += -1;

			if ((NextLocation.first >= -5 && NextLocation.first <= 5) &&
				(NextLocation.second >= -5 && NextLocation.second <= 5))
			{
				if (mapVisitedRoads[{ CurLocation, NextLocation }] != 1 &&
					mapVisitedRoads[{ NextLocation, CurLocation }] != 1)
				{
					mapVisitedRoads[{ CurLocation, NextLocation }] = 1;
					mapVisitedRoads[{ NextLocation, CurLocation }] = 1;

					iAnswer++;
					CurLocation = NextLocation;
				}
				else
					CurLocation = NextLocation;
			}
			else
				continue;

			break;
		}
	}

	return iAnswer;
}


