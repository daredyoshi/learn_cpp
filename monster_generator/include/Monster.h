#ifndef MONSTER
#define MONSTER 


#include <string>



class Monster{
public:
    enum class Type{
        ogre,
        dragon,
        orc,
        giant_spider,
        slime,
        skeleton,
        zombie,
        troll,
        goblin,
        max_monster_types 
    };
    
    Monster(Type type = Type::dragon, std::string name = "", std::string roar = "", int hp = 0) :
        m_type{type}, m_name{name}, m_roar{roar}, m_hitPoints{hp} {}

    std::string_view getTypeString() const;
    void print() const;

private:
    Type m_type{};
    std::string m_name{};
    std::string m_roar{};
    int m_hitPoints{};
   


};



#endif /* ifndef MONSTER */
