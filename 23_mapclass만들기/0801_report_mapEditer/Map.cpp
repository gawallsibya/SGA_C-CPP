#include "Map.h"
#include <iostream>
#include <conio.h>
#include <math.h>
#include <vector>
#include <string>

using std::vector;
using std::string;
using std::cout;
using std::endl;
using std::cin;

Map::Map()
{
	stageWidth = 0;
	stageHeight = 0;
	vpStateMap = new vector<Object>;
	pFile = nullptr;

}

Map::~Map()
{
	delete vpStateMap;
	vpStateMap = nullptr;
}

void Map::createMap(int row, int cloumn)
{
	stageWidth = row+1;		// \n ���� �޴´ٸ� �迭�� +1�Ǿ��ִ�
	stageHeight = cloumn;
	vpStateMap->clear();
	for (int vert = 0; vert < stageHeight; vert++)
	{
		for (int horz = 0; horz < stageWidth-1; horz++)		// \n�� ��ġ�� ���߱����� ����-1 ��ŭ �����Ѵ�
		{
			vpStateMap->push_back(OBJ_SPACE);
		}
		vpStateMap->push_back(OBJ_UNKNOWN);
	}
}

void Map::renderMap()
{
	for (int vert = 0; vert < stageWidth * stageHeight; vert++)
	{
			switch (vpStateMap->at(vert))
			{
			case OBJ_SPACE:
				cout << "��";
				break;

			case OBJ_WALL:
				cout << "��";
				break;

			case OBJ_UNKNOWN:
				cout << endl;
				break;
			default:
				cout << endl << endl << "drowingObject ���� ERROR!!" << endl << endl;
				break;
			}
	}
}

void Map::setTile(int row, int column, Object objType)
{

	vpStateMap->at((column*stageWidth) + row) = objType;
}

void Map::saveMap(string fileName)
{
	
	errno_t err;
	if (err = fopen_s(&pFile, fileName.c_str(), "w") == 0)
	{
		int fsize = vpStateMap->size();
		char *buffer = new char[fsize];

		for (int i = 0; i <fsize; i++)
		{
			switch (vpStateMap->at(i))
			{
			case OBJ_SPACE:
				buffer[i] = '0';
				break;
			case OBJ_WALL:
				buffer[i] = '1';
				break;
			case OBJ_UNKNOWN:
				buffer[i] = '\n';
			default:
				break;
			}
		}
		fwrite(buffer, vpStateMap->size(), 1, pFile);
		
		delete buffer;
		buffer = nullptr;
		fclose(pFile);
	}

}

void Map::loadMap(string fileName)
{
	errno_t err;
	if (err = fopen_s(&pFile, fileName.c_str(), "r") == 0)
	{
		fseek(pFile, 0, SEEK_END);         // ���������͸� ������ ������ �̵�
		int fsize = ftell(pFile);
		fseek(pFile, 0, SEEK_SET);         // ���������͸� �ٽ� ������ �� ó������ �̵�
		char *buffer = new char[fsize + 1];

		fsize = fread(buffer, 1, fsize, pFile);    // ������ �ѹ��� ����
		vpStateMap->clear();
	
		int row = 0;
		stageHeight = 0;
		stageWidth = 0;
		for (int i = 0; i < fsize; i++)
		{
			row += 1;
			switch (buffer[i])
			{
			case '0':
				vpStateMap->push_back(OBJ_SPACE);
				break;

			case '1': 
				vpStateMap->push_back(OBJ_WALL);
				break;

			case '\n': 
				vpStateMap->push_back(OBJ_UNKNOWN);
				stageHeight += 1;
				stageWidth = row;
				row = 0; 
				break;

			default: break;
			}

		}
		delete buffer;
		buffer = nullptr;
		fclose(pFile);
	}

}




// === getset ===
int Map::getStageWidth()
{
	return stageWidth;
}
void Map::setStageWidth(int _stageWidth)
{
	stageWidth = _stageWidth;
}
int Map::getStageHeight()
{
	return stageHeight;
}
void Map::setStageHeight(int _stageHeight)
{
	stageHeight = _stageHeight;
}
