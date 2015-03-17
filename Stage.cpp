#include "Stage.h"

/**
 * A Stage is a "window" that contains animated Sprite
 * objects
 *
 * @author  Prof. David Bernstein, James Madison University
 * @version 1.0
 */

/**
 * Default Constructor
 */
Stage::Stage()
{

    light0Position[0] = 50.0; light0Position[1] = 50.0; 
    light0Position[2] = 0.0; light0Position[3] = 0.0;   

    colorWhite[0] = 1.2; colorWhite[1] = 1.2;
    colorWhite[2] = 1.2; colorWhite[3] = 1.2;   
   
    colorYellow[0] = 0.5; colorYellow[1] = 0.0;
    colorYellow[2] = 0.5; colorYellow[3] = 0.5;  

    colorGray[0] = 0.9; colorGray[1] = 0.9;
    colorGray[2] = 0.9; colorGray[3] = 1.0;  

    size = 0;
}

/**
 * Destructor
 */
Stage::~Stage()
{
   // Someone else is responsible for deleting the Sprite
}

/**
 * Add a Sprite to this Stage
 *
 * @param s   The Sprite to add
 */
void Stage::addSprite(Sprite* s)
{
   if (size < MAX_SPRITES)
   {
      sprite[size] = s;
      ++size;   
   }
}

/**
 * Perform OpenGL initializations
 */
void Stage::init() 
{
   glClearColor(1, 1, 1, 1);

   // Shading
   glShadeModel(GL_SMOOTH);   


   // Lighting
   GLfloat lightingmodelAmbient[] = {0.5, 0.5, 0.6, 1.0};   
   glLightModelfv(GL_LIGHT_MODEL_AMBIENT, lightingmodelAmbient);
   glLightModeli(GL_LIGHT_MODEL_LOCAL_VIEWER, GL_FALSE);
   glLightModeli(GL_LIGHT_MODEL_TWO_SIDE, GL_TRUE);

   // Lights
   glLightfv(GL_LIGHT0, GL_POSITION, light0Position);
   glLightfv(GL_LIGHT0, GL_DIFFUSE,  colorWhite);
   glLightfv(GL_LIGHT0, GL_SPECULAR, colorWhite);

   glLightfv(GL_LIGHT1, GL_POSITION, light0Position);
   glLightfv(GL_LIGHT1, GL_DIFFUSE,  colorYellow);
   glLightfv(GL_LIGHT1, GL_SPECULAR, colorYellow);


   // Enable
   glEnable(GL_LIGHTING);     // Enable lighting
   glEnable(GL_LIGHT0);       // Enable light number 0
   glEnable(GL_LIGHT1);       // Enable light number 1
   glEnable(GL_DEPTH_TEST);   // Enable depth buffering

   glEnable(GL_FOG);
   {
      glFogi(GL_FOG_MODE,    GL_EXP);
      glFogfv(GL_FOG_COLOR,  colorGray);
      glFogf(GL_FOG_DENSITY, 0.01);      
   }
   glClearColor(colorGray[0], colorGray[1], colorGray[2], colorGray[3]);   
}

/**
 * Forwards "key pressed" events to a particaulr Sprite
 *
 * @param key   The key
 * @param x      The x-position of the mouse
 * @param y      The y-position of the mouse
 * @param id     The ID of the sprite to forward to
 */
void Stage::keyPressed(unsigned char key, int x, int y, int id)
{
   if ((id >= 0) && (id < size)) sprite[id]->keyPressed(key, x, y);
}

/**
 * Forwards "mouse clicked" events to a particular Sprite object
 *
 * @param button The button (e.g., GLUT_LEFT_BUTTON)
 * @param state  The state (e.g., GLUT_UP or GLUT_DOWN)
 * @param x      The x-position of the mouse
 * @param y      The y-position of the mouse
 * @param id     The ID of the sprite to forward to
 */
void Stage::mouseClicked(int button, int state, int x, int y, int id)
{
   if ((id >= 0) && (id < size)) sprite[id]->mouseClicked(button, state, x, y);
}

/**
 * Forwards timer events to Sprite objects
 */
void Stage::onTimer()
{
   // Clear the screen
   glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

   // Tell the sprites
   for (int i=0; i<size; i++) sprite[i]->timerTicked();
   

   // Force a display callback
   glutPostRedisplay();
}

/**
 * Forces the Stage to be painted/rendered
 */
void Stage::paint()
{
   // Force the rendering (off-screen)
   glFlush();

   // Handle the double buffering
   glutSwapBuffers();
}

/**
 * Called to reshape the Stage
 *
 * @param width   The new width
 * @param height  The new height
 */
void Stage::reshape(int width, int height)
{
   GLfloat  aspect;
   GLfloat  size;
   size = 15.0;

   glViewport(0, 0, width, height);
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();

   aspect = (GLfloat)width/(GLfloat)height; 
   
   gluPerspective(65.0, aspect, 1.0, 80.0);
   
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
   gluLookAt(0.0, 20, 30, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
}

/**
 * Start the Stage
 */
void Stage::start()
{
    init();

    glutMainLoop();
}
