#ifndef edu_jmu_cs_Crane_h
#define edu_jmu_cs_Crane_h

#include <stdio.h>
#include <string.h>
#include <GL/glew.h>
#include <GL/glu.h>
#include <math.h>

#include "Sprite.h"

/**
	  * Crane
	  *
	  * Purpose:   Draws the crane using an OBJ importer
	  *
	  * Author:    Sebastian Gsell, James Madison University
	  *
	  * Version:   May 4, 2014
	  *
	  * This work complies with the JMU Honor Code.
	  */

class Crane: public Sprite
{
  public:
   Crane();
   void handleTick();
   void drawPart(char* partName);
   void keyPressed(unsigned char key, int x, int y);   
  protected:
   GLMmodel* wheels;
   GLMmodel* base;
   GLMmodel* arm1;
   GLMmodel* arm2;
   GLMmodel* claw;
};
#endif
