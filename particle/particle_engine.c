#include "particle_engine.h"
#include <math.h>
#include <stdlib.h>
#include <time.h>

#define ELASTICITY 0.98f
#define MAX_VELOCITY 5.0f

void initParticle(Particle* p) {
    p->x = (float)(rand() % WINDOW_WIDTH);
    p->y = (float)(rand() % WINDOW_HEIGHT);

    p->vx = (float)((rand() % (2 * (int)MAX_VELOCITY)) - MAX_VELOCITY) / 2.0f;
    p->vy = (float)((rand() % (2 * (int)MAX_VELOCITY)) - MAX_VELOCITY) / 2.0f;

    p->ax = 0.0f;
    p->ay = 0.1f;  // Slight gravity

    p->mass = 1.0f + ((float)rand() / RAND_MAX);

    p->color.r = rand() % 256;
    p->color.g = rand() % 256;
    p->color.b = rand() % 256;
    p->color.a = 255;
}

void updateParticle(Particle* p, Particle* particles, int numParticles, int currentIndex) {
    // Update velocity with acceleration
    p->vx += p->ax;
    p->vy += p->ay;

    // Update position
    p->x += p->vx;
    p->y += p->vy;

    // Wall collisions
    if (p->x <= PARTICLE_RADIUS) {
        p->x = (float)PARTICLE_RADIUS;
        p->vx = -p->vx * ELASTICITY;
    }
    if (p->x >= WINDOW_WIDTH - PARTICLE_RADIUS) {
        p->x = (float)(WINDOW_WIDTH - PARTICLE_RADIUS);
        p->vx = -p->vx * ELASTICITY;
    }
    if (p->y <= PARTICLE_RADIUS) {
        p->y = (float)PARTICLE_RADIUS;
        p->vy = -p->vy * ELASTICITY;
    }
    if (p->y >= WINDOW_HEIGHT - PARTICLE_RADIUS) {
        p->y = (float)(WINDOW_HEIGHT - PARTICLE_RADIUS);
        p->vy = -p->vy * ELASTICITY;
    }

    // Particle-particle collisions
    for (int i = 0; i < numParticles; i++) {
        if (i == currentIndex) continue;

        float dx = particles[i].x - p->x;
        float dy = particles[i].y - p->y;
        float distance = sqrtf(dx * dx + dy * dy);

        if (distance < 2 * PARTICLE_RADIUS) {
            float angle = atan2f(dy, dx);
            float sin_angle = sinf(angle);
            float cos_angle = cosf(angle);

            float vx1 = p->vx * cos_angle + p->vy * sin_angle;
            float vy1 = -p->vx * sin_angle + p->vy * cos_angle;
            float vx2 = particles[i].vx * cos_angle + particles[i].vy * sin_angle;
            float vy2 = -particles[i].vx * sin_angle + particles[i].vy * cos_angle;

            float p1_mass = p->mass;
            float p2_mass = particles[i].mass;
            float new_vx1 = ((p1_mass - p2_mass) * vx1 + 2 * p2_mass * vx2) / (p1_mass + p2_mass);
            float new_vx2 = ((p2_mass - p1_mass) * vx2 + 2 * p1_mass * vx1) / (p1_mass + p2_mass);

            p->vx = (new_vx1 * cos_angle - vy1 * sin_angle) * ELASTICITY;
            p->vy = (new_vx1 * sin_angle + vy1 * cos_angle) * ELASTICITY;
            particles[i].vx = (new_vx2 * cos_angle - vy2 * sin_angle) * ELASTICITY;
            particles[i].vy = (new_vx2 * sin_angle + vy2 * cos_angle) * ELASTICITY;

            float overlap = 2 * PARTICLE_RADIUS - distance;
            p->x -= overlap * cos_angle / 2;
            p->y -= overlap * sin_angle / 2;
            particles[i].x += overlap * cos_angle / 2;
            particles[i].y += overlap * sin_angle / 2;
        }
    }
}

bool initializeSDL(SDL_Window** window, SDL_Renderer** renderer) {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        return false;
    }

    *window = SDL_CreateWindow("Particle Simulation",
        SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
        WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);

    if (!*window) {
        return false;
    }

    *renderer = SDL_CreateRenderer(*window, -1,
        SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

    if (!*renderer) {
        SDL_DestroyWindow(*window);
        return false;
    }

    return true;
}

void cleanup(SDL_Window* window, SDL_Renderer* renderer) {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}