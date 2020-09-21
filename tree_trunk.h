#ifndef tree_trunk_h
#define tree_trunk_h

#include "structures.h"
#include "moving_element.h"

// Each element of the game like forg, cars, turtles inherits from this virtual class
class Tree_trunk : public Moving_element
{
private:
	int tree_type;
	char* sprite_path;

public:
	~Tree_trunk();
	// SHORT, MIDDLE, LONG - diffetent speed and sprite
	void set_tree_type(int type);
	int load_sprite();
};


#endif // tree_trunk_h

