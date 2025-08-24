#include <raylib.h>
#include <iostream>
#include "Button.hpp"
#include "Dino.hpp"

int main()
{
    InitWindow(1200, 800, "Raylib Buttons Tutorial");

    SetTargetFPS(60);

    Texture2D background = LoadTexture("Graphics/background.png");
    Button startButton{"Graphics/start_button.png", {300, 150}, 0.65};
    Button exitButton{"Graphics/exit_button.png", {300, 300}, 0.65};
    Dino dino;
    Rectangle obstacle = Rectangle{800, 200, 200, 175};
    bool exit = false;

    while (WindowShouldClose() == false && exit == false)
    {
        // Vector2 mousePosition = GetMousePosition();
        // bool mousePressed = IsMouseButtonPressed(MOUSE_BUTTON_LEFT);

        // if (startButton.isPressed(mousePosition, mousePressed))
        // {
        //     std::cout << "Start Button Pressed" << std::endl;
        // }

        // if (exitButton.isPressed(mousePosition, mousePressed))
        // {
        //     exit = true;
        // }
        dino.Update();
        bool isColliding = CheckCollisionRecs(dino.GetRect(), obstacle);
        BeginDrawing();
        ClearBackground(WHITE);
        // DrawTexture(background, 0, 0, WHITE);
        //  startButton.Draw();
        //  exitButton.Draw();
        DrawRectangleLinesEx(obstacle, 5, BLACK);
        dino.Draw();
        dino.DrawHitbox(isColliding);
        EndDrawing();
    }
}