#include <stdbool.h>

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600
#define NUM_PARTICLES 100
#define PARTICLE_RADIUS 5

typedef struct {
    float x, y;
    float vx, vy;
    float ax, ay;
    float mass;
    SDL_Color color;
} Particle;

// Function declarations
void initParticle(Particle* p);
void updateParticle(Particle* p, Particle* particles, int numParticles, int currentIndex);
bool initializeSDL(SDL_Window** window, SDL_Renderer** renderer);
void cleanup(SDL_Window* window, SDL_Renderer* renderer);