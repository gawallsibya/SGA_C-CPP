
/*
map class �����

Member Var )
�ʱⰪ���� �� ũ�� �����ϱ�
��ġ�� �����ϸ� Ÿ�� �Ӽ��� 1�� ��ȯ

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

�⺻]
createMap( int row, int cloumn );
renderMap();
setTile(int row, int column, tiletype etype);

Ȯ��]
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

