









void mouse(int button, int state, int x, int y)
{
    //either left or right click
    switch(button)
    {    
        case GLUT_LEFT_BUTTON:
        {
        //storing coordinates for left click
        Input[0] = x;
        Input[1] = 720-y;
        }

    

        case GLUT_RIGHT_BUTTON :
        {
         //storing coordinates for right click
        glClearColor(1.0, 1.0, 1.0, 0.0);
        glClear(GL_COLOR_BUFFER_BIT);
        check = false;
        
        }
    glutPostRedisplay();
   }
}


    