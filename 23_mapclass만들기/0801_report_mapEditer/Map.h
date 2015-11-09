#ifndef _MAP_H_
#define _MAP_H_

#include <vector>
#include <string>

using std::vector;
using std::string;

struct POINT
{
	// 배열구조에 따른 좌표로 되어있어 int형이어야 하지만.. float형을 고집해봄
	float x;
	float y;
};

// 0부터 빈공간, 벽, 으로 구성
enum Object
{
	OBJ_SPACE,
	OBJ_WALL,
	OBJ_UNKNOWN
};

class Map
{
private:
	int stageWidth;		// 맵의 가로 크기
	int stageHeight;	// 맵의 세로 크기
	vector<Object> *vpStateMap;	// 맵의 배열 
	// vector를 인클루드 하기 싫어서 void*로 만들어서 사용하고 싶었으나 매번 캐스팅해줘야해서 포기
	// static_cast를 썼다해도 매번 계속 바꾼다는건 안좋은거같은데 뭐가 더 좋을지..
	FILE *pFile;

public:
	Map();
	~Map();

	void createMap(int row, int cloumn);
	void renderMap();
	void setTile(int row, int column, Object objType);
	int getStageWidth();
	void setStageWidth(int _stageWidth);
	int getStageHeight();
	void setStageHeight(int _stageHeight);
	void saveMap(string fileName);
	void loadMap(string fileName);
};

#endif /*_MAP_H_*/