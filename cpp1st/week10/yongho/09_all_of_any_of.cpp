#include <algorithm>
#include <functional>
#include <iostream>
#include <string>
#include <vector>

struct User
{
    std::string name;
    int level;

    User(std::string name, int level) : name(name), level(level) {}
    bool operator==(const User& user) const 
    {
        if (name == user.name && level == user.level)
        {
            return true;
        }
        return false;
    }
};

class Party
{
    public:
        std::vector<User> users;

        bool add_user(std::string name, int level)
        {
            User new_user(name, level);
            if (std::find(users.begin(), users.end(), new_user) != users.end())
            {
                return false;
            }
            users.push_back(new_user);
            return true;
        }

        //level 15 can join dungeon
        bool can_join_dungeon()
        {
            return std::all_of(users.begin(), users.end(),
                                [](User& user) { return user.level >= 15; });
        }

        //level 19 can user special item
        bool can_use_special_item()
        {
            return std::any_of(users.begin(), users.end(),
                                [](User& user) { return user.level >= 19; });
        }
};

int main()
{
    Party party;
    party.add_user("ChulSu", 15);
    party.add_user("YoungHee", 18);
    party.add_user("MinSoo", 12);
    party.add_user("SooBin", 19);

    std::cout << std::boolalpha;
    std::cout << "Can join the dungeon? " << party.can_join_dungeon() << std::endl;
    std::cout << "Can use the special item? " << party.can_use_special_item() << std::endl;
}