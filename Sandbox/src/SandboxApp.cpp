#include <GameOMat.h>

// the games version of the application, which atm does nothing special
class Sandbox : public GameOMat::Application {
public:
	Sandbox() {
	
	}
	
	~Sandbox() {
	
	}
};

// the game has just to create an application, the whole lifecircle is done already by the engine (wip)
GameOMat::Application* GameOMat::CreateApplication() {
	return new Sandbox();
}
