#include "sfWindow.hpp"

sfWindow::sfWindow(sf::Vector2f size, const std::string &title) : win(sf::VideoMode(size.x, size.y), title)
{
}

void sfWindow::draw(Sprite &)
{
}

void sfWindow::render(void)
{
}
