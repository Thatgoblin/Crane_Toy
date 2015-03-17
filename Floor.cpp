#include "Floor.h"

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

/**
 * Constructor
 */
Floor::Floor()
{
   floor = glmReadOBJ("Models/Floor.obj");

   log = glmReadOBJ("Models/Log.obj");
   tree = glmReadOBJ("Models/Tree.obj");
   bush = glmReadOBJ("Models/Bush.obj");
}

void Floor::drawModel(GLMmodel* model, float x_rot, float y_rot, float z_rot, 
                                       float x_pos, float y_pos, float z_pos) 
{
   glPushMatrix();

   glTranslatef(x_pos, y_pos, z_pos);
   glRotatef(x_rot, 1.0, 0.0, 0.0);
   glRotatef(y_rot, 0.0, 1.0, 0.0);
   glRotatef(z_rot, 0.0, 0.0, 1.0);
   glmDraw(model, GLM_SMOOTH | GLM_TEXTURE | GLM_MATERIAL);

   glPopMatrix();
}

void Floor::handleTick()
{
   /* LOGS */
   drawModel(log, 0.0, 30.0, 0.0, 10.0, 1.0, 10.0);
   drawModel(log, 0.0, 150.0, 0.0, 14.0, 1.0, -15.0);
   drawModel(log, 0.0, 10.0, 0.0, -18.0, 1.0, -22.0);
   drawModel(log, 0.0, 110.0, 0.0, -18.0, 1.0, 18.0);

   drawModel(log, 0.0, -5.0, 0.0, -18.0, 1.0, 0.0);
   drawModel(log, 0.0, -5.0, 0.0, -20.0, 1.0, 0.0);
   drawModel(log, 0.0, -5.0, 0.0, -19.0, 2.5, 0.0);

   /* TREES */

   for(float i = -30.0; i < 30.0; i += 6.0) {  
      //back side
      drawModel(tree, -90.0, 0.0, 0.0, i+3.0, 0.0, -34.0);
      drawModel(tree, -90.0, 0.0, 0.0, i, 0.0, -30.0);
      drawModel(tree, -90.0, 0.0, 0.0, i+2.0, 0.0, -26.0);
      //left side
      drawModel(tree, -90.0, 0.0, 0.0, -24.0, 0.0, i);
      drawModel(tree, -90.0, 0.0, 0.0, -26.0, 0.0, i+3.0);
      //right side
      drawModel(tree, -90.0, 0.0, 0.0, 24.0, 0.0, i);
      drawModel(tree, -90.0, 0.0, 0.0, 28.0, 0.0, i+3.0);
   }
   
   /* BUSHES */
   drawModel(bush, -90.0, 30.0, 0.0, 18.0, 1.0, 4.0);
   drawModel(bush, -90.0, 0.0, 0.0, -12.0, 1.0, -20.0);
   drawModel(bush, -90.0, 0.0, 90.0, 4.0, 1.0, -20.0);

   //floor
   glPushMatrix();

   glRotatef(90.0, 1.0, 0.0, 0.0);
   glScalef(2.0, 8.0, 1.0);
   glmDraw(floor, GLM_SMOOTH | GLM_MATERIAL);

   glPopMatrix();
}
