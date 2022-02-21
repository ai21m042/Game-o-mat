#include <GameOMat.h>

class Sandbox : public GameOMat::Application {
public:
	Sandbox() {
	
	}
	
	~Sandbox() {
	
	}
};

GameOMat::Application* GameOMat::CreateApplication() {

	return new Sandbox();
}
