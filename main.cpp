# include <SFML/Graphics.hpp>
#define WIDE 800
#define HIGH 600
# include <iostream>
#define TILESIZE 96







int main()
{
  sf::RenderWindow window(sf::VideoMode(WIDE,HIGH),"ADVENTURE OF GERALD THE ROBBER");



//Make Circle
  sf::CircleShape circle(100);
  circle.setFillColor(sf::Color::Green);
  circle.setPosition(200,200);
//Make Hero
  sf::Texture hero_texture;
  if(!hero_texture.loadFromFile("Assets/Hero.png"))
  {
    std::cout << "Error loading texture" << std::endl;
  }
  sf::Sprite hero;
  hero.setTexture(hero_texture);

  hero.setScale(sf::Vector2f(3,3));


  int circleDirection = 0;
  double speed = 1;
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
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && hero.getPosition().y<HIGH-TILESIZE)
    {
      hero.move(0,speed);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)&& hero.getPosition().x > 0)
    {
      hero.move(-speed,0);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && hero.getPosition().x<WIDE-TILESIZE)
    {
      hero.move(speed,0);
    }

    if(hero.getGlobalBounds().intersects(circle.getGlobalBounds()))
    {

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
