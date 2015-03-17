#include "Crane.h"

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

static float   drive_x, drive_z, p_drive_x, p_drive_z = 0;
static int     r_drive_x, pr_drive_x, base_x, claw_x = 0;
static int     arm1_y, arm2_y, arm3_y = 0;

/**
 * Constructor
 */
Crane::Crane()
{
   wheels = glmReadOBJ("Models/Wheels.obj");
   base = glmReadOBJ("Models/Base.obj");
   arm1 = glmReadOBJ("Models/Arm1.obj");
   arm2 = glmReadOBJ("Models/Arm2.obj");
   claw = glmReadOBJ("Models/Claw.obj");
}

void Crane::handleTick()
{   
   /* THE DRIVE */
   
   //position model properly
   glRotatef(90.0, 1.0, 0.0, 0.0);
   glRotatef(180.0, 0.0, 1.0, 0.0);
   glRotatef(225.0, 0.0, 0.0, 1.0); 
   glTranslatef(0.0, 0.0, 1.0);

   //movements
   glTranslatef(drive_x, 0.0, 0.0);
   glTranslatef(0.0, drive_z, 0.0);
   glRotatef((GLfloat)r_drive_x, 0.0, 0.0, 1.0);
   glmDraw(wheels, GLM_SMOOTH | GLM_MATERIAL);

   /* THE BASE */

   //position model
   glTranslatef(0.0, -1.0, 1.0);
  
   glRotatef((GLfloat)base_x, 0.0, 0.0, 1.0); 
   glmDraw(base, GLM_SMOOTH | GLM_MATERIAL);
   
   /* FIRST ARM */

   //position model
   glTranslatef(0.0, -1.0, 1.6);
   
   glRotatef((GLfloat)arm1_y, 1.0, 0.0, 0.0);
   glmDraw(arm1, GLM_SMOOTH | GLM_MATERIAL);
   
   /* SECOND ARM */

   //position model
   glTranslatef(0.0, -9.0, 7.0);

   glRotatef((GLfloat)arm2_y, 1.0, 0.0, 0.0);

   glmDraw(arm2, GLM_SMOOTH | GLM_MATERIAL);
  
   /* CLAW */

   //position model
   glTranslatef(0.0, -4.5, -3.0);
  
   glRotatef(-20.0, 1.0, 0.0, 0.0);
   glRotatef((GLfloat)claw_x, 0.0, 0.0, 1.0); 
   glmDraw(claw, GLM_SMOOTH | GLM_MATERIAL);
}

void Crane::keyPressed(unsigned char key, int x, int y)
{
   float  PI = 3.14159265;
   float  speed = 0.15;

   //forward
   if(key == 'w') {
      drive_z -= cos(r_drive_x * (PI/180) ) * speed;
      drive_x += sin(r_drive_x * (PI/180) ) * speed;
   }
   //backward
   if(key == 's') { 
      drive_z += cos(r_drive_x * (PI/180) ) * speed;
      drive_x -= sin(r_drive_x * (PI/180) ) * speed;
   }
   //rotate whole model left
   if(key == 'a') {
      r_drive_x = (r_drive_x + 6) % 360;
   }
   //rotate whole model right
   if(key == 'd') { 
      r_drive_x = (r_drive_x - 6) % 360;
   }

   //rotate the base
   if       (key == 'J') base_x = (base_x + 6) % 360;
   else if  (key == 'j') base_x = (base_x - 6) % 360;
   

   //rotate the first arm
   if (key == 'K') {
      arm1_y += 2;
      if(arm1_y > 30) arm1_y = 30;
   }
   else if (key == 'k') {
      arm1_y -= 2;

      if(arm1_y < -30) arm1_y = -30;
   }

   //rotate the second arm
   if (key == 'L') {
      arm2_y += 2;
      if(arm2_y > 30) arm2_y = 30;
   }
   else if (key == 'l') {
      arm2_y -= 2;
      if(arm2_y < -30) arm2_y = -30;
   }
   
   //rotate the claw
   if       (key == ':') claw_x  = (claw_x  + 6) % 360;
   else if  (key == ';') claw_x  = (claw_x  - 6) % 360; 
}

