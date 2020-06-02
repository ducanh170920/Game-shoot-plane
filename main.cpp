#include<iostream>
#include<SFML/Graphics.hpp>
#include<cstdlib>
#include<vector>
#include<ctime>
#include <windows.h>
#include<string>
#include<vector>
#include"game.h"
#include<thread>
#include<SFML/Audio.hpp>



struct toado{
    int x;
    int y;
    };

int main(){


        srand(time(NULL));
        sf::RenderWindow window(sf::VideoMode(650,650),"SNAKE GAME");
        std::vector<sf::Texture>ran=texture();
        std::vector<sf::Texture>quaivat=textures();


        sf::Sprite snake(ran[3]);
        int x=300,y=300;
        int speed[2];
        int count =-1;
        int dem[2]={0,0};
        bool check=true;
        bool play=false;
        bool trangchu=true;
        toado dan[2];

        sf::Texture background;
        sf::Texture start;
        background.loadFromFile("background.png");
        start.loadFromFile("start.jpg");
        sf::Sprite st(start);
        sf::Texture ov;
        ov.loadFromFile("gameover.jpg");
        sf::Sprite over(ov);

        //loadfont
        sf::Font font;
        font.loadFromFile("MarkerFelt.ttf");

        //nhacne

        sf::SoundBuffer nhac1,nhac2,nhac3,nhac4;
        nhac1.loadFromFile("music.ogg");
        nhac2.loadFromFile("Fire1.wav");
        nhac3.loadFromFile("Explosion+1.wav");
        nhac4.loadFromFile("laser.wav");
        sf::Sound n1(nhac1),n2(nhac2),n3(nhac3),n4(nhac4);
        n1.setLoop(true);
        n1.play();


       // lay tao do ngau nhien anh quai vat



// load background
        toado bk;
        bk.x=0;
        bk.y=7540;
        sf::Texture t,rock;
        t.loadFromFile("anh1.png");
        rock.loadFromFile("rock.png");


while(window.isOpen()){
        sf::Event e;
        while(window.pollEvent(e))
            if(e.type==sf::Event::Closed)window.close();
            int score=0;
            toado mouse;
            mouse.x=sf::Mouse::getPosition(window).x;
            mouse.y=sf::Mouse::getPosition(window).y;
            int randommonster[5];
        randommonster[0]=rand()%13;
        randommonster[1]=rand()%13;
        randommonster[2]=rand()%13;
        randommonster[3]=rand()%13;
        randommonster[4]=rand()%13;


        toado monster[10];
        monster[0].x=50+rand()%90;
        monster[1].x=90+rand()%90;
        monster[2].x=180+rand()%90;
        monster[3].x=270+rand()%90;
        monster[4].x=360+rand()%90;
        monster[5].x=50+rand()%90;
        monster[6].x=90+rand()%90;
        monster[7].x=180+rand()%90;
        monster[8].x=270+rand()%90;
        monster[9].x=360+rand()%90;

        monster[0].y=-rand()%500;
        monster[1].y=-rand()%500;
        monster[2].y=-rand()%500;
        monster[3].y=-rand()%500;
        monster[4].y=-rand()%500;
        monster[5].y=-rand()%500;
        monster[6].y=-rand()%500;
        monster[7].y=-rand()%500;
        monster[8].y=-rand()%500;
        monster[9].y=-rand()%500;

        speed[0]=2;
        speed[1]=5;
         int mang=5;
        int x=300,y=300;
        int count =-1;
        int dem[2]={0,0};

        while(trangchu)
        {

            while(window.pollEvent(e))
                if(e.type==sf::Event::Closed)window.close();
            window.display();
            window.draw(st);
            mouse.x=sf::Mouse::getPosition(window).x;
            mouse.y=sf::Mouse::getPosition(window).y;
            if(mouse.x>263&&mouse.x<=442&&mouse.y>410&&mouse.y<468&&sf::Mouse::isButtonPressed(sf::Mouse::Left))
                    {
                        play=true;
                        trangchu=false;
                    }
            else if(mouse.x>263&&mouse.x<=442&&mouse.y>488&&mouse.y<542&&sf::Mouse::isButtonPressed(sf::Mouse::Left))
                    {
                        bool dung=true;
                        while(dung){
                        window.clear();
                        sf::Texture guide;
                        guide.loadFromFile("huongdan.png");
                        sf::Sprite g(guide);
                        window.draw(g);
                        window.display();
                        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
                            dung=false;
                        }

                    }
            else if(mouse.x>263&&mouse.x<=442&&mouse.y>579&&mouse.y<638&&sf::Mouse::isButtonPressed(sf::Mouse::Left))
                    {
            window.close();
                    }

        }

while(play)

        {

            sf::Sprite run_background(background,sf::IntRect(bk.x,bk.y,650,650));
            bk.y=bk.y-speed[0];

            if(bk.y<=0)bk.y=0;
            window.clear();
            window.draw(run_background);


            sf::Sprite qv1(quaivat[randommonster[0]]);
            qv1.setPosition(monster[0].x,monster[0].y);

            sf::Sprite qv2(quaivat[randommonster[1]]);
            qv2.setPosition(monster[1].x,monster[1].y);
            sf::Sprite qv3(quaivat[randommonster[2]]);
            qv3.setPosition(monster[2].x,monster[2].y);
            sf::Sprite qv4(quaivat[randommonster[3]]);
            qv4.setPosition(monster[3].x,monster[3].y);
            sf::Sprite qv6(quaivat[randommonster[4]]);
            qv6.setPosition(monster[4].x,monster[4].y);
            sf::Sprite qv7(quaivat[randommonster[0]]);
            qv7.setPosition(monster[5].x,monster[5].y);
            sf::Sprite qv8(rock);
            qv8.setPosition(monster[6].x,monster[6].y);
            sf::Sprite qv9(rock);
            qv9.setPosition(monster[7].x,monster[7].y);
            sf::Sprite qv10(rock);
            qv10.setPosition(monster[8].x,monster[8].y);
            sf::Sprite qv5(quaivat[randommonster[4]]);
            qv5.setPosition(monster[9].x,monster[9].y);

           if(dan[0].y>=monster[0].y&&dan[0].y<=monster[0].y+70&&dan[0].x>=monster[0].x&&dan[0].x<=monster[0].x+70) {if(bk.y>650){monster[0].x=180+rand()%90; monster[0].y=-rand()%500;}n3.play();check=true;score++;}
           if(dan[0].y>=monster[1].y&&dan[0].y<=monster[1].y+70&&dan[0].x>=monster[1].x&&dan[0].x<=monster[1].x+70) {if(bk.y>650){monster[1].x=270+rand()%90; monster[1].y=-rand()%500;}n3.play();check=true;score++;}
           if(dan[0].y>=monster[2].y&&dan[0].y<=monster[2].y+70&&dan[0].x>=monster[2].x&&dan[0].x<=monster[2].x+70){if(bk.y>650){monster[2].x=360+rand()%90; monster[2].y=-rand()%500;}n3.play();check=true;score++;}
           if(dan[0].y>=monster[3].y&&dan[0].y<=monster[3].y+70&&dan[0].x>=monster[3].x&&dan[0].x<=monster[3].x+70) {if(bk.y>650){monster[3].x=50+rand()%90; monster[3].y=-rand()%500;}n3.play();check=true;score++;}
           if(dan[0].y>=monster[4].y&&dan[0].y<=monster[4].y+70&&dan[0].x>=monster[4].x&&dan[0].x<=monster[4].x+70) {if(bk.y>650){monster[4].x=180+rand()%90; monster[4].y=-rand()%500;}n3.play();check=true;score++;}
           if(dan[0].y>=monster[5].y&&dan[0].y<=monster[5].y+70&&dan[0].x>=monster[5].x&&dan[0].x<=monster[5].x+70) {if(bk.y>650){monster[5].x=90+rand()%90; monster[5].y=-rand()%500;}n3.play();check=true;score++;}
           if(dan[0].y>=monster[6].y&&dan[0].y<=monster[6].y+70&&dan[0].x>=monster[6].x&&dan[0].x<=monster[6].x+70){n4.play();check=true;}
           if(dan[0].y>=monster[7].y&&dan[0].y<=monster[7].y+70&&dan[0].x>=monster[7].x&&dan[0].x<=monster[7].x+70){n4.play();check=true;}
           if(dan[0].y>=monster[8].y&&dan[0].y<=monster[8].y+70&&dan[0].x>=monster[8].x&&dan[0].x<=monster[8].x+70){n4.play();check=true;}
           if(dan[0].y>=monster[9].y&&dan[0].y<=monster[9].y+70&&dan[0].x>=monster[9].x&&dan[0].x<=monster[9].x+70){if(bk.y>650){monster[9].x=300+rand()%90; monster[9].y=-rand()%500;}n3.play();check=true;score++;}



            window.draw(qv1);
            window.draw(qv2);
            window.draw(qv3);
            window.draw(qv4);
            window.draw(qv5);
            window.draw(qv6);
            window.draw(qv7);
            window.draw(qv8);
            window.draw(qv9);
            window.draw(qv10);
            monster[0].y=monster[0].y+speed[0];
            monster[1].y=monster[1].y+speed[0];
            monster[2].y=monster[2].y+speed[0];
            monster[3].y=monster[3].y+speed[0];
            monster[4].y=monster[4].y+speed[0];
            monster[5].y=monster[5].y+speed[0];
            monster[6].y=monster[6].y+speed[1];
            monster[7].y=monster[7].y+speed[1];
            monster[8].y=monster[8].y+speed[1];
            monster[9].y=monster[9].y+speed[0];
            monster[10].y=monster[10].y+speed[0];
            dem[0]++;
            if(dem[0]==1000) {speed[0]=speed[0]+1;speed[1]=speed[1]+1;}

            window.draw(snake);


            sf::Event event;
            while(window.pollEvent(event))
            {
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
                    window.close();

            }

            dieukhienran(x,y);

            //su li dan
            sf::Texture bullet;
            bullet.loadFromFile("sphere.png");
            sf::Sprite b1(bullet);
            if(sf::Mouse::isButtonPressed(sf::Mouse::Left)&&check==true)
                {        n2.play();
                        dan[0].x=x+49;
                        dan[0].y=y-8;
                        check=false;
                }
                        else if(check==false)
                {
                    b1.setPosition(dan[0].x,dan[0].y);
                    dan[0].y=dan[0].y-50;
                    if(dan[0].y<0)check=true;
                    window.draw(b1);
                }


                 window.setFramerateLimit(60);

if(bk.y>650){
        if(monster[0].y>650){monster[0].x=180+rand()%90; monster[0].y=-rand()%500;mang--;}
        if(monster[1].y>650){monster[1].x=360+rand()%90; monster[1].y=-rand()%500;mang--;}
        if(monster[2].y>650){monster[2].x=270+rand()%90; monster[2].y=-rand()%500;mang--;}
        if(monster[3].y>650){monster[3].x=50+rand()%90; monster[3].y=-rand()%500;mang--;}
        if(monster[4].y>650){monster[4].x=270+rand()%90; monster[4].y=-rand()%500;mang--;}
        if(monster[5].y>650){monster[5].x=360+rand()%90; monster[5].y=-rand()%500;mang--;}
        if(monster[6].y>650){monster[6].x=160+rand()%90; monster[6].y=-rand()%500;}
        if(monster[7].y>650){monster[7].x=50+rand()%90; monster[7].y=-rand()%500;}
        if(monster[8].y>650){monster[8].x=280+rand()%90; monster[8].y=-rand()%500;}
        if(monster[9].y>650){monster[9].x=270+rand()%90; monster[9].y=-rand()%500;mang--;}
}
 if(bk.y==0){
        std::string ende="YOU WIN !";
        sf::Text textt(ende,font);
        textt.setColor(sf::Color::Yellow);
        textt.setPosition(200,200);
        textt.setCharacterSize(50);
        window.draw(textt);
    }

   // va cham da

   for(int i=6;i<=8;i++){
        if(x+55>monster[i].x&&x+55<monster[i].x+90&&y+10>monster[i].y&&monster[i].y+90>y+10)play=false;
        else if(x>monster[i].x&&x<monster[i].x+80&&y+55>monster[i].y&&monster[i].y+80>y+55)play=false;
        else if(x+90>monster[i].x&&x+90<monster[i].x+80&&y+55>monster[i].y&&monster[i].y+80>y+55)play=false ;
   }

   checkMang(mang,window);
   if(mang==0) play=false;


   std::string s="Score :"+std::to_string(score);
   sf::Text text(s,font);
   text.setColor(sf::Color::Red);
   text.setPosition(520,0);
   window.draw(text);
            snake.setPosition(x,y);
            window.display();



    }
 if(mouse.x>281&&mouse.x<=406&&mouse.y>453&&mouse.y<514&&sf::Mouse::isButtonPressed(sf::Mouse::Left))
                    {
                        window.close();
                    }
else if(mouse.x>276&&mouse.x<=411&&mouse.y>534&&mouse.y<592&&sf::Mouse::isButtonPressed(sf::Mouse::Left))
                    {
                       play=true;
                       trangchu=false;
                       bk.y=7540;
                    }
window.draw(over);
window.display();
window.clear();

}


}
