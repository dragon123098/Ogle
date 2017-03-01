# include <SFML/Graphics.hpp>
#define WIDE 800
#define HIGH 600
# include <iostream>
int main()
{
  sf::RenderWindow window(sf::VideoMode(WIDE,HIGH),"ADVENTURE OF GERALD THE SOLDIER");



//Make Circle
  sf::CircleShape circle(100);
  circle.setFillColor(sf::Color::Green);
  circle.setPosition(200,200);
//Make Hero
  sf::RectangleShape hero(sf::Vector2f(50,50));
  hero.setFillColor(sf::Color::Red);
  hero.setPosition(WIDE-50,0);
  int circleDirection = 0;
  int speed = 1;
  int points = 10;

  //Game loop
  while(window.isOpen())
  {
    //Handles Events
    sf::Event event;
    while(window.pollEvent(event))
    {
      //Close Event
      if(event.type == sf::Event::Closed)
      {
        window.close();
      }

    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && hero.getPosition().y > 0)
    {
      hero.move(0,-speed);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && hero.getPosition().y<HIGH-hero.getSize().y)
    {
      hero.move(0,speed);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)&& hero.getPosition().x > 0)
    {
      hero.move(-speed,0);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && hero.getPosition().x<WIDE-hero.getSize().x)
    {
      hero.move(speed,0);
    }

    if(hero.getGlobalBounds().intersects(circle.getGlobalBounds()))

      std::cout << "                      ****************************************                                         Touching circle" << std::endl;
    }

    window.clear(sf::Color::Blue);
    //controls circle movment
    if(circleDirection == 0)
    {
      circle.move(1,0);
    }
    else
    {
      circle.move(-1,0);
    }
    if(circle.getPosition().x > 600)
    {
      circleDirection = 1;
    }
    if(circle.getPosition().x < 0)
    {
      circleDirection = 0;
    }

    //circle.move(3,0.00001);
    //render. This is Max
    //Draw hero
    window.draw(hero);
    //Draw Circle
    window.draw(circle);
    //Display the stuff
    window.display();


  }
}
