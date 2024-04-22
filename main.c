#include <GL/glut.h>

float angle = 0.0; // Rotation angle

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    glPushMatrix(); // Save the current matrix

    glTranslatef(250, 250, 0); // Translate to the center of the window
    glRotatef(angle, 0, 0, 1); // Rotate around the z-axis
    glTranslatef(-250, -250, 0); // Translate back to the original position

    // Draw a square
    glBegin(GL_QUADS);
    glColor3f(1.0, 0.0, 0.0); // Red
    glVertex2f(200, 200);
    glColor3f(0.0, 1.0, 0.0); // Green
    glVertex2f(300, 200);
    glColor3f(0.0, 0.0, 1.0); // Blue
    glVertex2f(300, 300);
    glColor3f(1.0, 1.0, 0.0); // Yellow
    glVertex2f(200, 300);
    glEnd();

    glPopMatrix(); // Restore the previous matrix

    glutSwapBuffers(); // Swap the front and back buffers to display the rendered image
}

void update(int value) {
    angle += 1.0; // Update the rotation angle
    if (angle > 360.0) {
        angle -= 360.0; // Reset angle after a full rotation
    }
    glutPostRedisplay();
    glutTimerFunc(16, update, 0); // Schedule the next update
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutCreateWindow("Colorful Rotating Square");
    glutInitWindowSize(500, 500);
    gluOrtho2D(0, 500, 0, 500);
    glutDisplayFunc(display);
    glutTimerFunc(25, update, 0); // Start the rotation animation
    glutMainLoop();

    return 0;
}