#include "App.hpp"
#include "MenuState.hpp"

int custom_main()
{
	App client;
	client.setState(new MenuState(client));
	client.run();
	return 0;
}

