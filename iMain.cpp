# include "iGraphics.h"

int x = 80, y = 70, r = 20;
/*
	function iDraw() is called again and again by the system.

	*/

void iDraw() {
	//place your drawing codes here
	iClear();
	iSetColor(20, 200, 200);
	iFilledCircle(x, y, r);
	//iFilledRectangle(10, 30, 20, 20);
	iSetColor(123, 248, 255);
	iText(42, 25, "This is iGraphics");
	iEllipse(1, 2, 10, 5, 100);
}

/*
	function iMouseMove() is called when the user presses and drags the mouse.
	(mx, my) is the position where the mouse pointer is.
	*/
void iMouseMove(int mx, int my) {
	x=mx;
	y=my;
	//place your codes here
}

/*
	function iMouse() is called when the user presses/releases the mouse.
	(mx, my) is the position where the mouse pointer is.
	*/
void iMouse(int button, int state, int mx, int my) {
	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		x=mx;
		y=my;
		printf("x = %d, y= %d\n", mx, my);
	}
}

/*
	function iKeyboard() is called whenever the user hits a key in keyboard.
	key- holds the ASCII value of the key pressed.
	*/
void iKeyboard(unsigned char key) {
	if (key == 'q') {
		exit(0);
	}
	//place your codes for other keys here
}

/*
	function iSpecialKeyboard() is called whenver user hits special keys like-
	function keys, home, end, pg up, pg down, arraows etc. you have to use
	appropriate constants to detect them. A list is:
	GLUT_KEY_F1, GLUT_KEY_F2, GLUT_KEY_F3, GLUT_KEY_F4, GLUT_KEY_F5, GLUT_KEY_F6,
	GLUT_KEY_F7, GLUT_KEY_F8, GLUT_KEY_F9, GLUT_KEY_F10, GLUT_KEY_F11, GLUT_KEY_F12,
	GLUT_KEY_LEFT, GLUT_KEY_UP, GLUT_KEY_RIGHT, GLUT_KEY_DOWN, GLUT_KEY_PAGE UP,
	GLUT_KEY_PAGE DOWN, GLUT_KEY_HOME, GLUT_KEY_END, GLUT_KEY_INSERT
	*/
void iSpecialKeyboard(unsigned char key) {

	if (key == GLUT_KEY_END) {
		exit(0);
	}
	//place your codes for other keys here
}


// int main() {
// 	//place your own initialization codes here.
// 	iInitialize(400, 300, "Graph Plotter");
// 	return 0;
// }
