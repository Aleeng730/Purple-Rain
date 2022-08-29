/*******************************************************************************************
*
*   raylib [core] example - Basic window
*
*   Welcome to raylib!
*
*   To test examples, just press F6 and execute raylib_compile_execute script
*   Note that compiled executable is placed in the same folder as .c file
*
*   You can find all basic examples on C:\raylib\raylib\examples folder or
*   raylib official webpage: www.raylib.com
*
*   Enjoy using raylib. :)
*
*   Example originally created with raylib 1.0, last time updated with raylib 1.0

*   Example licensed under an unmodified zlib/libpng license, which is an OSI-certified,
*   BSD-like license that allows static linking with closed source software
*
*   Copyright (c) 2013-2022 Ramon Santamaria (@raysan5)
*
********************************************************************************************/

#include "raylib.h"

//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------
int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 640;
    const int screenHeight = 360;

    InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------
        class Drop {
        
            public:
            float x = GetRandomValue(0, screenWidth);
            float y = GetRandomValue(-500, -100);
            float yspeed = GetRandomValue(4, 10);
            float len = GetRandomValue(10, 20);
            
        
            void fall() {
                
                y = y + yspeed;
                
                if (y > screenHeight) {
                    
                    y = GetRandomValue(-200, -100);
                    
                }
            }
        
            void show() {
                
                DrawRectangle(x, y + len, 2, 10, DARKPURPLE);
                
                if (len <= 15 || yspeed <= 5) {
                    
                    DrawRectangle(x, y + len, 2.5, 15, VIOLET);
                    
                }
                else if (len >= 15 || yspeed >= 5) {
                    
                    DrawRectangle(x, y + len, 3, 17, PURPLE);
                    
                }

            }
        
        };
        Drop drops[500];
    
    
    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {

        for (int i = 0; i < 500; i++){
            
            drops[i].fall();
        }


        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

            ClearBackground(BLACK);
         for (int i = 0; i < 500; i++){
            
            drops[i].show();  
            
        }   

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}
