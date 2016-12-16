#include "App.hpp"
#include "MenuState.hpp"
#include "EmptyState.hpp"

int custom_main()
{
	App client;
	client.setState(new EmptyState(client));
	client.setState(new MenuState(client));
	client.run();
	return 0;
}

