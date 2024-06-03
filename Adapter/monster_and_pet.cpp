#include "monster_and_pet.h"

/* Slime */
std::string Slime::Name() const { return "Slime"; }
int Slime::AttackAbility() const { return 6; }
int Slime::DefenseAbility() const { return 20; }

/* Goblin */
std::string Goblin::Name() const { return "Goblin"; }
int Goblin::AttackAbility() const { return 30; }
int Goblin::DefenseAbility() const { return 10; }

/* Dragon */
std::string Dragon::Name() const { return "Dragon"; }
int Dragon::AttackAbility() const { return 1000; }
int Dragon::DefenseAbility() const { return 500; }

/* Puppy */
std::string Puppy::Name() const { return "Puppy"; }
int Puppy::CutenessAbility() const { return 50; }
int Puppy::BattleBonus() const { return 5; }

/* Cat */
std::string Cat::Name() const { return "Cat"; }
int Cat::CutenessAbility() const { return 40; }
int Cat::BattleBonus() const { return 10; }

/* PetAdapterStatic */
template <typename MonsterType, typename>
std::string PetAdapterStatic<MonsterType>::Name() const { return monster_.Name(); }

template <typename MonsterType, typename>
int PetAdapterStatic<MonsterType>::CutenessAbility() const { return monster_.DefenseAbility() - 2 * monster_.AttackAbility(); }

template <typename MonsterType, typename>
int PetAdapterStatic<MonsterType>::BattleBonus() const { return monster_.AttackAbility() + monster_.DefenseAbility() / 2; }

/* PetAdapterDynamic */
PetAdapterDynamic::PetAdapterDynamic(std::unique_ptr<Monster>&& monster)
    : monster_(std::move(monster)) {}

std::unique_ptr<Monster> PetAdapterDynamic::ChangeMonster(std::unique_ptr<Monster>&& monster) 
{
    std::unique_ptr<Monster> returnedMonster = std::move(monster_);
    monster_ = std::move(monster); 
    return returnedMonster;
}

std::string PetAdapterDynamic::Name() const { return monster_->Name(); }
int PetAdapterDynamic::CutenessAbility() const { return monster_->DefenseAbility() - 2 * monster_->AttackAbility(); }
int PetAdapterDynamic::BattleBonus() const { return monster_->AttackAbility() + monster_->DefenseAbility() / 2; }

void PrintMonster(Monster const& monster)
{
    std::cout << "---- Infomation ----" << std::endl;
    std::cout << "Name             : " << monster.Name() << std::endl;
    std::cout << "Attack Ability   : " << monster.AttackAbility() << std::endl;
    std::cout << "Defense Ability  : " << monster.DefenseAbility() << std::endl;
    std::cout << "--------------------" << std::endl;
}

void PrintPet(Pet const& pet)
{
    std::cout << "---- Infomation ----" << std::endl;
    std::cout << "Name             : " << pet.Name() << std::endl;
    std::cout << "Cuteness Ability : " << pet.CutenessAbility() << std::endl;
    std::cout << "Battle Bonus     : " << pet.BattleBonus() << std::endl;
    std::cout << "--------------------" << std::endl;
}

/* Explicit template instantiation */
template class PetAdapterStatic<Slime>;
template class PetAdapterStatic<Goblin>;
template class PetAdapterStatic<Dragon>;

int main()
{
    Puppy puppy;
    Cat cat;

    std::cout << "====== Normal Pet ======" << std::endl << std::endl;

    PrintPet(puppy);
    PrintPet(cat);

    std::cout << std::endl << "====== Monster Pet ======" << std::endl << std::endl;

    PetAdapterStatic<Slime> petSlime;
    PetAdapterStatic<Goblin> petGoblin;
    PetAdapterStatic<Dragon> petDragon;

    PrintPet(petSlime);
    PrintPet(petGoblin);
    PrintPet(petDragon);

    std::cout << std::endl << "====== Monster ======" << std::endl << std::endl;

    auto slime = std::make_unique<Slime>();
    auto goblin = std::make_unique<Goblin>();
    auto dragon = std::make_unique<Dragon>();

    PrintMonster(*slime);
    PrintMonster(*goblin);
    PrintMonster(*dragon);

    std::cout << std::endl << "====== Pet From Monster ======" << std::endl << std::endl;

    PetAdapterDynamic petAdapter(std::move(slime));
    PrintPet(petAdapter);
    petAdapter.ChangeMonster(std::move(goblin));
    PrintPet(petAdapter);
    auto returnedMonster = petAdapter.ChangeMonster(std::move(dragon));
    PrintPet(petAdapter);

    std::cout << std::endl << "====== Monster Returned From Pet ======" << std::endl << std::endl;

    PrintMonster(*returnedMonster);
}
