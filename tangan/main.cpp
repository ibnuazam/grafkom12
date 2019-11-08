#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <GL/freeglut.h> // Include the GLUT header file

static GLint anum = 0 ;
static GLfloat angles[5] = {30, 50, 80, 25, 90 } ;
static GLfloat final = 0 ;
static int direction = 1;

static float step = 0.05 ;

static GLfloat Ltheta1 = 0;
static float Ltheta2 = 0;
static float Ltheta3 = 0;

static float Rtheta1 = 0;
static float Rtheta2 = 0;
static float Rtheta3 = 0;

static float Mtheta1 = 0;
static float Mtheta2 = 0;
static float Mtheta3 = 0;

static float Itheta1 = 0;
static float Itheta2 = 0;
static float Itheta3 = 0;

void drawmodel (void) {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Clear the background of our &lt;a title="window" href="http://www.swiftless.com/tutorials/opengl/window.html"&gt;window&lt;/a&gt; to red
glClear(GL_COLOR_BUFFER_BIT); //Clear the colour buffer (more buffers later on)
glMatrixMode(GL_MODELVIEW);
glLoadIdentity(); // Load the Identity Matrix to reset our drawing locations

glTranslatef(0.0f, -5.0f, -10.0f); }
// glutWireCube(2.0f); // Render the primitive
//glRotatef(30, 0.0, 1.0, 0.0 );
//glScalef(2.0, 1.0, 1.0);
/********************************* Palm Region as a cuboid *************************************/
// Front face of the cube
glColor3f(1.0, 0.0, 0.0);
glBegin(GL_QUADS); // It will take the vertices in order
glVertex3f(-3.0f, 3.0f, 1.0f);
glVertex3f(2.5f, 3.0f, 1.0f);
glVertex3f(2.5f, -2.5f, 1.0f);
glVertex3f(-3.0f, -2.5f, 1.0f);
glEnd();

// Back face of the cube
glEnable(GL_CULL_FACE);
glColor3f(0.0, 1.0, 0.0);
glBegin(GL_QUADS); // It will take the vertices in order
glVertex3f(-3.0f, 3.0f, -1.0f);
glVertex3f(2.5f, 3.0f, -1.0f);
glVertex3f(2.5f, -2.5f, -1.0f);
glVertex3f(-3.0f, -2.5f, -1.0f);
glEnd();
glDisable(GL_CULL_FACE);

// Top face of the cube
glColor3f(0.0, 0.0, 1.0);
glBegin(GL_QUADS); // It will take the vertices in order
glVertex3f(-3.0f, 3.0f, 1.0f);
glVertex3f(2.5f, 3.0f, 1.0f);
glVertex3f(2.5f, 3.0f, -1.0f);
glVertex3f(-3.0f, 3.0f, -1.0f);
glEnd();

// Bottom face of the cube
glEnable(GL_CULL_FACE);
glColor3f(1.0, 1.0, 0.0);
glBegin(GL_QUADS); // It will take the vertices in order
glVertex3f(2.5f, -2.5f, 1.0f);
glVertex3f(-3.0f, -2.5f, 1.0f);
glVertex3f(-3.0f, -2.5f, -1.0f);
glVertex3f(2.5f, -2.5f, -1.0f);
glEnd();
glDisable(GL_CULL_FACE);

// Left side face of the cube
//glEnable(GL_CULL_FACE);
glColor3f(1.0, 1.0, 0.0);
glBegin(GL_QUADS); // It will take the vertices in order
glVertex3f(-3.0f, -2.5f, 1.0f);
glVertex3f(-3.0f, -2.5f, -1.0f);
glVertex3f(-3.0f, 3.0f, -1.0f);
glVertex3f(-3.0f, 3.0f, 1.0f);
glEnd();
//glDisable(GL_CULL_FACE);

// Right side face of the cube
glEnable(GL_CULL_FACE);
glColor3f(1.0, 1.0, 0.0);
glBegin(GL_QUADS); // It will take the vertices in order
glVertex3f(2.5f, 3.0f, 1.0f);
glVertex3f(2.5f, -2.5f, 1.0f);
glVertex3f(2.5f, -2.5f, -1.0f);
glVertex3f(2.5f, 3.0f, -1.0f);
glEnd();
glDisable(GL_CULL_FACE);
/******************************** Palm is completed *************************/

/*********************** We are trying to model fingers as cylinders ****************************/

// Little Finger ----------------------------
// P-M cylinder
glColor3f(0.3, 0.5, 0.7);
glPushMatrix();
GLUquadricObj *lpm = gluNewQuadric();
glTranslatef(-2.5, 3, 0);
glRotatef(-(90-Ltheta1), 1, 0, 0);
//glRotatef(-10, 0, 1, 0);
gluCylinder(lpm, 0.5, 0.4, 1.0, 10, 10);
gluDeleteQuadric(lpm);
glPopMatrix();
// D-P cylinder
    glColor3f(0.7, 0.5, 0.3);
	glPushMatrix();
	GLUquadricObj *ldp = gluNewQuadric();
	glTranslatef(-2.5, (3+cos((float)(Ltheta1)*22/(7*180))), sin((float)(Ltheta1)*22/(7*180)));
	glRotatef( -(90-Ltheta1-Ltheta2), 1, 0, 0);
	//glRotatef(-10, 0, 1, 0);
	gluCylinder(ldp, 0.4, 0.3, 1.0, 10, 10);
	gluDeleteQuadric(ldp);
	glPopMatrix();

	// T-D cylinder
    glColor3f(0.7, 0.7, 0.7);
	glPushMatrix();
	GLUquadricObj *ltd = gluNewQuadric();
	glTranslatef(-2.5, (3+cos((float)(Ltheta1)*22/(7*180))+cos((float)(Ltheta1+Ltheta2)*22/(7*180))), (sin((float)(Ltheta1)*22/(7*180))+sin((float)(Ltheta1+Ltheta2)*22/(7*180))));
	glRotatef( -(90-Ltheta1-Ltheta2-Ltheta3), 1, 0, 0);
//	glRotatef(-10, 0, 1, 0);
	gluCylinder(ltd, 0.3, 0.2, 1.0, 10, 10);
	gluDeleteQuadric(ltd);
	glPopMatrix();
	//-------------------------------------------------------------

//Ring Finger ----------------------------
// P-M cylinder
glColor3f(0.3, 0.5, 0.7);
glPushMatrix();
GLUquadricObj *rpm = gluNewQuadric();
glTranslatef(-1, 3, 0);
glRotatef(-(90-Rtheta1), 1, 0, 0);
gluCylinder(rpm, 0.5, 0.4, 1.5, 10, 10);
gluDeleteQuadric(rpm);
glPopMatrix();
// D-P cylinder
    glColor3f(0.7, 0.5, 0.3);
	glPushMatrix();
	GLUquadricObj *rdp = gluNewQuadric();
	glTranslatef(-1, (3 + 1.5*cos((float)Rtheta1*22/(7*180))) , 1.5*sin((float)Rtheta1*22/(7*180)));
	glRotatef(-(90-Rtheta1-Rtheta2), 1, 0, 0);
	gluCylinder(rdp, 0.4, 0.3, 1.5, 10, 10);
	gluDeleteQuadric(rdp);
	glPopMatrix();

	// T-D cylinder
    glColor3f(0.7, 0.7, 0.7);
	glPushMatrix();
	GLUquadricObj *rtd = gluNewQuadric();
	glTranslatef(-1, (3 + 1.5*cos((float)Rtheta1*22/(7*180)) + 1.5*cos((float)(Rtheta1+Rtheta2)*22/(7*180))), (1.5*sin((float)Rtheta1*22/(7*180)) + 1.5*sin((float)(Rtheta1+Rtheta2)*22/(7*180)) ));
	glRotatef(-(90-Rtheta1-Rtheta2-Rtheta3), 1, 0, 0);
	gluCylinder(rtd, 0.3, 0.2, 1.5, 10, 10);
	gluDeleteQuadric(rtd);
	glPopMatrix();
	//-------------------------------------------------------------

//Middle Finger ----------------------------
// P-M cylinder
glColor3f(0.3, 0.5, 0.7);
glPushMatrix();
GLUquadricObj *mpm = gluNewQuadric();
glTranslatef(0.5, 3, 0);
glRotatef(-(90-Mtheta1), 1, 0, 0);
gluCylinder(mpm, 0.5, 0.4, 1.75, 10, 10);
gluDeleteQuadric(mpm);
glPopMatrix();
// D-P cylinder
    glColor3f(0.7, 0.5, 0.3);
	glPushMatrix();
	GLUquadricObj *mdp = gluNewQuadric();
	glTranslatef(0.5, (3 + 1.75*cos((float)Mtheta1*22/(7*180))) , 1.75*sin((float)Mtheta1*22/(7*180)));
	glRotatef(-(90-Mtheta1-Mtheta2), 1, 0, 0);
	gluCylinder(mdp, 0.4, 0.3, 1.75, 10, 10);
	gluDeleteQuadric(mdp);
	glPopMatrix();

	// T-D cylinder
    glColor3f(0.7, 0.7, 0.7);
	glPushMatrix();
	GLUquadricObj *mtd = gluNewQuadric();
	glTranslatef(0.5,(3 + 1.75*cos((float)Mtheta1*22/(7*180)) + 1.75*cos((float)(Mtheta1+Mtheta2)*22/(7*180))), (1.75*sin((float)Rtheta1*22/(7*180)) + 1.75*sin((float)(Mtheta1+Mtheta2)*22/(7*180)) ));
	glRotatef(-(90-Mtheta1-Mtheta2-Mtheta3), 1, 0, 0);
	gluCylinder(mtd, 0.3, 0.2, 1.75, 10, 10);
	gluDeleteQuadric(mtd);
	glPopMatrix();

/*	glColor3f(1, 1, 1);
	glPushMatrix();
	GLUquadricObj *mtdisk = gluNewQuadric();
	gluDisk( mtdisk, 0, 1, 20, 20 );
	gluDeleteQuadric(mtdisk);
	glPopMatrix();   */
	//-------------------------------------------------------------

//Index Finger ----------------------------
// P-M cylinder
glColor3f(0.3, 0.5, 0.7);
glPushMatrix();
GLUquadricObj *ipm = gluNewQuadric();
glTranslatef(2, 3, 0);
glRotatef(-(90-Itheta1), 1, 0, 0);
gluCylinder(ipm, 0.5, 0.4, 1.35, 10, 10);
gluDeleteQuadric(ipm);
glPopMatrix();
// D-P cylinder
    glColor3f(0.7, 0.5, 0.3);
	glPushMatrix();
	GLUquadricObj *idp = gluNewQuadric();
	glTranslatef(2, (3 + 1.35*cos((float)Itheta1*22/(7*180))) , 1.35*sin((float)Itheta1*22/(7*180)));
	glRotatef(-(90-Itheta1-Itheta2), 1, 0, 0);
	gluCylinder(idp, 0.4, 0.3, 1.35, 10, 10);
	gluDeleteQuadric(idp);
	glPopMatrix();

	// T-D cylinder
    glColor3f(0.7, 0.7, 0.7);
	glPushMatrix();
	GLUquadricObj *itd = gluNewQuadric();
	glTranslatef(2, (3 + 1.35*cos((float)Itheta1*22/(7*180)) + 1.35*cos((float)(Itheta1+Itheta2)*22/(7*180))), (1.35*sin((float)Itheta1*22/(7*180)) + 1.35*sin((float)(Itheta1+Itheta2)*22/(7*180)) ));
	glRotatef(-(90-Itheta1-Itheta2-Itheta3), 1, 0, 0);
	gluCylinder(itd, 0.3, 0.2, 1.35, 10, 10);
	gluDeleteQuadric(itd);
	glPopMatrix();
	//-------------------------------------------------------------

// Thumb Finger
glColor3f(0.3, 0.5, 0.7);
glPushMatrix();
GLUquadricObj *tpm = gluNewQuadric();
glTranslatef(2.5, -1, 0);
glRotatef(90, 0, 1, 0);
gluCylinder(tpm, 0.5, 0.4, 1.25, 10, 10);
gluDeleteQuadric(tpm);
glPopMatrix();
glColor3f(0.7f, 0.5f, 0.3f);
	glPushMatrix();
	GLUquadricObj *tdp = gluNewQuadric();
	glTranslatef(3.75, -1, 0);
	glRotatef(-45, 0, 0, 1);
	glRotatef(-90, 1, 0, 0);
	gluCylinder(tdp, 0.4, 0.3, 1.0, 10, 10);
	gluDeleteQuadric(tdp);
	glPopMatrix();

glFlush(); // Flush the OpenGL buffers to the window
glutSwapBuffers();

}

void reshape (int width, int height) {
glViewport(0, 0, (GLsizei)width, (GLsizei)height); // Set our viewport to the size of our window
glMatrixMode(GL_PROJECTION); // Switch to the projection matrix so that we can manipulate how our scene is viewed
glLoadIdentity(); // Reset the projection matrix to the identity matrix so that we don't get any artifacts (cleaning up)

//gluPerspective(100, (GLfloat)width/(GLsizei)height, 1.0, 100.0); // Set the Field of view angle (in degrees), the aspect ratio of our window, and the new and far planes
glOrtho(-(width/50.0), (width/50.0), -(height/50.0), (height/50.0), 1, 100);
glMatrixMode(GL_MODELVIEW); // Switch back to the model view matrix, so that we can start drawing shapes correctly


}

void update (void)
{
		if ((Ltheta1 &lt; final) && (direction == 1))
			Ltheta1 += step ;
		else
			if (Ltheta1 &gt; final)
				Ltheta1 -= step ;

		if ((Ltheta1 == final)&& (anum &lt; 5))
		{
			final = angles[anum] ;
			anum++ ;
			if (final &lt; Ltheta1)
				direction = -1;
			else direction = 1;
		}

	glutPostRedisplay();
} // update

int main (int argc, char **argv) {
glutInit(&argc, argv); // Initialize GLUT
glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH); // Set up a basic display buffer (only single buffered for now)
//glutSetOption(GLUT_ACTION_ON_WINDOW_CLOSE,GLUT_ACTION_CONTINUE_EXECUTION);
glutInitWindowSize (500, 500); // Set the width and height of the window
glutInitWindowPosition (100, 100); // Set the position of the window
glutCreateWindow ("Hand Model"); // Set the title for the window

// Call backs
glutDisplayFunc(drawmodel); // Tell GLUT to use the method "display" for rendering
glutReshapeFunc(reshape); // Tell GLUT to use the method "reshape" for reshaping
glutIdleFunc(update) ;
glutMainLoop(); // Enter GLUT's main loop

}
