#include"game.h"
std::vector<sf::Texture>texture(){
    std::vector<sf::Texture>ran;

    sf::Texture tx;
                tx.loadFromFile("images/ran1.png");
                ran.push_back(tx);
                tx.loadFromFile("images/ran2.png");
                ran.push_back(tx);
                tx.loadFromFile("images/ran3.png");
                ran.push_back(tx);
                tx.loadFromFile("images/ran4.png");
                ran.push_back(tx);
                return ran;



}
void dieukhienran(int &x,int &y)
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        x=x-7;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        x=x+7;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
        y=y-7;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
        y=y+7;
    }
    if(x<50) x=50;
    if(x>500)x=500;
    if(y<0) y=0;
    if(y>600)y=600;


}
std::vector<sf::Texture>textures(){
    std::vector<sf::Texture>ran;

    sf::Texture tx;
     tx.loadFromFile("images/a1.png");
                ran.push_back(tx);
     tx.loadFromFile("images/a2.png");
                ran.push_back(tx);
    tx.loadFromFile("images/a3.png");
                ran.push_back(tx);
    tx.loadFromFile("images/a4.png");
                ran.push_back(tx);
    tx.loadFromFile("images/a5.png");
                ran.push_back(tx);
    tx.loadFromFile("images/a6.png");
                ran.push_back(tx);
     tx.loadFromFile("images/a7.png");
                ran.push_back(tx);
    tx.loadFromFile("images/a8.png");
                ran.push_back(tx);
    tx.loadFromFile("images/a9.png");
                ran.push_back(tx);
     tx.loadFromFile("images/a10.png");
                ran.push_back(tx);
     tx.loadFromFile("images/a11.png");
                ran.push_back(tx);
     tx.loadFromFile("images/a12.png");
                ran.push_back(tx);
    tx.loadFromFile("images/a13.png");
                ran.push_back(tx);
        ran.push_back(tx);
        return ran;
};
void checkMang(int mang,sf::RenderWindow &window)
{sf::Texture tx;
tx.loadFromFile("mang.png");
sf::Sprite s1(tx),s2(tx),s3(tx),s4(tx),s5(tx);
   for(int a=0;a<mang;a++){
   if(a==0) window.draw(s1);
   if(a==1) {s2.setPosition(a*48,0);window.draw(s2);}
   if(a==2) {s3.setPosition(a*48,0);window.draw(s3);}
   if(a==3) {s4.setPosition(a*48,0);window.draw(s4);}
   if(a==4) {s5.setPosition(a*48,0);window.draw(s5);}
   }
}
