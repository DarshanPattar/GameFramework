#include "Game.h"
#include <iostream>
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
	//std::cout << dt <<" ";
}

//Function to render the frame
void Game::Draw()
{
	gfx.DrawRect((int)x-1, (int)y-1, 800+1, 800+1, false, Color(255, 255, 255));

}
