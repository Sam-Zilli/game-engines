// main.cpp
#include <iostream>
typedef void(*void_void)(void);

void input() {
	std::cout << "Input" << std::endl;	
}

void update() {
	std::cout << "Update" << std::endl;
}

void render() {
	std::cout << "Render" << std::endl;
}

struct Application {
	// Constructor
	Application() {}

	// Destructor
	~Application() {}

	void loop() {
		while(true) {
			pfn_input();
			pfn_update();
			pfn_render();
		}	
	}

	void SetInputFunction(void_void func) {
		pfn_input = func;
	}

	
	void SetUpdateFunction(void_void func) {
		pfn_update = func;
	}


	void SetRenderFunction(void_void func) {
		pfn_render = func;
	}

	void_void pfn_input;
	void_void pfn_update;
	void_void pfn_render;
};


int main() {
	// Creating instance of application
	Application gameApp;

	// giving it the created functinos	
	gameApp.SetInputFunction(&input);
	gameApp.SetUpdateFunction(&update);
	gameApp.SetRenderFunction(&render);

	// Starting the game loop
	gameApp.loop();

	return 0;
}

