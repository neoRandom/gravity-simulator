#include "raylib.h"
#include "body.h"
#include <vector>
#include <string>

double lastFrameTime = GetTime(); // Time step for simulation

void drawTexts(std::vector<std::string> textList, Vector2 initialPosition)
{
    float yPos = initialPosition.y;

    for (auto text : textList)
    {
        DrawText(text.c_str(), initialPosition.x, yPos, 20, GREEN);
        yPos += 20;
    }
}

int main()
{
    const int screenWidth = 1080;
    const int screenHeight = 720;

    SetConfigFlags(FLAG_VSYNC_HINT | FLAG_MSAA_4X_HINT | FLAG_WINDOW_HIGHDPI);
    InitWindow(screenWidth, screenHeight, "2D Gravity Simulator");
    // SetTargetFPS(60);

    std::vector<Body> bodies = {
        {{540, 360}, {0, 0}, 100, RED},    // Central massive body
        {{1000, 360}, {0, 100}, 10, BLUE},  // Orbiting body
    };

    while (!WindowShouldClose())
    {
        double currentTime = GetTime();
        double deltaTime = currentTime - lastFrameTime;
        lastFrameTime = currentTime;

        // --------------------------------------------------------------------

        if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT))
            bodies.emplace_back(Body{GetMousePosition(), Vector2{0, 0}, 10, RAYWHITE});

        // --------------------------------------------------------------------

        for (auto &body : bodies)
        {
            body.update(bodies, deltaTime);
        }

        // --------------------------------------------------------------------

        BeginDrawing();

        ClearBackground(BLACK);
        for (const auto &body : bodies)
        {
            body.draw();
        }

        drawTexts(
            std::vector {
                std::string("FPS: ") + std::to_string(GetFPS()),
                std::string("G Val.: ") + std::to_string(G),
                std::string("Num. Body: ") + std::to_string(bodies.size()),
                std::string("Time: ") + std::to_string((int) GetTime()) + std::string("s")
            },
            Vector2 {10, 10}
        );

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
