# include <SFML/Graphics.hpp>
#define WIDE 800
#define HIGH 640
# include <iostream>
#define TILESIZE 32
#include <vector>



bool testCall(sf::Sprite a, sf::Sprite b)
{
  return a.getGlobalBounds().intersects(b.getGlobalBounds());
}

bool testWallColl(sf::Sprite a, std::vector<sf::Sprite>walls)
{
  for(int i=0; i<walls.size(); i++)
  {
    if(a.getGlobalBounds().intersects(walls[i].getGlobalBounds()))
    {
      return true;
    }
  }
  return false;
}


int main()
{
  sf::RenderWindow window(sf::VideoMode(WIDE,HIGH),"ADVENTURE OF GERALD THE ROBBER");
  int tileW = WIDE/TILESIZE;
  int tileH = HIGH/TILESIZE;
  std::vector<std::vector<bool> > map;

  for(int i=0; i<tileH; i ++)
  {
    std::vector<bool> temp;
    for(int j=0; j<tileW; j++)
    {
      temp.push_back(false);
    }
    map.push_back(temp);
  }


  map[3][2] = true;
  map[3][3] = true;
  map[3][4] = true;
  map[2][10] = true;
  for(int i=0; i<map.size(); i++)
  {
      for(int j=0; j<map[i].size(); j++)
      {
        if(map[i][j] == true)
        {
          std::cout << '0';
        }
        else
        {
          std::cout << ' ';
        }
      }
      std::cout << std::endl;
  }


//Make Enemy/enemy
sf::Texture enemy_texture;
if(!enemy_texture.loadFromFile("Assets/EnemyDog.png"))
{
  std::cout << "Error loading texture" << std::endl;
}

//I know someone who is a dirty dishrag
sf::Sprite enemy;
enemy.setTexture(enemy_texture);

enemy.setScale(sf::Vector2f(5,5));
enemy.setPosition(100,100);

//cloud
sf::Texture cloud_texture;
if(!cloud_texture.loadFromFile("Assets/grass.png"))
{
  std::cout << "thkgds;jafkldajs;" << std::endl;
}
sf::Sprite cloud;
cloud.setTexture(cloud_texture);
//He lives in Boston
cloud.setScale(sf::Vector2f(2,2));





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


  //He likes to eat butterflies
  std::vector<sf::Sprite> wallArr;

    for(int i=0; i<map.size(); i++)
    {
        for(int j=0; j<map[i].size(); j++)
        {
          if(map[i][j] == true)
          {
            sf::Sprite temp;
            temp.setTexture(rock_texture);
            temp.setScale(sf::Vector2f(3,3));
            temp.setPosition(i*TILESIZE,j*TILESIZE);
            wallArr.push_back(temp);
          }
        }
    }










  int enemyDirection = 0;



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
      hero.move(0,-speed);
      if(testWallColl(hero, wallArr))
      {
        hero.move(0,speed);
      }
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && hero.getPosition().y<HIGH-TILESIZE)
    {
      hero.move(0,speed);
      if(testWallColl(hero, wallArr))
      {
        hero.move(0,-speed);
      }
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)&& hero.getPosition().x > 0)
    {
      hero.move(-speed,0);
      if(testWallColl(hero, wallArr))
      {
        hero.move(speed,0);
      }
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && hero.getPosition().x<WIDE-TILESIZE)
    {
      hero.move(speed,0);
      if(testWallColl(hero, wallArr))
      {
        hero.move(-speed,0);
      }
    }


    //Colide with Enemy
    if(hero.getGlobalBounds().intersects(enemy.getGlobalBounds()))
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
    //controls enemy movment
    if(enemyDirection == 0)
    {
      enemy.move(1,0);
    }
    else
    {
      enemy.move(-1,0);
    }
    if(enemy.getPosition().x > 600)
    {
      enemyDirection = 1;
    }
    if(enemy.getPosition().x < 0)
    {
      enemyDirection = 0;
    }

    for(int i=0; i<tileH; i++)
    {
      for(int j=0; j<tileW; j++)
      {
        cloud.setPosition(j*TILESIZE, i*TILESIZE);
        window.draw(cloud);
      }
    }



    //Draw Text
    window.draw(livesDisp);
    //Drow hero
    window.draw(hero);
    //Draw enemy
    window.draw(enemy);

    for(int i=0; i<wallArr.size(); i++)
    {
      window.draw(wallArr[i]);
    }
    //Draw background



    //Display all stuff
    window.display();

  }
}
