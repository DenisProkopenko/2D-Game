/*
    CSCI 1101  
    Denis Prokopenko
    
    
    //home set
    C:/Dev-Cpp/lib/libopengl32.a
    C:/Dev-Cpp/lib/libglu32.a
    C:/Dev-Cpp/lib/libglut32.a
    

    //school set
    "C:/Program Files/Dev C++/lib/libglu32.a"
    "C:/Program Files/Dev C++/lib/libglut32.a"
    "C:/Program Files/Dev C++/lib/libopengl32.a"

     
    This is a simple example to get you
    up and running with OpenGL and GLUT.

    This example can be used to do simple
    2 dimensional drawing.  Do your work in
    the function DrawScene()

 
   Assignment
   
 Draw a 2 dimensional scene using OpenGl -- make sure to use the following OpenGL functions
   
   glColor3f(GLfloat red, GLfloat green, GLfloat blue); 
   glVertex2i(GLint x, GLint y);
   
   glBegin(int mode) using GL_POINTS, GL_LINES, GL_TRIANGLES, GL_QUADS
   glEnd()
   
   
   I suggest you look at the example already done in DrawScene and figure out how it
   works first.  For more information on OpenGL the official web site is http://www.opengl.org/
   
  ------- OPTIONAL -------
  
  for more fun you might want to try playing with
      glPointSize(GLFloat size); //try numbers from 1.0 to 10.0
      glLineWidth(GLFloat width); //try numbers from 1.0 to 10.0
   make sure to call these function before a glBegin(), not between a glBegin() and glEnd()
   
   another fun thing to try is when you draw a triangle of quadrilateral change the color
   for each vertex, in other words use a call to glColor before the call to glVertex
   
   ------ END OF OPTIONAL ---------
   
 
   
*/

#include <windows.h>
#include <gl\gl.h>
#include "glut.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>


#define WINDOW_HEIGHT 500

/*function prototypes*/
void drawScene(void);
void display(void);
void myMouse(int button, int state, int x, int y);
void myMouseMove(int x, int y);
void myKeyboard(unsigned char key, int x, int y);
int getRand(int first, int last);
void init(void);
void drawGridLines(int small_spacing, int big_spacing);
void drawCircle(int center_x, int center_y, int radius, int nSides);

/* global variables -- generally a bad idea
these are used to illustrate using the mouse keep track of the last place clicked */
int gMouse_x = 200;
int gMouse_y = 100;
char gShowGrid = 1;

int gChopperState=0;
int gWaveState=0;
int gBeachState=0;
int gRocketState=0;

int ChopperY =0;
int ChopperX =0;

int RocketX1 =0;
int RocketY1 =0;
int RocketX2 =0;
int RocketY2 =0;
int RocketX3 =0;
int RocketY3 =0;
int RocketX4 =0;
int RocketY4 =0;
int RocketX5 =0;
int RocketY5 =0;
int RocketX6 =0;
int RocketY6 =0;
int RocketX7 =0;
int RocketY7 =0;
int RocketX8 =0;
int RocketY8 =0;


int height = 180;
int delta = 5;


char g_bAnimateChopper =0;
char g_bAnimateWater =0;
char g_bAnimateBeach =0;
char g_bAnimateRocket1 =0;
char g_bAnimateRocket2 =0;

void drawCheckerSquares( float left,
float top, float rect_width, 
float rect_height, float kerf,
int rows, int cols);


void drawScene(void)
{ /* Start Draw */

glBegin(GL_QUADS); 
// Sand 
glColor3f(0.9, 0.8, 0.7); //Sand Color
glVertex2i(0, 500);
glVertex2i(500, 500);
glVertex2i(500, 300);
glVertex2i(0, 300);

// Water 
glColor3f(0.0, 0.5, 1.0); //Water Color
glVertex2i(0, 300);
glVertex2i(500, 300);
glVertex2i(500, 0);
glVertex2i(0, 0);
glEnd(); // End Quads (Water+Sand)
//
//
// Start Circle Waves
glColor3f(0.0, 0.5, 1.0); //Water Color
// Wave 1
if (gWaveState == 0){
   drawCircle(0, 300, 50, 50);
   }else if (gWaveState == 1){
   drawCircle(0, 315, 50, 50);
   }else if (gWaveState == 2){
   drawCircle(0, 325, 50, 50);
   }else if (gWaveState == 3){
   drawCircle(0, 315, 50, 50);
}
// Wave 2
if (gWaveState == 0){
   drawCircle(50, 315, 50, 50);
   }else if (gWaveState == 1){
   drawCircle(50, 325, 50, 50);
   }else if (gWaveState == 2){
   drawCircle(50, 315, 50, 50);
   }else if (gWaveState == 3){
   drawCircle(50, 300, 50, 50);
}
// Wave 3
if (gWaveState == 0){
   drawCircle(100, 325, 50, 50);
   }else if (gWaveState == 1){
   drawCircle(100, 315, 50, 50);
   }else if (gWaveState == 2){
   drawCircle(100, 300, 50, 50);
   }else if (gWaveState == 3){
   drawCircle(100, 315, 50, 50);
}
// Wave 4
if (gWaveState == 0){
   drawCircle(150, 315, 50, 50);
   }else if (gWaveState == 1){
   drawCircle(150, 300, 50, 50);
   }else if (gWaveState == 2){
   drawCircle(150, 315, 50, 50);
   }else if (gWaveState == 3){
   drawCircle(150, 325, 50, 50);
}
// Wave 5
if (gWaveState == 0){
   drawCircle(200, 300, 50, 50);
   }else if (gWaveState == 1){
   drawCircle(200, 315, 50, 50);
   }else if (gWaveState == 2){
   drawCircle(200, 325, 50, 50);
   }else if (gWaveState == 3){
   drawCircle(200, 315, 50, 50);
}
// Wave 6
if (gWaveState == 0){
   drawCircle(250, 315, 50, 50);
   }else if (gWaveState == 1){
   drawCircle(250, 325, 50, 50);
   }else if (gWaveState == 2){
   drawCircle(250, 315, 50, 50);
   }else if (gWaveState == 3){
   drawCircle(250, 300, 50, 50);
}
// Wave 7
if (gWaveState == 0){
   drawCircle(300, 325, 50, 50);
   }else if (gWaveState == 1){
   drawCircle(300, 315, 50, 50);
   }else if (gWaveState == 2){
   drawCircle(300, 300, 50, 50);
   }else if (gWaveState == 3){
   drawCircle(300, 315, 50, 50);
}
// Wave 8
if (gWaveState == 0){
   drawCircle(350, 315, 50, 50);
   }else if (gWaveState == 1){
   drawCircle(350, 300, 50, 50);
   }else if (gWaveState == 2){
   drawCircle(350, 315, 50, 50);
   }else if (gWaveState == 3){
   drawCircle(350, 325, 50, 50);
}
// Wave 9
if (gWaveState == 0){
   drawCircle(400, 300, 50, 50);
   }else if (gWaveState == 1){
   drawCircle(400, 315, 50, 50);
   }else if (gWaveState == 2){
   drawCircle(400, 325, 50, 50);
   }else if (gWaveState == 3){
   drawCircle(400, 315, 50, 50);
}
// Wave 10
if (gWaveState == 0){
   drawCircle(450, 315, 50, 50);
   }else if (gWaveState == 1){
   drawCircle(450, 325, 50, 50);
   }else if (gWaveState == 2){
   drawCircle(450, 315, 50, 50);
   }else if (gWaveState == 3){
   drawCircle(450, 300, 50, 50);
}
// Wave 11

if (gWaveState == 0){
   drawCircle(500, 325, 50, 50);
   }else if (gWaveState == 1){
   drawCircle(500, 315, 50, 50);
   }else if (gWaveState == 2){
   drawCircle(500, 300, 50, 50);
   }else if (gWaveState == 3){
   drawCircle(500, 315, 50, 50);
}

glBegin(GL_QUADS); // Start Squares
// Water 
glColor3f(0.0, 0.5, 1.0); //Water Color
glVertex2i(0, 300);
glVertex2i(500, 300);
glVertex2i(500, 0);
glVertex2i(0, 0);
glEnd(); // End Quads

glColor3f(0.627, 0.776, 0.529); // Grey body parts
drawCircle(310+ ChopperX, 200+ ChopperY, 10, 10);//Front circle

glBegin(GL_QUADS); // Grey center parts
glVertex2i(230+ ChopperX, 238+ ChopperY);// gun top
glVertex2i(255+ ChopperX, 238+ ChopperY);
glVertex2i(255+ ChopperX, 230+ ChopperY);
glVertex2i(230+ ChopperX, 230+ ChopperY);

glVertex2i(230+ ChopperX, 162+ ChopperY);// gun bottom
glVertex2i(255+ ChopperX, 162+ ChopperY);
glVertex2i(255+ ChopperX, 170+ ChopperY);
glVertex2i(230+ ChopperX, 170+ ChopperY);

glVertex2i(250+ ChopperX, 215+ ChopperY);// tail length
glVertex2i(115+ ChopperX, 203+ ChopperY);
glVertex2i(115+ ChopperX, 197+ ChopperY);
glVertex2i(250+ ChopperX, 185+ ChopperY);

glVertex2i(230+ ChopperX, 250+ ChopperY);// Center bottom
glVertex2i(250+ ChopperX, 250+ ChopperY);
glVertex2i(250+ ChopperX, 150+ ChopperY);
glVertex2i(230+ ChopperX, 150+ ChopperY);

glVertex2i(220+ ChopperX, 230+ ChopperY);//Center back
glVertex2i(250+ ChopperX, 230+ ChopperY);
glVertex2i(250+ ChopperX, 170+ ChopperY);
glVertex2i(220+ ChopperX, 170+ ChopperY);

glVertex2i(135+ ChopperX, 215+ ChopperY);//Back wings
glVertex2i(145+ ChopperX, 215+ ChopperY);
glVertex2i(145+ ChopperX, 185+ ChopperY);
glVertex2i(135+ ChopperX, 185+ ChopperY);

glVertex2i(250+ ChopperX, 210+ ChopperY);//Front Bottom
glVertex2i(310+ ChopperX, 210+ ChopperY);
glVertex2i(310+ ChopperX, 190+ ChopperY);
glVertex2i(250+ ChopperX, 190+ ChopperY);

glVertex2i(250+ ChopperX, 215+ ChopperY);//Front Cabin
glVertex2i(300+ ChopperX, 215+ ChopperY);
glVertex2i(300+ ChopperX, 185+ ChopperY);
glVertex2i(250+ ChopperX, 185+ ChopperY);

glVertex2i(250+ ChopperX, 220+ ChopperY);//Front Around Cabin
glVertex2i(285+ ChopperX, 220+ ChopperY);
glVertex2i(285+ ChopperX, 180+ ChopperY);
glVertex2i(250+ ChopperX, 180+ ChopperY);
glEnd();

glBegin(GL_TRIANGLES);//Triangles to smothe edges
glVertex2i(132+ ChopperX, 202+ ChopperY);//Tail top
glVertex2i(135+ ChopperX, 215+ ChopperY);
glVertex2i(135+ ChopperX, 202+ ChopperY);

glVertex2i(132+ ChopperX, 198+ ChopperY);//Tail bottom
glVertex2i(135+ ChopperX, 185+ ChopperY);
glVertex2i(135+ ChopperX, 198+ ChopperY);

glVertex2i(225+ ChopperX, 230+ ChopperY);//Wing top
glVertex2i(230+ ChopperX, 250+ ChopperY);
glVertex2i(230+ ChopperX, 230+ ChopperY);

glVertex2i(225+ ChopperX, 170+ ChopperY);//Wing top
glVertex2i(230+ ChopperX, 150+ ChopperY);
glVertex2i(230+ ChopperX, 170+ ChopperY);

glVertex2i(285+ ChopperX, 220+ ChopperY);//Cabin top
glVertex2i(300+ ChopperX, 215+ ChopperY);
glVertex2i(285+ ChopperX, 215+ ChopperY);

glVertex2i(285+ ChopperX, 180+ ChopperY);//Cabin bottom
glVertex2i(300+ ChopperX, 185+ ChopperY);
glVertex2i(285+ ChopperX, 185+ ChopperY);
glEnd();

glColor3f(0.0, 0.0, 0.0); // Black
if (gChopperState == 0){
glBegin(GL_QUADS); // Start top Propeller
// Propeller Top
glVertex2i(247+ ChopperX, 220+ ChopperY);
glVertex2i(247+ ChopperX, 280+ ChopperY);
glVertex2i(253+ ChopperX, 280+ ChopperY);
glVertex2i(253+ ChopperX, 220+ ChopperY);
glEnd(); // //End top propeller

glBegin(GL_TRIANGLES); // Propeller connector
glVertex2i(250+ ChopperX, 200+ ChopperY);
glVertex2i(247+ ChopperX, 220+ ChopperY);
glVertex2i(253+ ChopperX, 220+ ChopperY);
glEnd(); // End triangles

glBegin(GL_QUADS); // Start bottom Propeller
// Propeller Bottom
glVertex2i(247+ ChopperX, 180+ ChopperY);
glVertex2i(247+ ChopperX, 120+ ChopperY);
glVertex2i(253+ ChopperX, 120+ ChopperY);
glVertex2i(253+ ChopperX, 180+ ChopperY);
glEnd(); //End propeller

glBegin(GL_TRIANGLES); // Propeller bottom connector
glVertex2i(250+ ChopperX, 200+ ChopperY);
glVertex2i(247+ ChopperX, 180+ ChopperY);
glVertex2i(253+ ChopperX, 180+ ChopperY);
glEnd();//End triangles

glBegin(GL_QUADS); // Start left Propeller
// Propeller left
glVertex2i(230+ ChopperX, 203+ ChopperY);
glVertex2i(170+ ChopperX, 203+ ChopperY);
glVertex2i(170+ ChopperX, 197+ ChopperY);
glVertex2i(230+ ChopperX, 197+ ChopperY);
glEnd(); //End Propeller

glBegin(GL_TRIANGLES); // Propeller connector
glVertex2i(250+ ChopperX, 200+ ChopperY);
glVertex2i(230+ ChopperX, 203+ ChopperY);
glVertex2i(230+ ChopperX, 197+ ChopperY);
glEnd();//End triangles

glBegin(GL_QUADS); // Start right Propeller
// Propeller Right
glVertex2i(270+ ChopperX, 203+ ChopperY);
glVertex2i(330+ ChopperX, 203+ ChopperY);
glVertex2i(330+ ChopperX, 197+ ChopperY);
glVertex2i(270+ ChopperX, 197+ ChopperY);
glEnd(); // //End propeller

glBegin(GL_TRIANGLES); // Propeller right connector
glVertex2i(250+ ChopperX, 200+ ChopperY);
glVertex2i(270+ ChopperX, 203+ ChopperY);
glVertex2i(270+ ChopperX, 197+ ChopperY);
glEnd(); //End triangles
}
//
// Start of 2nd state of the propeller
//

if (gChopperState == 1){
glBegin(GL_QUADS); // Start top Propeller
// Propeller Top
glVertex2i(266.2634+ ChopperX, 212.0208+ ChopperY);//br
glVertex2i(312.93244+ ChopperX, 254.4472+ ChopperY);//tr
glVertex2i(308.68984+ ChopperX, 258.6898+ ChopperY);//tl
glVertex2i(262.0208+ ChopperX, 216.2634+ ChopperY);//bl
glEnd(); //End propeller

glBegin(GL_TRIANGLES); // Propeller connector
glVertex2i(250+ ChopperX, 200+ ChopperY);
glVertex2i(266.2634+ ChopperX, 212.0208+ ChopperY);
glVertex2i(262.0208+ ChopperX, 216.2634+ ChopperY);
glEnd(); // End triangles

glBegin(GL_QUADS); // Start bottom-left Propeller
// Propeller Bottom-left
glVertex2i(237.9792+ ChopperX, 183.8377+ ChopperY);//tr
glVertex2i(191.3002+ ChopperX, 141.31016+ ChopperY);//br
glVertex2i(187.06756+ ChopperX, 145.5528+ ChopperY);//bl
glVertex2i(233.7366+ ChopperX, 187.9792+ ChopperY);//tl
glEnd(); //End propeller

glBegin(GL_TRIANGLES); // Propeller bottom-left connector
glVertex2i(250+ ChopperX, 200+ ChopperY);
glVertex2i(233.7366+ ChopperX, 187.9792+ ChopperY);
glVertex2i(237.9792+ ChopperX, 183.8377+ ChopperY);
glEnd();//End triangles

glBegin(GL_QUADS); // Start left-up Propeller
// Propeller left-up
glVertex2i(237.9792+ ChopperX, 216.2634+ ChopperY);//br
glVertex2i(195.5528+ ChopperX, 262.93244+ ChopperY);//tl
glVertex2i(190.06756+ ChopperX, 258.4472+ ChopperY);//tr
glVertex2i(233.7366+ ChopperX, 212.0208+ ChopperY);//bl
glEnd(); //End Propeller

glBegin(GL_TRIANGLES); // Propeller connector
glVertex2i(250+ ChopperX, 200+ ChopperY);
glVertex2i(233.7366+ ChopperX, 212.0208+ ChopperY);
glVertex2i(237.9792+ ChopperX, 216.2634+ ChopperY);
glEnd(); // End left-up connector
glEnd(); // End left-up Propeller

glBegin(GL_QUADS); // Start right-bottom Propeller
// Propeller Right-bottom
glVertex2i(266.2634+ ChopperX, 187.9792+ ChopperY);//tl
glVertex2i(312.93244+ ChopperX, 145.5528+ ChopperY);//tl
glVertex2i(306.4472+ ChopperX, 141.16866+ ChopperY);//tr
glVertex2i(262.0208+ ChopperX, 183.8377+ ChopperY);//tr
glEnd(); // End Propeller

glBegin(GL_TRIANGLES); // Propeller right-bottom connector
glVertex2i(250+ ChopperX, 200+ ChopperY);
glVertex2i(266.2634+ ChopperX, 187.9792+ ChopperY);
glVertex2i(262.0208+ ChopperX, 183.8377+ ChopperY);
glEnd(); // End right-bottom connector
glEnd();// End right-bottom Propeller
}

glColor3f(0.0, 0.0, 0.0); // Black
glBegin(GL_QUADS); // Cockpit
//Front Window
glVertex2i(300+ ChopperX, 208+ ChopperY);
glVertex2i(300+ ChopperX, 192+ ChopperY);
glVertex2i(285+ ChopperX, 194+ ChopperY);
glVertex2i(285+ ChopperX, 206+ ChopperY);

//Back Window
glVertex2i(283+ ChopperX, 206+ ChopperY);
glVertex2i(283+ ChopperX, 194+ ChopperY);
glVertex2i(263+ ChopperX, 195+ ChopperY);
glVertex2i(263+ ChopperX, 205+ ChopperY);
glEnd(); //
//
//Propeller Centers
// 
glColor3f(0.3, 0.3, 0.3); // Light Black
drawCircle(250+ ChopperX, 200+ ChopperY, 10, 10);
glColor3f(0.0, 0.0, 0.0); // Black
drawCircle(250+ ChopperX, 200+ ChopperY, 2, 10);
//
//Helicopter outline
//
glBegin(GL_LINE_STRIP);
glVertex2i(115+ ChopperX, 197+ ChopperY);
glVertex2i(115+ ChopperX, 203+ ChopperY);
glVertex2i(220+ ChopperX, 213+ ChopperY);
glVertex2i(220+ ChopperX, 230+ ChopperY);
glVertex2i(225+ ChopperX, 230+ ChopperY);
glVertex2i(230+ ChopperX, 250+ ChopperY);
glVertex2i(250+ ChopperX, 250+ ChopperY);
glVertex2i(250+ ChopperX, 238+ ChopperY);
glVertex2i(255+ ChopperX, 238+ ChopperY);
glVertex2i(255+ ChopperX, 230+ ChopperY);
glVertex2i(250+ ChopperX, 230+ ChopperY);
glVertex2i(250+ ChopperX, 220+ ChopperY);
glVertex2i(285+ ChopperX, 220+ ChopperY);
glVertex2i(300+ ChopperX, 215+ ChopperY);
glVertex2i(300+ ChopperX, 210+ ChopperY);
glVertex2i(312+ ChopperX, 210+ ChopperY);
glEnd();
glBegin(GL_LINE_STRIP);
glVertex2i(115+ ChopperX, 197+ ChopperY);
glVertex2i(220+ ChopperX, 188+ ChopperY);
glVertex2i(220+ ChopperX, 170+ ChopperY);
glVertex2i(225+ ChopperX, 170+ ChopperY);
glVertex2i(230+ ChopperX, 150+ ChopperY);
glVertex2i(250+ ChopperX, 150+ ChopperY);
glVertex2i(250+ ChopperX, 162+ ChopperY);
glVertex2i(255+ ChopperX, 162+ ChopperY);
glVertex2i(255+ ChopperX, 170+ ChopperY);
glVertex2i(250+ ChopperX, 170+ ChopperY);
glVertex2i(250+ ChopperX, 180+ ChopperY);
glVertex2i(285+ ChopperX, 180+ ChopperY);
glVertex2i(300+ ChopperX, 185+ ChopperY);
glVertex2i(300+ ChopperX, 190+ ChopperY);
glVertex2i(312+ ChopperX, 190+ ChopperY);
glEnd();
glBegin(GL_LINE_STRIP);
glVertex2i(145+ ChopperX, 194+ ChopperY);
glVertex2i(145+ ChopperX, 185+ ChopperY);
glVertex2i(135+ ChopperX, 185+ ChopperY);
glVertex2i(133+ ChopperX, 195+ ChopperY);
glEnd();
glBegin(GL_LINE_STRIP);
glVertex2i(145+ ChopperX, 206+ ChopperY);
glVertex2i(145+ ChopperX, 215+ ChopperY);
glVertex2i(135+ ChopperX, 215+ ChopperY);
glVertex2i(133+ ChopperX, 205+ ChopperY);
glEnd();
glBegin(GL_LINE_STRIP);
glVertex2i(312+ ChopperX, 190+ ChopperY);
glVertex2i(315+ ChopperX, 192+ ChopperY);
glVertex2i(319+ ChopperX, 198+ ChopperY);
glVertex2i(319+ ChopperX, 202+ ChopperY);
glVertex2i(315+ ChopperX, 208+ ChopperY);
glVertex2i(312+ ChopperX, 210+ ChopperY);
glEnd();
glBegin(GL_LINE_STRIP);
glVertex2i(250+ ChopperX, 175+ ChopperY);
glVertex2i(220+ ChopperX, 170+ ChopperY);
glVertex2i(220+ ChopperX, 188+ ChopperY);
glVertex2i(235+ ChopperX, 188+ ChopperY);
glEnd();
glBegin(GL_LINE_STRIP);
glVertex2i(250+ ChopperX, 225+ ChopperY);
glVertex2i(220+ ChopperX, 230+ ChopperY);
glVertex2i(220+ ChopperX, 212+ ChopperY);
glVertex2i(235+ ChopperX, 212+ ChopperY);
glEnd();
glBegin(GL_LINE_STRIP);
glVertex2i(300+ ChopperX, 190+ ChopperY);
glVertex2i(260+ ChopperX, 193+ ChopperY);
glVertex2i(260+ ChopperX, 207+ ChopperY);
glVertex2i(300+ ChopperX, 210+ ChopperY);
glVertex2i(300+ ChopperX, 190+ ChopperY);
glEnd();
glBegin(GL_LINE_STRIP);
glVertex2i(250+ ChopperX, 245+ ChopperY);
glVertex2i(245+ ChopperX, 245+ ChopperY);
glVertex2i(245+ ChopperX, 227+ ChopperY);
glVertex2i(250+ ChopperX, 225+ ChopperY);
glVertex2i(250+ ChopperX, 245+ ChopperY);
glEnd();
glBegin(GL_LINE_STRIP);
glVertex2i(250+ ChopperX, 155+ ChopperY);
glVertex2i(245+ ChopperX, 155+ ChopperY);
glVertex2i(245+ ChopperX, 173+ ChopperY);
glVertex2i(250+ ChopperX, 175+ ChopperY);
glVertex2i(250+ ChopperX, 155+ ChopperY);
glEnd();
//Star Top
glBegin(GL_LINE_STRIP);
glVertex2i(230+ ChopperX, 230+ ChopperY);
glVertex2i(235+ ChopperX, 242+ ChopperY);
glVertex2i(240+ ChopperX, 230+ ChopperY);
glVertex2i(228+ ChopperX, 237+ ChopperY);
glVertex2i(242+ ChopperX, 237+ ChopperY);
glVertex2i(230+ ChopperX, 230+ ChopperY);
glEnd();
//Star Bottom
glBegin(GL_LINE_STRIP);
glVertex2i(230+ ChopperX, 170+ ChopperY);
glVertex2i(235+ ChopperX, 158+ ChopperY);
glVertex2i(240+ ChopperX, 170+ ChopperY);
glVertex2i(228+ ChopperX, 163+ ChopperY);
glVertex2i(242+ ChopperX, 163+ ChopperY);
glVertex2i(230+ ChopperX, 170+ ChopperY);
glEnd();
glBegin(GL_LINE_STRIP);
glVertex2i(310+ ChopperX, 210+ ChopperY);
glVertex2i(310+ ChopperX, 190+ ChopperY);
glEnd();
//
//Start Rockets
//
//Rocket States
if (gRocketState == 0){
      RocketX1 = RocketX1 - 1;
      RocketX3 = RocketX3 - 1;
      RocketX4 = RocketX4 - 1;
      RocketX2 = RocketX2 - 1;
      RocketX5 = RocketX5 - 1;
      RocketX6 = RocketX6 - 1;
      if (RocketX2 < -115){
         RocketX2 = 460;
         
         }
      if (RocketX5 < -115){
         RocketX5 = 460;
         
         }
      if (RocketX6 < -115){
         RocketX6 = 460;
         
         }
      if (RocketX1 < -445){
         RocketX1 = 120;
         
         }
      if (RocketX3 < -445){
         RocketX3 = 120;
         
         }
      if (RocketX4 < -445){
         RocketX4 = 120;
         
         }
}
if (gRocketState == 1){
      RocketX1 = RocketX1 - 1;
      RocketX2 = RocketX2 - 1;
      RocketX3 = RocketX3 - 1;
      RocketX4 = RocketX4 - 1;
      RocketX5 = RocketX5 - 1;
      RocketX6 = RocketX6 - 1;
      if (RocketX2 < -115){
         RocketX2 = 460;
         
         }
      if (RocketX5 < -115){
         RocketX5 = 460;
         
         }
      if (RocketX6 < -115){
         RocketX6 = 460;
         
         }
      if (RocketX1 < -445){
         RocketX1 = 120;
         
         }
      if (RocketX3 < -445){
         RocketX3 = 120;
         
         }
      if (RocketX4 < -445){
         RocketX4 = 120;
         
         }
}
//
glColor3f(1.0, 1.0, 1.0); //White Bullets (Bullet #1)
glBegin(GL_QUADS);
glVertex2i(400+ RocketX1, 55+ RocketY1);
glVertex2i(400+ RocketX1, 45+ RocketY1);
glVertex2i(430+ RocketX1, 45+ RocketY1);
glVertex2i(430+ RocketX1, 55+ RocketY1);
glEnd();
//
glBegin(GL_TRIANGLES);
glVertex2i(400+ RocketX1, 55+ RocketY1);
glVertex2i(400+ RocketX1, 45+ RocketY1);
glVertex2i(395+ RocketX1, 50+ RocketY1);
//
glVertex2i(429+ RocketX1, 50+ RocketY1);
glVertex2i(434+ RocketX1, 45+ RocketY1);
glVertex2i(434+ RocketX1, 55+ RocketY1);
//
glColor3f(1.0, 0.0, 0.0);//Red Flame Base
glVertex2i(434+ RocketX1, 55+ RocketY1);
glVertex2i(434+ RocketX1, 50+ RocketY1);
glColor3f(0.7, 0.0, 0.0);//Red Flame Base
glVertex2i(444+ RocketX1, 57+ RocketY1);
//
glColor3f(1.0, 0.0, 0.0);//Red Flame Base
glVertex2i(434+ RocketX1, 45+ RocketY1);
glVertex2i(434+ RocketX1, 50+ RocketY1);
glColor3f(0.7, 0.0, 0.0);//Red Flame Base
glVertex2i(444+ RocketX1, 43+ RocketY1);
//
glColor3f(1.0, 0.0, 0.0);//Red Flame Base
glVertex2i(434+ RocketX1, 55+ RocketY1);
glVertex2i(434+ RocketX1, 45+ RocketY1);
glColor3f(0.7, 0.0, 0.0);//Red Flame Base
glVertex2i(448+ RocketX1, 50+ RocketY1);
glEnd();
//
glColor3f(1.0, 0.0, 0.0);//Red Flame Base
glColor3f(0.0, 0.8, 0.0); //Green Strips
glBegin(GL_LINE_STRIP);
glVertex2i(410+ RocketX1, 55+ RocketY1);
glVertex2i(410+ RocketX1, 45+ RocketY1);
glEnd();
//
glColor3f(0.0, 0.0, 0.0); //Black Outlines (Bullet #1)
glBegin(GL_LINE_STRIP);
glVertex2i(430+ RocketX1, 49+ RocketY1);
glVertex2i(430+ RocketX1, 45+ RocketY1);
glVertex2i(400+ RocketX1, 45+ RocketY1);
glVertex2i(395+ RocketX1, 50+ RocketY1);
glVertex2i(400+ RocketX1, 55+ RocketY1);
glVertex2i(430+ RocketX1, 55+ RocketY1);
glVertex2i(430+ RocketX1, 51+ RocketY1);
glVertex2i(434+ RocketX1, 55+ RocketY1);
glVertex2i(434+ RocketX1, 45+ RocketY1);
glVertex2i(430+ RocketX1, 49+ RocketY1);
glEnd();
//
glColor3f(1.0, 1.0, 1.0); //White Bullets (Bullet #2)
glBegin(GL_QUADS);
glVertex2i(70+ RocketX2, 55+ RocketY2);
glVertex2i(70+ RocketX2, 45+ RocketY2);
glVertex2i(100+ RocketX2, 45+ RocketY2);
glVertex2i(100+ RocketX2, 55+ RocketY2);
glEnd();
//
glBegin(GL_TRIANGLES);
glVertex2i(70+ RocketX2, 55+ RocketY2);
glVertex2i(70+ RocketX2, 45+ RocketY2);
glVertex2i(65+ RocketX2, 50+ RocketY2);
//
glVertex2i(99+ RocketX2, 50+ RocketY2);
glVertex2i(104+ RocketX2, 45+ RocketY2);
glVertex2i(104+ RocketX2, 55+ RocketY2);
//
glColor3f(1.0, 0.0, 0.0);//Red Flame Base
glVertex2i(104+ RocketX2, 55+ RocketY2);
glVertex2i(104+ RocketX2, 50+ RocketY2);
glColor3f(0.7, 0.0, 0.0);//Red Flame Base
glVertex2i(114+ RocketX2, 57+ RocketY2);
//
glColor3f(1.0, 0.0, 0.0);//Red Flame Base
glVertex2i(104+ RocketX2, 45+ RocketY2);
glVertex2i(104+ RocketX2, 50+ RocketY2);
glColor3f(0.7, 0.0, 0.0);//Red Flame Base
glVertex2i(114+ RocketX2, 43+ RocketY2);
//
glColor3f(1.0, 0.0, 0.0);//Red Flame Base
glVertex2i(104+ RocketX2, 55+ RocketY2);
glVertex2i(104+ RocketX2, 45+ RocketY2);
glColor3f(0.7, 0.0, 0.0);//Red Flame Base
glVertex2i(118+ RocketX2, 50+ RocketY2);
glEnd();
//
glColor3f(0.0, 0.8, 0.0); //Green Strips
glBegin(GL_LINE_STRIP);
glVertex2i(80+ RocketX2, 55+ RocketY2);
glVertex2i(80+ RocketX2, 45+ RocketY2);
glVertex2i(83+ RocketX2, 45+ RocketY2);
glVertex2i(83+ RocketX2, 55+ RocketY2);
glEnd();
//
glColor3f(0.0, 0.0, 0.0); //Black Outlines (Bullet #2)
glBegin(GL_LINE_STRIP);
glVertex2i(100+ RocketX2, 49+ RocketY2);
glVertex2i(100+ RocketX2, 45+ RocketY2);
glVertex2i(70+ RocketX2, 45+ RocketY2);
glVertex2i(65+ RocketX2, 50+ RocketY2);
glVertex2i(70+ RocketX2, 55+ RocketY2);
glVertex2i(100+ RocketX2, 55+ RocketY2);
glVertex2i(100+ RocketX2, 51+ RocketY2);
glVertex2i(104+ RocketX2, 55+ RocketY2);
glVertex2i(104+ RocketX2, 45+ RocketY2);
glVertex2i(100+ RocketX2, 49+ RocketY2);
glEnd();
//
glColor3f(1.0, 1.0, 1.0); //White Bullets (Bullet #3)
glBegin(GL_QUADS);
glVertex2i(400+ RocketX3, 255+ RocketY3);
glVertex2i(400+ RocketX3, 245+ RocketY3);
glVertex2i(430+ RocketX3, 245+ RocketY3);
glVertex2i(430+ RocketX3, 255+ RocketY3);
glEnd();
//
glBegin(GL_TRIANGLES);
glVertex2i(400+ RocketX3, 255+ RocketY3);
glVertex2i(400+ RocketX3, 245+ RocketY3);
glVertex2i(395+ RocketX3, 250+ RocketY3);
//
glVertex2i(429+ RocketX3, 250+ RocketY3);
glVertex2i(434+ RocketX3, 245+ RocketY3);
glVertex2i(434+ RocketX3, 255+ RocketY3);
//
glColor3f(1.0, 0.0, 0.0);//Red Flame Base
glVertex2i(434+ RocketX3, 255+ RocketY3);
glVertex2i(434+ RocketX3, 250+ RocketY3);
glColor3f(0.7, 0.0, 0.0);//Red Flame Base
glVertex2i(444+ RocketX3, 257+ RocketY3);
//
glColor3f(1.0, 0.0, 0.0);//Red Flame Base
glVertex2i(434+ RocketX3, 245+ RocketY3);
glVertex2i(434+ RocketX3, 250+ RocketY3);
glColor3f(0.7, 0.0, 0.0);//Red Flame Base
glVertex2i(444+ RocketX3, 243+ RocketY3);
//
glColor3f(1.0, 0.0, 0.0);//Red Flame Base
glVertex2i(434+ RocketX3, 255+ RocketY3);
glVertex2i(434+ RocketX3, 245+ RocketY3);
glColor3f(0.7, 0.0, 0.0);//Red Flame Base
glVertex2i(448+ RocketX3, 250+ RocketY3);
glEnd();
//
glColor3f(0.0, 0.8, 0.0); //Green Strips
glBegin(GL_LINE_STRIP);
glVertex2i(410+ RocketX3, 255+ RocketY3);
glVertex2i(410+ RocketX3, 245+ RocketY3);
glVertex2i(413+ RocketX3, 245+ RocketY3);
glVertex2i(413+ RocketX3, 255+ RocketY3);
glVertex2i(416+ RocketX3, 255+ RocketY3);
glVertex2i(416+ RocketX3, 245+ RocketY3);
glEnd();
//
glColor3f(0.0, 0.0, 0.0); //Black Outlines (Bullet #3)
glBegin(GL_LINE_STRIP);
glVertex2i(430+ RocketX3, 249+ RocketY3);
glVertex2i(430+ RocketX3, 245+ RocketY3);
glVertex2i(400+ RocketX3, 245+ RocketY3);
glVertex2i(395+ RocketX3, 250+ RocketY3);
glVertex2i(400+ RocketX3, 255+ RocketY3);
glVertex2i(430+ RocketX3, 255+ RocketY3);
glVertex2i(430+ RocketX3, 251+ RocketY3);
glVertex2i(434+ RocketX3, 255+ RocketY3);
glVertex2i(434+ RocketX3, 245+ RocketY3);
glVertex2i(430+ RocketX3, 249+ RocketY3);
glEnd();
//
glColor3f(1.0, 1.0, 1.0); //White Bullets (Bullet #4)
glBegin(GL_QUADS);
glVertex2i(400+ RocketX4, 455+ RocketY4);
glVertex2i(400+ RocketX4, 445+ RocketY4);
glVertex2i(430+ RocketX4, 445+ RocketY4);
glVertex2i(430+ RocketX4, 455+ RocketY4);
glEnd();
glBegin(GL_TRIANGLES);
glVertex2i(400+ RocketX4, 455+ RocketY4);
glVertex2i(400+ RocketX4, 445+ RocketY4);
glVertex2i(395+ RocketX4, 450+ RocketY4);
//
glVertex2i(429+ RocketX4, 450+ RocketY4);
glVertex2i(434+ RocketX4, 445+ RocketY4);
glVertex2i(434+ RocketX4, 455+ RocketY4);
//
glColor3f(1.0, 0.0, 0.0);//Red Flame Base
glVertex2i(434+ RocketX4, 455+ RocketY4);
glVertex2i(434+ RocketX4, 450+ RocketY4);
glColor3f(0.7, 0.0, 0.0);//Red Flame Base
glVertex2i(444+ RocketX4, 457+ RocketY4);
//
glColor3f(1.0, 0.0, 0.0);//Red Flame Base
glVertex2i(434+ RocketX4, 445+ RocketY4);
glVertex2i(434+ RocketX4, 450+ RocketY4);
glColor3f(0.7, 0.0, 0.0);//Red Flame Base
glVertex2i(444+ RocketX4, 443+ RocketY4);
//
glColor3f(1.0, 0.0, 0.0);//Red Flame Base
glVertex2i(434+ RocketX4, 455+ RocketY4);
glVertex2i(434+ RocketX4, 445+ RocketY4);
glColor3f(0.7, 0.0, 0.0);//Red Flame Base
glVertex2i(448+ RocketX4, 450+ RocketY4);
glEnd();
//
glColor3f(0.0, 0.8, 0.0); //Green Strips
glBegin(GL_LINE_STRIP);
glVertex2i(410+ RocketX4, 455+ RocketY4);
glVertex2i(410+ RocketX4, 445+ RocketY4);
glVertex2i(413+ RocketX4, 445+ RocketY4);
glVertex2i(413+ RocketX4, 455+ RocketY4);
glVertex2i(416+ RocketX4, 455+ RocketY4);
glVertex2i(416+ RocketX4, 445+ RocketY4);
glVertex2i(419+ RocketX4, 445+ RocketY4);
glVertex2i(419+ RocketX4, 455+ RocketY4);
glEnd();
//
glColor3f(0.0, 0.0, 0.0); //Black Outlines (Bullet #4)
glBegin(GL_LINE_STRIP);
glVertex2i(430+ RocketX4, 449+ RocketY4);
glVertex2i(430+ RocketX4, 445+ RocketY4);
glVertex2i(400+ RocketX4, 445+ RocketY4);
glVertex2i(395+ RocketX4, 450+ RocketY4);
glVertex2i(400+ RocketX4, 455+ RocketY4);
glVertex2i(430+ RocketX4, 455+ RocketY4);
glVertex2i(430+ RocketX4, 451+ RocketY4);
glVertex2i(434+ RocketX4, 455+ RocketY4);
glVertex2i(434+ RocketX4, 445+ RocketY4);
glVertex2i(430+ RocketX4, 449+ RocketY4);
glEnd();
//
glColor3f(1.0, 1.0, 1.0); //White Bullets (Bullet #5)
glBegin(GL_QUADS);
glVertex2i(70+ RocketX5, 455+ RocketY5);
glVertex2i(70+ RocketX5, 445+ RocketY5);
glVertex2i(100+ RocketX5, 445+ RocketY5);
glVertex2i(100+ RocketX5, 455+ RocketY5);
glEnd();
glBegin(GL_TRIANGLES);
glVertex2i(70+ RocketX5, 455+ RocketY5);
glVertex2i(70+ RocketX5, 445+ RocketY5);
glVertex2i(65+ RocketX5, 450+ RocketY5);
//
glVertex2i(99+ RocketX5, 450+ RocketY5);
glVertex2i(104+ RocketX5, 445+ RocketY5);
glVertex2i(104+ RocketX5, 455+ RocketY5);
//
glColor3f(1.0, 0.0, 0.0);//Red Flame Base
glVertex2i(104+ RocketX5, 455+ RocketY5);
glVertex2i(104+ RocketX5, 450+ RocketY5);
glColor3f(0.7, 0.0, 0.0);//Red Flame Base
glVertex2i(114+ RocketX5, 457+ RocketY5);
//
glColor3f(1.0, 0.0, 0.0);//Red Flame Base
glVertex2i(104+ RocketX5, 445+ RocketY5);
glVertex2i(104+ RocketX5, 450+ RocketY5);
glColor3f(0.7, 0.0, 0.0);//Red Flame Base
glVertex2i(114+ RocketX5, 443+ RocketY5);
//
glColor3f(1.0, 0.0, 0.0);//Red Flame Base
glVertex2i(104+ RocketX5, 455+ RocketY5);
glVertex2i(104+ RocketX5, 445+ RocketY5);
glColor3f(0.7, 0.0, 0.0);//Red Flame Base
glVertex2i(118+ RocketX5, 450+ RocketY5);
glEnd();
//
glColor3f(0.0, 0.8, 0.0); //Green Strips
glBegin(GL_LINE_STRIP);
glVertex2i(80+ RocketX5, 455+ RocketY5);
glVertex2i(80+ RocketX5, 445+ RocketY5);
glVertex2i(83+ RocketX5, 445+ RocketY5);
glVertex2i(83+ RocketX5, 455+ RocketY5);
glVertex2i(86+ RocketX5, 455+ RocketY5);
glVertex2i(86+ RocketX5, 445+ RocketY5);
glVertex2i(89+ RocketX5, 445+ RocketY5);
glVertex2i(89+ RocketX5, 455+ RocketY5);
glVertex2i(80+ RocketX5, 445+ RocketY5);
glEnd();
//
glColor3f(0.0, 0.0, 0.0); //Black Outlines (Bullet #5)
glBegin(GL_LINE_STRIP);
glVertex2i(100+ RocketX5, 449+ RocketY5);
glVertex2i(100+ RocketX5, 445+ RocketY5);
glVertex2i(70+ RocketX5, 445+ RocketY5);
glVertex2i(65+ RocketX5, 450+ RocketY5);
glVertex2i(70+ RocketX5, 455+ RocketY5);
glVertex2i(100+ RocketX5, 455+ RocketY5);
glVertex2i(100+ RocketX5, 451+ RocketY5);
glVertex2i(104+ RocketX5, 455+ RocketY5);
glVertex2i(104+ RocketX5, 445+ RocketY5);
glVertex2i(100+ RocketX5, 449+ RocketY5);
glEnd();
//
glColor3f(1.0, 1.0, 1.0); //White Bullets (Bullet #6)
glBegin(GL_QUADS);
glVertex2i(70+ RocketX6, 255+ RocketY6);
glVertex2i(70+ RocketX6, 245+ RocketY6);
glVertex2i(100+ RocketX6, 245+ RocketY6);
glVertex2i(100+ RocketX6, 255+ RocketY6);
glEnd();
glBegin(GL_TRIANGLES);
glVertex2i(70+ RocketX6, 255+ RocketY6);
glVertex2i(70+ RocketX6, 245+ RocketY6);
glVertex2i(65+ RocketX6, 250+ RocketY6);
//
glVertex2i(99+ RocketX6, 250+ RocketY6);
glVertex2i(104+ RocketX6, 245+ RocketY6);
glVertex2i(104+ RocketX6, 255+ RocketY6);
//
glColor3f(1.0, 0.0, 0.0);//Red Flame Base
glVertex2i(104+ RocketX6, 255+ RocketY6);
glVertex2i(104+ RocketX6, 250+ RocketY6);
glColor3f(0.7, 0.0, 0.0);//Red Flame Base
glVertex2i(114+ RocketX6, 257+ RocketY6);
//
glColor3f(1.0, 0.0, 0.0);//Red Flame Base
glVertex2i(104+ RocketX6, 245+ RocketY6);
glVertex2i(104+ RocketX6, 250+ RocketY6);
glColor3f(0.7, 0.0, 0.0);//Red Flame Base
glVertex2i(114+ RocketX6, 243+ RocketY6);
//
glColor3f(1.0, 0.0, 0.0);//Red Flame Base
glVertex2i(104+ RocketX6, 255+ RocketY6);
glVertex2i(104+ RocketX6, 245+ RocketY6);
glColor3f(0.7, 0.0, 0.0);//Red Flame Base
glVertex2i(118+ RocketX6, 250+ RocketY6);
glEnd();
//
glColor3f(0.0, 0.8, 0.0); //Green Strips
glBegin(GL_LINE_STRIP);
glVertex2i(80+ RocketX6, 255+ RocketY6);
glVertex2i(80+ RocketX6, 245+ RocketY6);
glVertex2i(83+ RocketX6, 245+ RocketY6);
glVertex2i(83+ RocketX6, 255+ RocketY6);
glVertex2i(86+ RocketX6, 255+ RocketY6);
glVertex2i(86+ RocketX6, 245+ RocketY6);
glVertex2i(89+ RocketX6, 245+ RocketY6);
glVertex2i(89+ RocketX6, 255+ RocketY6);
glVertex2i(80+ RocketX6, 245+ RocketY6);
glVertex2i(94+ RocketX6, 245+ RocketY6);
glVertex2i(94+ RocketX6, 255+ RocketY6);
glEnd();
//
glColor3f(0.0, 0.0, 0.0); //Black Outlines (Bullet #6)
glBegin(GL_LINE_STRIP);
glVertex2i(100+ RocketX6, 249+ RocketY6);
glVertex2i(100+ RocketX6, 245+ RocketY6);
glVertex2i(70+ RocketX6, 245+ RocketY6);
glVertex2i(65+ RocketX6, 250+ RocketY6);
glVertex2i(70+ RocketX6, 255+ RocketY6);
glVertex2i(100+ RocketX6, 255+ RocketY6);
glVertex2i(100+ RocketX6, 251+ RocketY6);
glVertex2i(104+ RocketX6, 255+ RocketY6);
glVertex2i(104+ RocketX6, 245+ RocketY6);
glVertex2i(100+ RocketX6, 249+ RocketY6);
glEnd();
//
} /* End Draw */

void display(void)
{
 glClear(GL_COLOR_BUFFER_BIT); //this clears the scene
 if (gShowGrid){
 drawGridLines(20, 100);
}

 drawScene();
 /* this needs to be the last function call in display() */
 glutSwapBuffers(); 
     
}
 //used to draw a coordinate grid so 
 //we can see where we are
 //remember the left, bottom is 0, 0
 void drawGridLines(int small_spacing, int big_spacing)

{
 int i, j;
    
 glBegin(GL_LINES);
 glColor3f(1.0, 1.0, 0); //this should be yellow
 for(i = 0; i < WINDOW_HEIGHT; i += small_spacing){
          
 //horizontal line first
 glVertex2i(0, i);
 glVertex2i(WINDOW_HEIGHT,i);
        
 //vertical line next
 glVertex2i(i, 0);
 glVertex2i(i,WINDOW_HEIGHT);
 
}
 glColor3f(1.0, 0.0, 0); //this should be red
 for(i = 0; i < WINDOW_HEIGHT; i += big_spacing){
 //horizontal line first
 glVertex2i(0, i);
 glVertex2i(WINDOW_HEIGHT,i);
        
 //vertical line next
 glVertex2i(i, 0);
 glVertex2i(i,WINDOW_HEIGHT);
        
}
glEnd();
}
int main(int argc, char *argv[])
{
 glutInit(&argc,argv);
 glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB);
 glutInitWindowSize(WINDOW_HEIGHT, WINDOW_HEIGHT);
 glutInitWindowPosition(100,40);
 glutCreateWindow("My First Glut/OpenGL Program (Helicopter)");
 init();

 /* set up our call back functions */
 glutDisplayFunc(display);
 glutMouseFunc(myMouse);
 glutKeyboardFunc(myKeyboard);
 glutMotionFunc(myMouseMove);

 /* turn control over to glut */
 glutMainLoop();
 return 0;
 
}
void init(void)

{
 /*back ground color-set to white */
 glClearColor(1.0f ,1.0f ,1.0f ,0.0f);

 /*drawing color -set to black*/
 glColor3f(0.0f,0.0f,0.0f);

 glMatrixMode(GL_PROJECTION);
 glLoadIdentity();
 gluOrtho2D(0.0f,(GLfloat)WINDOW_HEIGHT, 0.0f, (GLfloat) WINDOW_HEIGHT);
 
}
void myMouse(int button, int state, int x, int y)

{ 
  if(button == GLUT_LEFT_BUTTON)
  
{
 if(state == GLUT_DOWN)
 
{
 glutPostRedisplay();
 gMouse_x = x;
 gMouse_y = WINDOW_HEIGHT - y; /* GLUT puts the origin at the bottom left of the window, MS Windows treats the top right as the origin */
 //glutPostRedisplay(); /* tell glut to redraw the screen */
 printf("( %d, %d )\n", gMouse_x, gMouse_y);
 
}}}

void myMouseMove(int x, int y)
{}
void myTimer1(int val)
{
 gChopperState = (gChopperState + 1) %2;
 glutPostRedisplay();
 if (g_bAnimateChopper){
    glutTimerFunc(20, myTimer1, 1);
}}
void myTimer2(int val)
{
 gWaveState = (gWaveState + 1) %4;
 glutPostRedisplay();
 if (g_bAnimateWater){
    glutTimerFunc(160, myTimer2, 1);
}}
void myTimer3(int val)
{
 gBeachState = (gBeachState + 1) %3;
 glutPostRedisplay();
 if (g_bAnimateBeach){
    glutTimerFunc(100, myTimer3, 1);
}}
void myTimer4(int val)
{
 gRocketState = (gRocketState +1) %2;
 glutPostRedisplay();
 if (g_bAnimateRocket1){
    glutTimerFunc(30, myTimer4, 1);
}}

void myKeyboard(unsigned char key, int x, int y)
{
if (key == 'g'){
   gShowGrid = !gShowGrid;
   glutPostRedisplay();
}else if (key == 'h'){
      printf("Press 'q' to see some action\n");
      printf("Use 'W, A, S, D' to move the Helicopter\n");
      printf("Press 'r' to reset Helicopter Position\n");
}else if (key == 'p'){
      printf("programmed by Denis Prokopenko \n");   
}else if (key == 'q'){
      gWaveState = (gWaveState + 1)% 4;
      gBeachState = (gBeachState + 1)% 3;
      gChopperState = (gChopperState + 1)% 2;
      gRocketState = (gRocketState +1) %2;
}else if (key == 'c'){
      g_bAnimateChopper = !g_bAnimateChopper;
      g_bAnimateWater = !g_bAnimateWater;
      g_bAnimateBeach = !g_bAnimateBeach;
      g_bAnimateRocket1 = !g_bAnimateRocket1;
      if (g_bAnimateChopper){
      glutTimerFunc(20, myTimer1, 1);
      if (g_bAnimateWater){
      glutTimerFunc(130, myTimer2, 1);
      if (g_bAnimateBeach){
      glutTimerFunc(100, myTimer3, 1);
      if (g_bAnimateRocket1){
      glutTimerFunc(30, myTimer4, 1);
}}}}}

if (key == 'w'){
   ChopperY = ChopperY+10;
}
if (key == 'w'+'d'){
   ChopperY = ChopperY+10;
   ChopperX = ChopperX+10;
}
if (key == 'a'){
   ChopperX = ChopperX-10;
}
if (key == 'w'+'a'){
   ChopperY = ChopperY+10;
   ChopperX = ChopperX-10;
}
if (key == 's'){
   ChopperY = ChopperY-10;
}
if (key == 'a'+'s'){
   ChopperY = ChopperY-10;
   ChopperX = ChopperX-10;
}
if (key == 'd'){
   ChopperX = ChopperX+10;
}
if (key == 'd'+'s'){
   ChopperY = ChopperY-10;
   ChopperX = ChopperX+10;
}
if (ChopperX >= 170){
      ChopperX = 170;
}
if (ChopperX <= -210){
      ChopperX = -210;
      }
if (ChopperY >= 300){
      ChopperY = 300;
      }
if (ChopperY <= -200){
      ChopperY = -200;
      }
if (key == 'r'){
      ChopperX = 0;
      ChopperY = 0;
      }

//printf("gWaveState = %d\n", gWaveState);
//printf("gBeachState = %d\n", gBeachState);
//printf("gChopperState = %d\n", gChopperState);
printf("ChopperX = %d\n", ChopperX);
printf("ChopperY = %d\n", ChopperY);

     glutPostRedisplay(); 
}
  int getRand(int first, int last)
{
 static int firstTime = 1;
 int amountOfNumbers;
 if (firstTime == 1){
 //first time in this function, seed the random number generator
 firstTime = 0;
 srand(time(NULL));
}
 amountOfNumbers = last - first + 1;
 return(rand() % amountOfNumbers + first);
}
 void drawCircle(int center_x, int center_y, int radius, int nSides)
{
 float x, y;
 int angle, delta;
 float theta;
 delta =  360/nSides;

 glBegin(GL_POLYGON);
 for(angle = 0; angle < 360; angle += delta)
{
 theta = angle * M_PI /180.0; //change to radians
 x = radius * cos(theta) + center_x;
 y = radius * sin(theta) + center_y;
 glVertex2f(x,y); 
}
glEnd(); 
}
 void drawLine(float x1, float y1,
 float x2, float y2)
{
 glBegin(GL_LINES);
 glVertex2f(x1, y1);
 glVertex2f(x2, y2);
 
 glEnd();
}
void drawCheckerSquares( float left,
float top, float rect_width, 
float rect_height, float kerf,
int rows, int cols)
{
 float right, y, x, bottom;
 int i;   
 //first try drawing the horizontal lines
 right = left + cols * (rect_width + kerf);
 y = top;
 for(i = 0; i <= rows; ++ i)
{
 drawLine(left, y, right, y);   
 y += rect_height + kerf;  
} 
  //next try drawing the vertical lines
  x = left;
  bottom = top + rows * (rect_height + kerf);
  for(i = 0; i <= cols; ++ i)
{
 drawLine(x, top, x, bottom);   
 x += rect_width + kerf;   
}}
