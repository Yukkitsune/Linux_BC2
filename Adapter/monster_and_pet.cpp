#include "monster_and_pet.h"
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
