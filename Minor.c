#include<stdio.h>
#include<GLUT/glut.h>

void Interface1() {

	//Interface 1 Design Display.
	// Om PAndey push your function here.*(Only the display function).


}

void display() {
	Interface1();


}



void reshaping(int w, int h) {
	glViewport(0, 0, w, h);
	gluOrtho2D(0, 1080, 0, 720);

}



void init() {
	glClearColor(0.0, 0.0, 0.0, 1.0);
}




int main(int argc, char** argv) {
	glutInit(&argc, argv);

	glutInitWindowPosition(0, 0);
	glutInitWindowSize(1080, 720);

	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
	glutCreateWindow("Box'em Up");

	glutDisplayFunc(display);
	glutReshapeFunc(reshaping);

	init();
	glutMainLoop();
}