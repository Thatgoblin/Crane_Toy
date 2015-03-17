#ifndef edu_jmu_cs_Floor_h
#define edu_jmu_cs_Floor_h

#include <GL/glew.h>
#include <GL/glu.h>
#include "Sprite.h"

/**
	  * Floor
	  *
	  * Purpose:   Draws the environment using trees, logs, and bushes by
     *            using an OBJ importer
	  *
	  * Author:    Sebastian Gsell, James Madison University
	  *
	  * Version:   May 4, 2014
	  *
	  * This work complies with the JMU Honor Code.
	  */

class Floor: public Sprite
{
  public:
   Floor();
   void drawModel(GLMmodel* model, float x_rot, float y_rot, float z_rot, 
                                       float x_pos, float y_pos, float z_pos);
   void handleTick(); 
  protected:
   GLMmodel* floor;
   GLMmodel* log;
   GLMmodel* tree;
   GLMmodel* bush;
};
#endif
