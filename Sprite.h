#ifndef edu_jmu_cs_Sprite_h
#define edu_jmu_cs_Sprite_h

#include <GL/glew.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include "glm.h"

/**
 * A Sprite is a geometric object that "plays" on a Stage
 *
 * @author  Prof. David Bernstein, James Madison University
 * @version 1.0
 */
class Sprite
{
  public:
   virtual void handleTick() = 0; // A pure virtual (i.e., abstract) method

   virtual void keyPressed(unsigned char key, int x, int y);   

   virtual void mouseClicked(int button, int state, int x, int y);   

           void timerTicked();   
   
};

#endif
