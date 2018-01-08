
#include "NPC.h"
class bagFella :
	public NPC
{
private:
	bool visible = true;
public:
	bagFella();
	~bagFella();
	virtual void Move();
	virtual void render();
};
