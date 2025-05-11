#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <algorithm>
#include <cstdlib>

using std::string;
using std::vector;
using std::cout;
using std::cin;
using std::ws;
using std::getline;
using std::srand;
using std::rand;
using std::time;
using std::max;
using std::min;

struct Student 
{
    string name;
    int hp;
    int dmg;
    int def;         
    int luck;        
    int crit;        
    int stamina;     
    int healChance;  

    Student(string name,
            int hp,
            int dmg,
            int def,
            int luck,
            int crit,
            int stamina,
            int healChance)
        : name(name), hp(hp), dmg(dmg), def(def),
          luck(luck), crit(crit),
          stamina(stamina), healChance(healChance)
    {}

    bool roll(int chance) 
    {
        return (rand() % 100 < chance);
    }

    bool isDead() const 
    {
        return hp <= 0;
    }

    void receiveDamage(int incoming) 
    {
        if (roll(luck)) 
        {
            cout << "\t" << name << " уклоняется от части урона!\n";
            incoming /= 2;
        }
        incoming = max(0, incoming - def);
        hp -= incoming;
        cout << "\t" << name << " получает " << incoming << " dmg (HP=" << hp << ")\n";
    }

    int attack(bool useSpecial = false) 
    {
        int base = dmg;
        if (useSpecial && stamina >= 30) 
        {
            cout << "\t" << name << " использует СПЕЦИАЛЬНУЮ АТАКУ!\n";
            stamina -= 30;
            base *= 3;
        }
        if (roll(crit)) 
        {
            cout << "\t" << name << " критует!\n";
            base *= 2;
        }
        return base;
    }

    void regen() 
    {
        int oldSt = stamina;
        stamina = min(100, stamina + 10);
        cout << "\t" << name << " восстанавливает выносливость (" << oldSt
             << "->" << stamina << ")\n";
        if (roll(healChance) && hp > 0) 
        {
            int heal = rand() % 16 + 5;
            hp += heal;
            cout << "\t" << name << " лечится на " << heal << " HP (теперь " << hp << ")\n";
        }
    }

    void printStatus() const 
    {
        cout << name << " [HP=" << hp
             << "; DEF=" << def
             << "; Dmg=" << dmg
             << "; Luck=" << luck
             << "; Crit=" << crit
             << "; Stam=" << stamina
             << "; HealCh=" << healChance
             << "]\n";
    }
};

void freeForAll(vector<Student>& players) 
{
    int round = 1;
    while (true) 
    {
        cout << "\n=== РАУНД " << round++ << " ===\n";
        vector<Student*> alive;
        for (auto &p : players)
            if (!p.isDead()) alive.push_back(&p);
        if (alive.size() <= 1) break;

        for (auto *attacker : alive) 
        {
            attacker->regen();
            vector<Student*> targets;
            for (auto *t : alive)
                if (t != attacker) targets.push_back(t);
            if (targets.empty()) break;
            Student* defender = targets[rand() % targets.size()];

            bool useSpec = (round % 3 == 0);
            int dmgDone = attacker->attack(useSpec);
            defender->receiveDamage(dmgDone);
        }
    }

    vector<Student*> alive;
    for (auto &p : players)
        if (!p.isDead()) alive.push_back(&p);

    if (alive.empty()) 
    {
        cout << "\n--- Все погибли! Ничья. ---\n";
    } else 
    {
        cout << "\n--- Победитель: " << alive[0]->name << "! ---\n";
    }
}

int main() 
{
    srand(static_cast<unsigned>(time(0)));

    int n;
    cout << "Введите число персонажей: ";
    cin >> n;
    vector<Student> players;
    players.reserve(n);

    for (int i = 0; i < n; ++i) 
    {
        cout << "\n### Персонаж " << (i + 1) << " ###\n";
        string name;
        int hp, dmg, def, luck, crit, stamina, healCh;
        cout << "Имя: ";
        cin >> ws;
        getline(cin, name);
        cout << "HP (например 100): ";
        cin >> hp;
        cout << "Урон (dmg, напр. 10): ";
        cin >> dmg;
        cout << "Защита (def, напр. 5): ";
        cin >> def;
        cout << "Шанс удачи (luck, 0-100): ";
        cin >> luck;
        cout << "Шанс крита (crit, 0-100): ";
        cin >> crit;
        cout << "Выносливость (stamina, 0-100): ";
        cin >> stamina;
        cout << "Шанс лечения (healChance, 0-100): ";
        cin >> healCh;

        players.emplace_back(name, hp, dmg, def, luck, crit, stamina, healCh);
    }

    cout << "\nСтарт free-for-all с " << players.size() << " игроками:\n";
    for (auto &p : players) p.printStatus();

    freeForAll(players);
    return 0;
}
