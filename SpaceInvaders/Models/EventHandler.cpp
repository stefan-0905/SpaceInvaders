#include "EventHandler.h"

EventHandler::EventHandler(Game* mGame, sf::RenderWindow* window)
	: m_Game(mGame), m_Window(window)
{
}

void EventHandler::Handle(sf::Event ev)
{
    switch (ev.type)
    {
    case sf::Event::Closed:
        m_Window->close();
        break;
    case sf::Event::KeyPressed:
        if (ev.key.code == sf::Keyboard::Enter)
        {
            m_Game->HandleStates(ev, *m_Window);
        }
        break;
    case sf::Event::MouseButtonPressed:
        if (ev.key.code == sf::Mouse::Left)
        {
            m_Game->Playing.m_PlayerController.Fire();
        }
        break;
    default:
        break;
    }
}
