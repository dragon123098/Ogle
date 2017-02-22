# include <SFML/Graphics.hpp>
#define WIDE 800
#define HIGH 600
int main()
{
  sf::RenderWindow window(sf::VideoMode(WIDE,HIGH),"ADVENTURE OF GERALD THE SOLDIER");



  sf::CircleShape circle(100);
  circle.setFillColor(sf::Color::Green);
  circle.setPosition(0,0);

  int circleDirection = 0;


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

    window.clear(sf::Color::Blue);
    //update stuff. This is Aaron
    if(circleDirection == 0)
    {
      circle.move(0.50,0);
    }
    else
    {
      circle.move(-0.50,0);
    }
    if(circle.getPosition().x > 600)
    {
      circleDirection = 1;
    }
    if(circle.getPosition().x < 0)
    {
      circleDirection = 0;
    }

    circle.move(3,0.00001);
    //render. This is Max
    window.draw(circle);
    window.display();


  }
}
