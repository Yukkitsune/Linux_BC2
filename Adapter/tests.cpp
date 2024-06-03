#include <gtest/gtest.h>
#include "monster_and_pet.h"

TEST(SlimeTest, NameTest) {
    Slime slime;
    EXPECT_EQ(slime.Name(), "Slime");
}

TEST(SlimeTest, AttackAbilityTest) {
    Slime slime;
    EXPECT_EQ(slime.AttackAbility(), 6);
}

TEST(SlimeTest, DefenseAbilityTest) {
    Slime slime;
    EXPECT_EQ(slime.DefenseAbility(), 20);
}

TEST(GoblinTest, NameTest) {
    Goblin goblin;
    EXPECT_EQ(goblin.Name(), "Goblin");
}

TEST(GoblinTest, AttackAbilityTest) {
    Goblin goblin;
    EXPECT_EQ(goblin.AttackAbility(), 30);
}

TEST(GoblinTest, DefenseAbilityTest) {
    Goblin goblin;
    EXPECT_EQ(goblin.DefenseAbility(), 10);
}

TEST(DragonTest, NameTest) {
    Dragon dragon;
    EXPECT_EQ(dragon.Name(), "Dragon");
}

TEST(DragonTest, AttackAbilityTest) {
    Dragon dragon;
    EXPECT_EQ(dragon.AttackAbility(), 1000);
}

TEST(DragonTest, DefenseAbilityTest) {
    Dragon dragon;
    EXPECT_EQ(dragon.DefenseAbility(), 500);
}

TEST(PetAdapterStaticTest, SlimeToPet) {
    PetAdapterStatic<Slime> petSlime;
    EXPECT_EQ(petSlime.Name(), "Slime");
    EXPECT_EQ(petSlime.CutenessAbility(), 8); // 20 - 2 * 6
    EXPECT_EQ(petSlime.BattleBonus(), 16); // 6 + 20 / 2
}

TEST(PetAdapterStaticTest, GoblinToPet) {
    PetAdapterStatic<Goblin> petGoblin;
    EXPECT_EQ(petGoblin.Name(), "Goblin");
    EXPECT_EQ(petGoblin.CutenessAbility(), -50); // 10 - 2 * 30
    EXPECT_EQ(petGoblin.BattleBonus(), 35); // 30 + 10 / 2
}

TEST(PetAdapterStaticTest, DragonToPet) {
    PetAdapterStatic<Dragon> petDragon;
    EXPECT_EQ(petDragon.Name(), "Dragon");
    EXPECT_EQ(petDragon.CutenessAbility(), -1500); // 500 - 2 * 1000
    EXPECT_EQ(petDragon.BattleBonus(), 1250); // 1000 + 500 / 2
}

TEST(PetAdapterDynamicTest, ChangeMonster) {
    auto slime = std::make_unique<Slime>();
    auto goblin = std::make_unique<Goblin>();
    auto dragon = std::make_unique<Dragon>();

    PetAdapterDynamic petAdapter(std::move(slime));
    EXPECT_EQ(petAdapter.Name(), "Slime");
    EXPECT_EQ(petAdapter.CutenessAbility(), 8);
    EXPECT_EQ(petAdapter.BattleBonus(), 16);

    petAdapter.ChangeMonster(std::move(goblin));
    EXPECT_EQ(petAdapter.Name(), "Goblin");
    EXPECT_EQ(petAdapter.CutenessAbility(), -50);
    EXPECT_EQ(petAdapter.BattleBonus(), 35);

    auto returnedMonster = petAdapter.ChangeMonster(std::move(dragon));
    EXPECT_EQ(petAdapter.Name(), "Dragon");
    EXPECT_EQ(petAdapter.CutenessAbility(), -1500);
    EXPECT_EQ(petAdapter.BattleBonus(), 1250);

    EXPECT_EQ(returnedMonster->Name(), "Goblin");
    EXPECT_EQ(returnedMonster->AttackAbility(), 30);
    EXPECT_EQ(returnedMonster->DefenseAbility(), 10);
}
