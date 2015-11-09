#ifndef _MAP_H_
#define _MAP_H_

#include <vector>
#include <string>

using std::vector;
using std::string;

struct POINT
{
	// �迭������ ���� ��ǥ�� �Ǿ��־� int���̾�� ������.. float���� �����غ�
	float x;
	float y;
};

// 0���� �����, ��, ���� ����
enum Object
{
	OBJ_SPACE,
	OBJ_WALL,
	OBJ_UNKNOWN
};

class Map
{
private:
	int stageWidth;		// ���� ���� ũ��
	int stageHeight;	// ���� ���� ũ��
	vector<Object> *vpStateMap;	// ���� �迭 
	// vector�� ��Ŭ��� �ϱ� �Ⱦ void*�� ���� ����ϰ� �;����� �Ź� ĳ����������ؼ� ����
	// static_cast�� ����ص� �Ź� ��� �ٲ۴ٴ°� �������Ű����� ���� �� ������..
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