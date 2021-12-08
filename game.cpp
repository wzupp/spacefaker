#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <ctime>
#include <cmath>
#include <vector>
#include <set>
#include <algorithm>
#include <iostream>

using namespace sf;
using std::vector;
using std::multiset;
using namespace std;

long long score=0.;

class texture_manager
{
    Texture simple_bot_texture;
    Texture main_hero_texture;
    Texture simple_bot_ammunition_texture;
    Texture first_boss_texture_state_of_fire;
    Texture firs_boss_texture_state_of_protect;
    Texture booster_texture;
    Texture simple_background_1;
    Texture simple_background_2;
    Texture simple_background_3;
    Texture simple_background_4;
    Texture boss_background_1;
    Texture boss_background_2;
    Texture end_game_texture;

    public:

        explicit texture_manager()
        {
            simple_bot_texture.loadFromFile("game_images/enemies/simple_enemies/enemies.png");
            main_hero_texture.loadFromFile("game_images/hero/space_ship/main_hero.png");
            simple_bot_ammunition_texture.loadFromFile("game_images/effects/rockets.png");
            first_boss_texture_state_of_fire.loadFromFile("game_images/enemies/bosses/first_boss_state_of_fire.png");
            firs_boss_texture_state_of_protect.loadFromFile("game_images/enemies/bosses/first_boss_state_of_protect.png");
            booster_texture.loadFromFile("game_images/game_object/booster.png");
            simple_background_1.loadFromFile("game_images/background/simple_background_1.png");
            simple_background_2.loadFromFile("game_images/background/simple_background_2.png");
            simple_background_3.loadFromFile("game_images/background/simple_background_3.png");
            simple_background_4.loadFromFile("game_images/background/simple_background_4.png");
            boss_background_1.loadFromFile("game_images/background/boss_state_fire_background.png");
            boss_background_2.loadFromFile("game_images/background/boss_state_protect.png");
            end_game_texture.loadFromFile("game_images/background/end_game.png");
        }

        const Texture& get_texture(int number)const
        {
            switch(number)
            {
                case 1:
                    return simple_bot_texture;
                case 2:
                    return main_hero_texture;
                case 3:
                    return simple_bot_ammunition_texture;
                case 4:
                    return first_boss_texture_state_of_fire;
                case 5:
                    return firs_boss_texture_state_of_protect;
                case 6:
                    return firs_boss_texture_state_of_protect;
                case 7:
                    return booster_texture;
                case 8:
                    return simple_background_1;
                case 9:
                    return simple_background_2;
                case 10:
                    return simple_background_3;
                case 11:
                    return simple_background_4;
                case 12:
                    return boss_background_1;
                case 13:
                    return boss_background_2;
                case 14:
                    return end_game_texture;
            }
        }
}texture_manager;

class Backgound
{
    Texture texture_background;

    Sprite sprite_background;

    Text* end_game_text;

    Font* end_game_font;

    bool end;

    bool boss_state;

    Backgound(const Backgound&);

    Backgound& operator=(const Backgound&);

        public:

            Backgound(const RenderWindow& window)
            {
                end_game_font = nullptr;

                end_game_text = nullptr;

                end = false;

                boss_state = true;

                switch(rand()%4)
                {
                    case 0:
                        texture_background = texture_manager.get_texture(8);
                        sprite_background.setTextureRect(IntRect(0,0,206,192));
                        break;
                    case 1:
                        texture_background = texture_manager.get_texture(9);
                        sprite_background.setTextureRect(IntRect(0,0,1920,960));
                        break;
                    case 2:
                        texture_background = texture_manager.get_texture(10);
                        sprite_background.setTextureRect(IntRect(0,0,960,540));
                        break;
                    case 3:
                        texture_background = texture_manager.get_texture(11);
                        sprite_background.setTextureRect(IntRect(0,0,1920,960));
                        break;
                }

                sprite_background.setPosition(0,0);

                sprite_background.setTexture(texture_background);

                sprite_background.setScale(window.getSize().x/sprite_background.getLocalBounds().width,window.getSize().x/sprite_background.getLocalBounds().height);
            }

            void set_boss_background(const RenderWindow& window)
            {
                if(boss_state)
                {
                    texture_background = texture_manager.get_texture(12);

                    sprite_background.setTextureRect(IntRect(0,0,942,529));

                    boss_state = false;
                }

                else
                {
                    texture_background = texture_manager.get_texture(13);

                    sprite_background.setTextureRect(IntRect(0,0,640,360));

                    boss_state = true;
                }

                sprite_background.setPosition(0,0);

                sprite_background.setTexture(texture_background);

                sprite_background.setScale(window.getSize().x/sprite_background.getLocalBounds().width,window.getSize().x/sprite_background.getLocalBounds().height);
            }

            void change_simple_background(const RenderWindow& window)
            {
                switch(rand()%4)
                {
                    case 0:
                        texture_background = texture_manager.get_texture(8);
                        sprite_background.setTextureRect(IntRect(0,0,206,192));
                        break;
                    case 1:
                        texture_background = texture_manager.get_texture(9);
                        sprite_background.setTextureRect(IntRect(0,0,1920,960));
                        break;
                    case 2:
                        texture_background = texture_manager.get_texture(10);
                        sprite_background.setTextureRect(IntRect(0,0,960,540));
                        break;
                    case 3:
                        texture_background = texture_manager.get_texture(11);
                        sprite_background.setTextureRect(IntRect(0,0,2000,1125));
                        break;
                }

                sprite_background.setPosition(0,0);

                sprite_background.setTexture(texture_background);

                sprite_background.setScale(window.getSize().x/sprite_background.getLocalBounds().width,window.getSize().x/sprite_background.getLocalBounds().height);
            }

            void set_end_game(const RenderWindow& window)
            {
                end = true;
                texture_background = texture_manager.get_texture(14);
                sprite_background.setTextureRect(IntRect(0,0,500,330));
                sprite_background.setTexture(texture_background);
                sprite_background.setScale(window.getSize().x/sprite_background.getLocalBounds().width,window.getSize().x/sprite_background.getLocalBounds().height);
                end_game_font = new Font();
                end_game_font->loadFromFile("font/font.ttf");
                end_game_text = new Text("",*end_game_font,30);
                end_game_text->setColor(Color::Green);
                end_game_text->setStyle(Text::Bold);
                end_game_text->setString("killed enemies "+std::to_string(score));
                sprite_background.setPosition(0,0);
                end_game_text->setPosition(0,0);
            }

            bool get_end_state()const{return end;}

            void draw_background(RenderWindow& window)
            {
                if(!end)
                    window.draw(sprite_background);

                else
                {
					
                    window.draw(sprite_background);
                    window.draw(*end_game_text);
                }
            }

        ~Backgound()
        {
            if(end_game_font!=nullptr && end_game_text!=nullptr)
            {
                delete end_game_font;

                delete end_game_text;
            }
        }
};

class character
{
    protected:

        Sprite character_sprite;

        Texture character_texture;

        int enemies_count;

        int height;

        int width;

    public:

            character(int height, int width,int number,int position_x, int position_y,int enemies_count):height(height),width(width),enemies_count(enemies_count)
            {
                character_texture = texture_manager.get_texture(number);

                character_sprite.setTextureRect(IntRect(position_x,position_y,width,height));

                character_sprite.setTexture(character_texture);
            }

            character(const character& temp)
            {
                character_sprite = temp.get_sprite();

                character_texture = temp.get_texture();

                enemies_count = temp.get_enemies_count();

                height = temp.get_height();

                width = temp.get_width();
            }

            const Texture get_texture()const{return character_texture;}

            const Sprite get_sprite()const{return character_sprite;}

            void change_enemies_count(){if(enemies_count)--enemies_count;}

            int get_width()const{return width;}

            int get_height()const{return height;}

            int get_enemies_count()const{return enemies_count;}


        virtual ~character()=0;
};

character::~character(){}

class main_hero;

class bot_ammunition
{
        Sprite ammunition_sprite;

        Texture ammunition_texture;

        enum weapon_selector
        {
            rockets1, rockets2, boss_turret_weapon,boss_weapon
        }select;

        float target_x;

        float target_y;

        float bot_ammunition_move_speed;

        float x;

        float y;

        int width;

        int height;

        int damage;


    public:

        explicit bot_ammunition(int weapon_view)
        {
            switch(weapon_view)
            {
                case 1:
                    select = rockets1;
                    bot_ammunition_move_speed = 0.12f;
                    damage = 5;
                    height = 13;
                    width = 13;
                    ammunition_texture = texture_manager.get_texture(3);
                    ammunition_sprite.setTextureRect(IntRect(328,249,width,height));
                    ammunition_sprite.setTexture(ammunition_texture);
                    break;

                case 2:
                    select = rockets2;
                    bot_ammunition_move_speed = 0.05f;
                    damage = 5;
                    height = 23;
                    width = 20;
                    ammunition_texture = texture_manager.get_texture(3);
                    ammunition_sprite.setTextureRect(IntRect(90,305,width,height));
                    ammunition_sprite.setTexture(ammunition_texture);
                    break;

                case 3:
                    select = boss_turret_weapon;
                    bot_ammunition_move_speed = 0.08f;
                    damage = 10;
                    height = 15;
                    width = 15;
                    ammunition_texture = texture_manager.get_texture(4);
                    ammunition_sprite.setTextureRect(IntRect(7,9,width,height));
                    ammunition_sprite.setTexture(ammunition_texture);
                    ammunition_sprite.setOrigin(7.5f,7.5f);
                    break;

                case 4:
                    select = boss_weapon;
                    bot_ammunition_move_speed = 0.05f;
                    damage = 10;
                    height = 15;
                    width = 15;
                    ammunition_texture = texture_manager.get_texture(6);
                    ammunition_sprite.setTextureRect(IntRect(7,9,width,height));
                    ammunition_sprite.setTexture(ammunition_texture);
                    ammunition_sprite.setOrigin(7.5f,7.5f);
            }
        }

        int get_damage()const{return damage;}

        bot_ammunition(const bot_ammunition& temp)
        {
            select = static_cast<weapon_selector>(temp.get_select_weapon());
            damage = temp.get_damage();
            bot_ammunition_move_speed = temp.get_ammunition_move_speed();
            width = temp.get_width();
            height=temp.get_height();
            ammunition_sprite = temp.get_ammunition_sprite();
            target_x = temp.get_target_x();
            target_y = temp.get_target_y();
            x = temp.get_x();
            y = temp.get_y();
        }

        int get_select_weapon()const{return static_cast<int>(select);}

        void change_weapon()
        {
            if(select==rockets1)
            {
                select = rockets2;
                bot_ammunition_move_speed = 0.05f;
                damage = 20;
                height = 23;
                width = 20;
                ammunition_sprite.setTextureRect(IntRect(90,305,width,height));
            }
            else
            {
                select = rockets1;
                bot_ammunition_move_speed = 0.1f;
                damage = 10;
                height = 13;
                width = 13;
                ammunition_sprite.setTextureRect(IntRect(328,249,width,height));
            }
        }

        void draw_ammunition(RenderWindow& window)const
        {
            window.draw(ammunition_sprite);
        }

        void set_start_coordinate(const float& x, const float& y,const float& tar_x, const float& tar_y)
        {
            this->x = x;

            this->y = y;

            target_x = tar_x;

            target_y = tar_y;

            ammunition_sprite.setPosition(x,y);
        }

        void update_coordinates(float time)
        {
            if(select==boss_turret_weapon || select==rockets1 || select==rockets2)
            {
                float distance = sqrt(pow(target_x-x,2)+pow(target_y-y,2));

                x+= bot_ammunition_move_speed*time*(target_x-x)/distance;

                y+= bot_ammunition_move_speed*time*(target_y-y)/distance;
            }

            else
            {
                ammunition_sprite.setRotation(atan2(target_y-y,target_x-x)*180/3.14159265);

                float distance = sqrt(pow(target_x-x,2)+pow(target_y-y,2));

                x+= bot_ammunition_move_speed*time*(target_x-x)/distance;

                y+= bot_ammunition_move_speed*time*(target_y-y)/distance;
            }

            ammunition_sprite.setPosition(x,y);
        }

        const int& get_width()const{return width;}

        const int& get_height()const{return height;}

        const Sprite& get_ammunition_sprite()const{return ammunition_sprite;}

        const int get_target_x()const{return target_x;}

        const int get_target_y()const{return target_y;}

        const int get_x()const{return x;}

        const int get_y()const{return y;}

        const float& get_ammunition_move_speed()const{return bot_ammunition_move_speed;}
};

class main_hero_ammunition
{
    float main_hero_ammunition_move_speed;

    int width;

    int height;

    int damage;

    Sprite ammunition_hero_sprite;

    Texture ammunition_hero_texture;

    float x;

    float y;

        public:

        explicit main_hero_ammunition(int weapon_index=2,int state=1,int position_picture_x=97, int position_picture_y=95,int width=15, int height=14):width(width),height(height),x(position_picture_x),y(position_picture_y)
        {
            if(weapon_index==2)
            {
                ammunition_hero_texture = texture_manager.get_texture(2);
                ammunition_hero_sprite.setTextureRect(IntRect(98,96,15,14));
                ammunition_hero_sprite.setTexture(ammunition_hero_texture);

                if(state==2)
                {
                    damage = 10;
                    main_hero_ammunition_move_speed = 0.09f;
                }

                else if(state==1)
                {
                    damage = 20;
                    main_hero_ammunition_move_speed = 0.05f;
                }
            }

            else if(weapon_index==4)
            {
                ammunition_hero_texture = texture_manager.get_texture(4);
                ammunition_hero_sprite.setTextureRect(IntRect(7,9,15,15));
                ammunition_hero_sprite.setTexture(ammunition_hero_texture);
                damage = 20;
                main_hero_ammunition_move_speed = 0.1f;
            }
        }

        main_hero_ammunition(const main_hero_ammunition& temp)
        {
            width = temp.get_width();

            height = temp.get_height();

            ammunition_hero_sprite = temp.get_ammunition_sprite();

            x = temp.get_x();

            y = temp.get_y();
        }

        int get_damage()const{return damage;}

        void set_damage(int new_damage){damage = new_damage;}

        void set_start_coordinate(const float& x, const float& y)
        {
            this->x = x;

            this->y = y;

            ammunition_hero_sprite.setPosition(x,y);
        }

        void update_coordinates(const float& time,const bool flag=true)
        {
            if(flag)
                x+=main_hero_ammunition_move_speed*time;
            else
                x-=main_hero_ammunition_move_speed*time;

            ammunition_hero_sprite.setPosition(x,y);
        }

        void draw_hero_ammunition(RenderWindow& window)
        {
            window.draw(ammunition_hero_sprite);
        }

        int get_width()const{return width;}

        int get_height()const{return height;}

        const Sprite get_ammunition_sprite()const{return ammunition_hero_sprite;}

        const int get_x()const{return ammunition_hero_sprite.getPosition().x;}

        const int get_y()const{return ammunition_hero_sprite.getPosition().y;}

        ~main_hero_ammunition(){}
};

class enemies:public character
{
    static const float move_speed;

    struct enemie_unit
    {
        int helth;

        Sprite sprite;
    };

    vector<enemie_unit*> arr;

    enemie_unit* one_unit;

    public:

        enemies(const RenderWindow& window,int count_enemies,int bot_type=1,int helth = 100, int x=0, int y=0, int width = 23, int height = 17):character(height,width,bot_type,x,y,count_enemies)
        {
            if((window.getSize().x/2-5)/count_enemies<=width)
                    while((window.getSize().x/2-5)/count_enemies<=width && count_enemies>0)
                        count_enemies-=1;

            character::enemies_count = count_enemies;

            one_unit = new enemie_unit[enemies_count];

            for(int i=0 ; i<enemies_count ; ++i)
            {
                arr.push_back(&one_unit[i]);
                arr[i]->sprite.setTextureRect(IntRect(x,y,width,height));
                arr[i]->sprite.setTexture(character::character_texture);
                arr[i]->helth = helth;
            }

            int count = (window.getSize().x/2-5)/enemies_count;

            for(int i=0,x=window.getSize().x/2 ; i<count_enemies; ++i,x+=count)
                arr[i]->sprite.setPosition(x+rand()%(count-width),height+rand()%(window.getSize().y-2*height));
        }

        void set_enemie_position(int enemie_index, float enemie_x, float enemie_y)
        {
            arr[enemie_index]->sprite.setPosition(enemie_x,enemie_y);
        }

        enemies(const enemies& temp):character(temp)
        {
            one_unit = new enemie_unit[enemies_count];

            for(int i=0 ; i<enemies_count ; ++i)
            {
                arr.push_back(&one_unit[i]);
                arr[i]->sprite.setTextureRect(IntRect(temp.get_sprite_position_x(i),temp.get_sprite_position_y(i),width,height));
                arr[i]->sprite.setTexture(character_texture);
                arr[i]->helth = temp.get_enemie_helth(i);
            }
        }

        const int& get_enemie_helth(int index_enemie)const{return arr[index_enemie]->helth;}

        const float& get_sprite_position_x(int index_enemie_sprite)const{return arr[index_enemie_sprite]->sprite.getPosition().x;}

        const float& get_sprite_position_y(int index_enemie_sprite)const{return arr[index_enemie_sprite]->sprite.getPosition().y;}

        void reload_helth(int new_helth,int index)
        {
            arr[index]->helth = new_helth;
        }

        void move(float time)
        {
            for(int i=0 ; i<enemies_count; ++i)
                arr[i]->sprite.setPosition(arr[i]->sprite.getPosition().x-move_speed*time,arr[i]->sprite.getPosition().y);
        }

        void collision_register_enemies_with_border()
        {
            for(int i=0 ; i<enemies_count; ++i)
            {
                if(arr[i]->sprite.getPosition().x<0.f)
                {
                    if(enemies_count==1)
                        arr.pop_back();
                    else
                        arr.erase(arr.begin()+i);

                    --enemies_count;
                }
            }
        }

        void erase_enemie(int index)
        {
            if(enemies_count==1)
                arr.pop_back();
            else
                arr.erase(arr.begin()+index);

            --enemies_count;
        }

        void draw_character(RenderWindow& window)
        {
            for(int i=0 ; i<enemies_count;++i)
                window.draw(arr[i]->sprite);
        }

        static float get_speed(){return move_speed;}

        friend void collision_register_enemies_with_main_hero(main_hero*,enemies*);

        friend int detect_main_hero(main_hero* ,enemies*,const RenderWindow&);

        ~enemies()
        {
            delete [] one_unit;

            enemies_count = 0;

            if(!arr.empty())
                arr.clear();
        }
};

class main_hero:public character
{
        main_hero& operator=(const main_hero&);

        Text* helth_text;

        Font* helth_font;

        float move_speed;

        int helth;

        class Booster
        {
            Sprite booster_sprite;

            Texture booster_texture;

            int booster_state;

            bool used;

                public:

                    Booster()
                    {
                        booster_state = rand()%2;

                        switch(booster_state)
                        {
                            case 0:
                                booster_texture = texture_manager.get_texture(7);
                                booster_sprite.setTextureRect(IntRect(0,0,25,26));
                                booster_sprite.setTexture(booster_texture);
                                break;

                            case 1:
                                booster_texture = texture_manager.get_texture(7);
                                booster_sprite.setTextureRect(IntRect(29,0,25,26));
                                booster_sprite.setTexture(booster_texture);
                                break;
                        }

                        booster_sprite.setPosition(0,0);

                        used = false;
                    }

                    void booster_collision(main_hero* hero)
                    {
                        if(used==false && IntRect(hero->get_sprite().getPosition().x,hero->get_sprite().getPosition().y,hero->get_width(),hero->get_height()).intersects(IntRect(0,0,25,26)))
                        {
                            used = true;

                            switch(booster_state)
                            {
                                case 0:
                                    hero->change_move_speed(0.09f);
                                    break;

                                case 1:
                                    if(hero->get_helth()<600)
                                        hero->reload_helth(50+hero->get_helth());
                                    break;
                            }
                        }
                    }

                    void draw_booster(RenderWindow& window)
                    {
                        if(!used)
                            window.draw(booster_sprite);
                    }
        };


    public:

        Booster* booster;

        main_hero(const RenderWindow& window,int x=234, int y=0, int height = 17, int width = 29):character(height,width,2,x,y,1),helth(100),booster(new Booster())
        {
            move_speed = 0.04f;

            helth_font = new Font();

            helth_font->loadFromFile("font/font.ttf");

            helth_text = new Text("",*helth_font,10);

            helth_text->setColor(Color::Green);

            helth_text->setStyle(Text::Bold);

            character::character_sprite.setPosition(0,window.getSize().y/2.f);
        }

        main_hero(const main_hero& temp):character(temp)
        {
            move_speed = temp.get_speed();

            helth = temp.get_helth();
        }

        void change_bosster()
        {
            delete booster;

            booster = new Booster();
        }

        void reload_helth(const int& new_helth)
        {
            helth=new_helth;
        }

        void draw_character(RenderWindow& window)
        {
            window.draw(character_sprite);
            helth_text->setPosition(character::character_sprite.getPosition().x,character::character_sprite.getPosition().y-10);
            helth_text->setString("HP "+std::to_string(helth));
            window.draw(*helth_text);
        }

        bool attack()const
        {
            if(Keyboard::isKeyPressed(Keyboard::Space))
                return true;

            return false;
        }

        float get_speed()const{return move_speed;}

        void change_move_speed(float new_move_speed){move_speed = new_move_speed;}

        void move(const RenderWindow& temp,float time)
        {
            if(Keyboard::isKeyPressed(Keyboard::Left))
                if(character_sprite.getPosition().x>=0)
                    character_sprite.setPosition(character_sprite.getPosition().x-move_speed*time,character_sprite.getPosition().y);


            if(Keyboard::isKeyPressed(Keyboard::Right))
                if(character_sprite.getPosition().x+width<=temp.getSize().x)
                    character_sprite.setPosition(character_sprite.getPosition().x+move_speed*time,character_sprite.getPosition().y);

            if(Keyboard::isKeyPressed(Keyboard::Up))
                if(character_sprite.getPosition().y>0)
                    character_sprite.setPosition(character_sprite.getPosition().x,character_sprite.getPosition().y-move_speed*time);

            if(Keyboard::isKeyPressed(Keyboard::Down))
                if(character_sprite.getPosition().y+height<=temp.getSize().y)
                    character_sprite.setPosition(character_sprite.getPosition().x,character_sprite.getPosition().y+move_speed*time);
        }

        int get_helth()const{return helth;}

        friend void collision_register_enemies_with_main_hero(main_hero*,enemies*);

        friend int detect_main_hero(main_hero* ,enemies*,const RenderWindow&);

        ~main_hero(){delete booster;delete helth_font;delete helth_text;}
};

class Boss
{
    Sprite boss_state_sprite;

    int helth;

    Text* helth_text;

    Font* helth_font;

    Texture boss_state_texture;

    enemies* bot_for_state_of_fire;

    bool side_shift;

    int height;

    int width;

    float attack_radius;

    enum state_selector
    {
        state_of_fire,state_of_protect,
    }selector;

        public:

    Boss(const RenderWindow& window)
    {
        selector = state_of_fire;

        boss_state_texture = texture_manager.get_texture(4);

        bot_for_state_of_fire = new enemies(window,2,4,100,11,43,37,33);

        bot_for_state_of_fire->set_enemie_position(0,window.getSize().x*(2.7f/4),window.getSize().y/3.f);

        bot_for_state_of_fire->set_enemie_position(1,window.getSize().x*(2.7f/4),window.getSize().y*(2.f/3));

        width = 121;

        height = 122;

        boss_state_sprite.setTextureRect(IntRect(65,42,width,height));

        boss_state_sprite.setTexture(boss_state_texture);

        boss_state_sprite.setPosition(window.getSize().x-121,window.getSize().y*(1.4f/3));

        helth = 600;

        side_shift = true;

        attack_radius = sqrt(pow(window.getSize().x/2.f,2)+pow(window.getSize().y/2.f,2));

        helth_font = new Font();

        helth_font->loadFromFile("font/font.ttf");

        helth_text = new Text("",*helth_font,15);

        helth_text->setColor(Color::Green);

        helth_text->setStyle(Text::Bold);
    }

    int get_boss_width()const{return width;}

    float get_attack_radius()const{if(selector==state_of_protect)return attack_radius;}

    int get_boss_height()const{return height;}

    void draw_boss(RenderWindow& window)
    {
        if(selector==state_of_fire && helth!=0)
        {
            bot_for_state_of_fire->draw_character(window);

            window.draw(boss_state_sprite);
        }

        else if(helth!=0)
            window.draw(boss_state_sprite);

        helth_text->setString("HP "+std::to_string(helth));

        helth_text->setPosition(boss_state_sprite.getPosition().x,boss_state_sprite.getPosition().y);

        window.draw(*helth_text);
    }

    const Sprite get_boss_sprite()const{return boss_state_sprite;}

    float get_boss_turret_sprite_x(int index_turret)const{return bot_for_state_of_fire->get_sprite_position_x(index_turret);}

    float get_boss_turret_sprite_y(int index_turret)const{return bot_for_state_of_fire->get_sprite_position_y(index_turret);}

    int get_boss_helth()const{return helth;}

    void change_boss_helth(int damage){helth-=damage;}

    void move(const RenderWindow& window,float time)
    {
        if(selector==state_of_fire)
        {
            if(side_shift)
            {
                boss_state_sprite.setPosition(boss_state_sprite.getPosition().x,boss_state_sprite.getPosition().y-0.06*time);

                if(boss_state_sprite.getPosition().y<=0)
                    side_shift=false;
            }

            else
            {
                boss_state_sprite.setPosition(boss_state_sprite.getPosition().x,boss_state_sprite.getPosition().y+0.06*time);

                if(boss_state_sprite.getPosition().y+126>=window.getSize().y)
                    side_shift=true;
            }
        }
    }

    int get_state()const{return static_cast<int>(selector);}

    void switch_state(const RenderWindow& window)
    {
        if(selector==state_of_fire)
        {
            selector = state_of_protect;

            width = 194;

            height = 176;

            boss_state_texture = texture_manager.get_texture(6);

            boss_state_sprite.setTextureRect(IntRect(32,32,width,height));

            boss_state_sprite.setTexture(boss_state_texture);

            boss_state_sprite.setPosition(window.getSize().x/2.f-97.f,window.getSize().y/2.f-88.f);
        }

        else
        {
            selector=state_of_fire;

            width = 121;

            height = 122;

            boss_state_texture = texture_manager.get_texture(4);

            boss_state_sprite.setTextureRect(IntRect(65,42,width,height));

            boss_state_sprite.setTexture(boss_state_texture);

            boss_state_sprite.setPosition(window.getSize().x-width,window.getSize().y*(1.4f/3));
        }
    }

    void collision_register_main_hero_boss(main_hero* hero)
    {
            if(helth!=0)
                if(IntRect(hero->get_sprite().getPosition().x,hero->get_sprite().getPosition().y,hero->get_width(),hero->get_height()).intersects(IntRect(boss_state_sprite.getPosition().x,boss_state_sprite.getPosition().y,width,height)))
                    hero->reload_helth(0);

            if(selector==state_of_fire)
            {
                for(int i=0 ; i<2 ; ++i)
                {
                    if(IntRect(hero->get_sprite().getPosition().x,hero->get_sprite().getPosition().y,hero->get_width(),hero->get_height()).intersects(IntRect(bot_for_state_of_fire->get_sprite_position_x(i),bot_for_state_of_fire->get_sprite_position_y(i),bot_for_state_of_fire->get_width(),bot_for_state_of_fire->get_height())))
                        hero->reload_helth(0);
                }
            }
    }

    void set_boss_helth(int new_helth){helth = new_helth;}

    int detect_main_hero(main_hero* hero)
    {
        if(selector==state_of_fire)
        {
            multiset<std::pair<double,int>> coordinates;

            for(int i=0 ; i<2;++i)
                coordinates.insert({sqrt(pow(((hero->get_sprite().getPosition().x+hero->get_width())/2)-((bot_for_state_of_fire->get_sprite_position_x(i)+bot_for_state_of_fire->get_width())/2),2)+pow(((hero->get_sprite().getPosition().y+hero->get_height())/2)-((bot_for_state_of_fire->get_sprite_position_y(i)+bot_for_state_of_fire->get_height())/2),2)),i});

            return coordinates.begin()->second;
        }
    }

    ~Boss()
    {
        delete bot_for_state_of_fire;

        delete helth_font;

        delete helth_text;
    }
};

int detect_main_hero(main_hero* hero, enemies* enemies,const RenderWindow& window)
{
    if(hero!=nullptr && !enemies->arr.empty() && enemies->arr[0]->sprite.getPosition().x<=window.getSize().x/2-10)
    {
        multiset<std::pair<double,int>> coordinates;

        for(int i=0 ; i<enemies->get_enemies_count();++i)
            coordinates.insert({sqrt(pow(((hero->character_sprite.getPosition().x+hero->get_width())/2)-((enemies->arr[i]->sprite.getPosition().x+enemies->get_width())/2),2)+pow(((hero->character_sprite.getPosition().y+hero->get_height())/2)-((enemies->arr[i]->sprite.getPosition().y+enemies->get_height())/2),2)),i});

        return coordinates.begin()->second;
    }
}

void collision_register_enemies_with_main_hero(main_hero* hero, enemies* enemies)
{
    if(hero!=nullptr && enemies->get_enemies_count()!=0)
    {
        for(int i=0 ; i<enemies->get_enemies_count();++i)
        {
            if(IntRect(hero->character_sprite.getPosition().x,hero->character_sprite.getPosition().y,hero->get_width(),hero->get_height()).intersects(IntRect(enemies->arr[i]->sprite.getPosition().x,enemies->arr[i]->sprite.getPosition().y,enemies->width,enemies->height)))
            {
                hero->reload_helth(0);

                if(enemies->get_enemies_count()==1)
                    enemies->arr.pop_back();
                else
                    enemies->arr.erase(enemies->arr.begin()+i);

                enemies->change_enemies_count();

                break;
            }
        }
    }
}

struct main_hero_
{
    main_hero* main_hero_;

    float main_hero_fire;

    float booster_timer;

    float main_hero_time;

    Clock main_hero_clock;

    vector<main_hero_ammunition*> hero_ammu;
};

struct simple_enemies_
{
    enemies* enemies_;

    int detect_index;

    float main_hero_detect_timer;

    float bot_change_weapon_timer;

    float enemie_time;

    Clock enemie_clock;

    vector<bot_ammunition*> bot_ammu;
};

struct boss_
{
    Boss* boss;

    int detect_index;

    float main_hero_boss_detect_timer;

    float boss_fire_timer;

    float boss_time;

    float a;

    float r;

    float speed;

    float state_switch_timer;

    Clock boss_clock;

    CircleShape circle[4];

    vector<bot_ammunition*> boss_hole_ammu[4];

    vector<main_hero_ammunition*> boss_ammu;
};

void main_hero_versus_simple_enemies(main_hero_* hero, simple_enemies_* enemies_,RenderWindow& window,const float& game_time)
{
    if(hero->main_hero_!=nullptr)
    {
        hero->main_hero_->booster->booster_collision(hero->main_hero_);

        hero->main_hero_->booster->draw_booster(window);
    }

    if(hero->main_hero_!=nullptr && hero->main_hero_->attack() && enemies_->enemies_->get_enemies_count()!=0)
    {
        if(hero->main_hero_fire>700)
        {
            hero->hero_ammu.push_back(new main_hero_ammunition(2));

            hero->hero_ammu.back()->set_start_coordinate(hero->main_hero_->get_sprite().getPosition().x+hero->main_hero_->get_width(),hero->main_hero_->get_sprite().getPosition().y);

            hero->main_hero_fire=0.f;
        }

        for(int i=0 ; i<enemies_->enemies_->get_enemies_count(); ++i)
        {
            for(int j=0 ; j<hero->hero_ammu.size();++j)
            {
                if(IntRect(enemies_->enemies_->get_sprite_position_x(i),enemies_->enemies_->get_sprite_position_y(i),enemies_->enemies_->get_width(),enemies_->enemies_->get_height()).intersects(IntRect(hero->hero_ammu[j]->get_x(),hero->hero_ammu[j]->get_y(),hero->hero_ammu[j]->get_width(),hero->hero_ammu[j]->get_height())))
                {
                    if(enemies_->enemies_->get_enemie_helth(i)==hero->hero_ammu[j]->get_damage())
                    {
                        enemies_->enemies_->erase_enemie(i);

                        ++score;
                    }
                    else
                        enemies_->enemies_->reload_helth(enemies_->enemies_->get_enemie_helth(i)-hero->hero_ammu[j]->get_damage(),i);

                    delete hero->hero_ammu[j];

                    if(hero->hero_ammu.size()==1)
                        hero->hero_ammu.pop_back();
                    else
                        hero->hero_ammu.erase(hero->hero_ammu.begin()+j);

                    goto afterloop;
                }

                else if(hero->hero_ammu[j]->get_x()+hero->hero_ammu[j]->get_width()>=window.getSize().x)
                {
                    delete hero->hero_ammu[j];

                    if(hero->hero_ammu.size()==1)
                        hero->hero_ammu.pop_back();
                    else
                        hero->hero_ammu.erase(hero->hero_ammu.begin()+j);

                    goto afterloop;
                }
            }
        }
    }

    else if(!hero->hero_ammu.empty())
    {
        for(int i=0 ; i<enemies_->enemies_->get_enemies_count(); ++i)
        {
            for(int j=0 ; j<hero->hero_ammu.size();++j)
            {
                if(IntRect(enemies_->enemies_->get_sprite_position_x(i),enemies_->enemies_->get_sprite_position_y(i),enemies_->enemies_->get_width(),enemies_->enemies_->get_height()).intersects(IntRect(hero->hero_ammu[j]->get_x(),hero->hero_ammu[j]->get_y(),hero->hero_ammu[j]->get_width(),hero->hero_ammu[j]->get_height())))
                {
                    if(enemies_->enemies_->get_enemie_helth(i)==hero->hero_ammu[j]->get_damage())
                    {
                        enemies_->enemies_->erase_enemie(i);

                        ++score;
                    }
                    else
                        enemies_->enemies_->reload_helth(enemies_->enemies_->get_enemie_helth(i)-hero->hero_ammu[j]->get_damage(),i);

                    delete hero->hero_ammu[j];

                    if(hero->hero_ammu.size()==1)
                        hero->hero_ammu.pop_back();
                    else
                        hero->hero_ammu.erase(hero->hero_ammu.begin()+j);

                    goto afterloop;
                }

                else if(hero->hero_ammu[j]->get_x()+hero->hero_ammu[j]->get_width()>=window.getSize().x)
                {
                    delete hero->hero_ammu[j];

                    if(hero->hero_ammu.size()==1)
                        hero->hero_ammu.pop_back();
                    else
                        hero->hero_ammu.erase(hero->hero_ammu.begin()+j);

                    goto afterloop;
                }
            }
        }
    }

    afterloop:

    if(!hero->hero_ammu.empty() && enemies_->enemies_->get_enemies_count()==0)
    {
        while(!hero->hero_ammu.empty())
        {
            for(int i=0 ; i<hero->hero_ammu.size();++i)
            {
                delete hero->hero_ammu[i];

                if(hero->hero_ammu.size()==1)
                    hero->hero_ammu.pop_back();
                else
                    hero->hero_ammu.erase(hero->hero_ammu.begin()+i);
                break;
            }
        }
    }

    for(int i=0 ; i<hero->hero_ammu.size();++i)
    {
        hero->hero_ammu[i]->draw_hero_ammunition(window);
        hero->hero_ammu[i]->update_coordinates(game_time);
    }

    if(hero->main_hero_!=nullptr && enemies_->enemies_->get_enemies_count()!=0)
    {
        collision_register_enemies_with_main_hero(hero->main_hero_,enemies_->enemies_);

        if(hero->main_hero_->get_helth()==0)
        {
            delete hero->main_hero_;

            hero->main_hero_ = nullptr;
        }

        if(hero->main_hero_!=nullptr)
        {
            if(enemies_->main_hero_detect_timer>600)
            {
                if(enemies_->bot_change_weapon_timer>1200)
                {
                    enemies_->bot_ammu.push_back(new bot_ammunition(1));
                    enemies_->bot_change_weapon_timer=0.f;
                }
                else
                    enemies_->bot_ammu.push_back(new bot_ammunition(2));

                enemies_->detect_index = detect_main_hero(hero->main_hero_,enemies_->enemies_,window);

                enemies_->bot_ammu.back()->set_start_coordinate(enemies_->enemies_->get_sprite_position_x(enemies_->detect_index),enemies_->enemies_->get_sprite_position_y(enemies_->detect_index),hero->main_hero_->get_sprite().getPosition().x,hero->main_hero_->get_sprite().getPosition().y);

                enemies_->main_hero_detect_timer = 0.f;
            }

            for(int i=0 ;i<enemies_->bot_ammu.size(); ++i)
            {
                if(IntRect(hero->main_hero_->get_sprite().getPosition().x,hero->main_hero_->get_sprite().getPosition().y,hero->main_hero_->get_width(),hero->main_hero_->get_height()).intersects(IntRect(enemies_->bot_ammu[i]->get_ammunition_sprite().getPosition().x,enemies_->bot_ammu[i]->get_ammunition_sprite().getPosition().y,enemies_->bot_ammu[i]->get_width(),enemies_->bot_ammu[i]->get_height())))
                {
                    delete enemies_->bot_ammu[i];

                    if(enemies_->bot_ammu.size()==1)
                        enemies_->bot_ammu.pop_back();
                    else
                        enemies_->bot_ammu.erase(enemies_->bot_ammu.begin()+i);

                if(hero->main_hero_->get_helth()<=enemies_->bot_ammu[i]->get_damage())
                {
                    delete hero->main_hero_;

                    hero->main_hero_ = nullptr;
                }

                else
                    hero->main_hero_->reload_helth(hero->main_hero_->get_helth()-enemies_->bot_ammu[i]->get_damage());

                    break;
                }

                else if(enemies_->bot_ammu[i]->get_target_x()==enemies_->bot_ammu[i]->get_x() && enemies_->bot_ammu[i]->get_target_y()==enemies_->bot_ammu[i]->get_y())
                {
                    delete enemies_->bot_ammu[i];

                    if(enemies_->bot_ammu.size()==1)
                        enemies_->bot_ammu.pop_back();
                    else
                        enemies_->bot_ammu.erase(enemies_->bot_ammu.begin()+i);

                    break;
                }
            }
        }
    }

    if(((hero->main_hero_==nullptr || enemies_->enemies_->get_enemies_count()==0) || (hero->main_hero_==nullptr && enemies_->enemies_->get_enemies_count()==0)) && !enemies_->bot_ammu.empty())
    {
        for(int i=0 ; i<enemies_->bot_ammu.size();++i)
        {
            delete enemies_->bot_ammu[i];

            if(enemies_->bot_ammu.size()==1)
                enemies_->bot_ammu.pop_back();
            else
                enemies_->bot_ammu.erase(enemies_->bot_ammu.begin()+i);

            break;
        }
    }

    for(int i=0 ; i<enemies_->bot_ammu.size(); ++i)
    {
        enemies_->bot_ammu[i]->draw_ammunition(window);
        enemies_->bot_ammu[i]->update_coordinates(game_time);
    }
}

void main_hero_versus_boss(main_hero_* hero, boss_* boss, RenderWindow& window, const float& game_time, Backgound& backgound)
{
    if(hero->main_hero_!=nullptr && hero->main_hero_->attack() && boss->boss->get_boss_helth()!=0 && boss->boss->get_state()==0)
    {
        if(hero->main_hero_fire>700)
        {
            hero->hero_ammu.push_back(new main_hero_ammunition(2,2));

            hero->hero_ammu.back()->set_start_coordinate(hero->main_hero_->get_sprite().getPosition().x+hero->main_hero_->get_width(),hero->main_hero_->get_sprite().getPosition().y);

            hero->main_hero_fire=0.f;
        }

        for(int i=0 ; i<hero->hero_ammu.size();++i)
        {
            if(IntRect(hero->hero_ammu[i]->get_x(),hero->hero_ammu[i]->get_y(),hero->hero_ammu[i]->get_width(),hero->hero_ammu[i]->get_height()).intersects(IntRect(boss->boss->get_boss_sprite().getPosition().x,boss->boss->get_boss_sprite().getPosition().y,boss->boss->get_boss_width(),boss->boss->get_boss_height())))
            {
                if(boss->boss->get_boss_helth()<=hero->hero_ammu[i]->get_damage())
                {
                    boss->boss->set_boss_helth(0);

                    ++score;
                }
                else
                    boss->boss->set_boss_helth(boss->boss->get_boss_helth()-hero->hero_ammu[i]->get_damage());

                delete hero->hero_ammu[i];

                if(hero->hero_ammu.size()==1)
                    hero->hero_ammu.pop_back();
                else
                    hero->hero_ammu.erase(hero->hero_ammu.begin()+i);

                break;
            }

            else if(hero->hero_ammu[i]->get_x()+hero->hero_ammu[i]->get_width()>=window.getSize().x)
            {
                delete hero->hero_ammu[i];

                if(hero->hero_ammu.size()==1)
                    hero->hero_ammu.pop_back();
                else
                    hero->hero_ammu.erase(hero->hero_ammu.begin()+i);

                break;
            }
        }
    }

    else if(hero->hero_ammu.size() && boss->boss->get_boss_helth()!=0)
    {
        for(int i=0 ; i<hero->hero_ammu.size();++i)
        {
            if(IntRect(hero->hero_ammu[i]->get_x(),hero->hero_ammu[i]->get_y(),hero->hero_ammu[i]->get_width(),hero->hero_ammu[i]->get_height()).intersects(IntRect(boss->boss->get_boss_sprite().getPosition().x,boss->boss->get_boss_sprite().getPosition().y,boss->boss->get_boss_width(),boss->boss->get_boss_height())))
            {
                if(boss->boss->get_boss_helth()<=hero->hero_ammu[i]->get_damage())
                {
                    boss->boss->set_boss_helth(0);

                    ++score;
                }
                else
                    boss->boss->set_boss_helth(boss->boss->get_boss_helth()-hero->hero_ammu[i]->get_damage());

                delete hero->hero_ammu[i];

                if(hero->hero_ammu.size()==1)
                    hero->hero_ammu.pop_back();
                else
                    hero->hero_ammu.erase(hero->hero_ammu.begin()+i);

                break;
            }

            else if(hero->hero_ammu[i]->get_x()+hero->hero_ammu[i]->get_width()>=window.getSize().x)
            {
                delete hero->hero_ammu[i];

                if(hero->hero_ammu.size()==1)
                    hero->hero_ammu.pop_back();
                else
                    hero->hero_ammu.erase(hero->hero_ammu.begin()+i);

                break;
            }
        }
    }

    else if(!hero->hero_ammu.empty() && boss->boss->get_boss_helth()!=0)
    {
        while(!hero->hero_ammu.empty())
        {
            for(int i=0 ; i<hero->hero_ammu.size();++i)
            {
                delete hero->hero_ammu[i];

                if(hero->hero_ammu.size()==1)
                    hero->hero_ammu.pop_back();
                else
                    hero->hero_ammu.erase(hero->hero_ammu.begin()+i);
                break;
            }
        }
    }

    for(int i=0 ; i<hero->hero_ammu.size();++i)
    {
        hero->hero_ammu[i]->draw_hero_ammunition(window);
        hero->hero_ammu[i]->update_coordinates(game_time);
    }

    if(hero->main_hero_!=nullptr && boss->boss->get_boss_helth()!=0 && boss->boss->get_state()==0)
    {
        if(boss->boss_fire_timer>700)
        {
            boss->boss_ammu.push_back(new main_hero_ammunition(4));

            boss->boss_ammu.back()->set_start_coordinate(boss->boss->get_boss_sprite().getPosition().x,boss->boss->get_boss_sprite().getPosition().y+boss->boss->get_boss_sprite().getPosition().y/5.f);

            boss->boss_fire_timer=0.f;
        }

        for(int i=0 ; i<boss->boss_ammu.size(); ++i)
        {
            if(IntRect(hero->main_hero_->get_sprite().getPosition().x,hero->main_hero_->get_sprite().getPosition().y,hero->main_hero_->get_width(),hero->main_hero_->get_height()).intersects(IntRect(boss->boss_ammu[i]->get_x(),boss->boss_ammu[i]->get_y(),boss->boss_ammu[i]->get_width(),boss->boss_ammu[i]->get_height())))
            {
                if(hero->main_hero_->get_helth()<=boss->boss_ammu[i]->get_damage())
                {
                    delete hero->main_hero_;

                    hero->main_hero_ = nullptr;
                }

                else
                    hero->main_hero_->reload_helth(hero->main_hero_->get_helth()-boss->boss_ammu[i]->get_damage());

                delete boss->boss_ammu[i];

                if(boss->boss_ammu.size()==1)
                    boss->boss_ammu.pop_back();
                else
                    boss->boss_ammu.erase(boss->boss_ammu.begin()+i);

                break;
            }

            else if(boss->boss_ammu[i]->get_x()<=0.f || boss->boss_ammu[i]->get_y()<=0.f || boss->boss_ammu[i]->get_y()>=window.getSize().y)
            {
                delete boss->boss_ammu[i];

                if(boss->boss_ammu.size()==1)
                    boss->boss_ammu.pop_back();
                else
                    boss->boss_ammu.erase(boss->boss_ammu.begin()+i);

                break;
            }
        }
    }

    else if(!boss->boss_ammu.empty() && hero->main_hero_!=nullptr)
    {
        for(int i=0 ; i<boss->boss_ammu.size();++i)
        {
            if(IntRect(boss->boss_ammu[i]->get_x(),boss->boss_ammu[i]->get_y(),boss->boss_ammu[i]->get_width(),boss->boss_ammu[i]->get_height()).intersects(IntRect(hero->main_hero_->get_sprite().getPosition().x,hero->main_hero_->get_sprite().getPosition().y,hero->main_hero_->get_width(),hero->main_hero_->get_height())))
            {
                if(hero->main_hero_->get_helth()<=boss->boss_ammu[i]->get_damage())
                {
                    delete hero->main_hero_;

                    hero->main_hero_ = nullptr;
                }

                else
                    hero->main_hero_->reload_helth(hero->main_hero_->get_helth()-boss->boss_ammu[i]->get_damage());

                delete boss->boss_ammu[i];

                if(boss->boss_ammu.size()==1)
                    boss->boss_ammu.pop_back();
                else
                    boss->boss_ammu.erase(boss->boss_ammu.begin()+i);

                break;
            }

            else if(boss->boss_ammu[i]->get_x()<=0.f)
            {
                delete boss->boss_ammu[i];

                if(boss->boss_ammu.size()==1)
                    boss->boss_ammu.pop_back();
                else
                    boss->boss_ammu.erase(boss->boss_ammu.begin()+i);

                break;
            }
        }
    }

    else if(hero->main_hero_==nullptr && !boss->boss_ammu.empty())
    {
        while(!boss->boss_ammu.empty())
        {
            for(int i=0 ; i<boss->boss_ammu.size(); ++i)
            {
                delete boss->boss_ammu[i];

                if(boss->boss_ammu.size()==1)
                    boss->boss_ammu.pop_back();
                else
                    boss->boss_ammu.erase(boss->boss_ammu.begin()+i);

                break;
            }
        }
    }

    for(int i=0 ; i<boss->boss_ammu.size();++i)
    {
        boss->boss_ammu[i]->draw_hero_ammunition(window);
        boss->boss_ammu[i]->update_coordinates(game_time,false);
    }

    if(hero->main_hero_!=nullptr && boss->boss->get_boss_helth()!=0 && boss->boss->get_state()==0)
    {
        boss->boss->collision_register_main_hero_boss(hero->main_hero_);

        if(hero->main_hero_->get_helth()==0)
        {
            delete hero->main_hero_;

            hero->main_hero_ = nullptr;
        }

        if(hero->main_hero_!=nullptr)
        {
            if(boss->main_hero_boss_detect_timer>600)
            {
                boss->boss_hole_ammu[0].push_back(new bot_ammunition(3));

                boss->detect_index = boss->boss->detect_main_hero(hero->main_hero_);

                boss->boss_hole_ammu[0].back()->set_start_coordinate(boss->boss->get_boss_turret_sprite_x(boss->detect_index),boss->boss->get_boss_turret_sprite_y(boss->detect_index),hero->main_hero_->get_sprite().getPosition().x, hero->main_hero_->get_sprite().getPosition().y);

                boss->main_hero_boss_detect_timer = 0.f;
            }

            for(auto i = boss->boss_hole_ammu[0].begin() ;i!=boss->boss_hole_ammu[0].end(); ++i)
            {
                if(IntRect(hero->main_hero_->get_sprite().getPosition().x,hero->main_hero_->get_sprite().getPosition().y,hero->main_hero_->get_width(),hero->main_hero_->get_height()).intersects(IntRect((*i)->get_ammunition_sprite().getPosition().x,(*i)->get_ammunition_sprite().getPosition().y,(*i)->get_width(),(*i)->get_height())))
                {
                    delete (*i);

                    if(boss->boss_hole_ammu[0].size()==1)
                        boss->boss_hole_ammu[0].pop_back();
                    else
                        boss->boss_hole_ammu[0].erase(i);

                    if(hero->main_hero_->get_helth()==(*i)->get_damage())
                    {
                        delete hero->main_hero_;

                        hero->main_hero_ = nullptr;
                    }

                    else
                        hero->main_hero_->reload_helth(hero->main_hero_->get_helth()-(*i)->get_damage());

                    break;
                }

                else if((*i)->get_target_x()==(*i)->get_x() && (*i)->get_target_y()==(*i)->get_y())
                {
                    delete (*i);

                    if(boss->boss_hole_ammu[0].size()==1)
                        boss->boss_hole_ammu[0].pop_back();
                    else
                        boss->boss_hole_ammu[0].erase(i);

                    break;
                }
            }
        }
    }

    if(((hero->main_hero_==nullptr || boss->boss->get_boss_helth()==0) || (hero->main_hero_==nullptr && boss->boss->get_boss_helth()==0)) && !boss->boss_hole_ammu[0].empty() && boss->boss->get_state()==0)
    {
        for(auto i = boss->boss_hole_ammu[0].begin(); i!=boss->boss_hole_ammu[0].end(); ++i)
        {
            delete (*i);

            if(boss->boss_hole_ammu[0].size()==1)
                boss->boss_hole_ammu[0].pop_back();
            else
                boss->boss_hole_ammu[0].erase(i);

            break;
        }
    }

    if(boss->state_switch_timer>60000)
    {
        backgound.set_boss_background(window);

        boss->state_switch_timer=0.f;

        boss->boss_fire_timer=0.f;

        boss->a=0.f;

        if(!boss->boss_hole_ammu[0].empty())
        {
            while(!boss->boss_hole_ammu[0].empty())
            {
                for(auto i = boss->boss_hole_ammu[0].begin(); i!=boss->boss_hole_ammu[0].end(); ++i)
                {
                    delete (*i);

                    if(boss->boss_hole_ammu[0].size()==1)
                        boss->boss_hole_ammu[0].pop_back();
                    else
                        boss->boss_hole_ammu[0].erase(i);

                    break;
                }
            }
        }

        if(!boss->boss_hole_ammu[1].empty())
        {
            while(!boss->boss_hole_ammu[1].empty())
            {
                for(auto i = boss->boss_hole_ammu[1].begin(); i!=boss->boss_hole_ammu[1].end(); ++i)
                {
                    delete (*i);

                    if(boss->boss_hole_ammu[1].size()==1)
                        boss->boss_hole_ammu[1].pop_back();
                    else
                        boss->boss_hole_ammu[1].erase(i);

                    break;
                }
            }
        }

        if(!boss->boss_hole_ammu[2].empty())
        {
            while(!boss->boss_hole_ammu[2].empty())
            {
                for(auto i = boss->boss_hole_ammu[2].begin(); i!=boss->boss_hole_ammu[2].end(); ++i)
                {
                    delete (*i);

                    if(boss->boss_hole_ammu[2].size()==1)
                        boss->boss_hole_ammu[2].pop_back();
                    else
                        boss->boss_hole_ammu[2].erase(i);

                    break;
                }
            }
        }

        if(!boss->boss_hole_ammu[3].empty())
        {
            while(!boss->boss_hole_ammu[3].empty())
            {
                for(auto i = boss->boss_hole_ammu[3].begin(); i!=boss->boss_hole_ammu[3].end(); ++i)
                {
                    delete (*i);

                    if(boss->boss_hole_ammu[3].size()==1)
                        boss->boss_hole_ammu[3].pop_back();
                    else
                        boss->boss_hole_ammu[3].erase(i);

                    break;
                }
            }
        }

        if(!hero->hero_ammu.empty())
        {
            while(!hero->hero_ammu.empty())
            {
                for(int i=0 ; i<hero->hero_ammu.size();++i)
                {
                    delete hero->hero_ammu[i];

                    if(hero->hero_ammu.size()==1)
                        hero->hero_ammu.pop_back();
                    else
                        hero->hero_ammu.erase(hero->hero_ammu.begin()+i);

                    break;
                }
            }
        }

        if(!boss->boss_ammu.empty())
        {
            while(!boss->boss_ammu.empty())
            {
                for(int i=0 ; i<boss->boss_ammu.size();++i)
                {
                    delete boss->boss_ammu[i];

                    if(boss->boss_ammu.size()==1)
                        boss->boss_ammu.pop_back();
                    else
                        boss->boss_ammu.erase(boss->boss_ammu.begin()+i);

                    break;
                }
            }
        }

        boss->boss->switch_state(window);
        boss->r = boss->boss->get_attack_radius();
    }

    if(hero->main_hero_!=nullptr && boss->boss->get_boss_helth()!=0 && boss->boss->get_state()==1)
    {
        boss->boss->collision_register_main_hero_boss(hero->main_hero_);

        if(hero->main_hero_->get_helth()==0)
        {
            delete hero->main_hero_;

            hero->main_hero_ = nullptr;
        }

        if(hero->main_hero_!=nullptr)
        {
            boss->a+=acos(-1)/180*(boss->speed*0.04);

            boss->circle[0].setPosition(window.getSize().x/2.f + boss->r * cosf(boss->a-400),window.getSize().y/2.f + boss->r * sinf(boss->a-400));

            boss->circle[1].setPosition(window.getSize().x/2.f + boss->r * cosf(boss->a+200),window.getSize().y/2.f + boss->r * sinf(boss->a+200));

            boss->circle[2].setPosition(window.getSize().x/2.f + boss->r * cosf(boss->a+10),window.getSize().y/2.f + boss->r * sinf(boss->a+10));

            boss->circle[3].setPosition(window.getSize().x/2.f + boss->r * cosf(boss->a-100),window.getSize().y/2.f + boss->r * sinf(boss->a-100));

            if(boss->a>=6.f)
                boss->a=0.f;

            if(boss->boss_fire_timer>700)
            {
                boss->boss_hole_ammu[0].push_back(new bot_ammunition(4));
                boss->boss_hole_ammu[1].push_back(new bot_ammunition(4));
                boss->boss_hole_ammu[2].push_back(new bot_ammunition(4));
                boss->boss_hole_ammu[3].push_back(new bot_ammunition(4));

                boss->boss_hole_ammu[0].back()->set_start_coordinate(window.getSize().x/2.f,window.getSize().y/2.f,boss->circle[0].getPosition().x,boss->circle[0].getPosition().y);
                boss->boss_hole_ammu[1].back()->set_start_coordinate(window.getSize().x/2.f,window.getSize().y/2.f,boss->circle[1].getPosition().x,boss->circle[1].getPosition().y);
                boss->boss_hole_ammu[2].back()->set_start_coordinate(window.getSize().x/2.f,window.getSize().y/2.f,boss->circle[2].getPosition().x,boss->circle[2].getPosition().y);
                boss->boss_hole_ammu[3].back()->set_start_coordinate(window.getSize().x/2.f,window.getSize().y/2.f,boss->circle[3].getPosition().x,boss->circle[3].getPosition().y);

                boss->boss_fire_timer = 0.f;
            }

            for(auto i = boss->boss_hole_ammu[0].begin() ;i!=boss->boss_hole_ammu[0].end(); ++i)
            {
                if(IntRect(hero->main_hero_->get_sprite().getPosition().x,hero->main_hero_->get_sprite().getPosition().y,hero->main_hero_->get_width(),hero->main_hero_->get_height()).intersects(IntRect((*i)->get_ammunition_sprite().getPosition().x,(*i)->get_ammunition_sprite().getPosition().y,(*i)->get_width(),(*i)->get_height())))
                {
                    delete (*i);

                    if(boss->boss_hole_ammu[0].size()==1)
                        boss->boss_hole_ammu[0].pop_back();
                    else
                        boss->boss_hole_ammu[0].erase(i);

                    if(hero->main_hero_->get_helth()<=(*i)->get_damage())
                    {
                        delete hero->main_hero_;

                        hero->main_hero_ = nullptr;
                    }

                    else
                        hero->main_hero_->reload_helth(hero->main_hero_->get_helth()-(*i)->get_damage());

                    break;
                }

                else if((*i)->get_target_x()==(*i)->get_x() && (*i)->get_target_y()==(*i)->get_y())
                {
                    delete (*i);

                    if(boss->boss_hole_ammu[0].size()==1)
                        boss->boss_hole_ammu[0].pop_back();
                    else
                        boss->boss_hole_ammu[0].erase(i);

                    break;
                }
            }
        }

        if(hero->main_hero_!=nullptr)
        {
            for(auto i = boss->boss_hole_ammu[1].begin() ;i!=boss->boss_hole_ammu[1].end(); ++i)
            {
                if(IntRect(hero->main_hero_->get_sprite().getPosition().x,hero->main_hero_->get_sprite().getPosition().y,hero->main_hero_->get_width(),hero->main_hero_->get_height()).intersects(IntRect((*i)->get_ammunition_sprite().getPosition().x,(*i)->get_ammunition_sprite().getPosition().y,(*i)->get_width(),(*i)->get_height())))
                {
                    delete (*i);

                    if(boss->boss_hole_ammu[1].size()==1)
                        boss->boss_hole_ammu[1].pop_back();
                    else
                        boss->boss_hole_ammu[1].erase(i);

                    if(hero->main_hero_->get_helth()<=(*i)->get_damage())
                    {
                        delete hero->main_hero_;

                        hero->main_hero_ = nullptr;
                    }

                    else
                        hero->main_hero_->reload_helth(hero->main_hero_->get_helth()-(*i)->get_damage());

                    break;
                }

                else if((*i)->get_target_x()==(*i)->get_x() && (*i)->get_target_y()==(*i)->get_y())
                {
                    delete (*i);

                    if(boss->boss_hole_ammu[1].size()==1)
                        boss->boss_hole_ammu[1].pop_back();
                    else
                        boss->boss_hole_ammu[1].erase(i);

                    break;
                }
            }
        }

        if(hero->main_hero_!=nullptr)
        {
            for(auto i = boss->boss_hole_ammu[2].begin() ;i!=boss->boss_hole_ammu[2].end(); ++i)
            {
                if(IntRect(hero->main_hero_->get_sprite().getPosition().x,hero->main_hero_->get_sprite().getPosition().y,hero->main_hero_->get_width(),hero->main_hero_->get_height()).intersects(IntRect((*i)->get_ammunition_sprite().getPosition().x,(*i)->get_ammunition_sprite().getPosition().y,(*i)->get_width(),(*i)->get_height())))
                {
                    delete (*i);

                    if(boss->boss_hole_ammu[2].size()==1)
                        boss->boss_hole_ammu[2].pop_back();
                    else
                        boss->boss_hole_ammu[2].erase(i);

                    if(hero->main_hero_->get_helth()<=(*i)->get_damage())
                    {
                        delete hero->main_hero_;

                        hero->main_hero_ = nullptr;
                    }

                    else
                        hero->main_hero_->reload_helth(hero->main_hero_->get_helth()-(*i)->get_damage());

                    break;
                }

                else if((*i)->get_target_x()==(*i)->get_x() && (*i)->get_target_y()==(*i)->get_y())
                {
                    delete (*i);

                    if(boss->boss_hole_ammu[2].size()==1)
                        boss->boss_hole_ammu[2].pop_back();
                    else
                        boss->boss_hole_ammu[2].erase(i);

                    break;
                }
            }
        }

        if(hero->main_hero_!=nullptr)
        {
            for(auto i = boss->boss_hole_ammu[3].begin() ;i!=boss->boss_hole_ammu[3].end(); ++i)
            {
                if(IntRect(hero->main_hero_->get_sprite().getPosition().x,hero->main_hero_->get_sprite().getPosition().y,hero->main_hero_->get_width(),hero->main_hero_->get_height()).intersects(IntRect((*i)->get_ammunition_sprite().getPosition().x,(*i)->get_ammunition_sprite().getPosition().y,(*i)->get_width(),(*i)->get_height())))
                {
                    delete (*i);

                    if(boss->boss_hole_ammu[3].size()==1)
                        boss->boss_hole_ammu[3].pop_back();
                    else
                        boss->boss_hole_ammu[3].erase(i);

                    if(hero->main_hero_->get_helth()<=(*i)->get_damage())
                    {
                        delete hero->main_hero_;

                        hero->main_hero_ = nullptr;
                    }

                    else
                        hero->main_hero_->reload_helth(hero->main_hero_->get_helth()-(*i)->get_damage());

                    break;
                }

                else if((*i)->get_target_x()==(*i)->get_x() && (*i)->get_target_y()==(*i)->get_y())
                {
                    delete (*i);

                    if(boss->boss_hole_ammu[3].size()==1)
                        boss->boss_hole_ammu[3].pop_back();
                    else
                        boss->boss_hole_ammu[3].erase(i);

                    break;
                }
            }
        }
    }

    if(((hero->main_hero_==nullptr || boss->boss->get_boss_helth()==0) || (hero->main_hero_==nullptr && boss->boss->get_boss_helth()==0)) && !boss->boss_hole_ammu[0].empty() && boss->boss->get_state()==1)
    {
        for(auto i = boss->boss_hole_ammu[0].begin(); i!=boss->boss_hole_ammu[0].end(); ++i)
        {
            delete (*i);

            if(boss->boss_hole_ammu[0].size()==1)
                boss->boss_hole_ammu[0].pop_back();
            else
                boss->boss_hole_ammu[0].erase(i);

            break;
        }
    }

    for(auto i = boss->boss_hole_ammu[0].begin(); i!=boss->boss_hole_ammu[0].end(); ++i)
    {
        (*i)->draw_ammunition(window);
        (*i)->update_coordinates(game_time);
    }

    if(((hero->main_hero_==nullptr || boss->boss->get_boss_helth()==0) || (hero->main_hero_==nullptr && boss->boss->get_boss_helth()==0)) && !boss->boss_hole_ammu[1].empty() && boss->boss->get_state()==1)
    {
        for(auto i = boss->boss_hole_ammu[1].begin(); i!=boss->boss_hole_ammu[1].end(); ++i)
        {
            delete (*i);

            if(boss->boss_hole_ammu[1].size()==1)
                boss->boss_hole_ammu[1].pop_back();
            else
                boss->boss_hole_ammu[1].erase(i);

            break;
        }
    }

    if(boss->boss->get_state()==1)
    {
        for(auto i = boss->boss_hole_ammu[1].begin(); i!=boss->boss_hole_ammu[1].end(); ++i)
        {
            (*i)->draw_ammunition(window);
            (*i)->update_coordinates(game_time);
        }
    }

    if(((hero->main_hero_==nullptr || boss->boss->get_boss_helth()==0) || (hero->main_hero_==nullptr && boss->boss->get_boss_helth()==0)) && !boss->boss_hole_ammu[2].empty() && boss->boss->get_state()==1)
    {
        for(auto i = boss->boss_hole_ammu[2].begin(); i!=boss->boss_hole_ammu[2].end(); ++i)
        {
            delete (*i);

            if(boss->boss_hole_ammu[2].size()==1)
                boss->boss_hole_ammu[2].pop_back();
            else
                boss->boss_hole_ammu[2].erase(i);

            break;
        }
    }

    if(boss->boss->get_state()==1)
    {
        for(auto i = boss->boss_hole_ammu[2].begin(); i!=boss->boss_hole_ammu[2].end(); ++i)
        {
            (*i)->draw_ammunition(window);
            (*i)->update_coordinates(game_time);
        }
    }

    if(((hero->main_hero_==nullptr || boss->boss->get_boss_helth()==0) || (hero->main_hero_==nullptr && boss->boss->get_boss_helth()==0)) && !boss->boss_hole_ammu[3].empty() && boss->boss->get_state()==1)
    {
        for(auto i = boss->boss_hole_ammu[3].begin(); i!=boss->boss_hole_ammu[3].end(); ++i)
        {
            delete (*i);

            if(boss->boss_hole_ammu[3].size()==1)
                boss->boss_hole_ammu[3].pop_back();
            else
                boss->boss_hole_ammu[3].erase(i);

            break;
        }
    }

    if(boss->boss->get_state()==1)
    {
        for(auto i = boss->boss_hole_ammu[3].begin(); i!=boss->boss_hole_ammu[3].end(); ++i)
        {
            (*i)->draw_ammunition(window);
            (*i)->update_coordinates(game_time);
        }
    }
}

simple_enemies_* simple_enemies_manager(const RenderWindow& window ,simple_enemies_* enemie)
{
    enemie->enemies_  = new enemies(window,100);

    enemie->main_hero_detect_timer = 0.f;

    enemie->bot_change_weapon_timer = 0.f;

    enemie->enemie_time = 0.f;

    return enemie;
}

int main_menu(RenderWindow& window,bool flag=false,Backgound* back = nullptr)
{
    Font font;
    font.loadFromFile("font/font.ttf");
    Text text1("",font,15);
    Text text2("",font,15);
    Text text3("",font,15);
    text1.setString("COMPANY");
    text2.setString("ARCADE");
    text3.setString("EXIT");
    text1.setColor(Color::Green);
    text2.setColor(Color::Green);
    text3.setColor(Color::Green);
    text1.setPosition(window.getSize().x/2.f,window.getSize().y/2.f);
    text2.setPosition(text1.getPosition().x,text1.getPosition().y+20);
    text3.setPosition(text2.getPosition().x,text2.getPosition().y+20);
	
	if(flag==false)
	{
		while(window.isOpen())
		{
			sf::Event event;

			while(window.pollEvent(event))
			{
				if(event.type == sf::Event::Closed)
					window.close();
			}

			window.clear();
			if(IntRect(text1.getPosition().x,text1.getPosition().y,105,15).contains(Mouse::getPosition(window))&& Mouse::isButtonPressed(Mouse::Left)){return 1;}
			if(IntRect(text2.getPosition().x,text2.getPosition().y,90,15).contains(Mouse::getPosition(window)) && Mouse::isButtonPressed(Mouse::Left)){return 2;}
			if(IntRect(text3.getPosition().x,text3.getPosition().y,60,15).contains(Mouse::getPosition(window)) && Mouse::isButtonPressed(Mouse::Left)){window.close();}
			window.draw(text1);
			window.draw(text2);
			window.draw(text3);
			window.display();
		}
	}
	
	else
	{
		while(window.isOpen())
		{
			sf::Event event;

			while(window.pollEvent(event))
			{
				if(event.type == sf::Event::Closed)
					window.close();
			}

			window.clear();
			back->draw_background(window);
			if(IntRect(text3.getPosition().x,text3.getPosition().y,60,15).contains(Mouse::getPosition(window)) && Mouse::isButtonPressed(Mouse::Left)){window.close();}
			window.draw(text3);
			window.display();
		}
	}
}

const float::enemies::move_speed = 0.009f;

int main()
{
    sf::RenderWindow window(sf::VideoMode(1000, 1000),"SPACE FUCKER",sf::Style::Close);
    srand(time(NULL));

    int game_mode = main_menu(window);

    if(game_mode==1 || game_mode==2)
    {
        Backgound backgound(window);

        main_hero_ hero1;

        hero1.main_hero_ = new main_hero(window);

        boss_ boss1;

        boss1.boss = nullptr;

        simple_enemies_* enemies1 = simple_enemies_manager(window,new simple_enemies_);

        hero1.main_hero_fire = 0.f;

        Clock main_clock;

        float game_time=0.f;

        while(window.isOpen())
        {
            game_time = main_clock.getElapsedTime().asMicroseconds();

            if(hero1.main_hero_==nullptr && !hero1.hero_ammu.empty())
            {
                for(int i=0 ; i<hero1.hero_ammu.size();++i)
                    delete hero1.hero_ammu[i];

                hero1.hero_ammu.clear();
            }

            if(enemies1!=nullptr)
                enemies1->enemie_time = enemies1->enemie_clock.getElapsedTime().asMicroseconds();

            if(hero1.main_hero_!=nullptr)
                hero1.main_hero_time = hero1.main_hero_clock.getElapsedTime().asMicroseconds();

            if(hero1.main_hero_!=nullptr)
                hero1.main_hero_clock.restart();

            if(enemies1!=nullptr)
                enemies1->enemie_clock.restart();

            main_clock.restart();

            if(enemies1!=nullptr)
                enemies1->enemie_time/=200;

            if(hero1.main_hero_!=nullptr)
                hero1.main_hero_time/=400;

            game_time/=400;

            if(enemies1!=nullptr)
                enemies1->main_hero_detect_timer+=enemies1->enemie_time;

            if(enemies1!=nullptr)
                enemies1->bot_change_weapon_timer+=enemies1->enemie_time;

            if(hero1.main_hero_!=nullptr)
                hero1.main_hero_fire+=hero1.main_hero_time;

            if(hero1.main_hero_!=nullptr)
                hero1.booster_timer+=hero1.main_hero_time;

            sf::Event event;

            while(window.pollEvent(event))
            {
                if(event.type == sf::Event::Closed)
                    window.close();
            }

            window.clear();
			
			if(!backgound.get_end_state())
				backgound.draw_background(window);
			
            if(hero1.main_hero_!=nullptr && enemies1!=nullptr)
                main_hero_versus_simple_enemies(&hero1,enemies1,window,game_time);

            if(enemies1==nullptr && hero1.main_hero_!=nullptr && boss1.boss!=nullptr)
                main_hero_versus_boss(&hero1,&boss1,window,game_time,backgound);

            if(enemies1!=nullptr && enemies1->enemies_->get_enemies_count()!=0)
            {
                enemies1->enemies_->collision_register_enemies_with_border();
                enemies1->enemies_->move(game_time);
                enemies1->enemies_->draw_character(window);
            }

            else if(enemies1!=nullptr)
            {
                static int enemies_count = 1;

                if(!enemies1->bot_ammu.empty())
                {
                    for(int i=0 ; i<enemies1->bot_ammu.size();++i)
                        delete enemies1->bot_ammu[i];

                    enemies1->bot_ammu.clear();
                }

                delete enemies1->enemies_;

                delete enemies1;

                if(game_mode == 2 && hero1.main_hero_!=nullptr)
                {
                    enemies1 = simple_enemies_manager(window,new simple_enemies_);

                    backgound.change_simple_background(window);
                }

                else if(hero1.main_hero_==nullptr)
				{	
					enemies1->enemies_ = nullptr;
					
					enemies1 = nullptr;
				}

                if(game_mode==1)
                {
                    if((hero1.main_hero_!=nullptr && enemies_count==4) || hero1.main_hero_== nullptr)
                        enemies1 = nullptr;

                    else if(enemies_count<4 && hero1.main_hero_!=nullptr)
                    {
                        enemies1 = simple_enemies_manager(window,new simple_enemies_);

                        backgound.change_simple_background(window);

                        ++enemies_count;
                    }

                    if(enemies_count==4 && hero1.main_hero_!=nullptr && enemies1==nullptr)
                    {
                        if(hero1.main_hero_->get_helth()<300)
                            hero1.main_hero_->reload_helth(300);

                        backgound.set_boss_background(window);

                        backgound.set_boss_background(window);

                        boss1.boss = new Boss(window);

                        boss1.boss->switch_state(window);

                        for(int i=0 ; i<4 ; ++i)
                            boss1.circle[i].setRadius(2);

                        for(int i=0 ; i<4;++i)
                            boss1.circle[i].setOrigin(1,1);

                        boss1.speed = 0.5;
                        boss1.a=0.f;

                        boss1.boss_fire_timer = 0.f;

                        boss1.state_switch_timer = 0.f;

                        boss1.main_hero_boss_detect_timer = 0.f;
                    }
                }
            }

            if(boss1.boss!=nullptr)
                boss1.boss_time = boss1.boss_clock.getElapsedTime().asMicroseconds();

            if(boss1.boss!=nullptr)
                boss1.boss_clock.restart();

            if(boss1.boss!=nullptr)
                boss1.boss_time/=300;

            if(boss1.boss!=nullptr)
                boss1.boss_fire_timer+=boss1.boss_time;

            if(boss1.boss!=nullptr)
                boss1.state_switch_timer+=boss1.boss_time;

            if(boss1.boss!=nullptr)
                boss1.main_hero_boss_detect_timer+=boss1.boss_time;

            if(hero1.main_hero_!=nullptr)
            {
                if(hero1.booster_timer>60000 && boss1.boss==nullptr)
                {
                    hero1.main_hero_->change_move_speed(0.04f);
                    hero1.main_hero_->change_bosster();
                    hero1.booster_timer = 0.f;
                }

                if(boss1.boss!=nullptr)
                    hero1.main_hero_->change_move_speed(0.04f);

                hero1.main_hero_->move(window,game_time);
                hero1.main_hero_->draw_character(window);
            }

            if(boss1.boss!=nullptr && boss1.boss->get_boss_helth()!=0 && hero1.main_hero_!=nullptr)
            {
                boss1.boss->move(window,game_time);
                boss1.boss->draw_boss(window);
            }

            else if(boss1.boss!=nullptr && ((boss1.boss->get_boss_helth()==0 && (hero1.main_hero_!=nullptr || hero1.main_hero_==nullptr)) || ((boss1.boss->get_boss_helth()==0 || boss1.boss->get_boss_helth()!=0) && hero1.main_hero_== nullptr)))
            {
                backgound.set_end_game(window);

                if(!boss1.boss_hole_ammu[0].empty())
                {
                    for(auto i = boss1.boss_hole_ammu[0].begin(); i!=boss1.boss_hole_ammu[0].end(); ++i)
                        delete (*i);

                    boss1.boss_hole_ammu[0].clear();
                }

                if(!boss1.boss_hole_ammu[1].empty())
                {
                    for(auto i = boss1.boss_hole_ammu[1].begin(); i!=boss1.boss_hole_ammu[1].end(); ++i)
                        delete (*i);

                    boss1.boss_hole_ammu[1].clear();
                }

                if(!boss1.boss_hole_ammu[2].empty())
                {
                    for(auto i = boss1.boss_hole_ammu[2].begin(); i!=boss1.boss_hole_ammu[2].end(); ++i)
                        delete (*i);

                    boss1.boss_hole_ammu[2].clear();
                }

                if(!boss1.boss_hole_ammu[3].empty())
                {
                    for(auto i = boss1.boss_hole_ammu[3].begin(); i!=boss1.boss_hole_ammu[3].end(); ++i)
                        delete (*i);

                    boss1.boss_hole_ammu[3].clear();
                }

                if(!boss1.boss_ammu.empty())
                {
                    for(int i=0 ; i<boss1.boss_ammu.size();++i)
                        delete boss1.boss_ammu[i];

                    boss1.boss_ammu.clear();
                }

                delete boss1.boss;

                boss1.boss=nullptr;
            }

            if(hero1.main_hero_==nullptr && !backgound.get_end_state())
				backgound.set_end_game(window);
			
			if(backgound.get_end_state())
			{	
				if(enemies1!=nullptr)
				{
					delete enemies1->enemies_;

					delete enemies1;
					
					enemies1 = nullptr;
				}
				
				main_menu(window,true,&backgound);
			}


            window.display();
        }
    }
	
	return 0;
}
