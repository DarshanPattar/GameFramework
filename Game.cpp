#include "Game.h"

// runs when game object is created
Game::Game()
{
}

//Called Initially before the game loop starts.
//Can be used for initializing variables and game attributes
void Game::Start()
{
}

//Called every frame inside the game loop, and dt is the deltatime.
//multiply dt to speed to standardize the speed
// update to update and modify the member variables
void Game::Update(double dt)
{
	
}

//Function to render the frame
void Game::Draw()
{
	gfx.DrawRect((int)x, (int)y, 200, 200, false, Color(255, 255, 255));
}
