#include <GL/glew.h>
#include <GL/glu.h>

#include "Stage.h"
#include "Crane.h"
#include "Floor.h"

/**
	  * Driver
	  *
	  * Purpose:   Driver of the OpenGL project
	  *
	  * Author:    Sebastian Gsell, James Madison University
	  *
	  * Version:   May 4, 2014
	  *
	  * This work complies with the JMU Honor Code.
	  */

static int            selectedSprite = 0;
static GLint          delay;
static Stage          stage;

/**
 * The display callback
 */
void display()
{
   stage.paint();   
}

/**
 * The keyboard callback
 */
void keyboard(unsigned char key, int x, int y)
{
   stage.keyPressed(key, x, y, selectedSprite);
}

/**
 * The reshape callback
 *
 * @param width   The new width
 * @param height  The new height
 */
void reshape(int width, int height)
{
   stage.reshape(width, height);   
}


/**
 * The timer callback
 *
 * @param value   The ID
 */
void timer(int value)
{
   stage.onTimer();

   // Re-start the timer
   glutTimerFunc(delay, timer, 1);
}



/**
 * The entry point of the application.
 *
 * @param argc  The number of command line arguments
 * @param argv  The array of command line arguments
 * @return      A status code
 */
int main(int argc, char **argv)
{
   Crane crane;
   Floor floor;
   
   delay = 20;   
   
   stage.addSprite(&crane); 
   stage.addSprite(&floor);

   glutInit(&argc, argv);
   
   glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
   glutInitWindowSize(1280, 800);
   glutCreateWindow("Crane Simulator");
   glutReshapeFunc(reshape);
   glutDisplayFunc(display);
   glutKeyboardFunc(keyboard);
   
   glutTimerFunc(delay, timer, 0);
   
   stage.start();
   
   return 0;   
}
