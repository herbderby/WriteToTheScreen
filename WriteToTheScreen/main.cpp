//
//  main.cpp
//  WriteToTheScreen
//
//  Created by Herb Derby on 7/31/13.
//  Copyright (c) 2013 Herb Derby. All rights reserved.
//

#include <iostream>
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <GLUT/glut.h>

void draw() {
    std::cout << "Draw" << std::endl;
    char buffer[1024*1024*4];
    
    glClear(GL_COLOR_BUFFER_BIT);
    
    for (int i = 0; i < 1024*1024*4; ++i) {
        
        buffer[i] = 0;
    }
    
    for (int i = 0; i < 1024*1024*4; ++i) {
        if (i % 4 == 2) {
            buffer[i] = 0xFF;
        }
    }
    
    glDrawPixels(1024, 1024, GL_RGBA, GL_UNSIGNED_BYTE, buffer);
    std::cout << "End Draw" << std::endl;
    
    glFinish();
}

void Keyboard(unsigned char key, int x, int y)
{
    switch (key)
    {
        case 27:             // ESCAPE key
            glutLeaveGameMode();
            exit (0);

            break;
    }
}


int main(int argc, char* argv[])
{
    std::cout << "Hello, World!\n";
    
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
   
    glutEnterGameMode();
    int width = glutGameModeGet(GLUT_GAME_MODE_WIDTH);
    int height = glutGameModeGet(GLUT_GAME_MODE_HEIGHT);
    int depth = glutGameModeGet(GLUT_GAME_MODE_PIXEL_DEPTH);
    
    glutKeyboardFunc(Keyboard);
    glutDisplayFunc(draw);
    
    glutMainLoop();
    
    glutLeaveGameMode();
    
    std::cout << "done. w: " << width << " h: " << height << " d: " << depth << std::endl;
    return 0;
}

