// main.cpp
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

void readfile(std::string filename) {
	std::cout << "In main.cpp => readFile\n";
	std::ifstream inputFile;
	inputFile.open(filename);
	if(inputFile.is_open()) {
		std::cout << "File opened!\n";
		std::string line;
			
		while(std::getline(inputFile, line)) {
			std::cout << line << std::endl;

		}
	}
	inputFile.close();
	std::cout << "File closed!\n";
}


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

	readfile("../story.txt");
	// Starting the game loop
	//gameApp.loop();

	return 0;
}

