#include "raylib.h"
#include <stdlib.h>
#include <math.h>

#define MAX_PARTICLES 1000
#define PARTICLE_RADIUS 4.0f

typedef struct {
    Vector2 position;
    Vector2 velocity;
    Color color;
    float radius;
    bool active;
} Particle;

int main(void) {
    // Initialize window
    const int screenWidth = 800;
    const int screenHeight = 600;
    InitWindow(screenWidth, screenHeight, "Particle System");
    SetTargetFPS(60);

    // Initialize particles
    Particle particles[MAX_PARTICLES] = { 0 };
    for (int i = 0; i < MAX_PARTICLES; i++) {
        particles[i].active = false;
    }

    while (!WindowShouldClose()) {
        // Update particles
        if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {
            // Create new particles at mouse position
            Vector2 mousePos = GetMousePosition();
            for (int i = 0; i < MAX_PARTICLES; i++) {
                if (!particles[i].active) {
                    particles[i].position = mousePos;
                    particles[i].velocity.x = (float)(rand() % 800 - 400) / 100.0f;
                    particles[i].velocity.y = (float)(rand() % 800 - 400) / 100.0f;
                    particles[i].radius = PARTICLE_RADIUS;
                    particles[i].color = (Color){
                        rand() % 200 + 55,
                        rand() % 200 + 55,
                        rand() % 200 + 55,
                        255
                    };
                    particles[i].active = true;
                    break;
                }
            }
        }

        // Update active particles
        for (int i = 0; i < MAX_PARTICLES; i++) {
            if (particles[i].active) {
                // Apply gravity
                particles[i].velocity.y += 0.3f;

                // Update position
                particles[i].position.x += particles[i].velocity.x;
                particles[i].position.y += particles[i].velocity.y;

                // Bounce off walls
                if (particles[i].position.x < 0) {
                    particles[i].position.x = 0;
                    particles[i].velocity.x *= -0.8f;
                }
                if (particles[i].position.x > screenWidth) {
                    particles[i].position.x = screenWidth;
                    particles[i].velocity.x *= -0.8f;
                }
                if (particles[i].position.y < 0) {
                    particles[i].position.y = 0;
                    particles[i].velocity.y *= -0.8f;
                }
                if (particles[i].position.y > screenHeight) {
                    particles[i].position.y = screenHeight;
                    particles[i].velocity.y *= -0.8f;
                }

                // Handle particle collisions
                for (int j = i + 1; j < MAX_PARTICLES; j++) {
                    if (particles[j].active) {
                        float dx = particles[j].position.x - particles[i].position.x;
                        float dy = particles[j].position.y - particles[i].position.y;
                        float distance = sqrtf(dx * dx + dy * dy);

                        if (distance < particles[i].radius + particles[j].radius) {
                            // Simple collision response
                            float angle = atan2f(dy, dx);
                            float sin_a = sinf(angle);
                            float cos_a = cosf(angle);

                            // Elastic collision
                            Vector2 vel1 = particles[i].velocity;
                            Vector2 vel2 = particles[j].velocity;

                            particles[i].velocity.x = vel2.x * cos_a * 0.8f;
                            particles[i].velocity.y = vel2.y * sin_a * 0.8f;
                            particles[j].velocity.x = vel1.x * cos_a * 0.8f;
                            particles[j].velocity.y = vel1.y * sin_a * 0.8f;

                            // Separate particles
                            float overlap = particles[i].radius + particles[j].radius - distance;
                            float moveX = (overlap * cos_a) / 2;
                            float moveY = (overlap * sin_a) / 2;

                            particles[i].position.x -= moveX;
                            particles[i].position.y -= moveY;
                            particles[j].position.x += moveX;
                            particles[j].position.y += moveY;
                        }
                    }
                }
            }
        }

        // Draw
        BeginDrawing();
        ClearBackground(BLACK);

        // Draw particles
        for (int i = 0; i < MAX_PARTICLES; i++) {
            if (particles[i].active) {
                DrawCircleV(particles[i].position, particles[i].radius, particles[i].color);
            }
        }

        DrawFPS(10, 10);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}