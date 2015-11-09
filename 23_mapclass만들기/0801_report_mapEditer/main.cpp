
/*
map class 만들기

Member Var )
초기값으로 맵 크기 설정하기
위치를 지정하면 타일 속성이 1로 변환

3,3
000
000
010

5,6
000000
000100
000100
000100
000100

>>>>
enum tiletype { ROAD, WALL, MAX_TILE };

기본]
createMap( int row, int cloumn );
renderMap();
setTile(int row, int column, tiletype etype);

확장]
saveMapFile ( filename );
loadMapFile ( filename );
*/



#include "Manager.h"
#include <stdlib.h>

void main()
{
	Manager mngr;

	mngr.init();
	mngr.run();
	mngr.end();

	
}

