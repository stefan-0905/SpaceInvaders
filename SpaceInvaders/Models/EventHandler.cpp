#include "EventHandler.h"

EventHandler::EventHandler(Game* mGame, sf::RenderWindow* window)
	: m_Game(mGame), m_Window(window)
{
}

void EventHandler::Handle(sf::Event ev, float& deltaTimeWhenUserTriesToFire)
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
            m_Game->m_PlayerController.Fire(deltaTimeWhenUserTriesToFire);
            /*if (deltaTimeWhenUserTriesToFire >= m_Game->m_Player.GetFireRate())
            {
                m_Game->m_Player.Fire();
                deltaTimeWhenUserTriesToFire = 0;
            }*/
        }
        break;
    default:
        break;
    }
}
