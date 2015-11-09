#ifndef _MANAGER_H_
#define _MANAGER_H_

#include "Map.h"
#include <string>

using std::string;
class Manager : public Map
{
private:
	char key;
	POINT point;
	Object obj;
	string fileName;

public:
	Manager();
	~Manager();

	void init();
	void run();
	void end();
};

#endif /*_MANAGER_H_*/
