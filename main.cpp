# include <SFML/Graphics.hpp>
#define WIDE 800
#define HIGH 600
# include <iostream>
#define TILESIZE 96







int main()
{
  sf::RenderWindow window(sf::VideoMode(WIDE,HIGH),"ADVENTURE OF GERALD THE ROBBER");



//Make Enemy/Circle
sf::Texture circle_texture;
if(!circle_texture.loadFromFile("Assets/EnemyDog.png"))
{
  std::cout << "Error loading texture" << std::endl;
}
sf::Sprite circle;
circle.setTexture(circle_texture);

circle.setScale(sf::Vector2f(5,5));
circle.setPosition(100,100);





//Add in Font
sf::Font font;
if(!font.loadFromFile("assets/ARCADECLASSIC.TTF"))
{
  std::cout << "Error loading font" << std::endl;
}
sf::Text livesDisp;
livesDisp.setFont(font);
livesDisp.setCharacterSize(24);
livesDisp.setColor(sf::Color::Blue);



//Make Hero
  sf::Texture hero_texture;
  if(!hero_texture.loadFromFile("Assets/Hero.png"))
  {
    std::cout << "Error loading texture" << std::endl;
  }
  sf::Sprite hero;
  hero.setTexture(hero_texture);

  hero.setScale(sf::Vector2f(3,3));

  //Make Rock
  sf::Texture rock_texture;
  if(!rock_texture.loadFromFile("Assets/ROCK.png"))
  {
    std::cout << "Error loading rock" << std::endl;
  }

  sf::Sprite rock;
  rock.setTexture(rock_texture);
  rock.setScale(sf::Vector2f(3,3));
  rock.setPosition(30,250);









  int circleDirection = 0;


  double speed = .7;

  int lives = 10;

  bool takingDamage = false;

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


    //Control movement
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && hero.getPosition().y > 0)
    {
      hero.move(50,-speed);
      if(hero.getGlobalBounds().intersects(rock.getGlobalBounds()))
      {
        hero.move(0,speed);
      }
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && hero.getPosition().y<HIGH-TILESIZE)
    {
      hero.move(0,speed);
      if(hero.getGlobalBounds().intersects(rock.getGlobalBounds()))
      {
        hero.move(0,-speed);
      }
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)&& hero.getPosition().x > 0)
    {
      hero.move(-speed,0);
      if(hero.getGlobalBounds().intersects(rock.getGlobalBounds()))
      {
        hero.move(speed,0);
      }
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && hero.getPosition().x<WIDE-TILESIZE)
    {
      hero.move(speed,0);
      if(hero.getGlobalBounds().intersects(rock.getGlobalBounds()))
      {
        hero.move(-speed,0);
      }
    }


    //Colide with Enemy
    if(hero.getGlobalBounds().intersects(circle.getGlobalBounds()))
    {
      if(takingDamage == false)
      {
        lives--;
        takingDamage = true;
      }
    }
    else
    {
      takingDamage = false;
    }



    livesDisp.setString(std::to_string(lives));

     window.clear(sf::Color::White);
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

    //Draw Text
    window.draw(livesDisp);
    //Drow hero
    window.draw(hero);
    //Draw Circle
    window.draw(circle);
    //Draw Rock
    window.draw(rock);
    //Display all stuff
    window.display();

  }
}
